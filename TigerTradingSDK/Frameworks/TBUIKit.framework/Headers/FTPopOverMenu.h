//
//  FTPopOverMenu.h
//  FTPopOverMenu
//
//  Created by liufengting on 16/4/5.
//  Copyright © 2016年 liufengting ( https://github.com/liufengting ). All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  FTPopOverMenuArrowDirection
 */
typedef NS_ENUM(NSUInteger, FTPopOverMenuArrowDirection) {
    // 自动计算
    FTPopOverMenuArrowDirectionAuto = 0,
    /**
     *  Up
     */
    FTPopOverMenuArrowDirectionUp,
    /**
     *  Down
     */
    FTPopOverMenuArrowDirectionDown,
};

/**
 *  FTPopOverMenuDoneBlock
 *
 *  @param selectedIndex SlectedIndex
 */
typedef void (^FTPopOverMenuDoneBlock)(NSInteger selectedIndex);
/**
 *  FTPopOverMenuDismissBlock
 */
typedef void (^FTPopOverMenuDismissBlock)(void);

/**
 *  -----------------------FTPopOverMenuModel-----------------------
 */
@interface FTPopOverMenuModel : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *selectedTextColor;
@property (nonatomic, strong) id image;
@property (nonatomic, assign) BOOL selected;

- (instancetype)initWithTitle:(NSString *)title image:(id)image selected:(BOOL)selected;

- (instancetype)initWithTitle:(NSString *)title textColor:(UIColor *)textColor selectedTextColor:(UIColor *)selectedTextColor image:(id)image selected:(BOOL)selected;

@end

/**
 *  -----------------------FTPopOverMenuConfiguration-----------------------
 */

typedef NS_ENUM(NSUInteger, FTPopOverMenuAnimationStyle) {
    FTPopOverMenuAnimationStyleDefault = 0, //正常缩放
    FTPopOverMenuAnimationStyleBounces,     //弹性缩放
};

@interface FTPopOverMenuConfiguration : NSObject

@property (nonatomic, assign) CGFloat menuTextMargin;// Default is 6.
@property (nonatomic, assign) CGFloat menuIconMargin;// Default is 6.
@property (nonatomic, assign) CGFloat menuRowHeight;
@property (nonatomic, assign) CGFloat menuTableHeight;
@property (nonatomic, assign) CGFloat menuWidth;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *borderColor;
@property (nonatomic, assign) CGFloat borderWidth;
@property (nonatomic, strong) UIFont *textFont;
@property (nonatomic, strong) UIFont *selectedTextFont;
@property (nonatomic, assign) CGFloat tableCornerRadius;
@property (nonatomic, assign) CGFloat tableHorizontalMargin;
@property (nonatomic, assign) NSTextAlignment textAlignment;
@property (nonatomic, assign) BOOL ignoreImageOriginalColor; // Default is 'NO', if sets to 'YES', images color will be same as textColor.
@property (nonatomic, assign) BOOL allowRoundedArrow;        // Default is 'NO', if sets to 'YES', the arrow will be drawn with round corner.
@property (nonatomic, assign) BOOL menuIconIsRight;          // Default is 'NO'
@property (nonatomic, assign) NSTimeInterval animationDuration;
@property (nonatomic, strong) UIColor *selectedTextColor;
@property (nonatomic, strong) UIColor *selectedCellBackgroundColor;
@property (nonatomic, strong) UIColor *separatorColor;
@property (nonatomic, strong) UIColor *shadowColor;
@property (nonatomic, assign) CGFloat shadowOpacity;
@property (nonatomic, assign) CGFloat shadowRadius;
@property (nonatomic, assign) CGFloat shadowOffsetX;
@property (nonatomic, assign) CGFloat shadowOffsetY;
@property (nonatomic, strong) UIColor *coverBackgroundColor;
@property (nonatomic, assign) CGFloat maxDisplayItemCount;
@property (nonatomic, assign) NSTimeInterval dismissDuration; // 如果非0，会在对应秒数后自动消失
@property (nonatomic, assign) BOOL backgroundInteractionEnabled; // 是否允许背景点击交互，默认点击背景弹层消失，后面视图无法接收事件

@property (nonatomic, assign) CGFloat iconImageSize;
@property (nonatomic, assign) FTPopOverMenuAnimationStyle animationStyle;
@property (nonatomic, assign) FTPopOverMenuArrowDirection arrowDirection;///< 箭头方向

@property (nonatomic, strong) UIView *superView;///< 替换 window，支持在自定义键盘上添加弹窗
@property (nonatomic, assign) BOOL allowManyLines;///< 是否允许换行，默认不允许

@property (nonatomic, assign) BOOL menuIconInRightIsFixedMargin; // 图片右侧间距固定，不依赖左侧label的宽度
@property (nonatomic, assign) CGFloat menuIconRightFixedMargin; // 图片右侧间距,在menuIconInRightIsFixedMargin==YES时生效
@property (nonatomic, assign) BOOL isNonSelectedMenuIconHidden; ///< 是否隐藏非选中的icon
/**
 *  defaultConfiguration
 *
 *  @return curren configuration
 */
+ (FTPopOverMenuConfiguration *)defaultConfiguration;

@end
/**
 *  -----------------------FTPopOverMenuCell-----------------------
 */
@interface FTPopOverMenuCell : UITableViewCell

@end
/**
 *  -----------------------FTPopOverMenuView-----------------------
 */
@interface FTPopOverMenuView : UIControl

@end

/**
 *  -----------------------FTPopOverMenu-----------------------
 */
@interface FTPopOverMenu : NSObject

//    menuArray supports following context:
//    1. image name (NSString, only main bundle),
//    2. image (UIImage),
//    3. image remote URL string (NSString),
//    4. image remote URL (NSURL),
//    5. model (FTPopOverMenuModel, select state support)

- (void) showForSender:(UIView *)sender
           senderFrame:(CGRect )senderFrame
              withMenu:(NSArray *)menuArray
        imageNameArray:(NSArray *)imageNameArray
                config:(FTPopOverMenuConfiguration *)config
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

- (void)setupTableViewDelegate:(id<UITableViewDelegate,UITableViewDataSource>)delegate;
- (void)registCell:(UITableViewCell *)cell reuseIdentifier:(NSString *)identifier;
- (void)dismiss;
- (void)scrollTo:(CGFloat)contentOffsetY;

- (CGFloat)tableHeight;
- (CGFloat)tableContentHeight;

/**
 show method with sender without images

 @param sender sender
 @param menuArray menuArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showForSender:(UIView *)sender
         withMenuArray:(NSArray *)menuArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method with sender and image resouce Array

 @param sender sender
 @param menuArray menuArray
 @param imageArray imageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showForSender:(UIView *)sender
         withMenuArray:(NSArray *)menuArray
            imageArray:(NSArray *)imageArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method with sender, image resouce Array and configuration

 @param sender sender
 @param menuArray menuArray
 @param imageArray imageArray
 @param configuration configuration
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showForSender:(UIView *)sender
         withMenuArray:(NSArray *)menuArray
            imageArray:(NSArray *)imageArray
         configuration:(FTPopOverMenuConfiguration *)configuration
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method for barbuttonitems with event without images

 @param event event
 @param menuArray menuArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showFromEvent:(UIEvent *)event
         withMenuArray:(NSArray *)menuArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method for barbuttonitems with event and imageArray

 @param event event
 @param menuArray menuArray
 @param imageArray imageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showFromEvent:(UIEvent *)event
         withMenuArray:(NSArray *)menuArray
            imageArray:(NSArray *)imageArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;


/**
 show method for barbuttonitems with event, imageArray and configuration

 @param event event
 @param menuArray menuArray
 @param imageArray imageArray
 @param configuration configuration
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showFromEvent:(UIEvent *)event
         withMenuArray:(NSArray *)menuArray
            imageArray:(NSArray *)imageArray
         configuration:(FTPopOverMenuConfiguration *)configuration
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;
/**
 show method with SenderFrame without images

 @param senderFrame senderFrame
 @param menuArray menuArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showFromSenderFrame:(CGRect )senderFrame
               withMenuArray:(NSArray *)menuArray
                   doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method with SenderFrame and image resouce Array

 @param senderFrame senderFrame
 @param menuArray menuArray
 @param imageArray imageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showFromSenderFrame:(CGRect )senderFrame
               withMenuArray:(NSArray *)menuArray
                  imageArray:(NSArray *)imageArray
                   doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method with SenderFrame, image resouce Array and configuration
 
 @param senderFrame senderFrame
 @param menuArray menuArray
 @param imageArray imageArray
 @param configuration configuration
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showFromSenderFrame:(CGRect )senderFrame
               withMenuArray:(NSArray *)menuArray
                  imageArray:(NSArray *)imageArray
               configuration:(FTPopOverMenuConfiguration *)configuration
                   doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;
/**
 *  dismiss method
 */
+ (void) dismiss;

@end
