//
//  TBOptionRankHeaderCell.h
//  Stock
//
//  Created by 王灵博 on 2021/7/29.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionRankHeaderCell : TBTableViewCell

@end

@interface TBOptionRankHeaderCellItem : TBTableViewCellItem

@property(nonatomic, copy)NSString *key;

@property(nonatomic, copy)NSString *timeStr;

@property(nonatomic, copy)NSString *market;

@end

NS_ASSUME_NONNULL_END
