//
//  TBStockDetailPriceTableViewCell.h
//  Stock
//
//  Created by luopengfei on 2018/4/13.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

@class TBStockDetailPromptItemView;
#import <TBStockKit/TBStock.h>

UIKIT_EXTERN NSString *const TBUKStockCurrencyPromptString;

typedef void(^TBStockDetailPromptTypeBlock)(TBStockDetailPromptItemView *view, TBStockQuotePromptType type);

@interface TBStockDetailPromptItemView : UIView {
    TBStockQuotePromptType _promptType;
    TBStockDetailPromptTypeBlock _clickedBlock;
}

@property (nonatomic, strong) UIImageView *iconImageView;

- (instancetype)initWithFrame:(CGRect)frame
                   promptType:(TBStockQuotePromptType)type
                 clickedBlock:(TBStockDetailPromptTypeBlock)block;

@end
