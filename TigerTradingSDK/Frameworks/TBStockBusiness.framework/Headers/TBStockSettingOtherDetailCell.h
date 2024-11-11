//
//  TBStockSettingOtherDetailCell.h
//  Stock
//
//  Created by zhenglanchun on 2021/6/15.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockSettingOtherDetailCellItem : TBTableViewCellItem
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSDictionary *query;
@property (nonatomic, copy) NSString *behaviorType;
@property (nonatomic, copy) NSString *behaviorName;
@end

@interface TBStockSettingOtherDetailCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
