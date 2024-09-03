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
#import "TBKNavigationMode.h"

/**
 * This object bundles up a set of parameters and ships them off
 * to TTBasicNavigator's openURLAction method. This object is designed with the chaining principle
 * in mind. Once you've created a TBKURLAction object, you can apply any other property to the
 * object via the apply* methods. Each of these methods returns self, allowing you to chain them.
 *
 * Example:
 * [[TBKURLAction actionWithURLPath:@"tt://some/path"] applyAnimated:YES];
 * Create an autoreleased URL action object with the path @"tt://some/path" that is animated.
 *
 * For the default values, see the apply method documentation below.
 */
@interface TBKURLAction : NSObject

@property (nonatomic, copy)   NSString*     urlPath;
@property (nonatomic, copy)   NSString*     parentURLPath;
@property (nonatomic, copy)   NSDictionary* query;
@property (nonatomic, copy)   NSDictionary* state;
@property (nonatomic, assign) BOOL          animated;
@property (nonatomic, assign) BOOL          withDelay;
@property (nonatomic, assign) CGRect        sourceRect;
@property (nonatomic, strong) UIView*       sourceView;
@property (nonatomic, strong) UIBarButtonItem* sourceButton;
@property (nonatomic, assign) UIViewAnimationTransition transition;
@property (nonatomic, assign) TBKNavigationMode navigationMode;

/**
 * Create an autoreleased TBKURLAction object.
 */
+ (id)action;

/**
 * Create an autoreleased TBKURLAction object with a URL path.
 */
+ (id)actionWithURLPath:(NSString*)urlPath;

/**
 * Initialize a TBKURLAction object with a URL path.
 *
 * Designated initializer.
 */
- (id)initWithURLPath:(NSString*)urlPath;

- (id)init;

/**
 * @default nil
 */
- (TBKURLAction*)applyParentURLPath:(NSString*)parentURLPath;

/**
 * @default nil
 */
- (TBKURLAction*)applyQuery:(NSDictionary*)query;

/**
 * @default nil
 */
- (TBKURLAction*)applyState:(NSDictionary*)state;

/**
 * @default NO
 */
- (TBKURLAction*)applyAnimated:(BOOL)animated;

/**
 * @default NO
 */
- (TBKURLAction*)applyWithDelay:(BOOL)withDelay;

/**
 * @default CGRectZero
 */
- (TBKURLAction*)applySourceRect:(CGRect)sourceRect;

/**
 * @default nil
 */
- (TBKURLAction*)applySourceView:(UIView*)sourceView;

/**
 * @default nil
 */
- (TBKURLAction*)applySourceButton:(UIBarButtonItem*)sourceButton;

/**
 * @default UIViewAnimationTransitionNone
 */
- (TBKURLAction*)applyTransition:(UIViewAnimationTransition)transition;

- (TBKURLAction*)applyNavigationMode:(TBKNavigationMode)navigationMode;

@end
