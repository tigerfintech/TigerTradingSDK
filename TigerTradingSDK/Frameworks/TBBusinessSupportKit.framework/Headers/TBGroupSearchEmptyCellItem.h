//
//  TBGroupSearchEmptyCellItem.h
//  Stock
//
//  Created by yangfan on 2017/5/2.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>

@interface TBGroupSearchEmptyCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString    * emptyText;

@end

@interface TBGroupSearchEmptyCell : TBTableViewCell

@property (nonatomic, strong) UILabel * emptyLabel;

@end
