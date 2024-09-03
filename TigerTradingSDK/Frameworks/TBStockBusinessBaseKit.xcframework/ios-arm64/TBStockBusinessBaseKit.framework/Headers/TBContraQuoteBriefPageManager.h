//
//  TBContraQuoteBriefPageManager.h
//  TBStockBusiness
//
//  Created by mashanli on 2024/1/4.
//

#import <Foundation/Foundation.h>
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBContraQuoteBriefPageManager : NSObject

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSMutableArray *cellItems;
@property (nonatomic, copy) void(^updateCellCount)(void);//cell个数变化

- (instancetype)initWithSymbol:(NSString *)symbol
                        market:(NSString *)market
                       secType:(NSString *)secType
                          name:(NSString *)name;

- (void)handleActionForCell:(TBTableViewCell *)cell object:(TBTableViewCellItem *)item info:(id)info;

- (void)refreshAllData;
- (void)subscribeTopic;
- (void)unsubscribeTopic;

- (void)invalidateRefreshTimer;
- (void)validateRefreshTimer;

@end

NS_ASSUME_NONNULL_END
