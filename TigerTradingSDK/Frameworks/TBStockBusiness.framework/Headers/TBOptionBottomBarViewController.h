//
//  TBOptionBottomBarViewController.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2022/1/24.
//

#import <TBUIKit/TBListTableViewController.h>
@class MZFormSheetPresentationViewController;
#import "TBStockDetailBottomTabBar.h"
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionBottomBarViewController : TBListTableViewController
+ (MZFormSheetPresentationViewController *)MZOptionBottomVcIsIndex:(BOOL)isIndex
                                                            market:(NSString *)market
                                                              back:(void (^)(TBStockBottomBarEventType type,BOOL isLock))backSelect;
@end

NS_ASSUME_NONNULL_END
