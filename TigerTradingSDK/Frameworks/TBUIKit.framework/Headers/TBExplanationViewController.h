//
//  TBExplanationViewController.h
//  TBUIKit
//
//  Created by swordzhou on 2022/8/11.
//

#import "TBListTableViewController.h"

NS_ASSUME_NONNULL_BEGIN

@class TBIndicatorExplanationModel;

@interface TBExplanationViewController : TBListTableViewController

@property (nonatomic, strong) void(^dismissBlock)(void);

- (instancetype)initWithGridIndicators:(NSArray<NSArray<TBIndicatorExplanationModel *> *> *)gridIndicators
                            indicators:(NSArray<TBIndicatorExplanationModel *>*)indicators
                        linkIndicators:(NSArray<TBIndicatorExplanationModel *>*)linkIndicators;

@end

NS_ASSUME_NONNULL_END
