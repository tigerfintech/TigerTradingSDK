//
//  TBOptionChainAskBidView.h
//  Stock
//
//  Created by mashanli on 2023/4/27.
//  Copyright © 2023年 com.tigerbrokers. All rights reserved.
//

@class TBOptionChainAskBidRetModel;

@interface TBOptionChainAskBidView : UIView

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, strong) TBOptionChainAskBidRetModel *model;

@end
