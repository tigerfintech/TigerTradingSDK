//
//  TBOptionChainWidthViewController.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/4/20.
//

#import <TBUIKit/TBListTableViewController.h>
#import "TBOptionChainWidthCell.h"
#import <TBUIKit/MZFormSheetPresentationViewController+MZStyle.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainWidthViewController : TBListTableViewController

@property (nonatomic, copy) NSString *pickTitle;
@property (nonatomic, copy) NSArray *listArray;
@property (nonatomic, copy) void (^backSelect)(TBOptionChainWidthCellItem *item);

+ (MZFormSheetPresentationViewController *)MZPickTitle:(NSString *)pickTitle listArray:(NSArray *)listArray  backSelect:(void (^)(TBOptionChainWidthCellItem * _Nonnull))backSelect;
- (void)reloadTableView;

@end

NS_ASSUME_NONNULL_END
