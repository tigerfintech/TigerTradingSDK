//
//  TBMessageFormSheetViewController.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2023/2/13.
//

#import <TBUIKit/TBListTableViewController.h>
@class TBTableViewCellItem, MZFormSheetPresentationViewController;

NS_ASSUME_NONNULL_BEGIN

@interface TBMessageFormSheetViewController : TBListTableViewController

+ (MZFormSheetPresentationViewController *)displayMessageFormDisplayItems:(NSArray<NSArray<TBTableViewCellItem *> *> *)displayItems
                                                             confirmTitle:(NSString *)confirmTitle
                                                             confirmBlock:(dispatch_block_t _Nullable)confirmBlock;

@end

NS_ASSUME_NONNULL_END
