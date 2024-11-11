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
 * @return the current runtime version of the iPhone OS.
 */
float TBKOSVersion(void);

/**
 * Checks if the run-time version of the OS is at least a certain version.
 */
BOOL TBKRuntimeOSVersionIsAtLeast(float version);

/**
 * Checks if the link-time version of the OS is at least a certain version.
 */
BOOL TBKOSVersionIsAtLeast(float version);

/**
 * @return TRUE if the keyboard is visible.
 */
BOOL TBKIsKeyboardVisible(void);

/**
 * @return TRUE if the device has phone capabilities.
 */
BOOL TBKIsPhoneSupported(void);

/**
 * @return TRUE if the device supports backgrounding
 */
BOOL TBKIsMultiTaskingSupported(void);

/**
 * @return TRUE if the device is iPad.
 */
BOOL TBKIsPad(void);

/**
 * @return the current device orientation.
 */
UIDeviceOrientation TBKDeviceOrientation(void);

/**
 * @return TRUE if the current device orientation is portrait or portrait upside down.
 */
BOOL TBKDeviceOrientationIsPortrait(void);

/**
 * @return TRUE if the current device orientation is landscape left, or landscape right.
 */
BOOL TBKDeviceOrientationIsLandscape(void);

/**
 * @return device full model name in human readable strings
 */
NSString* TBKDeviceModelName(void);

/**
 * On iPhone/iPod touch
 * Checks if the orientation is portrait, landscape left, or landscape right.
 * This helps to ignore upside down and flat orientations.
 *
 * On iPad:
 * Always returns Yes.
 */
BOOL TBKIsSupportedOrientation(UIInterfaceOrientation orientation);

/**
 * @return the rotation transform for a given orientation.
 */
CGAffineTransform TBKRotateTransformForOrientation(UIInterfaceOrientation orientation);

/**
 * @return the application frame with no offset.
 *
 * From the Apple docs:
 * Frame of application screen area in points (i.e. entire screen minus status bar if visible)
 */
CGRect TBKApplicationFrame(void);

/**
 * @return the toolbar height for a given orientation.
 *
 * The toolbar is slightly shorter in landscape.
 */
CGFloat TBKToolbarHeightForOrientation(UIInterfaceOrientation orientation);

/**
 * @return the height of the keyboard for a given orientation.
 */
CGFloat TBKKeyboardHeightForOrientation(UIInterfaceOrientation orientation);

/**
 * @return the space between the edge of the screen and a grouped table cell. Larger on iPad.
 */
CGFloat TBKGroupedTableCellInset(void);

/**
 * A convenient way to show a UIAlertView with a message.
 */
void TBKAlert(NSString* message);

/**
 * Same as TBKAlert but the alert view has no title.
 */
void TBKAlertNoTitle(NSString* message);


///////////////////////////////////////////////////////////////////////////////////////////////////
// Debug logging helpers

#define TBKLOGRECT(rect) \
TBKDEBUGINFO(@"%s x=%f, y=%f, w=%f, h=%f", #rect, rect.origin.x, rect.origin.y, \
rect.size.width, rect.size.height)

#define TBKLOGPOINT(pt) \
TBKDEBUGINFO(@"%s x=%f, y=%f", #pt, pt.x, pt.y)

#define TBKLOGSIZE(size) \
TBKDEBUGINFO(@"%s w=%f, h=%f", #size, size.width, size.height)

#define TBKLOGEDGES(edges) \
TBKDEBUGINFO(@"%s left=%f, right=%f, top=%f, bottom=%f", #edges, edges.left, edges.right, \
edges.top, edges.bottom)

#define TBKLOGHSV(_COLOR) \
TBKDEBUGINFO(@"%s h=%f, s=%f, v=%f", #_COLOR, _COLOR.hue, _COLOR.saturation, _COLOR.value)

#define TBKLOGVIEWS(_VIEW) \
{ for (UIView* view = _VIEW; view; view = view.superview) { TBKDEBUGINFO(@"%@", view); } }


// Dimensions of common iPhone OS Views

/**
 * The standard height of a row in a table view controller.
 * @const 44 pixels
 */
extern const CGFloat tbkkDefaultRowHeight;

/**
 * The standard height of a toolbar in portrait orientation.
 * @const 44 pixels
 */
extern const CGFloat tbkkDefaultPortraitToolbarHeight;

/**
 * The standard height of a toolbar in landscape orientation.
 * @const 33 pixels
 */
extern const CGFloat tbkkDefaultLandscapeToolbarHeight;

/**
 * The standard height of the keyboard in portrait orientation.
 * @const 216 pixels
 */
extern const CGFloat tbkkDefaultPortraitKeyboardHeight;

/**
 * The standard height of the keyboard in landscape orientation.
 * @const 160 pixels
 */
extern const CGFloat tbkkDefaultLandscapeKeyboardHeight;

/**
 * The space between the edge of the screen and the cell edge in grouped table views.
 * @const 10 pixels
 */
extern const CGFloat tbkkGroupedTableCellInset;

/**
 * Deprecated macros for common constants.
 */
#define TBK_ROW_HEIGHT                 tbkkDefaultRowHeight
#define TBK_TOOLBAR_HEIGHT             tbkkDefaultPortraitToolbarHeight
#define TBK_LANDSCAPE_TOOLBAR_HEIGHT   tbkkDefaultLandscapeToolbarHeight

#define TBK_KEYBOARD_HEIGHT                 tbkkDefaultPortraitKeyboardHeight
#define TBK_LANDSCAPE_KEYBOARD_HEIGHT       tbkkDefaultLandscapeKeyboardHeight
#define TBK_IPAD_KEYBOARD_HEIGHT            tbkkDefaultPadPortraitKeyboardHeight
#define TBK_IPAD_LANDSCAPE_KEYBOARD_HEIGHT  tbkkDefaultPadLandscapeKeyboardHeight

// Animation

/**
 * The standard duration length for a transition.
 * @const 0.3 seconds
 */
extern const CGFloat tbkkDefaultTransitionDuration;

/**
 * The standard duration length for a fast transition.
 * @const 0.2 seconds
 */
extern const CGFloat tbkkDefaultFastTransitionDuration;

/**
 * The standard duration length for a flip transition.
 * @const 0.7 seconds
 */
extern const CGFloat tbkkDefaultFlipTransitionDuration;

/**
 * Deprecated macros for common constants.
 */
#define TBK_TRANSITION_DURATION      tbkkDefaultTransitionDuration
#define TBK_FAST_TRANSITION_DURATION tbkkDefaultFastTransitionDuration
#define TBK_FLIP_TRANSITION_DURATION tbkkDefaultFlipTransitionDuration
