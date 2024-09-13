//
//  TBOptionRankListViewController.h
//  Stock
//
//  Created by 王灵博 on 2021/7/23.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
#import "TBOptionAnalysisHeader.h"
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionRankListViewController : TBListTableViewController
@property(nonatomic, assign)TBOptionChangeType optionType;
@property(nonatomic, copy)NSString *market;
@property (nonatomic, assign)BOOL openFirstStock;
- (void)cleanData;
- (void)fetchOptionUnusual;
@end

NS_ASSUME_NONNULL_END
