//
//  TBTradeMarkModel.h
//  Stock
//
//  Created by dull grass on 2019/12/12.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeMarkItemModel : JSONModel

@property (nonatomic, copy) NSString *type;
@property (nonatomic, assign) NSTimeInterval timestamp;

@end

@protocol TBTradeMarkItemModel <NSObject>

@end
@interface TBTradeMarkModel : JSONModel

@property (nonatomic, copy) NSArray<TBTradeMarkItemModel> *items;

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSTimeInterval serverTime;
@property (nonatomic, copy) NSString *msg;

@end

@interface TBTradeMarkOmnibusModel : JSONModel

@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, assign) NSTimeInterval timestamp;

@property (nonatomic, copy) NSArray<TBTradeMarkItemModel> *data;

@end

NS_ASSUME_NONNULL_END
