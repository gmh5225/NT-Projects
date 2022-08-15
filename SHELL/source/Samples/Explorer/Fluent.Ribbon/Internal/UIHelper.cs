﻿namespace Fluent.Internal
{
    using System;
    using System.Collections.Generic;
    using System.Windows;
    using System.Windows.Media;

    /// <summary>
    /// Class with helper functions for UI related stuff
    /// </summary>
    internal static class UIHelper
    {
        /// <summary>
        /// Tries to find immediate visual child of type <typeparamref name="T"/> which matches <paramref name="predicate"/>
        /// </summary>
        /// <returns>
        /// The visual child of type <typeparamref name="T"/> that matches <paramref name="predicate"/>. 
        /// Returns <c>null</c> if no child matches.
        /// </returns>
        public static T FindImmediateVisualChild<T>(DependencyObject parent, Predicate<T> predicate)
            where T : DependencyObject
        {
            foreach (var child in GetVisualChildren(parent))
            {
                var obj = child as T;

                if (obj != null
                    && predicate(obj))
                {
                    return obj;
                }
            }

            return null;
        }

        /// <summary>
        /// Gets the first visual child of type TChildItem by walking down the visual tree.
        /// </summary>
        /// <typeparam name="TChildItem">The type of visual child to find.</typeparam>
        /// <param name="parent">The parent element whose visual tree shall be walked down.</param>
        /// <returns>The first element of type TChildItem found in the visual tree is returned. If none is found, null is returned.</returns>
        public static TChildItem FindVisualChild<TChildItem>(DependencyObject parent) where TChildItem : DependencyObject
        {
            foreach (var child in GetVisualChildren(parent))
            {
                var item = child as TChildItem;

                if (item != null)
                {
                    return item;
                }

                var childOfChild = FindVisualChild<TChildItem>(child);
                if (childOfChild != null)
                {
                    return childOfChild;
                }
            }
            return null;
        }

        /// <summary>
        /// Gets all visual children of <paramref name="parent"/>.
        /// </summary>
        /// <returns></returns>
        public static IEnumerable<DependencyObject> GetVisualChildren(DependencyObject parent)
        {
            var visualChildrenCount = VisualTreeHelper.GetChildrenCount(parent);

            for (var i = 0; i < visualChildrenCount; i++)
            {
                var child = VisualTreeHelper.GetChild(parent, i);

                if (child != null)
                {
                    yield return child;
                }
            }
        }

        /// <summary>
        /// Finds the parent control of type <typeparamref name="T"/>.
        /// First looks at the visual tree and then at the logical tree to find the parent.
        /// </summary>
        /// <returns>The found visual/logical parent or null.</returns>
        public static T GetParent<T>(DependencyObject element)
            where T : DependencyObject
        {
            var item = element;

            while (item != null
                && item is T == false)
            {
                item = VisualTreeHelper.GetParent(item);
            }

            if (item == null)
            {
                item = element;

                while (item != null &&
                       item is T == false)
                {
                    item = LogicalTreeHelper.GetParent(item);
                }
            }

            return (T)item;
        }
    }
}