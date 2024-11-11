//
//  TBStrikeAndSaveHomePageCollectionViewCell.h
//  TBStockBusiness
//
//  Created by zlc on 2024/4/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define TBStrikeAndSaveHomePageCollectionViewCellRowCount 3

@class TBStockDetailOptionPremiumOptionItemModel;

@interface TBStrikeAndSaveHomePageCollectionViewCell : UICollectionViewCell

@property (nonatomic, copy) void(^actionBlock)(TBStockDetailOptionPremiumOptionItemModel *itemModel);

- (void)updateModels:(NSArray <TBStockDetailOptionPremiumOptionItemModel *> *)models;

- (void)refreshLogoImage:(NSDictionary <NSString *, UIImage *> *)logos;

@end

NS_ASSUME_NONNULL_END
