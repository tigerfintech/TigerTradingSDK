//
//  TBFundamentalMoreDetailViewController.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/5/21.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
#import <TBBaseKit/JSONModel.h>

@interface TBFundamentalMoreDetailViewController : TBListTableViewController
+ (TBFundamentalMoreDetailViewController *)showFundamentalMoreDataWithtitle:(NSString *)title Models:(NSArray *)models des:(NSString *)des;

@property (nonatomic, assign) CGFloat promptHeight;

@end

@interface TBStockFundamentalMoreModel : JSONModel

@property (nonatomic, copy) NSString *icon;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subTitle;
@property (nonatomic, copy) NSString *value;

@property (nonatomic, assign) BOOL selected;

@property (nonatomic, assign) BOOL header;

@end
