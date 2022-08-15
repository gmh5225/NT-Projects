VERSION 4.00
Begin VB.Form PathForm 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Path Mapping"
   ClientHeight    =   3810
   ClientLeft      =   1125
   ClientTop       =   4275
   ClientWidth     =   5175
   Height          =   4215
   Icon            =   "Path.frx":0000
   Left            =   1065
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3810
   ScaleWidth      =   5175
   ShowInTaskbar   =   0   'False
   Top             =   3930
   Width           =   5295
   Begin VB.CommandButton OkButton 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   1560
      TabIndex        =   1
      Top             =   3360
      Width           =   1095
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   2760
      TabIndex        =   8
      Top             =   3360
      Width           =   1095
   End
   Begin VB.CommandButton RefreshButton 
      Caption         =   "Refresh"
      Height          =   375
      Left            =   3960
      TabIndex        =   9
      Top             =   3360
      Width           =   1095
   End
   Begin VB.Frame Frame2 
      Caption         =   "General"
      Height          =   1455
      Left            =   120
      TabIndex        =   12
      Top             =   120
      Width           =   4935
      Begin VB.ComboBox TypeCombo 
         Height          =   315
         Left            =   1200
         TabIndex        =   4
         Text            =   "Combo1"
         Top             =   960
         Width           =   1935
      End
      Begin VB.TextBox LocalPathText 
         Height          =   285
         Left            =   1200
         TabIndex        =   3
         Text            =   "Text1"
         Top             =   600
         Width           =   3615
      End
      Begin VB.TextBox RemotePathText 
         Height          =   285
         Left            =   1200
         TabIndex        =   2
         Text            =   "Text1"
         Top             =   240
         Width           =   3615
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "Remote Path:"
         Height          =   195
         Left            =   120
         TabIndex        =   15
         Top             =   240
         Width           =   975
      End
      Begin VB.Label LocalPathLabel 
         AutoSize        =   -1  'True
         Caption         =   "Local Path:"
         Height          =   195
         Left            =   120
         TabIndex        =   14
         Top             =   600
         Width           =   810
      End
      Begin VB.Label Label1 
         Caption         =   "Type:"
         Height          =   255
         Left            =   120
         TabIndex        =   13
         Top             =   960
         Width           =   495
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Security"
      Height          =   1575
      Left            =   120
      TabIndex        =   0
      Top             =   1680
      Width           =   4935
      Begin VB.ComboBox AuthLocationCombo 
         Height          =   315
         Left            =   2040
         TabIndex        =   7
         Text            =   "Nope"
         Top             =   1080
         Width           =   1935
      End
      Begin VB.CheckBox AllowDirListCheck 
         Caption         =   "Allow Directory Listings"
         Height          =   255
         Left            =   120
         TabIndex        =   5
         Top             =   240
         Width           =   2535
      End
      Begin VB.ComboBox AuthUserCombo 
         Height          =   315
         Left            =   2040
         TabIndex        =   6
         Text            =   "Nope"
         Top             =   600
         Width           =   1935
      End
      Begin VB.Label Label5 
         AutoSize        =   -1  'True
         Caption         =   "Authorized Location:"
         Height          =   195
         Left            =   120
         TabIndex        =   11
         Top             =   1080
         Width           =   1455
      End
      Begin VB.Label Label4 
         AutoSize        =   -1  'True
         Caption         =   "Authorized Group or User:"
         Height          =   195
         Left            =   120
         TabIndex        =   10
         Top             =   600
         Width           =   1830
      End
   End
End
Attribute VB_Name = "PathForm"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
DefInt A-Z
Option Explicit

'Public variables
Public TargetRemotePathStr As String

Private Sub CancelButton_Click()
Unload Me
End Sub


Private Sub Form_Load()
Dim i As Integer

MainForm.NumSubForms = MainForm.NumSubForms + 1

'Load Mapping Types into combo box
TypeCombo.Clear
TypeCombo.AddItem "Normal"
TypeCombo.AddItem "CGI"
'TypeCombo.AddItem "WinCGI"
TypeCombo.AddItem "ISAPI"
TypeCombo.AddItem "Redirect"

'Load "Anyone" into combo box
AuthUserCombo.Clear
AuthUserCombo.AddItem "Anyone"

'Load Users into combo box
For i = 1 To Config.NumUsers
    AuthUserCombo.AddItem Config.Users(i).NameStr
Next i

'Load Groups into combo box
For i = 1 To Config.NumGroups
    AuthUserCombo.AddItem Config.Groups(i).NameStr
Next i

'Load Auth Locations into combo box
AuthLocationCombo.AddItem "Anywhere"
AuthLocationCombo.AddItem "Class A Subnet"
AuthLocationCombo.AddItem "Class B Subnet"
AuthLocationCombo.AddItem "Class C Subnet"
AuthLocationCombo.AddItem "Class D Subnet"
End Sub


Private Sub Form_Unload(Cancel As Integer)
MainForm.NumSubForms = MainForm.NumSubForms - 1
End Sub



Private Sub LocalPathText_LostFocus()
'If directory has a \ at the end, remove it
If ((Right(LocalPathText.Text, 1) = "\") And (Right(LocalPathText.Text, 2) <> ":\")) Then
    LocalPathText.Text = Left(LocalPathText.Text, Len(LocalPathText.Text) - 1)
End If

'Make sure directory exits
If TypeCombo.Text <> "Redirect" Then
   On Error Resume Next 'If we change to a non-existant dir, don't complain
   ChDir (LocalPathText.Text)
   If Not CurDir(Left(LocalPathText.Text, 1)) = LocalPathText.Text Then
      'Directory does not exist
      MsgBox "Local path does not exist"
   End If
End If
End Sub


Private Sub OkButton_Click()
'Make sure the remote path field isn't blank
If RemotePathText.Text = "" Then
    MsgBox "Remote path field is blank", vbOKOnly, "Fnord! Server Control"
    RemotePathText.SetFocus
    Exit Sub
End If

'Make sure the local path field isn't blank
If LocalPathText.Text = "" Then
    MsgBox "Local path field is blank", vbOKOnly, "Fnord! Server Control"
    LocalPathText.SetFocus
    Exit Sub
End If

Dim i As Integer
Dim Item As ListItem
Dim TypeNameStr As String
Dim AuthLocStr As String

'Data is dirty
MainForm.ConfigDirty = True
MainForm.PathConfigDirty = True
MainForm.ApplyButton.Enabled = True

'If the Target item exists, kill it
If TargetRemotePathStr <> "" Then
    'Remove it from Config
    Config.DeletePathMapping TargetRemotePathStr
    
    'Remove it from the listview
    Set Item = MainForm.PathListView.FindItem(TargetRemotePathStr)
    If Not (Item Is Nothing) Then MainForm.PathListView.ListItems.Remove Item.Index
End If

'Make sure another doesn't exist with the same local path
Dim Match As Boolean
Match = False

For i = 1 To Config.NumMappings
    If UCase(Config.DirMappings(i).RemotePathStr) = UCase(RemotePathText.Text) Then _
        Match = True
Next i
    
If Not Match Then
    'Add it to Config
    If AuthLocationCombo.Text = "Anywhere" Then
        AuthLocStr = "-"
    Else
        AuthLocStr = AuthLocationCombo.Text
    End If
        
    If TypeCombo.Text = "Normal" Then
        TypeNameStr = "None"
    Else
        TypeNameStr = TypeCombo.Text
    End If
        
    Config.AddPathMapping RemotePathText.Text, LocalPathText.Text, _
        (AllowDirListCheck.Value = 1), TypeNameStr, AuthUserCombo.Text, _
        AuthLocStr

    'Add it to the list view
    Set Item = MainForm.PathListView.ListItems.Add()
    Item.Text = RemotePathText.Text
    Item.SubItems(1) = LocalPathText.Text
    
    If TypeCombo.Text = "Redirect" Then
       Item.SubItems(2) = "Redir"
    Else
       Item.SubItems(2) = TypeCombo.Text
    End If
    
    If (AllowDirListCheck.Value = 1) Then
        Item.SubItems(3) = "Yes"
    Else
        Item.SubItems(3) = "No"
    End If

    Item.SubItems(4) = AuthUserCombo.Text
    
    If AuthLocationCombo.Text = "Class A Subnet" Then
        Item.SubItems(5) = "A"
    ElseIf AuthLocationCombo.Text = "Class B Subnet" Then
        Item.SubItems(5) = "B"
    ElseIf AuthLocationCombo.Text = "Class C Subnet" Then
        Item.SubItems(5) = "C"
    ElseIf AuthLocationCombo.Text = "Class D Subnet" Then
        Item.SubItems(5) = "D"
    Else
        Item.SubItems(5) = "-"
    End If

    MainForm.PathListView.Sorted = True
Else
    Dim Answer As Integer
    
    Answer = MsgBox("An entry already exists for " + RemotePathText.Text + _
        ", do you want to overwrite it?", vbYesNo, "Fnord! Server Control")
    If Answer = vbYes Then
    
        'Remove it from the Config
        Config.DeletePathMapping RemotePathText.Text
    
        'Remove it from the listview
        Set Item = MainForm.PathListView.FindItem(RemotePathText.Text)
        If Not (Item Is Nothing) Then MainForm.PathListView.ListItems.Remove Item.Index
        
        'Add it to Config
        If AuthLocationCombo.Text = "Anywhere" Then
            AuthLocStr = "-"
        Else
            AuthLocStr = AuthLocationCombo.Text
        End If
        
        If TypeCombo.Text = "Normal" Then
            TypeNameStr = "None"
        Else
            TypeNameStr = TypeCombo.Text
        End If
        
        Config.AddPathMapping RemotePathText.Text, LocalPathText.Text, _
            (AllowDirListCheck.Value = 1), TypeNameStr, AuthUserCombo.Text, _
            AuthLocStr

        'Add it to the list view
        Set Item = MainForm.PathListView.ListItems.Add()
        Item.Text = RemotePathText.Text
        Item.SubItems(1) = LocalPathText.Text
        Item.SubItems(2) = TypeCombo.Text
    
        If (AllowDirListCheck.Value = 1) Then
            Item.SubItems(3) = "Yes"
        Else
            Item.SubItems(3) = "No"
        End If

        Item.SubItems(4) = AuthUserCombo.Text
    
        If AuthLocationCombo.Text = "Class A Subnet" Then
            Item.SubItems(5) = "A"
        ElseIf AuthLocationCombo.Text = "Class B Subnet" Then
            Item.SubItems(5) = "B"
        ElseIf AuthLocationCombo.Text = "Class C Subnet" Then
            Item.SubItems(5) = "C"
        ElseIf AuthLocationCombo.Text = "Class D Subnet" Then
            Item.SubItems(5) = "D"
        Else
            Item.SubItems(5) = "-"
        End If

        MainForm.PathListView.Sorted = True
    End If
End If

Unload Me
End Sub




Private Sub RefreshButton_Click()
Dim SelUser As String
Dim i As Integer

'Save the selected user
SelUser = AuthUserCombo.Text

'Load "Anyone" into combo box
AuthUserCombo.Clear
AuthUserCombo.AddItem "Anyone"

'Load Users into combo box
For i = 1 To Config.NumUsers
    AuthUserCombo.AddItem Config.Users(i).NameStr
Next i

'Load Groups into combo box
For i = 1 To Config.NumGroups
    AuthUserCombo.AddItem Config.Groups(i).NameStr
Next i

'Select the originaly selected user
AuthUserCombo.Text = SelUser

End Sub

Private Sub RemotePathText_LostFocus()
'If directory has a / at the end, but is not "/" remove it
If (RemotePathText.Text <> "/") And (Right(RemotePathText.Text, 1) = "/") Then
    RemotePathText.Text = Left(RemotePathText.Text, Len(RemotePathText.Text) - 1)
End If
End Sub


Private Sub TypeCombo_Change()
If TypeCombo.Text = "Redirect" Then
   LocalPathLabel.Caption = "New URL:"
Else
   LocalPathLabel.Caption = "Local Path:"
End If
End Sub


Private Sub TypeCombo_Click()
TypeCombo_Change
End Sub


Private Sub TypeCombo_KeyPress(KeyAscii As Integer)
TypeCombo_Change
End Sub


