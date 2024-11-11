//
//  TBOptionRankViewController.h
//  Stock
//
//  Created by 王灵博 on 2021/7/23.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN
static NSString *const kOptionRankOnlyOptionNotification = @"kOptionRankOnlyOptionNotification";
@interface TBOptionRankViewController : TBBaseViewController
@property(nonatomic, copy)NSString *market;
@property (nonatomic, assign)BOOL openFirstStock;
- (void)reloadAllData;
@end

NS_ASSUME_NONNULL_END
