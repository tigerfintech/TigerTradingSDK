//
//  TBOptionCallPutChoiceView.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/11/16.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class TBOptionChainModel;
UIKIT_EXTERN NSString *const OPITION_LOCK_ARCHIVE_KEY;
UIKIT_EXTERN NSString *const OPITION_TMODE_ARCHIVE_KEY;

@interface TBOptionCallPutChoiceView : UIView

@property (nonatomic, readonly) UIButton *settingBtn;
@property (nonatomic, strong) NSNumber *chainIV;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *strategy;

@property (nonatomic, strong) void(^callPutChoiceBtnSelected)(NSInteger selectedIndex);
@property (nonatomic, strong) void(^handleSettingBtnAction)(void);

//常规形态
- (void)setupNormalView;
//持仓Rollover形态
- (void)setupRolloverView:(NSString *)rolloverText;

@end

NS_ASSUME_NONNULL_END
