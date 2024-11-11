//
//  TBLaunchConfigTestSwitchViewController.h
//  TBInitializeKit
//
//  Created by zhengzhiwen on 2024/3/4.
//

#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBLaunchConfigTestSwitchViewController : TBListTableViewController

//@property (nonatomic, strong) TBStockAttachSwitchCellItem *configTestCellItem;
//@property (nonatomic, strong) TBStockAttachSwitchCellItem *traceTestCellItem;
//@property (nonatomic, strong) TBStockAttachSwitchCellItem *logTestCellItem;
//@property (nonatomic, strong) TBStockAttachSwitchCellItem *recordTestCellItem;
//@property (nonatomic, strong) TBStockAttachSwitchCellItem *crashTestCellItem;
//@property (nonatomic, strong) TBStockAttachSwitchCellItem *patchTestCellItem;
//@property (nonatomic, strong) TBStockAttachSwitchCellItem *lagTestCellItem;
//@property (nonatomic, strong) TBStockAttachSwitchCellItem *coldTestCellItem;

+ (BOOL)isConfigTestCrash;
+ (BOOL)isTrachTestCrash;
//+ (BOOL)is


@end

NS_ASSUME_NONNULL_END
