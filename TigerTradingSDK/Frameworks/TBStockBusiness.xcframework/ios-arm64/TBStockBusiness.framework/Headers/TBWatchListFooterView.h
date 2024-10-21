//
//  TBWatchListFooterView.h
//  Stock
//
//  Created by 王灵博 on 2020/4/29.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol  TBWatchListFooterDelegate <NSObject>

- (void)watchlistOnTappedSearchAndAddStock;

@end

@interface TBWatchListFooterView : UIView

@property(nonatomic, copy)NSString *market;
@property(nonatomic,weak)id<TBWatchListFooterDelegate>delegate;

- (UIButton *)getAddStockBtn;

-(void)showHkStockHintViewWithSelectGroup:(NSInteger)selectgroup withStockCount:(NSInteger)hkstockCount withLv0:(BOOL)lv0;
-(void)showSelectLikeStockViewIsLandScapeMode:(BOOL)isLandScape;

-(void)hiddenwHkStockHintView;
-(void)hiddenSelectLikeStockView;

- (void)updateHeight;
- (void)updateTheme;

@end

NS_ASSUME_NONNULL_END
