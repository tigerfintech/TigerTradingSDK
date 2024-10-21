//
//  TBStockWatchListIndexChangeView.h
//  Stock
//
//  Created by PXJ on 2020/7/24.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBView.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockWatchListIndexChangeView : TBView
-(void)updateDataWithDic:(NSDictionary *)dic;
- (void)changeAppColorStyle;
- (void)updateFrame;
@end

NS_ASSUME_NONNULL_END
