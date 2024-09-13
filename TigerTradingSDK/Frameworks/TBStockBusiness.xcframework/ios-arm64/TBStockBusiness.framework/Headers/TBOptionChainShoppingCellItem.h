//
//  TBOptionChainShoppingCellItem.h
//  TBStockBusiness
//
//  Created by mashanli on 2024/6/19.
//

@class TBCombineOptionBaseItemModel;
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainShoppingCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *strategy;//策略key
@property (nonatomic, copy) NSString *market;
@property (nonatomic, strong) TBCombineOptionBaseItemModel *model;
//唯一标识
@property (nonatomic, copy) NSString *combinedKey;

@property (nonatomic, copy) void(^removeBlock)(void); //移除
@property (nonatomic, copy) void(^directionBlock)(void); //买卖
@property (nonatomic, copy) void(^changeSizeBlock)(void); //数量改变

@end

NS_ASSUME_NONNULL_END
