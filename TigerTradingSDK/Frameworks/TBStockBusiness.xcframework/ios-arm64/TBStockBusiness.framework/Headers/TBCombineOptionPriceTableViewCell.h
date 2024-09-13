//
//  TBCombineOptionPriceTableViewCell.h
//  Stock
//
//  Created by mashanli on 2023/6/19.
//  Copyright © 2023年 com.tigerbrokers. All rights reserved.
//

#import "TBOptionPriceTableViewCell.h"

@interface TBCombineOptionPriceTableViewCell : TBTableViewCell

@end


@interface TBCombineOptionPriceTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *market;
@property (nonatomic, weak) id<TBOptionPriceTableViewCellDelegate> dataSource;

@end
