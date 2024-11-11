//
//  TBOptionPickPriceTimeViewController.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2021/11/23.
//

#import <TBUIKit/TBListTableViewController.h>
#import "TBOptionPickListCell.h"
#import "TBOptionPickModel.h"
#import <TBUIKit/MZFormSheetPresentationViewController.h>
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionPickPriceTimeViewController : TBListTableViewController
@property (nonatomic, copy) NSString *picktitle;
@property (nonatomic, strong) NSArray *listArray;
@property (nonatomic, copy) void (^backSelect)(NSInteger index,NSString *displayTitle,TBOptionPickListCellItem *item);
+ (MZFormSheetPresentationViewController *)MZPickTitle:(NSString *)pickTitle listArray:(NSArray *)listArray type:(TBOptionPickListType)type backSelect:(void (^)(NSInteger index,NSString *displayTitle,TBOptionPickListCellItem *item))backSelect;
@end

NS_ASSUME_NONNULL_END
