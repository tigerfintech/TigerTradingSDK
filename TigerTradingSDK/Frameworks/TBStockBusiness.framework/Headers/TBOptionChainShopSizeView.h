//
//  TBOptionChainShopSizeView.h
//  Stock
//
//  Created by mashanli on 2024/6/27.
//  Copyright © 2024年 com.tigerbrokers. All rights reserved.
//

@interface TBOptionChainShopSizeView : UIView

@property (nonatomic, assign) NSInteger currentValue;

@property (nonatomic, copy) void(^changeValueBlock)(NSInteger currentValue);

@end
