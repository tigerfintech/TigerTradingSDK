//
//  TBOptionRankingListViewController.h
//  AFNetworking
//
//  Created by 王昌阳 on 2023/8/7.
//

#import <TBStockbusinessBaseKit/TBExcelTableViewController.h>
@class TBOptionTabRankModel, TBOptionRankTypeModel;
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSUInteger, kTBOptionRankingListType) {
    kTBOptionRankingListTypeDetailPage = 0,
    kTBOptionRankingListTypeHomePage,
};

@interface TBOptionRankingListViewController : TBExcelTableViewController

@property (nonatomic, assign) BOOL isLandscape;
@property (nonatomic, strong) UIButton *rotateBtn;

@property (nonatomic, assign) kTBOptionRankingListType listType;

@property (nonatomic, strong) TBOptionTabRankModel *currentRankModel;

@property (nonatomic, strong) TBOptionRankTypeModel *selectedRankModel;

- (void)reloadDisplayItemsView:(TBOptionTabRankModel *)rankModel;

@property (nonatomic, copy) void (^selectRankBlock)(TBOptionRankTypeModel *selectedRank);

@end

NS_ASSUME_NONNULL_END
