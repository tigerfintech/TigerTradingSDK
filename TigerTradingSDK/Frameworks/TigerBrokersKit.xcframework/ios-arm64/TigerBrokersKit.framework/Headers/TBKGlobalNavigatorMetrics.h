//
// Copyright 2009-2011 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * @return the current orientation of the visible view controller.
 */
UIInterfaceOrientation TBKInterfaceOrientation(void);

/**
 * @return the bounds of the screen with device orientation factored in.
 */
CGRect TBKScreenBounds(void);

/**
 * @return the application frame below the navigation bar.
 */
CGRect TBKNavigationFrame(void);

/**
 * @return the application frame below the navigation bar and above a toolbar.
 */
CGRect TBKToolbarNavigationFrame(void);

/**
 * @return the application frame below the navigation bar and above the keyboard.
 */
CGRect TBKKeyboardNavigationFrame(void);

/**
 * @return the height of the area containing the status bar and possibly the in-call status bar.
 */
CGFloat TBKStatusHeight(void);

/**
 * @return the height of the area containing the status bar and navigation bar.
 */
CGFloat TBKBarsHeight(void);

/**
 * @return the height of a toolbar considering the current orientation.
 */
CGFloat TBKToolbarHeight(void);

/**
 * @return the height of the keyboard considering the current orientation.
 */
CGFloat TBKKeyboardHeight(void);
