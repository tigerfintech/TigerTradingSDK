//
//  TBHomePageStockView.h
//  TBStockBusiness
//
//  Created by mashanli on 2022/9/20.
//
@class TBHomePageStocksDataModel;
@class TBHomePageStocksEtfModel;

NS_ASSUME_NONNULL_BEGIN

static const CGFloat kTBHomePageStockIndexViewHeight = 90;
static const CGFloat kTBHomePageStockEtfCellHeight = 64;
static const NSUInteger kTBHomePageStockEtfCount = 3;

@interface TBHomePageStockIndexView : UIView

@property (nonatomic, copy) void(^tapBlock)(void);
- (void)updateWithName:(NSString *)name price:(NSString *)price change:(NSString *)change textColor:(UIColor *)textColor;

@end


@interface TBHomePageStockEtfView : UIView

@property (nonatomic, copy) void(^tapBlock)(void);
@property (nonatomic, strong) TBHomePageStocksEtfModel *model;

@end



@interface TBHomePageStockCollectionCell : UICollectionViewCell

@property (nonatomic, copy) void(^gotoStockDetailBlock)(NSString *symbol, NSString *market);
@property (nonatomic, copy) void (^gotoEtfList)(void);
@property (nonatomic, strong) TBHomePageStocksDataModel *model;

@end

NS_ASSUME_NONNULL_END
