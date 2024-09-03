//
//  TBWatchListParamObject.h
//  TBStockBusiness
//
//  Created by zhengzhiwen on 2021/6/24.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchListParamObject : JSONModel

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *nameCN;

/// 为行情添加埋点，用于优化股票搜索
@property (nonatomic, copy) NSString *sid;


@end

NS_ASSUME_NONNULL_END
