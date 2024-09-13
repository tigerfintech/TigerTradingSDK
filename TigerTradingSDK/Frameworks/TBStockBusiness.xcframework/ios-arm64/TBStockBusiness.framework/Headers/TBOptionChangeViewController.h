//
//  TBOptionChangeViewController.h
//  Stock
//
//  Created by 王灵博 on 2021/5/7.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChangeViewController : TBListTableViewController

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *optionSymbol;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, assign) BOOL isIndex;

@end

NS_ASSUME_NONNULL_END
