//
//  TBExcelTableHeaderCell.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/5.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBExcelTableViewProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@interface TBExcelTableHeaderCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSArray<NSDictionary *> *collectArray; // collectionView数据源

+ (CGFloat)cellHeight;

@end

@interface TBExcelTableHeaderCell : TBTableViewCell<TBExcelTablePropertyProtocol>


@end

NS_ASSUME_NONNULL_END
