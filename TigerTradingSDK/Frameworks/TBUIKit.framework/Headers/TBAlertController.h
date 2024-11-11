//
//  TBAlertController.h
//  Stock
//
//  Created by chenxin on 2018/4/19.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, TBAlertActionStyle) {
    TBAlertActionStyleDefault = UIAlertActionStyleDefault,
    TBAlertActionStyleCancel = UIAlertActionStyleCancel,
};

/*

@interface TBAlertAction : UIAlertAction

+ (instancetype)actionWithTitle:(NSString *)title style:(TBAlertActionStyle)style handler:(void (^)(TBAlertAction *action))handler;

@end

@interface TBAlertController : UIAlertController

+ (instancetype)alertControllerWithTitle:(NSString *)title message:(NSString *)message;

@end

*/

@interface TBAlertAction : NSObject

@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) TBAlertActionStyle style;
@property (nonatomic, getter=isEnabled) BOOL enabled;

+ (instancetype)actionWithTitle:(NSString *)title style:(TBAlertActionStyle)style handler:(void (^)(TBAlertAction *action))handler;

@end

@interface TBAlertController : UIViewController

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, strong) UIView *accessoryView;
@property (nonatomic, assign) NSTextAlignment messageAlignment;

- (void)addAction:(TBAlertAction *)action;

+ (instancetype)alertControllerWithTitle:(NSString *)title message:(NSString *)message;

+ (void)showWithTitle:(NSString *)title message:(NSString *)message buttonTitle:(NSString *)buttonTitle handler:(void (^)(TBAlertAction *action))handler;

- (CGFloat)accessoryViewMaxWidth;
- (CGFloat)accessoryViewMaxHeight;

@end
