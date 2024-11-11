//
//  TBRoundedCornerActionTypeView.h
//  TBTradeBusiness
//
//  Created by zlc on 2023/7/31.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBRoundedCornerActionTypeView : UIView

@property (nonatomic, assign) BOOL disable;
@property (nonatomic, assign) BOOL borderEnable;              // Default:YES

@property (nonatomic, assign) NSTextAlignment textAlignment;  // Default:NSTextAlignmentLeft

@property (nonatomic, copy) NSString *title;

@property (nonatomic, strong, nullable) UIFont *titleFont;
@property (nonatomic, strong, nullable) UIFont *disabledTitleFont;

@property (nonatomic, strong, nullable) UIColor *titleColor;
@property (nonatomic, strong, nullable) UIColor *disabledTitleColor;

@property (nonatomic, copy) void(^tapBlock)(void);

@end

NS_ASSUME_NONNULL_END
