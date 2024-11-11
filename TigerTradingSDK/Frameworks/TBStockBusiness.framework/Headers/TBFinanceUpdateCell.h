//
//  TBFinanceUpdateCell.h
//  TBStockDetailComponentKit
//
//  Created by JustLee on 2021/6/1.
//  Copyright © 2021 Just. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBStockPrompView.h>

NS_ASSUME_NONNULL_BEGIN


@protocol TBFinanceUpdateCell <NSObject>

- (NSString *)title;

- (NSString *)fianceClickedKey;

- (NSString *)promptDes;


- (NSDate *)promptDate;

- (TBStockPrompViewType)promptType;

@end


@interface TBFinanceUpdateCell : TBTableViewCell

@end

@interface TBFinanceUpdateCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *symbol;


@property (nonatomic, copy) NSString *dateString;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *fianceClickKey;
@property (nonatomic, assign) TBStockPrompViewType promptType;

@property (nonatomic, strong) id<TBFinanceUpdateCell> dataSource;
@end


NS_ASSUME_NONNULL_END
