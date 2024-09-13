//
//  TBOptionUtils+tb_option.h
//  Stock
//
//  Created by 王灵博 on 2021/5/31.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBOptionUtils.h"
#import "TBOptionAnalysisHeader.h"
#import <TBBaseKit/TBPhoneUtility.h>
@import ChartKLineView;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionUtils (tb_option)

//存储期权k线类型
+ (void)saveOptionKlineType:(TBLineType)type;
+ (TBLineType)getOptionKlineType;

//存储期权明细展开收起
+ (void)saveOptionDetail:(BOOL)select;
+ (BOOL)getOptionDetail;
@end

NS_ASSUME_NONNULL_END
