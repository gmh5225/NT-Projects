VERSION 4.00
Begin VB.Form UserForm 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "User"
   ClientHeight    =   1530
   ClientLeft      =   1140
   ClientTop       =   2325
   ClientWidth     =   2550
   Height          =   1950
   Icon            =   "User.frx":0000
   Left            =   1080
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1530
   ScaleWidth      =   2550
   ShowInTaskbar   =   0   'False
   Top             =   1965
   Width           =   2670
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   1320
      TabIndex        =   4
      Top             =   1080
      Width           =   1095
   End
   Begin VB.CommandButton OkButton 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   1080
      Width           =   1095
   End
   Begin VB.TextBox NameText 
      Height          =   285
      Left            =   960
      TabIndex        =   1
      Top             =   240
      Width           =   1455
   End
   Begin VB.TextBox PasswordText 
      Height          =   285
      Left            =   960
      PasswordChar    =   "*"
      TabIndex        =   2
      Top             =   600
      Width           =   1455
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Password:"
      Height          =   195
      Left            =   120
      TabIndex        =   5
      Top             =   600
      Width           =   735
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "Name:"
      Height          =   195
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   465
   End
End
Attribute VB_Name = "UserForm"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
DefInt A-Z
Option Explicit

'Public Variables
Public TargetUserStr As String

Private Sub CancelButton_Click()
Unload Me
End Sub


Private Sub Form_Load()
MainForm.NumSubForms = MainForm.NumSubForms + 1
End Sub


Private Sub Form_Unload(Cancel As Integer)
MainForm.NumSubForms = MainForm.NumSubForms - 1
End Sub


Private Sub NameText_LostFocus()
NameText.Text = LCase(NameText.Text)
End Sub


Private Sub OkButton_Click()
'Make sure the name field isn't blank
If NameText.Text = "" Then
    MsgBox "Name field is blank", vbOKOnly, "Fnord! Server Control"
    NameText.SetFocus
    Exit Sub
End If

'Make sure we don't have the same name as a group
Dim i As Integer
For i = 1 To NumGroups
    If LCase(NameText.Text) = LCase(Config.Groups(i).NameStr) Then
        MsgBox "A group already exists with this name", vbOKOnly, "Fnord! Server Control"
        NameText.SetFocus
        Exit Sub
    End If
Next i


'Data is dirty
MainForm.ConfigDirty = True
MainForm.UserConfigDirty = True
MainForm.ApplyButton.Enabled = True

'If the Target item exists, kill it
If TargetUserStr <> "" Then
    'Remove it from Config
    Config.DeleteUser TargetUserStr
    
    'Remove it from the list box
    i = 0
    While (i < MainForm.UserList.ListCount) And (MainForm.UserList.List(i) <> TargetUserStr)
        i = i + 1
    Wend
    If (i < MainForm.UserList.ListCount) Then
        MainForm.UserList.RemoveItem i
    End If
End If

'Make sure another doesn't exist with the same extention
Dim Match As Boolean
Match = False

For i = 1 To Config.NumUsers
    If LCase(Config.Users(i).NameStr) = LCase(NameText.Text) Then _
        Match = True
Next i
    
If Not Match Then
    'Add it to Config
    Config.AddUser LCase(NameText.Text), PasswordText.Text

    'Add it to the list box
    MainForm.UserList.AddItem LCase(NameText.Text)
Else
    Dim Answer As Integer
    
    Answer = MsgBox("An entry already exists for " + LCase(NameText.Text) + _
        ", do you want to overwrite it?", vbYesNo, "Fnord! Server Control")
    If Answer = vbYes Then
    
        'Remove it from the Config
        Config.DeleteUser LCase(NameText.Text)
    
        'Remove it from the listbox
        i = 0
        While (i < MainForm.UserList.ListCount) And (MainForm.UserList.List(i) <> LCase(NameText.Text))
            i = i + 1
        Wend
        If (i < MainForm.UserList.ListCount) Then
            MainForm.UserList.RemoveItem i
        End If
        
        'Add it to Config
        Config.AddUser LCase(NameText.Text), PasswordText.Text

        'Add it to the list box
        MainForm.UserList.AddItem LCase(NameText.Text)
    End If
End If

Unload Me
End Sub


