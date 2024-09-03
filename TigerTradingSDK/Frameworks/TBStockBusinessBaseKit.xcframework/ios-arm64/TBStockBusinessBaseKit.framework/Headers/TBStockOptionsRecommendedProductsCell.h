//
//  TBStockOptionsRecommendedProductsCell.h
//  Pods
//
//  Created by zlc on 2022/3/28.
//  
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockOptionsRecommendedProductsCellItem : TBTableViewCellItem

@property (nonatomic, assign) CGFloat topMargin; // 上间距，默认5
@property (nonatomic, assign) CGFloat bottomMargin; // 下间距，默认10

@property (nonatomic, copy) NSString * symbol;
@property (nonatomic, copy) NSString * market;
@property (nonatomic, copy) NSString * secType;

@end

@interface TBStockOptionsRecommendedProductsCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
