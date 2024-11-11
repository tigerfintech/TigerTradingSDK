//
//  TBAccountAnalysisTitleCell.h
//  Stock
//
//  Created by donggongfu on 2017/4/17.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBStockKit/TBStock.h>

@interface TBAccountAnalysisTitleCell : TBTableViewCell

@end

@interface TBAccountAnalysisTitleCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *note;
@property (nonatomic, assign) BOOL hasBottomBorder;

@property (nonatomic, copy) NSString *buttonTitle;
@property (nonatomic, copy) NSString *rightTitle;
@property (nonatomic, strong) UIFont *rightFont;
@property (nonatomic, copy) NSString *iConImage;
@property (nonatomic, assign) TBOmnibusCurrentAccountType omnibusCurrentAccountType;
@end

