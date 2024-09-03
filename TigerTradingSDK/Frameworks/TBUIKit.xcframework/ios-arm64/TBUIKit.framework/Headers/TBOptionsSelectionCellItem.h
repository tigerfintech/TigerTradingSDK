//
//  TBOptionsSelectionCellItem.h
//  TBTradeBusiness
//
//  Created by swordzhou on 10/12/23.
//

#import "TBTableViewCellItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionsSelectionCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *title;       //左侧title
@property (nonatomic, copy) NSString *text;        //右侧文案

@property (nonatomic, assign) CGSize borderSize;   //Defult (198, 36)
@property (nonatomic, assign) NSTextAlignment textAlignment;  // Default:NSTextAlignmentLeft
@property (nonatomic, assign) BOOL disable;        /// 不允许修改

@property (nonatomic, assign) BOOL showAlert;      /// Default:NO
@property (nonatomic, assign) BOOL showBottomLine; /// Default:NO
@property (nonatomic, assign) BOOL borderEnable;   /// Default:YES

@property (nonatomic, strong) void(^showOptionsSelectBlock)(void);

@property (nonatomic, strong) UIFont *textFont;             /// Default: FONTO(14)
@property (nonatomic, strong) UIFont *disabledTextFont;     /// Default: FONTO(14)

@property (nonatomic, strong) UIColor *titleTextColor;      /// 左侧标题颜色 Default:B2
@property (nonatomic, strong) UIColor *textColor;           /// 右侧文案颜色 Default:B1
@property (nonatomic, strong) UIColor *disabledTextColor;   /// 右侧文案不可点击颜色 Default:B3

@property (nonatomic, strong) void(^alertInfoBlock)(void);

@end

NS_ASSUME_NONNULL_END
