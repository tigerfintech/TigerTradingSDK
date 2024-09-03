//
//  TBStockDetailTradeDetailTableViewCell.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/2/26.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBStockDetailTradeDetailTableViewCell <NSObject>

@property (nonatomic, copy, readonly) NSString *title;
@property (nonatomic, copy, readonly) NSString *priceStr;

@property (nonatomic, strong, readonly) NSNumber *price;

@property (nonatomic, copy, readonly) NSString *sizeStr;

@end

@interface TBStockDetailTradeDetailTableViewCell : TBTableViewCell

@property (nonatomic, strong) UILabel *titleLabel;

@property (nonatomic, strong) UILabel *priceLabel;

@property (nonatomic, strong) UILabel *sizeLabel;

@property (nonatomic, weak) id<TBStockDetailTradeDetailTableViewCell> dataSource;
@property (nonatomic, strong) NSNumber *preClose;


@end

NS_ASSUME_NONNULL_END
