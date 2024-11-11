//
//  TBTableViewCell+Excel.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/5.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBExcelTableConfigOptions;
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTableViewCell (Excel)

@property (nonatomic, copy, readonly) NSString * tbNotificationId;
@property (nonatomic, strong, readonly) TBExcelTableConfigOptions * configOption;


- (instancetype)initWithStyle:(UITableViewCellStyle)style
              reuseIdentifier:(NSString *)reuseIdentifier
                       config:(TBExcelTableConfigOptions *)configOption
               notificationId:(NSString *)notificationId;

+ (id)tb_dequeueCellForTableView:(UITableView *)inTableView
                          config:(TBExcelTableConfigOptions *)configOption
              withNotificationId:(NSString *)notificationId;

@end

NS_ASSUME_NONNULL_END
