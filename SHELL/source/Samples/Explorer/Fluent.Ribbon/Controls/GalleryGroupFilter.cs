﻿using System.Windows;

namespace Fluent
{
    /// <summary>
    /// Represents gallery group filter definition
    /// </summary>
    public class GalleryGroupFilter : DependencyObject
    {
        /// <summary>
        /// Gets or sets title of filter
        /// </summary>
        public string Title
        {
            get { return (string)this.GetValue(TitleProperty); }
            set { this.SetValue(TitleProperty, value); }
        }

        /// <summary>
        /// Using a DependencyProperty as the backing store for Title.  
        /// This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty TitleProperty =
            DependencyProperty.Register("Title", typeof(string), 
            typeof(GalleryGroupFilter), new UIPropertyMetadata("GalleryGroupFilter"));
               
        /// <summary>
        /// Gets or sets list pf groups splitted by comma
        /// </summary>
        public string Groups
        {
            get { return (string)this.GetValue(GroupsProperty); }
            set { this.SetValue(GroupsProperty, value); }
        }

        /// <summary>
        /// Using a DependencyProperty as the backing store for ContextualGroups.  
        /// This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty GroupsProperty =
            DependencyProperty.Register("ContextualGroups", typeof(string), 
            typeof(GalleryGroupFilter), new UIPropertyMetadata(string.Empty));
    }
}