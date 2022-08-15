VERSION 4.00
Begin VB.Form MIMEForm 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "MIME Type"
   ClientHeight    =   1545
   ClientLeft      =   1140
   ClientTop       =   1935
   ClientWidth     =   5205
   Height          =   1965
   Icon            =   "MIME.frx":0000
   Left            =   1080
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1545
   ScaleWidth      =   5205
   ShowInTaskbar   =   0   'False
   Top             =   1575
   Width           =   5325
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4080
      TabIndex        =   3
      Top             =   1080
      Width           =   1095
   End
   Begin VB.CommandButton OkButton 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   2880
      TabIndex        =   0
      Top             =   1080
      Width           =   1095
   End
   Begin VB.TextBox MIMEDescText 
      Height          =   285
      Left            =   1560
      TabIndex        =   2
      Top             =   600
      Width           =   3615
   End
   Begin VB.TextBox FileExtentionText 
      Height          =   285
      Left            =   1560
      TabIndex        =   1
      Top             =   240
      Width           =   735
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "MIME Description:"
      Height          =   195
      Left            =   120
      TabIndex        =   5
      Top             =   600
      Width           =   1305
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "File Extension:"
      Height          =   195
      Left            =   120
      TabIndex        =   4
      Top             =   240
      Width           =   1020
   End
End
Attribute VB_Name = "MIMEForm"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
DefInt A-Z
Option Explicit

'Public Variables
Public TargetFileExtStr As String


Private Sub CancelButton_Click()
Unload Me
End Sub


Private Sub Form_Load()
MainForm.NumSubForms = MainForm.NumSubForms + 1
End Sub

Private Sub Form_Unload(Cancel As Integer)
MainForm.NumSubForms = MainForm.NumSubForms - 1
End Sub


Private Sub OkButton_Click()
'Make sure the extention field isn't blank
If FileExtentionText.Text = "" Then
    MsgBox "File extention field is blank", vbOKOnly, "Fnord! Server Control"
    FileExtentionText.SetFocus
    Exit Sub
End If

'Make sure the description field isn't blank
If MIMEDescText.Text = "" Then
    MsgBox "MIME description field is blank", vbOKOnly, "Fnord! Server Control"
    MIMEDescText.SetFocus
    Exit Sub
End If

Dim i As Integer
Dim Item As ListItem

'Data is dirty
MainForm.ConfigDirty = True
MainForm.MIMEConfigDirty = True
MainForm.ApplyButton.Enabled = True

'If the Target item exists, kill it
If TargetFileExtStr <> "" Then
    'Remove it from Config
    Config.DeleteMIMEType TargetFileExtStr
    
    'Remove it from the listview
    Set Item = MainForm.MIMEListView.FindItem(TargetFileExtStr)
    If Not (Item Is Nothing) Then MainForm.MIMEListView.ListItems.Remove Item.Index
End If

'Make sure another doesn't exist with the same extention
Dim Match As Boolean
Match = False

For i = 1 To Config.NumMIMETypes
    If UCase(Config.MIMETypes(i).FileExtStr) = UCase(FileExtentionText.Text) Then _
        Match = True
Next i
    
If Not Match Then
    'Add it to Config
    Config.AddMIMEType UCase(FileExtentionText.Text), MIMEDescText.Text

    'Add it to the list view
    Set Item = MainForm.MIMEListView.ListItems.Add()
    Item.Text = UCase(FileExtentionText.Text)
    Item.SubItems(1) = MIMEDescText.Text

    MainForm.MIMEListView.Sorted = True
Else
    Dim Answer As Integer
    
    Answer = MsgBox("An entry already exists for " + UCase(FileExtentionText.Text) + _
        ", do you want to overwrite it?", vbYesNo, "Fnord! Server Control")
    If Answer = vbYes Then
    
        'Remove it from the Config
        Config.DeleteMIMEType UCase(FileExtentionText.Text)
    
        'Remove it from the listview
        Set Item = MainForm.MIMEListView.FindItem(FileExtentionText.Text)
        If Not (Item Is Nothing) Then MainForm.MIMEListView.ListItems.Remove Item.Index
        
        'Add it to Config
        Config.AddMIMEType UCase(FileExtentionText.Text), MIMEDescText.Text

        'Add it to the list view
        Set Item = MainForm.MIMEListView.ListItems.Add()
        Item.Text = UCase(FileExtentionText.Text)
        Item.SubItems(1) = MIMEDescText.Text

        MainForm.MIMEListView.Sorted = True
    End If
End If

Unload Me
End Sub


