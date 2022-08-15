VERSION 4.00
Begin VB.Form MainForm 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Fnord! Server Control"
   ClientHeight    =   4980
   ClientLeft      =   1275
   ClientTop       =   2145
   ClientWidth     =   6495
   Height          =   5385
   Icon            =   "Main.frx":0000
   Left            =   1215
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4980
   ScaleWidth      =   6495
   Top             =   1800
   Width           =   6615
   Begin VB.CommandButton OkButton 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   2880
      TabIndex        =   0
      Top             =   4560
      Width           =   1095
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4080
      TabIndex        =   1
      Top             =   4560
      Width           =   1095
   End
   Begin VB.CommandButton ApplyButton 
      Caption         =   "&Apply"
      Enabled         =   0   'False
      Height          =   375
      Left            =   5280
      TabIndex        =   2
      Top             =   4560
      Width           =   1095
   End
   Begin VB.PictureBox MainBoxes 
      BorderStyle     =   0  'None
      Height          =   3735
      Index           =   0
      Left            =   240
      ScaleHeight     =   3735
      ScaleWidth      =   6015
      TabIndex        =   4
      Top             =   600
      Width           =   6015
      Begin VB.CheckBox ScriptDNSCheck 
         Caption         =   "DNS Lookups for Scripts"
         Height          =   255
         Left            =   3360
         TabIndex        =   75
         Top             =   2880
         Value           =   1  'Checked
         Width           =   2055
      End
      Begin VB.Frame Frame6 
         Caption         =   "Thread Management"
         Height          =   1335
         Left            =   120
         TabIndex        =   63
         Top             =   840
         Width           =   5775
         Begin VB.TextBox NumThreadsKeepFreeText 
            Height          =   285
            Left            =   5040
            TabIndex        =   74
            Text            =   "2"
            Top             =   360
            Width           =   495
         End
         Begin VB.TextBox ThreadCompactLazinessText 
            Height          =   285
            Left            =   5040
            TabIndex        =   69
            Text            =   "2"
            Top             =   840
            Width           =   495
         End
         Begin VB.TextBox ThreadCompactPeriodText 
            Height          =   285
            Left            =   1560
            TabIndex        =   68
            Text            =   "300"
            Top             =   840
            Width           =   855
         End
         Begin VB.TextBox MaxNumThreadsText 
            Height          =   285
            Left            =   3240
            TabIndex        =   67
            Text            =   "10"
            Top             =   360
            Width           =   495
         End
         Begin VB.TextBox InitNumThreadsText 
            Height          =   285
            Left            =   1560
            MaxLength       =   4
            TabIndex        =   64
            Text            =   "2"
            Top             =   360
            Width           =   495
         End
         Begin VB.Label Label23 
            AutoSize        =   -1  'True
            Caption         =   "Keep Free:"
            Height          =   195
            Left            =   4080
            TabIndex        =   73
            Top             =   360
            Width           =   780
         End
         Begin VB.Label Label22 
            AutoSize        =   -1  'True
            Caption         =   "sec"
            Height          =   195
            Left            =   2520
            TabIndex        =   72
            Top             =   840
            Width           =   255
         End
         Begin VB.Label Label21 
            AutoSize        =   -1  'True
            Caption         =   "Compact Laziness:"
            Height          =   195
            Left            =   3600
            TabIndex        =   71
            Top             =   840
            Width           =   1335
         End
         Begin VB.Label Label20 
            AutoSize        =   -1  'True
            Caption         =   "Compact Period:"
            Height          =   195
            Left            =   120
            TabIndex        =   70
            Top             =   840
            Width           =   1170
         End
         Begin VB.Label Label19 
            AutoSize        =   -1  'True
            Caption         =   "Maximum:"
            Height          =   195
            Left            =   2400
            TabIndex        =   66
            Top             =   360
            Width           =   705
         End
         Begin VB.Label Label2 
            AutoSize        =   -1  'True
            Caption         =   "Initial Number:"
            Height          =   195
            Left            =   120
            TabIndex        =   65
            Top             =   360
            Width           =   1005
         End
      End
      Begin VB.TextBox TempPathText 
         Height          =   285
         Left            =   1680
         TabIndex        =   9
         Text            =   "c:\fnord\temp"
         Top             =   3360
         Width           =   3615
      End
      Begin VB.TextBox ErrorMsgPathText 
         Height          =   285
         Left            =   1680
         TabIndex        =   8
         Text            =   "c:\fnord\error"
         Top             =   2400
         Width           =   3615
      End
      Begin VB.TextBox IndexFileNameText 
         Height          =   285
         Left            =   1680
         TabIndex        =   7
         Text            =   "index.html"
         Top             =   2880
         Width           =   1455
      End
      Begin VB.TextBox PortNumText 
         Height          =   285
         Left            =   5160
         MaxLength       =   4
         TabIndex        =   6
         Text            =   "80"
         Top             =   240
         Width           =   495
      End
      Begin VB.TextBox ServerAddressText 
         Height          =   285
         Left            =   1680
         TabIndex        =   5
         Top             =   240
         Width           =   2775
      End
      Begin VB.Label Label7 
         AutoSize        =   -1  'True
         Caption         =   "Leave blank to auto detect"
         Height          =   195
         Left            =   1800
         TabIndex        =   47
         Top             =   600
         Width           =   1920
      End
      Begin VB.Label Label6 
         AutoSize        =   -1  'True
         Caption         =   "Server Address:"
         Height          =   195
         Left            =   120
         TabIndex        =   46
         Top             =   240
         Width           =   1125
      End
      Begin VB.Label Label5 
         AutoSize        =   -1  'True
         Caption         =   "Index File Name:"
         Height          =   195
         Left            =   120
         TabIndex        =   45
         Top             =   2880
         Width           =   1185
      End
      Begin VB.Label Label4 
         AutoSize        =   -1  'True
         Caption         =   "Script Temp Path:"
         Height          =   195
         Left            =   120
         TabIndex        =   44
         Top             =   3360
         Width           =   1275
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "Error Message Path:"
         Height          =   195
         Left            =   120
         TabIndex        =   43
         Top             =   2400
         Width           =   1440
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         Caption         =   "Port:"
         Height          =   195
         Left            =   4680
         TabIndex        =   42
         Top             =   240
         Width           =   330
      End
   End
   Begin VB.PictureBox MainBoxes 
      BorderStyle     =   0  'None
      Height          =   3735
      Index           =   5
      Left            =   240
      ScaleHeight     =   3735
      ScaleWidth      =   6015
      TabIndex        =   41
      Top             =   600
      Width           =   6015
      Begin VB.Label Label13 
         Alignment       =   2  'Center
         Caption         =   "The author can be reached via email at bmorin@wpi.edu"
         Height          =   195
         Left            =   0
         TabIndex        =   53
         Top             =   3120
         Width           =   6015
      End
      Begin VB.Label Label12 
         Alignment       =   2  'Center
         Caption         =   "For details see http://www.wpi.edu/~bmorin/fnord/ or email the author"
         Height          =   195
         Left            =   0
         TabIndex        =   52
         Top             =   2880
         Width           =   6015
      End
      Begin VB.Label Label11 
         Alignment       =   2  'Center
         Caption         =   "Fnord! Server is released under the GNU GENERAL PUBLIC LICENSE"
         Height          =   195
         Left            =   0
         TabIndex        =   51
         Top             =   2400
         Width           =   6015
      End
      Begin VB.Label Label10 
         Alignment       =   2  'Center
         Caption         =   "Fnord! Server comes with ABSOLUTELY NO WARRANTY"
         Height          =   195
         Left            =   0
         TabIndex        =   50
         Top             =   2640
         Width           =   6015
      End
      Begin VB.Image Image1 
         Height          =   960
         Left            =   2400
         Picture         =   "Main.frx":0442
         Stretch         =   -1  'True
         Top             =   840
         Width           =   960
      End
      Begin VB.Label Label9 
         Alignment       =   2  'Center
         Caption         =   "Version 0.9.9.23, Copyright (C) 1996 Brian R. Morin"
         Height          =   195
         Left            =   0
         TabIndex        =   49
         Top             =   2160
         Width           =   6015
      End
      Begin VB.Label Label8 
         Alignment       =   2  'Center
         Caption         =   "Fnord! Server Control"
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   24
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   540
         Left            =   0
         TabIndex        =   48
         Top             =   120
         Width           =   6030
      End
   End
   Begin VB.PictureBox MainBoxes 
      BorderStyle     =   0  'None
      Height          =   3735
      Index           =   4
      Left            =   240
      ScaleHeight     =   3735
      ScaleWidth      =   6015
      TabIndex        =   40
      Top             =   600
      Width           =   6015
      Begin VB.CommandButton RemoveMIMETypeButton 
         Caption         =   "&Remove"
         Height          =   375
         Left            =   4680
         TabIndex        =   35
         Top             =   720
         Width           =   1215
      End
      Begin VB.CommandButton NewMIMETypeButton 
         Caption         =   "&New Type..."
         Height          =   375
         Left            =   4680
         TabIndex        =   34
         Top             =   240
         Width           =   1215
      End
      Begin VB.CommandButton EditMIMETypeButton 
         Caption         =   "&Edit..."
         Height          =   375
         Left            =   4680
         TabIndex        =   36
         Top             =   1200
         Width           =   1215
      End
      Begin ComctlLib.ListView MIMEListView 
         Height          =   3375
         Left            =   120
         TabIndex        =   33
         Top             =   240
         Width           =   4335
         _Version        =   65536
         _ExtentX        =   7646
         _ExtentY        =   5953
         _StockProps     =   205
         ForeColor       =   -2147483640
         BackColor       =   -2147483643
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Appearance      =   1
         BorderStyle     =   1
         HideSelection   =   0   'False
         Icons           =   ""
         LabelEdit       =   1
         MouseIcon       =   "Main.frx":074C
         SmallIcons      =   ""
         Sorted          =   -1  'True
         View            =   3
         NumItems        =   2
         i1              =   "Main.frx":08A6
         i2              =   "Main.frx":097C
      End
   End
   Begin VB.PictureBox MainBoxes 
      BorderStyle     =   0  'None
      Height          =   3735
      Index           =   3
      Left            =   240
      ScaleHeight     =   3735
      ScaleWidth      =   6015
      TabIndex        =   38
      Top             =   600
      Width           =   6015
      Begin VB.Frame Frame5 
         Caption         =   "Groups"
         Height          =   3495
         Left            =   3120
         TabIndex        =   59
         Top             =   240
         Width           =   2895
         Begin VB.CommandButton EditGroupButton 
            Caption         =   "Edit..."
            Height          =   375
            Left            =   1680
            TabIndex        =   32
            Top             =   1200
            Width           =   1095
         End
         Begin VB.CommandButton RemoveGroupButton 
            Caption         =   "Remove"
            Height          =   375
            Left            =   1680
            TabIndex        =   31
            Top             =   720
            Width           =   1095
         End
         Begin VB.CommandButton NewGroupButton 
            Caption         =   "New Group..."
            Height          =   375
            Left            =   1680
            TabIndex        =   30
            Top             =   240
            Width           =   1095
         End
         Begin VB.ListBox GroupList 
            Height          =   2985
            Left            =   120
            TabIndex        =   29
            Top             =   240
            Width           =   1455
         End
      End
      Begin VB.Frame Frame4 
         Caption         =   "Users"
         Height          =   3495
         Left            =   0
         TabIndex        =   58
         Top             =   240
         Width           =   2895
         Begin VB.ListBox UserList 
            Height          =   2985
            Left            =   120
            TabIndex        =   25
            Top             =   240
            Width           =   1455
         End
         Begin VB.CommandButton NewUserButton 
            Caption         =   "New User..."
            Height          =   375
            Left            =   1680
            TabIndex        =   26
            Top             =   240
            Width           =   1095
         End
         Begin VB.CommandButton EditUserButton 
            Caption         =   "Edit..."
            Height          =   375
            Left            =   1680
            TabIndex        =   28
            Top             =   1200
            Width           =   1095
         End
         Begin VB.CommandButton RemoveUserButton 
            Caption         =   "Remove"
            Height          =   375
            Left            =   1680
            TabIndex        =   27
            Top             =   720
            Width           =   1095
         End
      End
   End
   Begin VB.PictureBox MainBoxes 
      BorderStyle     =   0  'None
      Height          =   3735
      Index           =   2
      Left            =   240
      ScaleHeight     =   3735
      ScaleWidth      =   6015
      TabIndex        =   39
      Top             =   600
      Width           =   6015
      Begin VB.CommandButton EditPathButton 
         Caption         =   "&Edit..."
         Height          =   375
         Left            =   4800
         TabIndex        =   24
         Top             =   3360
         Width           =   1095
      End
      Begin VB.CommandButton NewPathButton 
         Caption         =   "&New Path..."
         Height          =   375
         Left            =   2400
         TabIndex        =   22
         Top             =   3360
         Width           =   1095
      End
      Begin VB.CommandButton RemovePathButton 
         Caption         =   "&Remove"
         Height          =   375
         Left            =   3600
         TabIndex        =   23
         Top             =   3360
         Width           =   1095
      End
      Begin ComctlLib.ListView PathListView 
         Height          =   3015
         Left            =   120
         TabIndex        =   21
         Top             =   240
         Width           =   5775
         _Version        =   65536
         _ExtentX        =   10186
         _ExtentY        =   5318
         _StockProps     =   205
         ForeColor       =   -2147483640
         BackColor       =   -2147483643
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Appearance      =   1
         BorderStyle     =   1
         HideSelection   =   0   'False
         Icons           =   ""
         LabelEdit       =   1
         SmallIcons      =   ""
         Sorted          =   -1  'True
         View            =   3
         NumItems        =   6
         i1              =   "Main.frx":0A52
         i2              =   "Main.frx":0B20
         i3              =   "Main.frx":0BEE
         i4              =   "Main.frx":0CBC
         i5              =   "Main.frx":0D82
         i6              =   "Main.frx":0E50
      End
   End
   Begin VB.PictureBox MainBoxes 
      BorderStyle     =   0  'None
      Height          =   3735
      Index           =   1
      Left            =   240
      ScaleHeight     =   3735
      ScaleWidth      =   6015
      TabIndex        =   37
      Top             =   600
      Width           =   6015
      Begin VB.Frame Frame3 
         Caption         =   "Reference Log"
         Height          =   615
         Left            =   0
         TabIndex        =   57
         Top             =   3120
         Width           =   6015
         Begin VB.TextBox RefLogNameText 
            Height          =   285
            Left            =   3720
            TabIndex        =   20
            Text            =   "ref.txt"
            Top             =   240
            Width           =   2055
         End
         Begin VB.CheckBox RefLogEnabledCheck 
            Caption         =   "Enabled"
            Height          =   255
            Left            =   120
            TabIndex        =   19
            Top             =   240
            Width           =   975
         End
         Begin VB.Label Label17 
            AutoSize        =   -1  'True
            Caption         =   "File Name:"
            Height          =   195
            Left            =   2880
            TabIndex        =   62
            Top             =   240
            Width           =   750
         End
      End
      Begin VB.Frame Frame2 
         Caption         =   "Count Log"
         Height          =   1335
         Left            =   0
         TabIndex        =   56
         Top             =   1680
         Width           =   6015
         Begin VB.TextBox CntLogNameText 
            Height          =   285
            Left            =   3720
            TabIndex        =   15
            Text            =   "count.txt"
            Top             =   240
            Width           =   2055
         End
         Begin VB.CheckBox CntLogCountKBytesCheck 
            Caption         =   "Count Total KBytes Sent"
            Height          =   255
            Left            =   120
            TabIndex        =   18
            Top             =   960
            Width           =   2535
         End
         Begin VB.CheckBox CntLogCountFilesCheck 
            Caption         =   "Count Total Files Sent"
            Height          =   255
            Left            =   2880
            TabIndex        =   17
            Top             =   600
            Width           =   2535
         End
         Begin VB.CheckBox CntLogCountConnectsCheck 
            Caption         =   "Count Total Connections"
            Height          =   255
            Left            =   120
            TabIndex        =   16
            Top             =   600
            Width           =   2535
         End
         Begin VB.CheckBox CntLogEnabledCheck 
            Caption         =   "Enabled"
            Height          =   255
            Left            =   120
            TabIndex        =   14
            Top             =   240
            Width           =   1335
         End
         Begin VB.Label Label16 
            AutoSize        =   -1  'True
            Caption         =   "File Name:"
            Height          =   195
            Left            =   2880
            TabIndex        =   61
            Top             =   240
            Width           =   750
         End
      End
      Begin VB.Frame Frame1 
         Caption         =   "Common Log"
         Height          =   975
         Left            =   0
         TabIndex        =   55
         Top             =   600
         Width           =   6015
         Begin VB.TextBox ComLogNameText 
            Height          =   285
            Left            =   3720
            TabIndex        =   12
            Text            =   "access.txt"
            Top             =   240
            Width           =   2055
         End
         Begin VB.CheckBox ComLogConvertIPCheck 
            Caption         =   "Convert IP Numbers to DNS Names"
            Height          =   255
            Left            =   120
            TabIndex        =   13
            Top             =   600
            Width           =   2895
         End
         Begin VB.CheckBox ComLogEnabledCheck 
            Caption         =   "Enabled"
            Height          =   255
            Left            =   120
            TabIndex        =   11
            Top             =   240
            Width           =   1095
         End
         Begin VB.Label Label15 
            AutoSize        =   -1  'True
            Caption         =   "File Name:"
            Height          =   195
            Left            =   2880
            TabIndex        =   60
            Top             =   240
            Width           =   750
         End
      End
      Begin VB.TextBox LogPathText 
         Height          =   285
         Left            =   960
         TabIndex        =   10
         Text            =   "c:\fnord\logs"
         Top             =   240
         Width           =   3615
      End
      Begin VB.Label Label14 
         AutoSize        =   -1  'True
         Caption         =   "Log Path:"
         Height          =   195
         Left            =   120
         TabIndex        =   54
         Top             =   240
         Width           =   690
      End
   End
   Begin ComctlLib.TabStrip MainTabStrip 
      Height          =   4335
      Left            =   120
      TabIndex        =   3
      Top             =   120
      Width           =   6255
      _Version        =   65536
      _ExtentX        =   11033
      _ExtentY        =   7646
      _StockProps     =   68
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ImageList       =   ""
      NumTabs         =   6
      i1              =   "Main.frx":0F1A
      i2              =   "Main.frx":106D
      i3              =   "Main.frx":11C4
      i4              =   "Main.frx":1313
      i5              =   "Main.frx":1466
      i6              =   "Main.frx":15B1
   End
End
Attribute VB_Name = "MainForm"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
DefInt A-Z
Option Explicit

'Dirty Flags
Public ConfigDirty As Boolean
Public ServerConfigDirty As Boolean
Public GeneralConfigDirty As Boolean
Public LogConfigDirty As Boolean
Public PathConfigDirty As Boolean
Public UserConfigDirty As Boolean
Public GroupConfigDirty As Boolean
Public MIMEConfigDirty As Boolean

'Number of subforms
Public NumSubForms As Integer




Sub InitAllControls()
InitServerControls
InitGeneralControls
InitLogControls
InitPathControls
InitUserControls
InitGroupControls
InitMIMEControls
End Sub

Sub InitGeneralControls()

PortNumText.Text = Config.PortNumStr

InitNumThreadsText.Text = Config.InitNumThreadsStr
MaxNumThreadsText.Text = Config.MaxNumThreadsStr
NumThreadsKeepFreeText.Text = Config.NumThreadsKeepFreeStr
ThreadCompactPeriodText.Text = Config.ThreadCompactPeriodStr
ThreadCompactLazinessText.Text = Config.ThreadCompactLazinessStr

IndexFileNameText.Text = IndexFileNameStr
ErrorMsgPathText.Text = ErrorMsgPathStr
TempPathText.Text = TempPathStr

If Config.ScriptDNSBool Then
    ScriptDNSCheck.Value = 1
Else
    ScriptDNSCheck.Value = 0
End If

End Sub



Sub InitGroupControls()
Dim i As Integer

GroupList.Clear
For i = 1 To Config.NumGroups
    GroupList.AddItem Config.Groups(i).NameStr
Next i
End Sub


Sub InitLogControls()
LogPathText.Text = Config.LogPathStr

'Common Log
If Config.ComLogEnabledBool Then
    ComLogEnabledCheck.Value = 1
    ComLogConvertIPCheck.Enabled = True
Else
    ComLogEnabledCheck.Value = 0
    ComLogConvertIPCheck.Enabled = False
End If

ComLogNameText = Config.ComLogNameStr

If Config.ComLogConvertIPBool Then
    ComLogConvertIPCheck.Value = 1
Else
    ComLogConvertIPCheck.Value = 0
End If


'Count Log
If Config.CntLogEnabledBool Then
    CntLogEnabledCheck.Value = 1
    CntLogCountFilesCheck.Enabled = True
    CntLogCountConnectsCheck.Enabled = True
    CntLogCountKBytesCheck.Enabled = True
Else
    CntLogEnabledCheck.Value = 0
    CntLogCountFilesCheck.Enabled = False
    CntLogCountConnectsCheck.Enabled = False
    CntLogCountKBytesCheck.Enabled = False
End If

CntLogNameText = Config.CntLogNameStr

If Config.CntLogCountFilesBool Then
    CntLogCountFilesCheck.Value = 1
Else
    CntLogCountFilesCheck.Value = 0
End If

If Config.CntLogCountConnectsBool Then
    CntLogCountConnectsCheck.Value = 1
Else
    CntLogCountConnectsCheck.Value = 0
End If

If Config.CntLogCountKBytesBool Then
    CntLogCountKBytesCheck.Value = 1
Else
    CntLogCountKBytesCheck.Value = 0
End If

'Reference Log
If Config.RefLogEnabledBool Then
    RefLogEnabledCheck.Value = 1
Else
    RefLogEnabledCheck.Value = 0
End If

RefLogNameText = Config.RefLogNameStr
End Sub



Sub InitMIMEControls()
Dim MIMEItem As ListItem
Dim i As Integer

'Clear remaining entries
MIMEListView.ListItems.Clear

For i = 1 To Config.NumMIMETypes
    Set MIMEItem = MIMEListView.ListItems.Add()
    MIMEItem.Text = Config.MIMETypes(i).FileExtStr
    MIMEItem.SubItems(1) = Config.MIMETypes(i).DescriptionStr
Next i

'Fixed bug where user had to select HTML before getting to lower items
Set MIMEListView.SelectedItem = Nothing

MIMEListView.Sorted = True
End Sub

Sub InitPathControls()
Dim i As Integer
Dim PathItem As ListItem

'Clear remaining entries
PathListView.ListItems.Clear

For i = 1 To Config.NumMappings
    Set PathItem = PathListView.ListItems.Add()
    
    PathItem.Text = Config.DirMappings(i).RemotePathStr
    
    PathItem.SubItems(1) = Config.DirMappings(i).LocalPathStr
    
    If Config.DirMappings(i).ScriptingStr = "None" Then
        PathItem.SubItems(2) = "Normal"
    ElseIf Config.DirMappings(i).ScriptingStr = "Redirect" Then
        PathItem.SubItems(2) = "Redir"
    ElseIf Config.DirMappings(i).ScriptingStr = "WinCGI" Then
        PathItem.SubItems(2) = "WinCGI"
    ElseIf Config.DirMappings(i).ScriptingStr = "CGI" Then
        PathItem.SubItems(2) = "CGI"
    ElseIf Config.DirMappings(i).ScriptingStr = "ISAPI" Then
        PathItem.SubItems(2) = "ISAPI"
    Else
        PathItem.SubItems(2) = "Unknown"
    End If
    
    If Config.DirMappings(i).AllowDirListBool Then
        PathItem.SubItems(3) = "Yes"
    Else
        PathItem.SubItems(3) = "No"
    End If

    PathItem.SubItems(4) = Config.DirMappings(i).AuthUserStr
    
    If Config.DirMappings(i).AuthLocStr = "Class A Subnet" Then
        PathItem.SubItems(5) = "A"
    ElseIf Config.DirMappings(i).AuthLocStr = "Class B Subnet" Then
        PathItem.SubItems(5) = "B"
    ElseIf Config.DirMappings(i).AuthLocStr = "Class C Subnet" Then
        PathItem.SubItems(5) = "C"
    ElseIf Config.DirMappings(i).AuthLocStr = "Class D Subnet" Then
        PathItem.SubItems(5) = "D"
    Else
        PathItem.SubItems(5) = "-"
    End If
Next i

'This fixed a selection problem with PathList where the first item had to
'be selected to be able to select other items
Set PathListView.SelectedItem = Nothing

PathListView.Sorted = True
End Sub



Sub InitServerControls()
ServerAddressText.Text = Config.ServerAddressStr
End Sub



Sub InitUserControls()
Dim i As Integer

UserList.Clear
For i = 1 To Config.NumUsers
    UserList.AddItem Config.Users(i).NameStr
Next i
End Sub


Sub SaveDirtyConfig()

'Save the modified parts
If ServerConfigDirty Then Config.SaveServerConfig
If GeneralConfigDirty Then Config.SaveGeneralConfig
If LogConfigDirty Then Config.SaveLogConfig
If PathConfigDirty Then Config.SavePathConfig
If UserConfigDirty Then Config.SaveUserConfig
If GroupConfigDirty Then Config.SaveGroupConfig
If MIMEConfigDirty Then Config.SaveMIMEConfig

'Send the reload message if we saved anything
If ConfigDirty Then Config.SendReloadMessage

'Set all parts as not modified
ConfigDirty = False
ServerConfigDirty = False
GeneralConfigDirty = False
LogConfigDirty = False
UserConfigDirty = False
GroupConfigDirty = False
MIMEConfigDirty = False
ApplyButton.Enabled = False
End Sub

Private Sub ApplyButton_Click()
SaveDirtyConfig
End Sub

Private Sub CancelButton_Click()
Dim Answer As Integer

'Check for unresolved forms
If NumSubForms <> 0 Then
    Answer = MsgBox("There are still are open subwindows, are you sure you want to exit?", _
        vbYesNo, "Fnord! Server Control")
    If Answer = vbNo Then Exit Sub
End If

If ConfigDirty Then
    Answer = MsgBox("Do you want to exit without saving changes?", vbYesNoCancel, _
        "Fnord! Server Control")
    If Answer = vbYes Then
        End
    ElseIf Answer = vbNo Then
        SaveDirtyConfig
        End
    'ElseIf Answer = vbCancel Then Continue
    End If
Else
    End
End If
End Sub



Private Sub CntLogCountConnectsCheck_Click()
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

If CntLogCountConnectsCheck.Value = 1 Then
    Config.CntLogCountConnectsBool = True
Else
    Config.CntLogCountConnectsBool = False
End If
End Sub

Private Sub CntLogCountFilesCheck_Click()
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

If CntLogCountFilesCheck.Value = 1 Then
    Config.CntLogCountFilesBool = True
Else
    Config.CntLogCountFilesBool = False
End If
End Sub

Private Sub CntLogCountKBytesCheck_Click()
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

If CntLogCountKBytesCheck.Value = 1 Then
    Config.CntLogCountKBytesBool = True
Else
    Config.CntLogCountKBytesBool = False
End If
End Sub

Private Sub CntLogEnabledCheck_Click()
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

If CntLogEnabledCheck.Value = 1 Then
    Config.CntLogEnabledBool = True
    CntLogCountConnectsCheck.Enabled = True
    CntLogCountFilesCheck.Enabled = True
    CntLogCountKBytesCheck.Enabled = True
    CntLogNameText.Enabled = True
Else
    Config.CntLogEnabledBool = False
    CntLogCountConnectsCheck.Enabled = False
    CntLogCountFilesCheck.Enabled = False
    CntLogCountKBytesCheck.Enabled = False
    CntLogNameText.Enabled = False
End If
End Sub

Private Sub CntLogNameText_Change()
'Set Server section as modified
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.CntLogNameStr = CntLogNameText.Text
End Sub

Private Sub ComLogConvertIPCheck_Click()
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

If ComLogConvertIPCheck.Value = 1 Then
    Config.ComLogConvertIPBool = True
Else
    Config.ComLogConvertIPBool = False
End If
End Sub

Private Sub ComLogEnabledCheck_Click()
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

If ComLogEnabledCheck.Value = 1 Then
    Config.ComLogEnabledBool = True
    ComLogConvertIPCheck.Enabled = True
    ComLogNameText.Enabled = True
Else
    Config.ComLogEnabledBool = False
    ComLogConvertIPCheck.Enabled = False
    ComLogNameText.Enabled = False
End If
End Sub





Private Sub ComLogNameText_Change()
'Set Server section as modified
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.ComLogNameStr = ComLogNameText.Text
End Sub

Private Sub EditGroupButton_Click()
'Make sure a group is selected
If GroupList.ListIndex = -1 Then
    MsgBox "Select a group first", vbOKOnly, "Fnord! Server Control"
    Exit Sub
End If

Dim NewGroup As New GroupForm
Dim i As Integer
Dim j As Integer
Dim k As Integer
Dim Member As Boolean

'Load new form
Load NewGroup

'Set vars
NewGroup.TargetGroupStr = GroupList.List(GroupList.ListIndex)

'Find the matching config entry
i = 1
While (LCase(Config.Groups(i).NameStr) <> LCase(GroupList.List(GroupList.ListIndex)))
    i = i + 1
Wend

'Set Controls
NewGroup.NameText.Text = GroupList.List(GroupList.ListIndex)
NewGroup.MemberList.Clear
NewGroup.NonMemberList.Clear

'Add everyone to the right list list
For j = 1 To Config.NumUsers
    'Are they a member?
    k = 1
    Member = False
    While (k <= Config.Groups(i).NumMembers) And (Not Member)
        If LCase(Config.Groups(i).Members(k)) = LCase(Config.Users(j).NameStr) Then
            Member = True
        End If
        k = k + 1
    Wend
    'Yes, add them to the members
    If Member Then
        NewGroup.MemberList.AddItem Users(j).NameStr
    'No, add them to the non-members
    Else
        NewGroup.NonMemberList.AddItem Users(j).NameStr
    End If
Next j

'Show it!
NewGroup.Show

End Sub


Private Sub EditMIMETypeButton_Click()

If Not (MIMEListView.SelectedItem Is Nothing) Then

    Dim NewMIME As New MIMEForm

    'Load new form
    Load NewMIME

    'Set vars
    NewMIME.TargetFileExtStr = MIMEListView.SelectedItem.Text

    'Set Controls
    NewMIME.FileExtentionText.Text = MIMEListView.SelectedItem.Text
    NewMIME.MIMEDescText.Text = MIMEListView.SelectedItem.SubItems(1)

    'Show it!
    NewMIME.Show
Else
    MsgBox "Select a MIME type first", vbOKOnly, "Fnord! Server Control"
End If

End Sub

Private Sub EditPathButton_Click()

If (PathListView.SelectedItem Is Nothing) Then
    MsgBox "Select a path mapping", vbOKOnly, "Fnord! Server Control"
    Exit Sub
End If

Dim NewPath As New PathForm
Dim i As Integer

'Load new form
Load NewPath

'Find the matching config entry
i = 1
While (UCase(DirMappings(i).RemotePathStr) <> _
    UCase(PathListView.SelectedItem.Text))
    i = i + 1
Wend

'Set vars
NewPath.TargetRemotePathStr = DirMappings(i).RemotePathStr

'Set Controls
NewPath.RemotePathText.Text = DirMappings(i).RemotePathStr

NewPath.LocalPathText.Text = DirMappings(i).LocalPathStr

If Config.DirMappings(i).ScriptingStr = "None" Then
    NewPath.TypeCombo.Text = "Normal"
ElseIf Config.DirMappings(i).ScriptingStr = "WinCGI" Then
    NewPath.TypeCombo.Text = "WinCGI"
ElseIf Config.DirMappings(i).ScriptingStr = "CGI" Then
    NewPath.TypeCombo.Text = "CGI"
ElseIf Config.DirMappings(i).ScriptingStr = "ISAPI" Then
    NewPath.TypeCombo.Text = "ISAPI"
Else
    NewPath.TypeCombo.Text = "Unknown"
End If
If DirMappings(i).AllowDirListBool Then
    NewPath.AllowDirListCheck.Value = 1
Else
    NewPath.AllowDirListCheck.Value = 0
End If

NewPath.AuthUserCombo.Text = DirMappings(i).AuthUserStr

If Config.DirMappings(i).AuthLocStr = "-" Then
    NewPath.AuthLocationCombo.Text = "Anywhere"
Else
    NewPath.AuthLocationCombo.Text = Config.DirMappings(i).AuthLocStr
End If

'Show it!
NewPath.Show
End Sub

Private Sub EditUserButton_Click()
Dim i As Integer

'Make sure a user is selected
If UserList.ListIndex = -1 Then
    MsgBox "Select a user first", vbOKOnly, "Fnord! Server Control"
    Exit Sub
End If

Dim NewUser As New UserForm

'Load new form
Load NewUser

'Set vars
NewUser.TargetUserStr = UserList.List(UserList.ListIndex)

'Find the matching config entry
i = 1
While (UCase(Config.Users(i).NameStr) <> _
    UCase(UserList.List(UserList.ListIndex)))
    i = i + 1
Wend

'Set Controls
NewUser.NameText.Text = Config.Users(i).NameStr
NewUser.PasswordText.Text = Config.Users(i).PasswordStr

'Show it!
NewUser.Show

End Sub

Private Sub ErrorMsgPathText_Change()
'Set Server section as modified
ConfigDirty = True
GeneralConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.ErrorMsgPathStr = ErrorMsgPathText.Text
End Sub

Private Sub ErrorMsgPathText_LostFocus()
'If directory has a \ at the end, remove it
If ((Right(ErrorMsgPathText.Text, 1) = "\") And (Right(ErrorMsgPathText.Text, 2) <> ":\")) Then
    ErrorMsgPathText.Text = Left(ErrorMsgPathText.Text, Len(ErrorMsgPathText.Text) - 1)
    Config.ErrorMsgPathStr = ErrorMsgPathText.Text
End If

'Make sure directory exits
On Error Resume Next 'If we change to a non-existant dir, don't complain
ChDir (ErrorMsgPathText.Text)
If Not CurDir(Left(ErrorMsgPathText.Text, 1)) = ErrorMsgPathText.Text Then
    'Directory does not exist
    MsgBox "Error path does not exist", vbOKOnly, "Fnord! Server Control"
End If
End Sub


Private Sub Form_Load()
'Set subform counter to 0
NumSubForms = 0

'Load configuration Data
Config.LoadConfig

'Init controls
InitAllControls

'Set data as not modified, must be done here,
'because in the process of initiaizing the
'controls we may have triggered modification
'code
ConfigDirty = False
ServerConfigDirty = False
GeneralConfigDirty = False
LogConfigDirty = False
PathConfigDirty = False
UserConfigDirty = False
GroupConfigDirty = False
MIMEConfigDirty = False
ApplyButton.Enabled = False

'Init the config module
Config.Init

End Sub


Private Sub Form_Unload(Cancel As Integer)
Dim Answer As Integer

If NumSubForms <> 0 Then
    Answer = MsgBox("There are still are open subwindows, are you sure you want to exit?", _
        vbYesNo, "Fnord! Server Control")
    If Answer = vbNo Then
        Cancel = True
        Exit Sub
    End If
End If

'Check for unsaved changes
If ConfigDirty Then
    Answer = MsgBox("Do you want to exit without saving changes?", vbYesNoCancel, _
        "Fnord! Server Control")
    If Answer = vbYes Then
        End
    ElseIf Answer = vbNo Then
        SaveDirtyConfig
        End
    ElseIf Answer = vbCancel Then
        Cancel = True
    End If
Else
    End
End If
End Sub


Private Sub GroupList_DblClick()
EditGroupButton_Click
End Sub


Private Sub IndexFileNameText_Change()
'Set Server section as modified
ConfigDirty = True
GeneralConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.IndexFileNameStr = IndexFileNameText.Text
End Sub

Private Sub IndexFileNameText_LostFocus()
If IndexFileNameText.Text = "" Then
    MsgBox "You must have a non-blank index file name"
End If
End Sub




Private Sub LogPathText_Change()
'Set Server section as modified
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.LogPathStr = LogPathText.Text
End Sub

Private Sub LogPathText_LostFocus()
'If directory has a \ at the end, remove it
If ((Right(LogPathText.Text, 1) = "\") And (Right(LogPathText.Text, 2) <> ":\")) Then
    LogPathText.Text = Left(LogPathText.Text, Len(LogPathText.Text) - 1)
    Config.LogPathStr = LogPathText.Text
End If

'Make sure directory exits
On Error Resume Next 'If we change to a non-existant dir, don't complain
ChDir (LogPathText.Text)
If Not CurDir(Left(LogPathText.Text, 1)) = LogPathText.Text Then
    'Directory does not exist
    MsgBox "Log path does not exist", vbOKOnly, "Fnord! Server Control"
End If
End Sub





Private Sub MainTabStrip_Click()
MainBoxes(MainTabStrip.SelectedItem.Index - 1).ZOrder 0
End Sub


Private Sub MaxNumThreadsText_Change()
'Set Server section as modified
ConfigDirty = True
GeneralConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.MaxNumThreadsStr = MaxNumThreadsText.Text
End Sub

Private Sub MaxNumThreadsText_LostFocus()
'Make sure we have a legal value
If Not (Val(MaxNumThreadsText.Text) > 0) And (Val(MaxNumThreadsText.Text) <= 500) Then
    MsgBox "Maximum Number of Threads must be set to a value between 1 and 500, 25 is recommended for light activity"
ElseIf Val(MaxNumThreadsText.Text) > 10 Then
    MsgBox "If you are running NT 4.0 Workstation, setting the maximum number of threads above 10 " + _
           "could result in a violation of the 10 user limit in the licensing agreement.", _
           vbOKOnly + vbExclamation, "Possible License Violation"
End If
End Sub


Private Sub MIMEListView_ColumnClick(ByVal ColumnHeader As ColumnHeader)
MIMEListView.SortKey = ColumnHeader.Index - 1

'Set Sorted to True to sort the list.
MIMEListView.Sorted = True
End Sub


Private Sub MIMEListView_DblClick()
EditMIMETypeButton_Click
End Sub


Private Sub MIMEListView_ItemClick(ByVal Item As ListItem)
Set MIMEListView.SelectedItem = Item
End Sub


Private Sub NewGroupButton_Click()
Dim NewGroup As New GroupForm

'Load new form
Load NewGroup

'Set vars
NewGroup.TargetGroupStr = ""

'Set Controls
NewGroup.NameText.Text = ""
NewGroup.MemberList.Clear
NewGroup.NonMemberList.Clear

'Add everyone to the non-members list
Dim i As Integer
For i = 1 To Config.NumUsers
    NewGroup.NonMemberList.AddItem Users(i).NameStr
Next i

'Show it!
NewGroup.Show
End Sub

Private Sub NewMIMETypeButton_Click()
Dim NewMIME As New MIMEForm

'Load new form
Load NewMIME

'Set vars
NewMIME.TargetFileExtStr = ""

'Set Controls
NewMIME.FileExtentionText.Text = ""
NewMIME.MIMEDescText.Text = ""

'Show it!
NewMIME.Show

End Sub

Private Sub NewPathButton_Click()
Dim NewPath As New PathForm

'Load new form
Load NewPath

'Set vars
NewPath.TargetRemotePathStr = ""

'Set Controls
NewPath.RemotePathText.Text = ""
NewPath.LocalPathText.Text = ""
NewPath.TypeCombo.Text = "Normal"
NewPath.AllowDirListCheck.Value = 0
NewPath.AuthUserCombo.Text = "Anyone"
NewPath.AuthLocationCombo.Text = "Anywhere"

'Show it!
NewPath.Show
End Sub

Private Sub NewUserButton_Click()
Dim NewUser As New UserForm

'Load new form
Load NewUser

'Set vars
NewUser.TargetUserStr = ""

'Set Controls
NewUser.NameText.Text = ""
NewUser.PasswordText.Text = ""

'Show it!
NewUser.Show

End Sub

Private Sub InitNumThreadsText_Change()
'Set Server section as modified
ConfigDirty = True
GeneralConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.InitNumThreadsStr = InitNumThreadsText.Text
End Sub

Private Sub InitNumThreadsText_LostFocus()
'Make sure we have a legal value
If Not (Val(InitNumThreadsText.Text) > 0) And (Val(InitNumThreadsText.Text) <= 500) Then
    MsgBox "Initial Number of Threads must be set to a value between 1 and 500, 2 is recommended for light activity"
End If
End Sub


Private Sub NumThreadsKeepFreeText_Change()
'Set Server section as modified
ConfigDirty = True
GeneralConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.NumThreadsKeepFreeStr = NumThreadsKeepFreeText.Text
End Sub

Private Sub NumThreadsKeepFreeText_LostFocus()
'Make sure we have a legal value
If Not (Val(NumThreadsKeepFreeText.Text) >= 0) And (Val(NumThreadsKeepFreeText.Text) <= 50) Then
    MsgBox " Number of Threads Keep Free must be set to a value between 0 and 50, 2 is recommended for light activity"
End If
End Sub


Private Sub OkButton_Click()
Dim Answer As Integer

'Check for unresolved forms
If NumSubForms <> 0 Then
    Answer = MsgBox("There are still are open subwindows, are you sure you want to exit?", _
        vbYesNo, "Fnord! Server Control")
    If Answer = vbNo Then Exit Sub
End If

SaveDirtyConfig
End
End Sub


Private Sub PathListView_ColumnClick(ByVal ColumnHeader As ColumnHeader)
PathListView.SortKey = ColumnHeader.Index - 1

'Set Sorted to True to sort the list.
PathListView.Sorted = True
End Sub


Private Sub PathListView_DblClick()
EditPathButton_Click
End Sub


Private Sub PortNumText_Change()
'Set Server section as modified
ConfigDirty = True
GeneralConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.PortNumStr = PortNumText.Text
End Sub

Private Sub PortNumText_LostFocus()
'Make sure we have a legal value
If Not (Val(PortNumText.Text) > 0) And (Val(PortNumText.Text) <= 9999) Then
    MsgBox "Port Number set to an illegal value (1-9999 expected, 80 is default)"
End If
End Sub


Private Sub RefLogEnabledCheck_Click()
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

If RefLogEnabledCheck.Value = 1 Then
    Config.RefLogEnabledBool = True
    RefLogNameText.Enabled = True
Else
    Config.RefLogEnabledBool = False
    RefLogNameText.Enabled = False
End If
End Sub

Private Sub RefLogNameText_Change()
'Set Server section as modified
ConfigDirty = True
LogConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.RefLogNameStr = RefLogNameText.Text
End Sub

Private Sub RemoveGroupButton_Click()
Dim i, j As Integer
Dim TargetName As String

'Make sure a group is selected
If GroupList.ListIndex = -1 Then
    MsgBox "Select a Group First", vbOKOnly, "Fnord! Server Control"
    Exit Sub
End If

TargetName = GroupList.List(GroupList.ListIndex)

'See if we are using selected name in any mappings...
For i = 1 To Config.NumMappings
    If UCase(Config.DirMappings(i).AuthUserStr) = UCase(TargetName) Then
        MsgBox "There is a path mapped for this group, please change or delete it first", vbOKOnly, "Fnord! Server Control"
        Exit Sub
    End If
Next i

'Set Data as dirty
ConfigDirty = True
GroupConfigDirty = True
ApplyButton.Enabled = True
    
'Remove from Control
GroupList.RemoveItem GroupList.ListIndex

'Remove from Data
Config.DeleteGroup TargetName
End Sub

Private Sub RemoveMIMETypeButton_Click()

If Not (MIMEListView.SelectedItem Is Nothing) Then

    'Set Data as dirty
    ConfigDirty = True
    MIMEConfigDirty = True
    ApplyButton.Enabled = True

    'Remove Data Item
    Config.DeleteMIMEType MIMEListView.SelectedItem.Text

    'Remove List Item
    MIMEListView.ListItems.Remove MIMEListView.SelectedItem.Index
Else
    MsgBox "Select a MIME type first", vbOKOnly, "Fnord! Server Control"
End If
End Sub

Private Sub RemovePathButton_Click()

If Not (PathListView.SelectedItem Is Nothing) Then

    'Set Data as dirty
    ConfigDirty = True
    PathConfigDirty = True
    ApplyButton.Enabled = True

    'Remove Data Item
    Config.DeletePathMapping PathListView.SelectedItem.Text

    'Remove List Item
    PathListView.ListItems.Remove PathListView.SelectedItem.Index
Else
    MsgBox "Select a path mapping first", vbOKOnly, "Fnord! Server Control"
End If
End Sub

Private Sub RemoveUserButton_Click()
Dim i, j As Integer
Dim TargetName As String

'Make sure a user is selected
If UserList.ListIndex = -1 Then
    MsgBox "Select a user first", vbOKOnly, "Fnord! Server Control"
    Exit Sub
End If

TargetName = UserList.List(UserList.ListIndex)

'See if we are using selected name in any mappings...
For i = 1 To Config.NumMappings
    If UCase(Config.DirMappings(i).AuthUserStr) = UCase(TargetName) Then
        MsgBox "There is a path mapped for this user, please change or delete it first", vbOKOnly, "Fnord! Server Control"
        Exit Sub
    End If
Next i

'Set Data as dirty
ConfigDirty = True
UserConfigDirty = True
GroupConfigDirty = True 'Just in case
ApplyButton.Enabled = True
    
'Remove from Control
UserList.RemoveItem UserList.ListIndex

'Remove from Data
Config.DeleteUser TargetName

End Sub



Private Sub ScriptDNSCheck_Click()
ConfigDirty = True
GeneralConfigDirty = True
ApplyButton.Enabled = True

If ScriptDNSCheck.Value = 1 Then
    Config.ScriptDNSBool = True
Else
    Config.ScriptDNSBool = False
End If
End Sub

Private Sub ServerAddressText_Change()

'Set Server section as modified
ConfigDirty = True
ServerConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.ServerAddressStr = ServerAddressText.Text
End Sub


Private Sub TempPathText_Change()
'Set Server section as modified
ConfigDirty = True
GeneralConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.TempPathStr = TempPathText.Text
End Sub


Private Sub TempPathText_LostFocus()
'If directory has a \ at the end, remove it
If ((Right(TempPathText.Text, 1) = "\") And (Right(TempPathText.Text, 2) <> ":\")) Then
    TempPathText.Text = Left(TempPathText.Text, Len(TempPathText.Text) - 1)
    Config.TempPathStr = TempPathText.Text
End If

'Make sure directory exits
On Error Resume Next 'If we change to a non-existant dir, don't complain
ChDir (TempPathText.Text)
If Not CurDir(Left(TempPathText.Text, 1)) = TempPathText.Text Then
    'Directory does not exist
    MsgBox "Temp path does not exist", vbOKOnly, "Fnord! Server Control"
End If
End Sub




Private Sub ThreadCompactLazinessText_Change()
'Set Server section as modified
ConfigDirty = True
GeneralConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.ThreadCompactLazinessStr = ThreadCompactLazinessText.Text
End Sub


Private Sub ThreadCompactLazinessText_LostFocus()
'Make sure we have a legal value
If Not (Val(ThreadCompactLazinessText.Text) > 0) And (Val(ThreadCompactLazinessText.Text) <= 100) Then
    MsgBox "Thread Compact Laziness must be set to a value between 1 and 100, 2 is recommended for light activity"
End If
End Sub


Private Sub ThreadCompactPeriodText_Change()
'Set Server section as modified
ConfigDirty = True
GeneralConfigDirty = True
ApplyButton.Enabled = True

'Update configuration information
Config.ThreadCompactPeriodStr = ThreadCompactPeriodText.Text
End Sub


Private Sub ThreadCompactPeriodText_LostFocus()
'Make sure we have a legal value
If Not (Val(ThreadCompactPeriodText.Text) >= 10) And (Val(ThreadCompactPeriodText.Text) <= 999999) Then
    MsgBox "Thread Compact Period must be set to a value between 10 and 999999 sec, 300 sec (5 min) is recommended for light activity"
End If
End Sub


Private Sub UserList_DblClick()
EditUserButton_Click
End Sub


