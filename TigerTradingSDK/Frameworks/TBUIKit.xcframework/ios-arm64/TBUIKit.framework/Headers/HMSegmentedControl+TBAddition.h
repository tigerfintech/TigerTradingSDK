//
//  HMSegmentedControl+TBAddition.h
//  Stock
//
//  Created by donggongfu on 2017/5/3.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBThirdParty/HMSegmentedControl.h>

@interface HMSegmentedControl (TBAddition)

- (void)depositHistoryLooks;
- (HMSegmentedControl *)applyDepositHistoryLooks;

- (void)dividendHistoryLooks;
- (HMSegmentedControl *)applyDividendHistoryLooks;

@end
