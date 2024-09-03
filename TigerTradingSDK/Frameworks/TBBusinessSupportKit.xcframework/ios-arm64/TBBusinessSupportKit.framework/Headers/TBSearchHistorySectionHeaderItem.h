//
//  TBSearchHistorySectionHeaderItem.h
//  Stock
//
//  Created by liwt on 15/1/9.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//


#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>

@interface TBSearchHistorySectionHeaderItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *historyTitle;
@property (nonatomic, copy) NSString *clearHistoryTitle;


- (TBSearchHistorySectionHeaderItem *) applyHistoryLabelTitle:(NSString *)historyTitle;
- (TBSearchHistorySectionHeaderItem *) applyRightLableTitle:(NSString *)clearHistoryTitle;


@end


@interface TBSearchHistorySectionHeaderView : TBTableViewCell

@property (nonatomic, strong) UILabel *historyLabel;
@property (nonatomic, strong) UILabel *clearHistoryLabel;

@end
