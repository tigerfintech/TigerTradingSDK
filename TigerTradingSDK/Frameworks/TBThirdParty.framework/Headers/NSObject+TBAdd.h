//
//  NSObject+TBAdd.h
//  dsbridge
//
//  Created by linbingjie on 2020/4/9.
//  Copyright © 2020 杜文. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Common tasks for NSObject.
 */
@interface NSObject (TBAdd)


#pragma mark - Sending messages with variable parameters
///=============================================================================
/// @name Sending messages with variable parameters
///=============================================================================

/**
 Sends a specified message to the receiver and returns the result of the message.
 
 @param sel    A selector identifying the message to send. If the selector is
               NULL or unrecognized, an NSInvalidArgumentException is raised.
 
 @param ...    Variable parameter list. Parameters type must correspond to the
               selector's method declaration, or unexpected results may occur.
               It doesn't support union or struct which is larger than 256 bytes.
 
 @return       An object that is the result of the message.
 
 @discussion   The selector's return value will be wrap as NSNumber or NSValue
               if the selector's `return type` is not object. It always returns nil
               if the selector's `return type` is void.
 
 Sample Code:
 
     // no variable args
     [view performSelectorWithArgs:@selector(removeFromSuperView)];
     
     // variable arg is not object
     [view performSelectorWithArgs:@selector(setCenter:), CGPointMake(0, 0)];
     
     // perform and return object
     UIImage *image = [UIImage.class performSelectorWithArgs:@selector(imageWithData:scale:), data, 2.0];
     
     // perform and return wrapped number
     NSNumber *lengthValue = [@"hello" performSelectorWithArgs:@selector(length)];
     NSUInteger length = lengthValue.unsignedIntegerValue;
     
     // perform and return wrapped struct
     NSValue *frameValue = [view performSelectorWithArgs:@selector(frame)];
     CGRect frame = frameValue.CGRectValue;
 */
- (nullable id)tb_performSelectorWithArgs:(SEL)sel, ...;

- (void)setAssociateValue:(id)value withKey:(void *)key;

+ (BOOL)swizzleInstanceMethod:(SEL)originalSel with:(SEL)newSel;

- (id)getAssociatedValueForKey:(void *)key;

+ (NSString *)className;

- (NSString *)className;
@end

NS_ASSUME_NONNULL_END
