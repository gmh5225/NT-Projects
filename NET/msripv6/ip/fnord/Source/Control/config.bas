Attribute VB_Name = "Config"
DefInt A-Z
Option Explicit

'========Public Config Vars and Structs========
'--------Server--------
Public ServerAddressStr As String

'--------General (HTTP) Vars--------
Public PortNumStr As String

Public InitNumThreadsStr As String
Public MaxNumThreadsStr As String
Public NumThreadsKeepFreeStr As String
Public ThreadCompactPeriodStr As String
Public ThreadCompactLazinessStr As String

Public IndexFileNameStr As String
Public ErrorMsgPathStr As String
Public TempPathStr As String
Public ScriptDNSBool As Boolean

'--------Log Vars--------
'General
Public LogPathStr As String
'Common Log
Public ComLogEnabledBool As Boolean
Public ComLogNameStr As String
Public ComLogConvertIPBool As Boolean
'Count Log
Public CntLogEnabledBool As Boolean
Public CntLogNameStr As String
Public CntLogCountFilesBool As Boolean
Public CntLogCountConnectsBool As Boolean
Public CntLogCountKBytesBool As Boolean
'Reference Log
Public RefLogEnabledBool As Boolean
Public RefLogNameStr As String

'--------Path Mapping Vars--------
Public Type DirMappingT
    'General Stuff
    RemotePathStr As String 'Key
    LocalPathStr As String
    'Security
    AllowDirListBool As Boolean
    ScriptingStr As String
    AuthUserStr As String
    AuthLocStr As String
End Type
Public NumMappings As Integer
Public DirMappings() As DirMappingT

'--------User Vars--------
Public Type UserT
    NameStr As String 'Key
    PasswordStr As String
End Type
Public NumUsers As Integer
Public Users() As UserT

'--------Group Vars--------
Public Type GroupT
    NameStr As String 'Key
    NumMembers As Integer
    Members() As String
End Type
Public NumGroups As Integer
Public Groups() As GroupT

'--------MIME Vars--------
Public Type MIMETypeT
    FileExtStr As String 'Key
    DescriptionStr As String
End Type
Public NumMIMETypes As Integer
Public MIMETypes() As MIMETypeT

'========API Declarations========
'Load APIs for registry editing
Private Type FILETIME
        dwLowDateTime As Long
        dwHighDateTime As Long
End Type
Private Declare Function RegOpenKeyEx Lib "advapi32.dll" Alias "RegOpenKeyExA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal ulOptions As Long, ByVal samDesired As Long, phkResult As Long) As Long
Private Declare Function RegCloseKey Lib "advapi32.dll" (ByVal hKey As Long) As Long
Private Declare Function RegCreateKeyEx Lib "advapi32.dll" Alias "RegCreateKeyExA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal Reserved As Long, ByVal lpClass As String, ByVal dwOptions As Long, ByVal samDesired As Long, ByVal lpSecurityAttributes As Long, phkResult As Long, lpdwDisposition As Long) As Long
Private Declare Function RegDeleteKey Lib "advapi32.dll" Alias "RegDeleteKeyA" (ByVal hKey As Long, ByVal lpSubKey As String) As Long
Private Declare Function RegSetValueEx Lib "advapi32.dll" Alias "RegSetValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal Reserved As Long, ByVal dwType As Long, ByVal lpData As String, ByVal cbData As Long) As Long         ' Note that if you declare the lpData parameter as String, you must pass it By Value.
Private Declare Function RegQueryValueEx Lib "advapi32.dll" Alias "RegQueryValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal lpReserved As Long, lpType As Long, ByVal lpData As String, lpcbData As Long) As Long         ' Note that if you declare the lpData parameter as String, you must pass it By Value.
'Origial Declaration, the reserved parameter was set up wrong and I set up the class parameter to always be double NULL
'Private Declare Function RegEnumKeyEx Lib "advapi32.dll" Alias "RegEnumKeyExA" (ByVal hKey As Long, ByVal dwIndex As Long, ByVal lpName As String, lpcbName As Long, lpReserved As Long, ByVal lpClass As String, lpcbClass As Long, lpftLastWriteTime As FILETIME) As Long
Private Declare Function RegEnumKeyEx Lib "advapi32.dll" Alias "RegEnumKeyExA" (ByVal hKey As Long, ByVal dwIndex As Long, ByVal lpName As String, lpcbName As Long, ByVal lpReserved As Long, ByVal lpClass As Long, ByVal lpcbClass As Long, lpftLastWriteTime As FILETIME) As Long


Const ERROR_SUCCESS = 0&
Const HKEY_LOCAL_MACHINE = &H80000002
Const STANDARD_RIGHTS_ALL = &H1F0000
Const KEY_QUERY_VALUE = &H1
Const KEY_SET_VALUE = &H2
Const KEY_CREATE_SUB_KEY = &H4
Const KEY_ENUMERATE_SUB_KEYS = &H8
Const KEY_NOTIFY = &H10
Const KEY_CREATE_LINK = &H20
Const SYNCHRONIZE = &H100000
Const KEY_ALL_ACCESS = ((STANDARD_RIGHTS_ALL Or KEY_QUERY_VALUE _
    Or KEY_SET_VALUE Or KEY_CREATE_SUB_KEY Or KEY_ENUMERATE_SUB_KEYS _
    Or KEY_NOTIFY Or KEY_CREATE_LINK) And (Not SYNCHRONIZE))
Const REG_OPTION_NON_VOLATILE = 0       ' Key is preserved when system is rebooted
Const REG_CREATED_NEW_KEY = &H1                      ' New Registry Key created
Const REG_OPENED_EXISTING_KEY = &H2                      ' Existing Key opened
Const REG_SZ = 1

'Thanx to Jason Formo for the reload message code
'Load APIs for IPC (Enable Server reload)
Private Declare Function RegisterWindowMessage Lib "user32" Alias "RegisterWindowMessageA" (ByVal lpString As String) As Long
Private Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hwnd As Long, ByVal wMsg As Long, ByVal wParam As Long, lParam As Long) As Long
'Assume WindowCaption is NULL, so we can search for
'any caption since the window class of the server is unique
Private Declare Function FindWindow Lib "user32" Alias "FindWindowA" (ByVal lpClassName As String, ByVal lpWindowName As Long) As Long

Dim ServerReloadMsg As Long
Dim ServerWindowHnd As Long





Sub AddGroup(NameStr As String)
'Adds an empty Group to the configuration data

NumGroups = NumGroups + 1
ReDim Preserve Groups(NumGroups)
Groups(NumGroups).NameStr = LCase(NameStr)
Groups(NumGroups).NumMembers = 0
End Sub


Sub AddPathMapping(RemotePathStr As String, LocalPathStr As String, _
    AllowDirListBool As Boolean, ScriptingStr As String, AuthUserStr As String, _
    AuthLocStr As String)
'Adds a Path Mapping to the configuration data

NumMappings = NumMappings + 1
ReDim Preserve DirMappings(NumMappings) As DirMappingT
DirMappings(NumMappings).RemotePathStr = RemotePathStr
DirMappings(NumMappings).LocalPathStr = LocalPathStr
DirMappings(NumMappings).AllowDirListBool = AllowDirListBool
DirMappings(NumMappings).ScriptingStr = ScriptingStr
DirMappings(NumMappings).AuthUserStr = AuthUserStr
DirMappings(NumMappings).AuthLocStr = AuthLocStr
End Sub


Sub AddUser(NameStr As String, PasswordStr As String)
'Adds a User to the configuration data

NumUsers = NumUsers + 1
ReDim Preserve Users(NumUsers)
Users(NumUsers).NameStr = NameStr
Users(NumUsers).PasswordStr = PasswordStr
End Sub


Sub AddUserToGroup(GroupNameStr As String, UserNameStr As String)
Dim i As Integer

'Find the group record
i = 0
While (i <= NumGroups) And (LCase(Groups(i).NameStr) <> LCase(GroupNameStr))
    i = i + 1
Wend

If i <= NumGroups Then
    'Add it the user to the members
    Groups(i).NumMembers = Groups(i).NumMembers + 1
    ReDim Preserve Groups(i).Members(Groups(i).NumMembers)
    Groups(i).Members(Groups(i).NumMembers) = UserNameStr
End If
End Sub


Function ConvertCString(CString As String) As String
'Cleans up a C style string into a VB string

Dim i As Integer
Dim CharStr As String
Dim NullStr As String
Dim RetStr As String

'Find the first NULL
NullStr = String(1, 0)
i = 1
Do
    CharStr = Mid(CString, i, 1)
    i = i + 1
Loop While ((i <= Len(CString)) And (CharStr <> NullStr))

'If we found the null, keep the part before the null
If (CharStr = NullStr) Then
    ConvertCString = Left(CString, i - 2)
Else
    ConvertCString = CString
End If
End Function
Sub AddMIMEType(FileExtStr As String, DescriptionStr As String)
'Adds a MIME type to the configuration data

NumMIMETypes = NumMIMETypes + 1
ReDim Preserve MIMETypes(NumMIMETypes) As MIMETypeT
MIMETypes(NumMIMETypes).FileExtStr = FileExtStr
MIMETypes(NumMIMETypes).DescriptionStr = DescriptionStr

End Sub




Sub CreateMimeType(Extention As String, Description As String)
'Creates a MIME type in the registry

Dim Ret As Long
Dim Disposition As Long
Dim MIMEKeyHandle As Long
Dim ExtKeyHandle As Long
Dim NumTypesStr As String
Dim NumTypes As Integer

'Open/Create the MIME Key
Ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\MIME", 0, KEY_ALL_ACCESS, _
    MIMEKeyHandle)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error openinging MIME key"

'Get/Set Number of Types
NumTypesStr = String(3, "X") 'Trick it into allocating memory
Ret = RegQueryValueEx(MIMEKeyHandle, "Number of Types", 0, REG_SZ, NumTypesStr, 4)
If Ret <> ERROR_SUCCESS Then Error.Print "Error getting Number of Types value"

NumTypes = Val(NumTypesStr)
NumTypes = NumTypes + 1
NumTypesStr = Format(NumTypes)

Ret = RegSetValueEx(MIMEKeyHandle, "Number of Types", 0, REG_SZ, NumTypesStr, Len(NumTypesStr) + 1)
If Ret <> ERROR_SUCCESS Then Error.Print "Error setting Number of Types value"

'Create the Key
Ret = RegCreateKeyEx(MIMEKeyHandle, Extention, 0, "", _
    REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, _
    ExtKeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating extention key"

'Set the description value
Ret = RegSetValueEx(ExtKeyHandle, "MIME Description", 0, REG_SZ, Description, Len(Description) + 1)
If Ret <> ERROR_SUCCESS Then Error.Print "Error setting MIME Description value"

'Close Extention Key
Ret = RegCloseKey(ExtKeyHandle)

'Close the MIME Key
Ret = RegCloseKey(MIMEKeyHandle)
End Sub
Sub DeleteGroup(NameStr As String)
Dim i As Integer
Dim j As Integer
Dim Found As Boolean

Found = False

j = 1
For i = 1 To NumGroups
    If (Groups(i).NameStr <> NameStr) Then
        Groups(j) = Groups(i)
        j = j + 1
    Else
        Found = True
    End If
Next i

If Found Then
    NumGroups = NumGroups - 1
    ReDim Preserve Groups(NumGroups)
End If

End Sub


Sub DeleteMIMEType(FileExtStr As String)
Dim i As Integer
Dim j As Integer
Dim Found As Boolean

Found = False

j = 1
For i = 1 To NumMIMETypes
    If (MIMETypes(i).FileExtStr <> FileExtStr) Then
        MIMETypes(j) = MIMETypes(i)
        j = j + 1
    Else
        Found = True
    End If
Next i

If Found Then
    NumMIMETypes = NumMIMETypes - 1
    ReDim Preserve MIMETypes(NumMIMETypes) As MIMETypeT
End If

End Sub


Sub DeletePathMapping(RemotePathStr As String)
Dim i As Integer
Dim j As Integer
Dim Found As Boolean

Found = False

j = 1
For i = 1 To NumMappings
    If (DirMappings(i).RemotePathStr <> RemotePathStr) Then
        DirMappings(j) = DirMappings(i)
        j = j + 1
    Else
        Found = True
    End If
Next i

If Found Then
    NumMappings = NumMappings - 1
    ReDim Preserve DirMappings(NumMappings) As DirMappingT
End If
End Sub


Sub DeleteUser(NameStr As String)
Dim i As Integer
Dim j As Integer
Dim Found As Boolean

Found = False

j = 1
For i = 1 To NumUsers
    If (Users(i).NameStr <> NameStr) Then
        Users(j) = Users(i)
        j = j + 1
    Else
        Found = True
    End If
Next i

If Found Then
    NumUsers = NumUsers - 1
    ReDim Preserve Users(NumUsers)
    
    'Remove from any groups (delete from all and let sanity checking handle it....)
    For i = 1 To NumGroups
        DeleteUserFromGroup Groups(i).NameStr, NameStr
    Next i
End If
End Sub


Sub DeleteUserFromGroup(GroupNameStr As String, UserNameStr As String)
Dim i As Integer
Dim j As Integer
Dim k As Integer
Dim Found As Boolean

'Find the group record
i = 0
While (i <= NumGroups) And (LCase(Groups(i).NameStr) <> LCase(GroupNameStr))
    i = i + 1
Wend

If i <= NumGroups Then
    'Delete the user from the members
    Groups(i).NumMembers = Groups(i).NumMembers + 1
    ReDim Preserve Groups(i).Members(Groups(i).NumMembers)
    Groups(i).Members(Groups(i).NumMembers) = UserNameStr
    
    Found = False

    k = 1
    For j = 1 To Groups(i).NumMembers
        If (LCase(Groups(i).Members(j)) <> LCase(UserNameStr)) Then
            Groups(i).Members(k) = Groups(i).Members(j)
            k = k + 1
        Else
            Found = True
        End If
    Next j

    If Found Then
        Groups(i).NumMembers = Groups(i).NumMembers - 1
        ReDim Preserve Groups(i).Members(Groups(i).NumMembers)
    End If
End If
End Sub

Function GetRegBoolean(KeyHandle As Long, EntryStr As String, Default As Boolean) As Boolean
Dim BoolStr As String

If Default = True Then
    BoolStr = GetRegString(KeyHandle, EntryStr, 2, "1")
Else
    BoolStr = GetRegString(KeyHandle, EntryStr, 2, "0")
End If

If BoolStr = "1" Then
    GetRegBoolean = True
Else
    GetRegBoolean = False
End If
End Function

Function GetRegString(KeyHandle As Long, EntryNameStr As String, MaxLen As Long, DefaultStr As String) As String

Dim OutStr As String
Dim Ret As Long

OutStr = String(MaxLen + 1, "X") 'Trick it into allocating memory
Ret = RegQueryValueEx(KeyHandle, EntryNameStr, 0, REG_SZ, OutStr, MaxLen + 1)

If Ret <> ERROR_SUCCESS Then
    'If we didn't get it, set it to default
    OutStr = DefaultStr
    Ret = RegSetValueEx(KeyHandle, EntryNameStr, 0, REG_SZ, OutStr, Len(OutStr) + 1)
    If Ret <> ERROR_SUCCESS Then Error.Print "Error setting" + EntryNameStr + " value"
Else
    'If we got it, convert it to a VB String
    OutStr = Left(Trim(ConvertCString(OutStr)), MaxLen)
End If

GetRegString = OutStr
End Function
Sub Init()

'Get/Register the server reload message
ServerReloadMsg = RegisterWindowMessage("Fnord Server Reload")

'Find the server window, NULL if not found...
ServerWindowHnd = FindWindow("Fnord Status", 0)
End Sub

Sub LoadConfig()
'Loads the entire configuration from the registry.
'If an entry is empty, the default is set and written
'to the registry.

LoadServerConfig
LoadGeneralConfig
LoadLogConfig
LoadPathConfig
LoadUserConfig
LoadGroupConfig
LoadMIMEConfig
End Sub



Sub LoadServerConfig()
'Loads settings that are valid for ALL Fnord
'services, seperate due to location in registry
'and due to planned FTP services

Dim Ret As Long
Dim Disposition As Long
Dim KeyHandle As Long

'-----Open/Create Key-----
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server", _
    0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, KeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating Application key in LoadServerConfig"

'-----Get Settings-----
ServerAddressStr = GetRegString(KeyHandle, "Server Address", 100, "")

'-----Close Applicaton Key-----
Ret = RegCloseKey(KeyHandle)
End Sub




Sub LoadGeneralConfig()
'Loads general HTTP server settings

Dim Ret As Long
Dim Disposition As Long
Dim KeyHandle As Long

'Open/Create Key
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\HTTPD", _
    0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, KeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating HTTPD key in LoadGeneralConfig"

'Get Settings
PortNumStr = GetRegString(KeyHandle, "Port Number", 4, "80")

InitNumThreadsStr = GetRegString(KeyHandle, "Initial Number of Threads", 4, "2")
MaxNumThreadsStr = GetRegString(KeyHandle, "Maximum Number of Threads", 4, "10")
NumThreadsKeepFreeStr = GetRegString(KeyHandle, "Number of Threads to Keep Free", 3, "2")
ThreadCompactPeriodStr = GetRegString(KeyHandle, "Thread Compact Period", 6, "300")
ThreadCompactLazinessStr = GetRegString(KeyHandle, "Thread Compact Laziness", 3, "2")

IndexFileNameStr = GetRegString(KeyHandle, "Index File Name", 50, "index.html")
ErrorMsgPathStr = GetRegString(KeyHandle, "Error Message Path", 100, "c:\fnord\error")
TempPathStr = GetRegString(KeyHandle, "Temp Directory", 100, "c:\fnord\temp")
ScriptDNSBool = GetRegBoolean(KeyHandle, "DNS Lookups for Scripts", True)

'Close Key
Ret = RegCloseKey(KeyHandle)

End Sub



Sub LoadGroupConfig()
Dim Ret As Long
Dim Disposition As Long
Dim LastWrite As FILETIME
Dim KeyHandle As Long
Dim NumGroupsStr As String
Dim i As Integer
Dim j As Integer

'Open/Create the Group Key
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Groups", 0, "", _
    REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, _
    KeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating Groups key"

'Get/Set Number of Groups
NumGroupsStr = String(3, "X") 'Trick it into allocating memory
Ret = RegQueryValueEx(KeyHandle, "Number of Groups", 0, REG_SZ, NumGroupsStr, 4)
If Ret <> ERROR_SUCCESS Then
    NumGroupsStr = "0"
    Ret = RegSetValueEx(KeyHandle, "Number of Groups", 0, REG_SZ, NumGroupsStr, Len(NumGroupsStr) + 1)
    If Ret <> ERROR_SUCCESS Then Error.Print "Error setting Number of Groups value"
End If
NumGroups = Val(NumGroupsStr)

If NumGroups > 0 Then
    'Allocate Memory for the Groups
    ReDim Groups(NumGroups) As GroupT
    
    Dim GroupKeyHandle As Long
    Dim GroupNameStr As String
    Dim NumMembersStr As String

    For i = 1 To NumGroups
        GroupNameStr = String(41, "X") 'Trick it into allocating memory
        NumMembersStr = String(5, "X") 'Trick it into allocating memory

        'Get Group Name
        Ret = RegEnumKeyEx(KeyHandle, (i - 1), GroupNameStr, 40, 0, 0, 0, LastWrite)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error Getting Group key"
        Groups(i).NameStr = RTrim(ConvertCString(GroupNameStr))

        'Open Group Key
        Ret = RegOpenKeyEx(KeyHandle, GroupNameStr, 0, KEY_ALL_ACCESS, GroupKeyHandle)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error opening Group key"
        
        'Number of Members
        Ret = RegQueryValueEx(GroupKeyHandle, "Number of Members", 0, REG_SZ, NumMembersStr, 4)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error getting Number of Members"
        Groups(i).NumMembers = Val(NumMembersStr)
        
        If Groups(i).NumMembers > 0 Then
            Dim MembersKeyHandle As Long
            Dim MemberNameStr As String
            
            'Allocate Memory for Members
            ReDim Groups(i).Members(Groups(i).NumMembers) As String
            
            'Open Members Key
            Ret = RegOpenKeyEx(GroupKeyHandle, "Members", 0, KEY_ALL_ACCESS, MembersKeyHandle)
            If Ret <> ERROR_SUCCESS Then Debug.Print "Error opening Group key"
            
            'Get Member Names
            For j = 1 To Groups(i).NumMembers
                MemberNameStr = String(41, "X") 'Trick it into allocating memory
                Ret = RegEnumKeyEx(MembersKeyHandle, (j - 1), MemberNameStr, 40, 0, 0, 0, LastWrite)
                If Ret <> ERROR_SUCCESS Then Debug.Print "Error Member Name"
                Groups(i).Members(j) = RTrim(ConvertCString(MemberNameStr))
            Next j
            
            'Close Members Key
            Ret = RegCloseKey(MembersKeyHandle)
        Else
            'Allocate Memory for Members
            ReDim Groups(i).Members(Groups(i).NumMembers + 1) As String
        End If
        
        'Close Group Key
        Ret = RegCloseKey(GroupKeyHandle)
    Next i
End If

'Close the Groups Key
Ret = RegCloseKey(KeyHandle)

End Sub


Sub LoadLogConfig()
'Loads general HTTP server settings

Dim Ret As Long
Dim Disposition As Long
Dim KeyHandle As Long
Dim SubKeyHandle As Long

'Open/Create Logs Key
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Logs", _
    0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, KeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating Logs key in LoadLogConfig"

'Get Log Settings
LogPathStr = GetRegString(KeyHandle, "Log Path", 100, "c:\fnord\logs")

'Open/Create Common Log Key
Ret = RegCreateKeyEx(KeyHandle, "HTTPD Common", _
    0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, SubKeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating HTTPD Common key in LoadLogConfig"

'Get Common Log Settings
ComLogEnabledBool = GetRegBoolean(SubKeyHandle, "Enabled", True)
ComLogNameStr = GetRegString(SubKeyHandle, "File Name", 100, "HTTPD Common Log.txt")
ComLogConvertIPBool = GetRegBoolean(SubKeyHandle, "Convert IP", True)

'Close Common Log Key
Ret = RegCloseKey(SubKeyHandle)

'Open/Create Count Log Key
Ret = RegCreateKeyEx(KeyHandle, "HTTPD Count", _
    0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, SubKeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating HTTPD Count key in LoadLogConfig"

'Get Count Log Settings
CntLogEnabledBool = GetRegBoolean(SubKeyHandle, "Enabled", True)
CntLogNameStr = GetRegString(SubKeyHandle, "File Name", 100, "HTTPD Count Log.txt")
CntLogCountFilesBool = GetRegBoolean(SubKeyHandle, "Count Files", True)
CntLogCountConnectsBool = GetRegBoolean(SubKeyHandle, "Count Connects", False)
CntLogCountKBytesBool = GetRegBoolean(SubKeyHandle, "Count KBytes", True)

'Close Count Log Key
Ret = RegCloseKey(SubKeyHandle)


'Open/Create Reference Log Key
Ret = RegCreateKeyEx(KeyHandle, "HTTPD Reference", _
    0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, SubKeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating HTTPD Reference key in LoadLogConfig"

'Get Reference Log Settings
RefLogEnabledBool = GetRegBoolean(SubKeyHandle, "Enabled", True)
RefLogNameStr = GetRegString(SubKeyHandle, "File Name", 100, "HTTPD Reference Log.txt")

'Close Reference Log Key
Ret = RegCloseKey(SubKeyHandle)

'Close Log Key
Ret = RegCloseKey(KeyHandle)
End Sub



Sub LoadMIMEConfig()
'Loads MIME settings

Dim Ret As Long
Dim Disposition As Long
Dim LastWrite As FILETIME
Dim KeyHandle As Long
Dim NumMIMETypesStr As String

'Open/Create Key
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\MIME", _
    0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, KeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating MIME key in LoadMIMEConfig"

'Get Number of types
NumMIMETypesStr = String(3, "X") 'Trick it into allocating memory
Ret = RegQueryValueEx(KeyHandle, "Number of Types", 0, REG_SZ, NumMIMETypesStr, 4)
If Ret <> ERROR_SUCCESS Then
    NumMIMETypesStr = "0"
    Ret = RegSetValueEx(KeyHandle, "Number of Types", 0, REG_SZ, NumMIMETypesStr, Len(NumMIMETypesStr) + 1)
    If Ret <> ERROR_SUCCESS Then Error.Print "Error setting Number of Types value in LoadMIMEConfig"

    'Add default types
    Ret = RegCloseKey(KeyHandle)
    
    CreateMimeType "HTML", "text/html"
    CreateMimeType "HTM", "text/html"
    CreateMimeType "JPG", "image/jpeg"
    CreateMimeType "JPEG", "image/jpeg"
    CreateMimeType "GIF", "image/gif"
    CreateMimeType "TXT", "text/plain"
    CreateMimeType "MOV", "video/quicktime"
    CreateMimeType "MPG", "video/mpeg"
    CreateMimeType "MPEG", "video/mpeg"
    CreateMimeType "QT", "video/quicktime"
    CreateMimeType "AU", "audio/basic"
    CreateMimeType "WAV", "audio/x-wave"
    
    Ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\MIME", _
        0, KEY_ALL_ACCESS, KeyHandle)
    If Ret <> ERROR_SUCCESS Then Debug.Print "Error reopening MIME key"
    NumMIMETypesStr = "12"
End If
NumMIMETypes = Val(NumMIMETypesStr)

If NumMIMETypes > 0 Then
    'Allocate Memory for Types
    ReDim MIMETypes(NumMIMETypes) As MIMETypeT
    Dim ExtKeyHandle As Long
    Dim Extention As String
    Dim Description As String
    Dim i As Long
    
    For i = 1 To NumMIMETypes
        Extention = String(11, "X") 'Trick it into allocating memory
        Description = String(101, "X") 'Trick it into allocating memory
        
        'Get Extention
        Ret = RegEnumKeyEx(KeyHandle, (i - 1), Extention, 10, 0, 0, 0, LastWrite)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error Getting MIME Extention key"
        MIMETypes(i).FileExtStr = RTrim(ConvertCString(Extention))
        'Open Type Key
        Ret = RegOpenKeyEx(KeyHandle, Extention, 0, KEY_ALL_ACCESS, ExtKeyHandle)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error opening MIME Extention key"
        'Get Data
        Ret = RegQueryValueEx(ExtKeyHandle, "MIME Description", 0, REG_SZ, Description, 100)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error Getting MIME Description"
        MIMETypes(i).DescriptionStr = RTrim(ConvertCString(Description))
        'Close Type Key
        Ret = RegCloseKey(ExtKeyHandle)
    Next i
End If

'Close Key
Ret = RegCloseKey(KeyHandle)

End Sub

Sub LoadPathConfig()
'Loads Path mappings
Dim Ret As Long
Dim Disposition As Long
Dim LastWrite As FILETIME
Dim KeyHandle As Long
Dim NumMappingsStr As String
Dim i As Integer

'Open/Create Key
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Directory Mappings", _
    0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, KeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating Directory Mappings key in LoadPathConfig"

'Get/Set Number of Mappings
NumMappingsStr = String(3, "X") 'Trick it into allocating memory
Ret = RegQueryValueEx(KeyHandle, "Number of Directories", 0, REG_SZ, NumMappingsStr, 4)
If Ret <> ERROR_SUCCESS Then
    NumMappingsStr = "0"
    Ret = RegSetValueEx(KeyHandle, "Number of Directories", 0, REG_SZ, NumMappingsStr, Len(NumMappingsStr) + 1)
    If Ret <> ERROR_SUCCESS Then Error.Print "Error setting Number of Directories value"
End If
NumMappings = Val(NumMappingsStr)

If NumMappings > 0 Then
    'Allocate Memory for Types
    ReDim DirMappings(NumMappings) As DirMappingT
    
    Dim DirKeyHandle As Long
    Dim Dir As String
    Dim LocalDir As String
    Dim AuthUser As String
    Dim AuthLocStr As String
    Dim ScriptingStr As String
    Dim BoolStr As String

    For i = 1 To NumMappings
        Dir = String(201, "X") 'Trick it into allocating memory
        LocalDir = String(301, "X") 'Trick it into allocating memory
        AuthUser = String(101, "X") 'Trick it into allocating memory
        AuthLocStr = String(20, "X") 'Trick it into allocating memory
        ScriptingStr = String(20, "X") 'Trick it into allocating memory
        BoolStr = String(4, "X") 'Trick it into allocating memory

        'Get Dir Key Name
        Ret = RegEnumKeyEx(KeyHandle, (i - 1), Dir, 200, 0, 0, 0, LastWrite)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error Getting Dir key"
        DirMappings(i).RemotePathStr = RTrim(ConvertCString(Dir))


        'Open Dir Key
        Ret = RegOpenKeyEx(KeyHandle, Dir, 0, KEY_ALL_ACCESS, DirKeyHandle)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error opening Dir key"
        
        'Local Dir
        Ret = RegQueryValueEx(DirKeyHandle, "Local Directory", 0, REG_SZ, LocalDir, 300)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error Getting Local Dir"
        DirMappings(i).LocalPathStr = RTrim(ConvertCString(LocalDir))
        'Authorized User
        Ret = RegQueryValueEx(DirKeyHandle, "Authorized User", 0, REG_SZ, AuthUser, 300)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error Getting Authorized User"
        DirMappings(i).AuthUserStr = RTrim(ConvertCString(AuthUser))
        'Allow List
        Ret = RegQueryValueEx(DirKeyHandle, "Allow Directory Listings", 0, REG_SZ, BoolStr, 3)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error Getting Allow Directory Listings"
        If Format(BoolStr) = 1 Then DirMappings(i).AllowDirListBool = True Else DirMappings(i).AllowDirListBool = False
        'Scripting
        Ret = RegQueryValueEx(DirKeyHandle, "Scripting", 0, REG_SZ, ScriptingStr, 20)
        If Ret <> ERROR_SUCCESS Then
            'Set for older versions
            Ret = RegSetValueEx(DirKeyHandle, "Scripting", 0, REG_SZ, "None", Len("None") + 1)
            ScriptingStr = "None"
        End If
        DirMappings(i).ScriptingStr = Trim(ConvertCString(ScriptingStr))
        'Authorized Location
        Ret = RegQueryValueEx(DirKeyHandle, "Authorized Location", 0, REG_SZ, AuthLocStr, 20)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error Getting Authorized Location"
        DirMappings(i).AuthLocStr = RTrim(ConvertCString(AuthLocStr))

        'Close Dir Key
        Ret = RegCloseKey(DirKeyHandle)
    Next i
End If

'Close Key
Ret = RegCloseKey(KeyHandle)

End Sub



Sub LoadUserConfig()
Dim Ret As Long
Dim Disposition As Long
Dim Class As String
Dim LastWrite As FILETIME
Dim KeyHandle As Long
Dim NumUsersStr As String
Dim i As Integer

'Open/Create Key
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Users", _
    0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, KeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating Directory Mappings key in LoadPathConfig"

'Get/Set Number of Users
NumUsersStr = String(3, "X") 'Trick it into allocating memory
Ret = RegQueryValueEx(KeyHandle, "Number of Users", 0, REG_SZ, NumUsersStr, 4)
If Ret <> ERROR_SUCCESS Then
    NumUsersStr = "0"
    Ret = RegSetValueEx(KeyHandle, "Number of Users", 0, REG_SZ, NumUsersStr, Len(NumUsersStr) + 1)
    If Ret <> ERROR_SUCCESS Then Error.Print "Error setting Number of Users value"
End If
NumUsers = Val(NumUsersStr)

If NumUsers > 0 Then
    'Allocate Memory for the Users
    ReDim Users(NumUsers) As UserT
    
    Dim UserKeyHandle As Long
    Dim UserNameStr As String
    Dim UserPasswordStr As String

    For i = 1 To NumUsers
        UserNameStr = String(41, "X") 'Trick it into allocating memory
        UserPasswordStr = String(41, "X") 'Trick it into allocating memory

        'Get User Name
        Ret = RegEnumKeyEx(KeyHandle, (i - 1), UserNameStr, 40, 0, 0, 0, LastWrite)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error Getting User key"
        Users(i).NameStr = RTrim(ConvertCString(UserNameStr))

        'Open User Key
        Ret = RegOpenKeyEx(KeyHandle, UserNameStr, 0, KEY_ALL_ACCESS, UserKeyHandle)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error opening User key"
        
        'Password
        Ret = RegQueryValueEx(UserKeyHandle, "Password", 0, REG_SZ, UserPasswordStr, 40)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error Getting User Password"
        Users(i).PasswordStr = RTrim(ConvertCString(UserPasswordStr))

        'Close User Key
        Ret = RegCloseKey(UserKeyHandle)
    Next i
End If

'Close the Users Key
Ret = RegCloseKey(KeyHandle)
End Sub



Sub RegNukeKey(KeyHnd As Long, SubKeyStr As String)
'Nukes a key and all subkeys, should work with both '95 and NT (fingers crossed)
'Mushroom cloud is optional....

Dim Ret As Long
Dim SubKeyHnd As Long

'Open the subkey so we can look for sub keys
Ret = RegOpenKeyEx(KeyHnd, SubKeyStr, 0, KEY_ALL_ACCESS, SubKeyHnd)
If Ret <> ERROR_SUCCESS Then Exit Sub

'Recursivly nuke all of the subsubkeys
Dim i As Long
Dim SubSubKeyStr As String
Dim LastWrite As FILETIME

i = 0
SubSubKeyStr = String(301, "X") 'Trick it into allocating memory
Ret = RegEnumKeyEx(SubKeyHnd, i, SubSubKeyStr, 300, 0, 0, 0, LastWrite)

Do While (Ret = ERROR_SUCCESS)
    SubSubKeyStr = RTrim(ConvertCString(SubSubKeyStr))
    RegNukeKey SubKeyHnd, SubSubKeyStr
    
    'i = i + 1 Not needed since the next one becomes index 0
    SubSubKeyStr = String(301, "X") 'Trick it into reallocating memory
    Ret = RegEnumKeyEx(SubKeyHnd, i, SubSubKeyStr, 300, 0, 0, 0, LastWrite)
Loop

'Close the target key
Ret = RegCloseKey(SubKeyHnd)

'Delete the target key
Ret = RegDeleteKey(KeyHnd, SubKeyStr)

End Sub


Sub RegSetStringValue(KeyHandle As Long, Var As String, Val As String)
Dim Ret As Long

Ret = RegSetValueEx(KeyHandle, Var, 0, REG_SZ, Val + String(1, 0), Len(Val) + 1)
If Ret <> ERROR_SUCCESS Then Error.Print "Error setting registry Var=" + Var + " Val=" + Val
End Sub

Sub SaveConfig()
SaveServerConfig
SaveGeneralConfig
SaveLogConfig
SavePathConfig
SaveUserConfig
SaveGroupConfig
SaveMIMEConfig
End Sub






Sub SaveGeneralConfig()
Dim KeyHandle As Long
Dim Ret As Long

'Open HTTPD Key
Ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\HTTPD", 0, KEY_ALL_ACCESS, KeyHandle)
If Ret <> ERROR_SUCCESS Then
    Debug.Print "Error opening HTTPD key"
    Exit Sub
End If

'Save Values
RegSetStringValue KeyHandle, "Port Number", PortNumStr
RegSetStringValue KeyHandle, "Initial Number of Threads", InitNumThreadsStr
RegSetStringValue KeyHandle, "Maximum Number of Threads", MaxNumThreadsStr
RegSetStringValue KeyHandle, "Number of Threads to Keep Free", NumThreadsKeepFreeStr
RegSetStringValue KeyHandle, "Thread Compact Period", ThreadCompactPeriodStr
RegSetStringValue KeyHandle, "Thread Compact Laziness", ThreadCompactLazinessStr

RegSetStringValue KeyHandle, "Index File Name", IndexFileNameStr
RegSetStringValue KeyHandle, "Error Message Path", ErrorMsgPathStr
RegSetStringValue KeyHandle, "Temp Directory", TempPathStr

Dim ScriptDNSStr As String
If ScriptDNSBool Then ScriptDNSStr = "1" Else ScriptDNSStr = "0"
RegSetStringValue KeyHandle, "DNS Lookups for Scripts", ScriptDNSStr

'Close HTTPD Key
Ret = RegCloseKey(KeyHandle)
End Sub



Sub SaveGroupConfig()
Dim i As Integer
Dim j As Integer
Dim Ret As Long
Dim Disposition As Long
Dim GroupsKeyHandle As Long
Dim NumGroupsStr As String

'Nuke Old Key
RegNukeKey HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Groups"

'Open/Create the Groups Key
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Groups", 0, "", _
    REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, GroupsKeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating Users key"

'Set Number of Groups
NumGroupsStr = Format(NumGroups)

RegSetStringValue GroupsKeyHandle, "Number of Groups", NumGroupsStr

For i = 1 To NumGroups
    Dim GroupKeyHandle As Long
    Dim MembersKeyHandle As Long
    Dim MemberKeyHandle As Long
    Dim NumMembersStr As String
        
    'Create the Key
    Ret = RegCreateKeyEx(GroupsKeyHandle, Groups(i).NameStr, 0, "", _
        REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, GroupKeyHandle, Disposition)
    If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating User key"

    'Set the Number of Members
    NumMembersStr = Format(Groups(i).NumMembers)
    RegSetStringValue GroupKeyHandle, "Number of Members", NumMembersStr

    'Create/Open the Members Key
    Ret = RegCreateKeyEx(GroupKeyHandle, "Members", 0, "", _
        REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, MembersKeyHandle, Disposition)
    If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating Group key"
            
    'Set the Members
    For j = 1 To Groups(i).NumMembers
        Ret = RegCreateKeyEx(MembersKeyHandle, Groups(i).Members(j), 0, "", _
            REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, MemberKeyHandle, Disposition)
        If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating Member key"
        Ret = RegCloseKey(MemberKeyHandle)
    Next j
            
    'Close Members Key
    Ret = RegCloseKey(MembersKeyHandle)

    'Close Group Key
    Ret = RegCloseKey(GroupKeyHandle)
Next i
'Close the Groups Key
Ret = RegCloseKey(GroupsKeyHandle)
End Sub


Sub SaveLogConfig()
Dim KeyHandle As Long
Dim Ret As Long

'Open Log Key
Ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Logs", 0, KEY_ALL_ACCESS, KeyHandle)
If Ret <> ERROR_SUCCESS Then
    Debug.Print "Error opening Log key"
    Exit Sub
End If

'Save log path
RegSetStringValue KeyHandle, "Log Path", LogPathStr

'-------------------Common Log Config-------------------
Dim CommonKeyHandle As Long
Dim ComLogEnabledStr As String
Dim ComLogConvertIPStr As String

'Open the HTTPD Common Key
Ret = RegOpenKeyEx(KeyHandle, "HTTPD Common", 0, KEY_ALL_ACCESS, CommonKeyHandle)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating HTTPD Common key"

'Set Enabled
If ComLogEnabledBool Then ComLogEnabledStr = "1" Else ComLogEnabledStr = "0"
RegSetStringValue CommonKeyHandle, "Enabled", ComLogEnabledStr

'Set File Name
RegSetStringValue CommonKeyHandle, "File Name", ComLogNameStr

'Set ConvertIP
If ComLogConvertIPBool Then ComLogConvertIPStr = "1" Else ComLogConvertIPStr = "0"
RegSetStringValue CommonKeyHandle, "Convert IP", ComLogConvertIPStr

'Close the HTTPD Common Key
Ret = RegCloseKey(CommonKeyHandle)

'-------------------Count Log Config-------------------
Dim CountKeyHandle As Long
Dim CntLogEnabledStr As String
Dim CntLogCountFilesStr As String
Dim CntLogCountConnectsStr As String
Dim CntLogCountKBytesStr As String

'Open/Create the HTTPD Count Key
Ret = RegOpenKeyEx(KeyHandle, "HTTPD Count", 0, KEY_ALL_ACCESS, CountKeyHandle)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating HTTPD Count key"

'Set Enabled
If CntLogEnabledBool Then CntLogEnabledStr = "1" Else CntLogEnabledStr = "0"
RegSetStringValue CountKeyHandle, "Enabled", CntLogEnabledStr

'Set File Name
RegSetStringValue CountKeyHandle, "File Name", CntLogNameStr

'Set Count Files
If CntLogCountFilesBool Then CntLogCountFilesStr = "1" Else CntLogCountFilesStr = "0"
RegSetStringValue CountKeyHandle, "Count Files", CntLogCountFilesStr

'Set Count Connects
If CntLogCountConnectsBool Then CntLogCountConnectsStr = "1" Else CntLogCountConnectsStr = "0"
RegSetStringValue CountKeyHandle, "Count Connects", CntLogCountConnectsStr

'Set Count KBytes
If CntLogCountKBytesBool Then CntLogCountKBytesStr = "1" Else CntLogCountKBytesStr = "0"
RegSetStringValue CountKeyHandle, "Count KBytes", CntLogCountKBytesStr

'Close the HTTPD Count Key
Ret = RegCloseKey(CountKeyHandle)
        
'-------------------Reference Log Config-------------------
Dim RefKeyHandle As Long
Dim RefLogEnabledStr As String

'Open the HTTPD Reference Key
Ret = RegOpenKeyEx(KeyHandle, "HTTPD Reference", 0, KEY_ALL_ACCESS, RefKeyHandle)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating HTTPD Reference key"

'Set Enabled
If RefLogEnabledBool Then RefLogEnabledStr = "1" Else RefLogEnabledStr = "0"
RegSetStringValue RefKeyHandle, "Enabled", RefLogEnabledStr

'Set File Name
RegSetStringValue RefKeyHandle, "File Name", RefLogNameStr

'Close the HTTPD Reference Key
Ret = RegCloseKey(RefKeyHandle)

'Close Log Key
Ret = RegCloseKey(KeyHandle)
End Sub



Sub SaveMIMEConfig()
Dim i As Integer
Dim Ret As Long
Dim Disposition As Long
Dim MIMEKeyHandle As Long
Dim ExtKeyHandle As Long
Dim NumMIMETypesStr As String
    
'Nuke existing MIME data
RegNukeKey HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\MIME"
        
'Add the MIME types in memory

'Open/ReCreate the MIME Key
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\MIME", 0, "", _
    REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, MIMEKeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating MIME key"

'Set Number of Types
NumMIMETypesStr = Format(NumMIMETypes)

RegSetStringValue MIMEKeyHandle, "Number of Types", NumMIMETypesStr

For i = 1 To NumMIMETypes
    'Create the Key
    Ret = RegCreateKeyEx(MIMEKeyHandle, MIMETypes(i).FileExtStr, 0, "", _
        REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, ExtKeyHandle, Disposition)
    If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating extention key"

    'Set the description value
    RegSetStringValue ExtKeyHandle, "MIME Description", MIMETypes(i).DescriptionStr

    'Close Extention Key
    Ret = RegCloseKey(ExtKeyHandle)
Next i

'Close the MIME Key
Ret = RegCloseKey(MIMEKeyHandle)

End Sub
Sub SavePathConfig()
Dim i As Integer
Dim Ret As Long
Dim Disposition As Long
Dim DirMapKeyHandle As Long
Dim DirKeyHandle As Long
Dim NumMappingsStr As String
Dim BoolStr As String
        
'Nuke Old Key
RegNukeKey HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Directory Mappings"

'ReCreate the DirMap Key
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Directory Mappings", 0, "", _
    REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, DirMapKeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then
    Debug.Print "Error creating Directory Mappings key"
    Exit Sub
End If

'Set Number of Mappings
NumMappingsStr = Format(NumMappings)

RegSetStringValue DirMapKeyHandle, "Number of Directories", NumMappingsStr

For i = 1 To NumMappings
    'Create the Key
    Ret = RegCreateKeyEx(DirMapKeyHandle, DirMappings(i).RemotePathStr, 0, "", _
        REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, _
        DirKeyHandle, Disposition)
    If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating Remote Path key"

    'Set the Local Dir value
    RegSetStringValue DirKeyHandle, "Local Directory", DirMappings(i).LocalPathStr

    'Set Authorized User
    RegSetStringValue DirKeyHandle, "Authorized User", DirMappings(i).AuthUserStr

    'Set Allow Directory List
    If DirMappings(i).AllowDirListBool = True Then BoolStr = "1" Else BoolStr = "0"
    RegSetStringValue DirKeyHandle, "Allow Directory Listings", BoolStr
    
    'Set Scripting
    RegSetStringValue DirKeyHandle, "Scripting", DirMappings(i).ScriptingStr

    'Set Authorized Location
    RegSetStringValue DirKeyHandle, "Authorized Location", DirMappings(i).AuthLocStr

    'Close Dir Key
    Ret = RegCloseKey(DirKeyHandle)
Next i

'Close the Dir Map Key
Ret = RegCloseKey(DirMapKeyHandle)

End Sub


Sub SaveServerConfig()
Dim KeyHandle As Long
Dim Ret As Long

'Open Fnord Key
Ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server", 0, KEY_ALL_ACCESS, KeyHandle)
If Ret <> ERROR_SUCCESS Then
    Debug.Print "Error opening Fnord key"
    Exit Sub
End If

'Save Values
RegSetStringValue KeyHandle, "Server Address", ServerAddressStr

'Close Fnord Key
Ret = RegCloseKey(KeyHandle)
End Sub

Sub SaveUserConfig()
Dim i As Integer
Dim Ret As Long
Dim Disposition As Long
Dim UsersKeyHandle As Long
Dim NumUsersStr As String
        
'Nuke Old Key
RegNukeKey HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Users"

'Open/Create the Users Key
Ret = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\Brian Morin\Fnord Server\Users", 0, "", _
    REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, UsersKeyHandle, Disposition)
If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating Users key"

'Set Number of Users
NumUsersStr = Format(NumUsers)

RegSetStringValue UsersKeyHandle, "Number of Users", NumUsersStr

For i = 1 To NumUsers
    Dim UserKeyHandle As Long
        
    'Create the Key
    Ret = RegCreateKeyEx(UsersKeyHandle, Users(i).NameStr, 0, "", _
        REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, _
        UserKeyHandle, Disposition)
    If Ret <> ERROR_SUCCESS Then Debug.Print "Error creating User key"

    'Set the Password value
    RegSetStringValue UserKeyHandle, "Password", Users(i).PasswordStr

    'Close User Key
    Ret = RegCloseKey(UserKeyHandle)
Next i

'Close the Users Key
Ret = RegCloseKey(UsersKeyHandle)
End Sub



Sub SendReloadMessage()
If ServerWindowHnd <> 0 Then
    'Look for it again, just to be sure
    ServerWindowHnd = FindWindow("Fnord Status", 0)
End If
If ServerWindowHnd <> 0 Then
    SendMessage ServerWindowHnd, ServerReloadMsg, 0, 0
End If
End Sub


