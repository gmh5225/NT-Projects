VERSION 4.00
Begin VB.Form GroupForm 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Group"
   ClientHeight    =   3690
   ClientLeft      =   3810
   ClientTop       =   2310
   ClientWidth     =   4470
   Height          =   4110
   Icon            =   "Group.frx":0000
   Left            =   3750
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3690
   ScaleWidth      =   4470
   ShowInTaskbar   =   0   'False
   Top             =   1950
   Width           =   4590
   Begin VB.TextBox NameText 
      Height          =   285
      Left            =   840
      TabIndex        =   9
      Top             =   2760
      Width           =   1455
   End
   Begin VB.CommandButton RemoveButton 
      Caption         =   "<- Remove"
      Height          =   375
      Left            =   1680
      TabIndex        =   8
      Top             =   1680
      Width           =   1095
   End
   Begin VB.CommandButton AddButton 
      Caption         =   "Add ->"
      Height          =   375
      Left            =   1680
      TabIndex        =   7
      Top             =   1080
      Width           =   1095
   End
   Begin VB.CommandButton RefreshButton 
      Caption         =   "Refresh"
      Height          =   375
      Left            =   3240
      TabIndex        =   6
      Top             =   3240
      Width           =   1095
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   2040
      TabIndex        =   5
      Top             =   3240
      Width           =   1095
   End
   Begin VB.CommandButton OkButton 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   840
      TabIndex        =   4
      Top             =   3240
      Width           =   1095
   End
   Begin VB.ListBox NonMemberList 
      Height          =   2010
      Left            =   120
      TabIndex        =   1
      Top             =   600
      Width           =   1455
   End
   Begin VB.ListBox MemberList 
      Height          =   2010
      Left            =   2880
      TabIndex        =   0
      Top             =   600
      Width           =   1455
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "Name:"
      Height          =   195
      Left            =   120
      TabIndex        =   10
      Top             =   2760
      Width           =   465
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "Non-Members"
      Height          =   195
      Left            =   120
      TabIndex        =   3
      Top             =   240
      Width           =   1485
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Members"
      Height          =   195
      Left            =   2880
      TabIndex        =   2
      Top             =   240
      Width           =   1485
   End
End
Attribute VB_Name = "GroupForm"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
DefInt A-Z
Option Explicit

'Public Variables
Public TargetGroupStr As String


Sub SaveData()
Dim i As Integer

Config.AddGroup NameText.Text
For i = 1 To MemberList.ListCount
    Config.AddUserToGroup LCase(NameText.Text), LCase(MemberList.List(i - 1))
Next i
End Sub


Private Sub AddButton_Click()
'Make sure a non-member is selected
If NonMemberList.ListIndex = -1 Then
    MsgBox "Select a non-member first", vbOKOnly, "Fnord! Server Control"
    Exit Sub
End If

'Add selected user to member list
MemberList.AddItem NonMemberList.List(NonMemberList.ListIndex)

'Remove selected user from non-member list
NonMemberList.RemoveItem NonMemberList.ListIndex
End Sub


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

'Make sure there is at least 1 member
If MemberList.ListCount = 0 Then
    MsgBox "Group has no members", vbOKOnly, "Fnord! Server Control"
    MemberList.SetFocus
    Exit Sub
End If

'Make sure we don't have the same name as a user
Dim i As Integer
For i = 1 To NumUsers
    If LCase(NameText.Text) = LCase(Config.Users(i).NameStr) Then
        MsgBox "A user already exists with this name", vbOKOnly, "Fnord! Server Control"
        NameText.SetFocus
        Exit Sub
    End If
Next i

'Data is dirty
MainForm.ConfigDirty = True
MainForm.GroupConfigDirty = True
MainForm.ApplyButton.Enabled = True

'If the Target item exists, kill it
If TargetGroupStr <> "" Then
    'Remove it from Config
    Config.DeleteGroup TargetGroupStr
    
    'Remove it from the list box
    i = 0
    While (i < MainForm.GroupList.ListCount) And (LCase(MainForm.GroupList.List(i)) <> LCase(TargetGroupStr))
        i = i + 1
    Wend
    If (i < MainForm.GroupList.ListCount) Then
        MainForm.GroupList.RemoveItem i
    End If
End If

'Make sure another doesn't exist with the same name
Dim Match As Boolean
Match = False

For i = 1 To Config.NumGroups
    If LCase(Config.Groups(i).NameStr) = LCase(NameText.Text) Then _
        Match = True
Next i
    
If Not Match Then
    'Add it to Config
    SaveData

    'Add it to the list box
    MainForm.GroupList.AddItem LCase(NameText.Text)
Else
    Dim Answer As Integer
    
    Answer = MsgBox("An entry already exists for " + LCase(NameText.Text) + _
        ", do you want to overwrite it?", vbYesNo, "Fnord! Server Control")
    If Answer = vbYes Then
    
        'Remove it from the Config
        Config.DeleteGroup LCase(NameText.Text)
    
        'Remove it from the listbox
        i = 0
        While (i < MainForm.GroupList.ListCount) And (LCase(MainForm.GroupList.List(i)) <> LCase(NameText.Text))
            i = i + 1
        Wend
        If (i < MainForm.GroupList.ListCount) Then
            MainForm.GroupList.RemoveItem i
        End If
        
        'Add it to Config
        SaveData

        'Add it to the list box
        MainForm.GroupList.AddItem LCase(NameText.Text)
    End If
End If

Unload Me
End Sub


Private Sub RefreshButton_Click()
Dim i As Integer
Dim j As Integer
Dim k As Integer
Dim Member As Boolean

If TargetGroupStr = "" Then
    'Put everyone in the non-member list
    MemberList.Clear
    NonMemberList.Clear
    
    For i = 1 To Config.NumUsers
        NonMemberList.AddItem Users(i).NameStr
    Next i
Else
    'Refresh the member and non-member lists
    
    'Find the matching config entry
    i = 1
    While LCase(Config.Groups(i).NameStr) <> LCase(TargetGroupStr)
        i = i + 1
    Wend

    'Set Controls
    MemberList.Clear
    NonMemberList.Clear

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
            MemberList.AddItem Users(j).NameStr
        'No, add them to the non-members
        Else
            NonMemberList.AddItem Users(j).NameStr
        End If
    Next j
End If

End Sub

Private Sub RemoveButton_Click()
'Make sure a member is selected
If MemberList.ListIndex = -1 Then
    MsgBox "Select a member first", vbOKOnly, "Fnord! Server Control"
    Exit Sub
End If

'Add selected user to non-member list
NonMemberList.AddItem MemberList.List(MemberList.ListIndex)

'Remove selected user from member list
MemberList.RemoveItem MemberList.ListIndex
End Sub


