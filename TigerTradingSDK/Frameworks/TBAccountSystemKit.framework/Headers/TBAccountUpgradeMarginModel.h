//
//  TBAccountUpgradeMarginModel.h
//  Stock
//
//  Created by charming on 2019/4/25.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@class TBAccountUpgradeMarginDataModel;

@interface TBAccountUpgradeMarginModel : JSONModel
@property (nonatomic, strong) TBAccountUpgradeMarginDataModel *data;
@property (nonatomic, assign) BOOL is_succ;
@end


@interface TBAccountUpgradeMarginDataModel : JSONModel
@property (nonatomic, copy) NSString *btn_text;
@property (nonatomic, copy) NSString *link;

@property (nonatomic, assign) BOOL clickable;
@property (nonatomic, assign) BOOL visible;

@end


