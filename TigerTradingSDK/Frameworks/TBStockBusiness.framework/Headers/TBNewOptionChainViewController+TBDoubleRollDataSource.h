//
//  TBNewOptionChainViewController+TBDoubleRollDataSource.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/1/14.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBNewOptionChainViewController.h"
@class TBOptionChainExpireModel;
#import "TBDoubleRollView.h"

NS_ASSUME_NONNULL_BEGIN
 
@interface TBNewOptionChainViewController (TBDoubleRollDataSource) <TBDoubleRollViewDataSource>
- (void)updateDoubleRollView:(TBOptionChainExpireModel *)chainModel;
- (void)updateDoubleRollView:(TBOptionChainExpireModel *)chainModel scrollToStrike:(BOOL)scrollToStrike;
//列表titles
- (NSArray *)opiontViewListTitles;
/// 处理T型长连接数据
/// @param data <#data description#>
- (void)handleMQTTTOptionModeChainDataWithDictionary:(NSDictionary *)dict;
@end

NS_ASSUME_NONNULL_END
