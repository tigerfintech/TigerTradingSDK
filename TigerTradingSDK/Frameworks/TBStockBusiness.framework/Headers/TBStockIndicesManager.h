//
//  TBStockIndicesManager.h
//  TBStockBusiness
//
//  Created by zhenglanchun on 2021/7/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBStockIndicesManagerDelegate;

@interface TBStockIndicesManager : NSObject

@property (nonatomic, weak) id<TBStockIndicesManagerDelegate > delegate;

-(void)fetchStockDetailIndices;

@end

@protocol TBStockIndicesManagerDelegate <NSObject>

@optional

- (void)stockIndicesManagerGetStockDetailBottomIndexInfoArray:(NSArray *)indexArray;

@end

NS_ASSUME_NONNULL_END
