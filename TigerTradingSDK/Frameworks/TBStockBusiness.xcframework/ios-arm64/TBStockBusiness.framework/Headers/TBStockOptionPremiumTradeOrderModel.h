//
//  TBStockOptionPremiumTradeOrderModel.h
//  AFNetworking
//
//  Created by zlc on 2024/4/2.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockOptionPremiumTradeOrderModel : JSONModel

@property (nonatomic, copy) NSString *digest;
@property (nonatomic, strong) NSNumber *tweetId;
// author
@property (nonatomic, copy) NSString *authorId;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *avatar;
@property (nonatomic, strong) NSNumber *winRationPercentage;

// orderData
@property (nonatomic, copy) NSString *action;
@property (nonatomic, assign) BOOL openFlag;
@property (nonatomic, strong) NSNumber *avgFillPrice;
@property (nonatomic, strong) NSNumber *createTime;

@end

NS_ASSUME_NONNULL_END
