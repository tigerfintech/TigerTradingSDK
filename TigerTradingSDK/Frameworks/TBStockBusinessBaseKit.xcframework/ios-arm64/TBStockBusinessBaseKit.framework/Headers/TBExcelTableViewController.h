//
//  TBTableExcelViewController.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/5.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewController.h>
@class TBExcelTableConfigOptions;

NS_ASSUME_NONNULL_BEGIN

@interface TBExcelTableViewController : TBTableViewController
{
    NSMutableArray *_items;
}
/// 二维数组
@property (atomic, strong) NSMutableArray *items;
/// didScroll时发送通知的key，为了不重复，取自身实例的值
@property (nonatomic, copy) NSString * notificationId;

@property (nonatomic, strong) TBExcelTableConfigOptions *configOption;

@end

NS_ASSUME_NONNULL_END
