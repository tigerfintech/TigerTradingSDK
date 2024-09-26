//
//  TBBoardListTableCellItem.h
//  Stock
//
//  Created by liwt on 11/4/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>
#import "TBAStockBoradItemView.h"



@interface TBBoardListTableCellItem : TBTableViewCellItem
@property (nonatomic, copy) NSString *marketType;
@property (nonatomic, copy) NSArray *itemArray;

@property (nonatomic, assign) BOOL hideBottomLine;

- (TBBoardListTableCellItem *) applyItemArray:(NSArray *)itemArray;

@end


@interface TBBoardListTableCell : TBTableViewCell

@property (nonatomic, strong) UILabel *nameLabel;
@property (nonatomic, strong) UILabel *changeRateLabel;
@property (nonatomic, strong) UILabel *topStockLabel;
@property (nonatomic, strong) UILabel *topStockChangeRateLabel;
@property (nonatomic, strong) UIView *bottomLine;

@end
