//
//  TBOrderListSummaryViewController.h
//  Stock
//
//  Created by 王昌阳 on 2020/10/16.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBNaviSegmentedControlViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOrderListSummaryViewController : TBNaviSegmentedControlViewController
@property (nonatomic, copy) NSString *segType;  ///< 证券 或 期货

@end

NS_ASSUME_NONNULL_END
