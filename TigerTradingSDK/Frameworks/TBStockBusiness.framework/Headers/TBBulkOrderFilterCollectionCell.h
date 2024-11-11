//
//  TBBulkOrderFilterCollectionCell.h
//  StockBusiness
//
//  Created by mashanli on 2022/10/12.
//  Copyright © 2022 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBBulkOrderFilterCollectionCell: UICollectionViewCell

@property (nonatomic, assign) BOOL isSingle;//是否单选
@property (nonatomic, assign) BOOL isSelected;
@property (nonatomic, copy) NSString *title;

@end

NS_ASSUME_NONNULL_END
