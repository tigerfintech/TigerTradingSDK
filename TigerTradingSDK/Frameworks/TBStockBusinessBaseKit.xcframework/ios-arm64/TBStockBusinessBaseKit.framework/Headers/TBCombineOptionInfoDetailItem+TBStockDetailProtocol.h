//
//  TBCombineOptionInfoDetailItem+TBStockDetailProtocol.h
//  Stock
//
//  Created by mashanli on 2023/6/16.
//  Copyright © 2023年 com.tigerbrokers. All rights reserved.
//

#import "TBCombineOptionInfoDetailItem.h"
#import <TBStockBusinessBaseKit/TBStockDetailViewControllerDelegate.h>

//组合期权详情model的协议
@interface TBCombineOptionInfoDetailItem (TBStockDetailProtocol) <TBStockDetailInfoDataSource>

@end
