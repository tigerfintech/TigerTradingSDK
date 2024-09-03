//
//  TBOptionChainRolloverModel.h
//  TBStockBusinessBaseKit
//
//  Created by zlc on 2023/12/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainRolloverModel : NSObject

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *expiry;
@property (nonatomic, strong, nullable) NSNumber *latestPrice;
@property (nonatomic, strong, nullable) NSNumber *askPrice;
@property (nonatomic, strong, nullable) NSNumber *bidPrice;
@property (nonatomic, assign) BOOL isIndex;

@end

NS_ASSUME_NONNULL_END
