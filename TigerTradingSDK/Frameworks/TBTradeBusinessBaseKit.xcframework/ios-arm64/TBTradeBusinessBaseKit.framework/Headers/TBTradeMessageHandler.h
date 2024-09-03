//
//  TBTradeMessageHandler.h
//  TBTradeBusiness
//
//  Created by swordzhou on 3/27/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeMessageHandler : NSObject

@property (nonatomic, assign) BOOL hasReadNewNewspaper;         ///< 是否已读更新的早晚报
@property (nonatomic, assign) NSTimeInterval newNewspaperTime;  ///< 早晚报更新时间

- (BOOL)hasUnreadTradeMessage;

- (void)fetchUnreadMessage:(void(^)(BOOL success, NSInteger unreadMessageTotal, NSInteger blacklistTotal, NSInteger unreadPortfolioMessageTotal))completion;

- (void)fetchNewspaperStatus:(void(^)(BOOL success, BOOL hasReadNewNewspaper, NSTimeInterval newNewspaperTime))completion;

@end

NS_ASSUME_NONNULL_END
