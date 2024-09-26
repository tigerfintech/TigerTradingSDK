//
//  TBMarketOptionRankDetailViewController.h
//  Stock
//
//  Created by JustLee on 2021/3/1.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMarketOptionRankDetailViewController : TBBaseViewController

@property (nonatomic, copy) NSString *market;
@property (nonatomic, assign) BOOL hiddenNav;
@property (nonatomic, copy) NSString *selectedRankType;

@end

NS_ASSUME_NONNULL_END
