//
//  TBAStockBoradItemView.h
//  Stock
//
//  Created by liwt on 11/3/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBAStockBoradItemView : UIView
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, strong) UILabel *boardName;
@property (nonatomic, strong) UILabel *boardChangeRate;
@property (nonatomic, strong) UILabel *topSymbolName;
@property (nonatomic, strong) UILabel *topChangeLabel;

@property (atomic, copy) NSArray *detailItem;

- (void)updateDetailItem:(NSArray *)detailItem;

@end