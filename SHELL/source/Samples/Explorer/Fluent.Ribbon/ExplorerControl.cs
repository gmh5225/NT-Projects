using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.WindowsAPICodePack.Shell;

namespace Fluent
{
    public partial class ExplorerControl : Form
    {
        public ExplorerControl()
        {
            InitializeComponent();

            // setup ExplorerBrowser navigation events

            explorerBrowser.ItemsChanged += new EventHandler(explorerBrowser_ItemsChanged);
            explorerBrowser.SelectionChanged += new EventHandler(explorerBrowser_SelectionChanged);
        }

           protected override void OnShown(EventArgs e)
         {
            base.OnShown(e);
            explorerBrowser.Navigate((ShellObject)KnownFolders.Desktop);
         }

        void explorerBrowser_SelectionChanged(object sender, EventArgs e)
            {
                
            }

            void explorerBrowser_ItemsChanged(object sender, EventArgs e)
            {
               
            }
       
    }
    }

