//
//  TBBottomToastView.h
//  TBToolsKit
//
//  Created by chenxin on 2023/4/19.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBBottomToastViewType) {
    TBBottomToastViewTypeNormal, // 普通浮动条
    TBBottomToastViewTypeWithIcon, // 带图片的浮动条
};

typedef NS_ENUM(NSUInteger, TBBottomToastViewIconType) {
    TBBottomToastViewIconTypeNormal, // 普通Icon
    TBBottomToastViewIconTypeLive, // 直播Icon
};

typedef void (^TBBottomToastViewBlock)(void);

/*
 在页面底部展示的物料浮动条
 */
@interface TBBottomToastView : UIView

// type=TBBottomToastViewTypeWithIcon时需要设置
@property (nonatomic, assign) TBBottomToastViewIconType iconType;

@property (nonatomic, strong) TBBottomToastViewBlock jumpBlock;
@property (nonatomic, strong) TBBottomToastViewBlock closeBlock;

- (instancetype)initWithType:(TBBottomToastViewType)type title:(NSString *)title buttonTitle:(nullable NSString *)buttonTitle;

- (void)showInView:(UIView *)view bottomOffset:(CGFloat)bottomOffset;

@end

NS_ASSUME_NONNULL_END
