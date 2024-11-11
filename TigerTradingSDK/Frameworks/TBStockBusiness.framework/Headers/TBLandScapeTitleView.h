//
//  TBLandScapeTitleView.h
//  Stock
//
//  Created by dull grass on 2019/12/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,TBLandScapeBackClickMode) {
    TBLandScapeClickBack,       //!< 返回
    TBLandScapeClickLand,      //!< 竖屏
    TBLandScapeClickSetting,      //!< 设置
    TBLandScapeClickCollege,    //!< 学院
    TBLandScapeClickRefresh,    //!< 刷新
};

typedef void(^LandScapeBlock)(TBLandScapeBackClickMode clickMode);

@interface TBLandScapeTitleView : UIView

@property (nonatomic, strong) UIButton *settingBtn;
@property (nonatomic, strong) void(^handleTOptionBtnAction)(BOOL);

@property (nonatomic, copy) LandScapeBlock callBack;

- (instancetype)initWithFrame:(CGRect)frame market:(NSString *)market;

- (void)updateLandScapeTitle:(NSString *)symbol
                       price:(NSString *)price
                 priceChange:(NSString *)priceChange
                      volume:(NSString *)volume;

@end

NS_ASSUME_NONNULL_END
