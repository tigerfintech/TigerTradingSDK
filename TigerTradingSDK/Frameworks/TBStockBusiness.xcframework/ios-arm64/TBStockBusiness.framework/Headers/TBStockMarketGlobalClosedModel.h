//
//  TBStockMarketGlobalClosedModel.h
//  Stock
//
//  Created by luopengfei on 2019/1/15.
//  Copyright © 2019年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBStockMarketGlobalClosedItemModel <NSObject>
@end
@interface TBStockMarketGlobalClosedItemModel : JSONModel
@property (nonatomic, assign) NSTimeInterval beginTime;
@property (nonatomic, assign) NSTimeInterval endTime;

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *closedStatus;
@property (nonatomic, copy) NSString *closedID;

@property (nonatomic, readonly) NSString *itemPromptString;

@end

@interface TBStockMarketGlobalClosedModel : JSONModel

@property (nonatomic, strong) NSNumber *ret;
@property (nonatomic, assign) NSTimeInterval serverTime;

@property (nonatomic, copy) NSArray<TBStockMarketGlobalClosedItemModel> *items;

@property (nonatomic, readonly) NSString *promptString;

/**
  简要休市提示
 */
@property (nonatomic, readonly) NSString *briefPromptString;

@property (nonatomic, readonly) NSString *promptKeyString;


@end

@protocol TBStockMarketWatchListItemNoticeModel <NSObject>
@end
@interface TBStockMarketWatchListItemNoticeModel : JSONModel

@property (nonatomic, copy) NSString *type;

@property (nonatomic, copy) NSString *outsideTitle;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *content;

@property (nonatomic, copy) NSString *noticeID;

@property (nonatomic, assign, getter=isRead) BOOL read;

@end


@interface TBStockMarketWatchListNoticeModel : JSONModel

@property (nonatomic, strong) NSNumber *ret;
@property (nonatomic, assign) NSTimeInterval serverTime;


@property (nonatomic, copy) NSArray<TBStockMarketWatchListItemNoticeModel> *items;

@end



NS_ASSUME_NONNULL_END
