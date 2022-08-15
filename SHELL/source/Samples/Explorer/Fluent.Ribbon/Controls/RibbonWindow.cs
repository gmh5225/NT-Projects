﻿namespace Fluent
{
    using System;
    using System.Diagnostics.CodeAnalysis;
    using System.Windows;
    using System.Windows.Data;
    using System.Windows.Input;
    using System.Windows.Interactivity;
    using ControlzEx.Behaviors;

    using Fluent.Extensions;
    using Fluent.Helpers;

    //using WindowChrome = System.Windows.Shell.WindowChrome;
    using WindowChrome = ControlzEx.Microsoft.Windows.Shell.WindowChrome;

    /// <summary>
    /// Represents basic window for ribbon
    /// </summary>
    [SuppressMessage("Microsoft.Design", "CA1049")]
    [TemplatePart(Name = PART_Icon, Type = typeof(UIElement))]
    [TemplatePart(Name = PART_ContentPresenter, Type = typeof(UIElement))]
    [TemplatePart(Name = PART_WindowCommands, Type = typeof(WindowCommands))]
    public class RibbonWindow : Window
    {
        private const string PART_Icon = "PART_Icon";
        private const string PART_ContentPresenter = "PART_ContentPresenter";
        private const string PART_WindowCommands = "PART_WindowCommands";

        private FrameworkElement iconImage;

        #region Properties

        /// <summary>
        /// Using a DependencyProperty as the backing store for WindowCommands.  This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty WindowCommandsProperty = DependencyProperty.Register("WindowCommands", typeof(WindowCommands), typeof(RibbonWindow), new PropertyMetadata(null));

        /// <summary>
        /// Gets or sets the window commands
        /// </summary>
        public WindowCommands WindowCommands
        {
            get { return (WindowCommands)this.GetValue(WindowCommandsProperty); }
            set { this.SetValue(WindowCommandsProperty, value); }
        }

        /// <summary>
        /// Gets or sets resize border thickness
        /// </summary>
        public Thickness ResizeBorderThickness
        {
            get { return (Thickness)this.GetValue(ResizeBorderThicknessProperty); }
            set { this.SetValue(ResizeBorderThicknessProperty, value); }
        }

        /// <summary>
        /// Using a DependencyProperty as the backing store for ResizeBorderTickness.  This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty ResizeBorderThicknessProperty =
            DependencyProperty.Register("ResizeBorderThickness", typeof(Thickness), typeof(RibbonWindow), new UIPropertyMetadata(new Thickness(8D)));

        /// <summary>
        /// Gets or sets glass border thickness
        /// </summary>
        public Thickness GlassFrameThickness
        {
            get { return (Thickness)this.GetValue(GlassFrameThicknessProperty); }
            set { this.SetValue(GlassFrameThicknessProperty, value); }
        }

        /// <summary>
        /// Using a DependencyProperty as the backing store for GlassFrameThickness.  This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty GlassFrameThicknessProperty =
            DependencyProperty.Register("GlassFrameThickness", typeof(Thickness), typeof(RibbonWindow), new UIPropertyMetadata(new Thickness(0D)));

        /// <summary>
        /// Gets or sets corner radius 
        /// </summary>
        public CornerRadius CornerRadius
        {
            get { return (CornerRadius)this.GetValue(CornerRadiusProperty); }
            set { this.SetValue(CornerRadiusProperty, value); }
        }

        /// <summary>
        /// Using a DependencyProperty as the backing store for CornerRadius.  This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty CornerRadiusProperty =
            DependencyProperty.Register("CornerRadius", typeof(CornerRadius), typeof(RibbonWindow), new UIPropertyMetadata(new CornerRadius(0D)));

        /// <summary>
        /// Using a DependencyProperty as the backing store for DontUseDwm.  This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty DontUseDwmProperty =
            DependencyProperty.Register("DontUseDwm", typeof(bool), typeof(RibbonWindow), new PropertyMetadata(false, OnDontUseDwmChanged));

        /// <summary>
        ///  Gets or sets whether DWM should be used.
        /// </summary>
        public bool DontUseDwm
        {
            get { return (bool)this.GetValue(DontUseDwmProperty); }
            set { this.SetValue(DontUseDwmProperty, value); }
        }

        /// <summary>
        /// Gets wheter DWM can be used (<see cref="NativeMethods.IsDwmEnabled"/> is true and <see cref="DontUseDwm"/> is false).
        /// </summary>
        public bool CanUseDwm
        {
            get { return (bool)this.GetValue(CanUseDwmProperty); }
            private set { this.SetValue(CanUseDwmPropertyKey, value); }
        }

        private static readonly DependencyPropertyKey CanUseDwmPropertyKey = DependencyProperty.RegisterReadOnly("CanUseDwm", typeof(bool), typeof(RibbonWindow), new PropertyMetadata(true));

        /// <summary>
        /// Using a DependencyProperty as the backing store for CanUseDwm.  This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty CanUseDwmProperty = CanUseDwmPropertyKey.DependencyProperty;

        /// <summary>
        /// Defines if the default window buttons should be used
        /// </summary>
        public bool UseAeroCaptionButtons
        {
            get { return (bool)this.GetValue(UseAeroCaptionButtonsProperty); }
            set { this.SetValue(UseAeroCaptionButtonsProperty, value); }
        }

        /// <summary>
        /// Using a DependencyProperty as the backing store for UseAeroCaptionButtons.  This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty UseAeroCaptionButtonsProperty =
            DependencyProperty.Register("UseAeroCaptionButtons", typeof(bool), typeof(RibbonWindow), new PropertyMetadata(true));

        /// <summary>
        /// Gets or sets whether icon is visible
        /// </summary>
        public bool IsIconVisible
        {
            get { return (bool)this.GetValue(IsIconVisibleProperty); }
            set { this.SetValue(IsIconVisibleProperty, value); }
        }

        /// <summary>
        /// Gets or sets whether icon is visible
        /// </summary>
        public static readonly DependencyProperty IsIconVisibleProperty = DependencyProperty.Register("IsIconVisible", typeof(bool), typeof(RibbonWindow), new UIPropertyMetadata(true));

        // todo check if IsCollapsed and IsAutomaticCollapseEnabled should be reduced to one shared property for RibbonWindow and Ribbon
        /// <summary>
        /// Gets whether window is collapsed
        /// </summary>              
        public bool IsCollapsed
        {
            get { return (bool)this.GetValue(IsCollapsedProperty); }
            set { this.SetValue(IsCollapsedProperty, value); }
        }

        /// <summary>
        /// Using a DependencyProperty as the backing store for IsCollapsed.  
        /// This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty IsCollapsedProperty =
            DependencyProperty.Register("IsCollapsed", typeof(bool),
            typeof(RibbonWindow), new FrameworkPropertyMetadata(false));

        /// <summary>
        /// Defines if the Ribbon should automatically set <see cref="IsCollapsed"/> when the width or height of the owner window drop under <see cref="Ribbon.MinimalVisibleWidth"/> or <see cref="Ribbon.MinimalVisibleHeight"/>
        /// </summary>
        public bool IsAutomaticCollapseEnabled
        {
            get { return (bool)this.GetValue(IsAutomaticCollapseEnabledProperty); }
            set { this.SetValue(IsAutomaticCollapseEnabledProperty, value); }
        }

        /// <summary>
        /// Using a DependencyProperty as the backing store for IsCollapsed.  
        /// This enables animation, styling, binding, etc...
        /// </summary>
        public static readonly DependencyProperty IsAutomaticCollapseEnabledProperty =
            DependencyProperty.Register("IsAutomaticCollapseEnabled", typeof(bool), typeof(RibbonWindow), new PropertyMetadata(true));

        #endregion

        #region Constructors

        /// <summary>
        /// Static constructor
        /// </summary>
        static RibbonWindow()
        {
            StyleProperty.OverrideMetadata(typeof(RibbonWindow), new FrameworkPropertyMetadata(null, OnCoerceStyle));
            DefaultStyleKeyProperty.OverrideMetadata(typeof(RibbonWindow), new FrameworkPropertyMetadata(typeof(RibbonWindow)));
        }

        // Coerce object style
        private static object OnCoerceStyle(DependencyObject d, object basevalue)
        {
            if (basevalue != null)
            {
                return basevalue;
            }

            var frameworkElement = d as FrameworkElement;
            if (frameworkElement != null)
            {
                basevalue = frameworkElement.TryFindResource(typeof(RibbonWindow));
            }

            return basevalue;
        }

        /// <summary>
        /// Default constructor
        /// </summary>
        public RibbonWindow()
        {
            this.SizeChanged += this.OnSizeChanged;

            // WindowChrome initialization has to occur in constructor. Otherwise the load event is fired early.
            this.InitializeWindowChromeBehavior();
        }

        #endregion

        #region Overrides

        /// <summary>
        /// Raises the <see cref="E:System.Windows.Window.SourceInitialized"/> event.
        /// </summary>
        /// <param name="e">An <see cref="T:System.EventArgs"/> that contains the event data.</param>
        protected override void OnSourceInitialized(EventArgs e)
        {
            base.OnSourceInitialized(e);

            this.UpdateCanUseDwm();
        }

        /// <summary>
        /// Initializes the WindowChromeBehavior which is needed to render the custom WindowChrome
        /// </summary>
        private void InitializeWindowChromeBehavior()
        {
            var behavior = new WindowChromeBehavior();
            BindingOperations.SetBinding(behavior, WindowChromeBehavior.CaptionHeightProperty, new Binding { Path = new PropertyPath(RibbonProperties.TitleBarHeightProperty), Source = this });
            BindingOperations.SetBinding(behavior, WindowChromeBehavior.ResizeBorderThicknessProperty, new Binding { Path = new PropertyPath(ResizeBorderThicknessProperty), Source = this });
            BindingOperations.SetBinding(behavior, WindowChromeBehavior.CornerRadiusProperty, new Binding { Path = new PropertyPath(CornerRadiusProperty), Source = this });
            BindingOperations.SetBinding(behavior, WindowChromeBehavior.GlassFrameThicknessProperty, new Binding { Path = new PropertyPath(GlassFrameThicknessProperty), Source = this });
            BindingOperations.SetBinding(behavior, WindowChromeBehavior.UseAeroCaptionButtonsProperty, new Binding { Path = new PropertyPath(UseAeroCaptionButtonsProperty), Source = this });
            Interaction.GetBehaviors(this).Add(behavior);
        }

        #endregion

        private static void OnDontUseDwmChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            var window = d as RibbonWindow;

            window?.UpdateCanUseDwm();
        }

        // Size change to collapse ribbon
        private void OnSizeChanged(object sender, SizeChangedEventArgs e)
        {
            this.MaintainIsCollapsed();
        }

        private void MaintainIsCollapsed()
        {
            if (this.IsAutomaticCollapseEnabled == false)
            {
                return;
            }

            if (this.ActualWidth < Ribbon.MinimalVisibleWidth
                || this.ActualHeight < Ribbon.MinimalVisibleHeight)
            {
                this.IsCollapsed = true;
            }
            else
            {
                this.IsCollapsed = false;
            }
        }

        private void UpdateCanUseDwm()
        {
            this.CanUseDwm = NativeMethods.IsDwmEnabled()
                          && this.DontUseDwm == false;
        }

        /// <summary>
        /// When overridden in a derived class, is invoked whenever application code or internal processes call <see cref="M:System.Windows.FrameworkElement.ApplyTemplate"/>.
        /// </summary>
        public override void OnApplyTemplate()
        {
            base.OnApplyTemplate();

            this.UpdateCanUseDwm();

            if (this.iconImage != null)
            {
                this.iconImage.MouseDown -= this.HandleIconMouseDown;
            }

            if (this.WindowCommands == null)
            {
                this.WindowCommands = new WindowCommands();
            }

            this.iconImage = this.GetPart<FrameworkElement>(PART_Icon);

            if (this.iconImage != null)
            {
                this.iconImage.MouseDown += this.HandleIconMouseDown;
            }

            this.GetPart<UIElement>(PART_Icon)?.SetValue(WindowChrome.IsHitTestVisibleInChromeProperty, true);
            this.GetPart<UIElement>(PART_WindowCommands)?.SetValue(WindowChrome.IsHitTestVisibleInChromeProperty, true);
        }

        /// <summary>
        /// Raises the <see cref="E:System.Windows.Window.StateChanged"/> event.
        /// </summary>
        /// <param name="e">An <see cref="T:System.EventArgs"/> that contains the event data.</param>
        protected override void OnStateChanged(EventArgs e)
        {
            this.WindowCommands?.RefreshMaximizeIconState();

            base.OnStateChanged(e);
        }

        private void HandleIconMouseDown(object sender, MouseButtonEventArgs e)
        {
            switch (e.ChangedButton)
            {
                case MouseButton.Left:
                    if (e.ClickCount == 1)
                    {
                        e.Handled = true;

                        WindowSteeringHelper.ShowSystemMenuPhysicalCoordinates(this, e, this.PointToScreen(new Point(0, RibbonProperties.GetTitleBarHeight(this))));
                    }
                    else if (e.ClickCount == 2)
                    {
                        e.Handled = true;

                        this.Close();
                    }
                    break;

                case MouseButton.Right:
                    e.Handled = true;

                    this.RunInDispatcherAsync(() =>
                                              {
                                                  WindowSteeringHelper.ShowSystemMenuPhysicalCoordinates(this, e);
                                              });
                    break;
            }
        }

        /// <summary>
        /// Gets the template child with the given name.
        /// </summary>
        /// <typeparam name="T">The interface type inheirted from DependencyObject.</typeparam>
        /// <param name="name">The name of the template child.</param>
        internal T GetPart<T>(string name)
            where T : DependencyObject
        {
            return this.GetTemplateChild(name) as T;
        }
    }
}