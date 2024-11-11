//
//  TBStockDetailRefreshHeaderView.h
//  Stock
//
//  Created by Pengfei_Luo on 16/9/13.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBRefreshNormalHeader.h>


@interface TBStockDetailRefreshHeaderView : TBRefreshNormalHeader
// 状态
@property (nonatomic, copy) NSString *statusTag;
// 时间
@property (nonatomic) long long statusRecordTime;

@end
