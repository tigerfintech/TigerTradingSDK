//
//  TBOptionChainShoppingViewController.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/4/20.
//

@class TBOptionChainShoppingModel;
#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainShoppingViewController : TBListTableViewController

@property (nonatomic, copy) NSString *strategy;//当前策略key，枚举值见TBOptionChainUtils
@property (nonatomic, copy) NSString *symbol;//对应的正股symbol
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSArray<NSNumber *> *expires;//当前到期日列表，可包含1或2个日期
@property (nonatomic, strong) NSMutableArray *itemArray;//[TBOptionChainShoppingCellItem]
@property (nonatomic, strong) NSMutableArray *dataArray;//[TBOptionChainShoppingModel]
@property (nonatomic, assign) BOOL enableRight;//支持callput切换

@property (nonatomic, assign, readonly) CGFloat tipHeight;
@property (nonatomic, assign, readonly) CGFloat halfHeight;
@property (nonatomic, assign, readonly) BOOL isEmpty;

/// 供外部调用，往购物车添加或者移除某个商品
/// @param model 商品model
/// @param isSuccess 操作成功或失败
/// @param isSelected  YES:添加 NO：移除
- (void)changeShopping:(TBOptionChainShoppingModel *)model finish:(void(^)(BOOL isSuccess, BOOL isSelected, NSString *errorMsg))finish;

/// 购物车商品移除
/// @param model 商品model
@property (nonatomic, copy) void(^removeBlock)(TBOptionChainShoppingModel *model);

/// 购物车商品的callput变化，rights里
/// @param model 商品model，model.rights是修改后的最新callput
@property (nonatomic, copy) void(^rightBlock)(TBOptionChainShoppingModel *model);

//更新高度
@property (nonatomic, copy) void(^updateHeightBlock)(void);

//商品是否为空
@property (nonatomic, copy) void(^setEmptyBlock)(void);

//商品变化：包括数量、四要素等任何变化
@property (nonatomic, copy) void(^shopUpdateBlock)(void);

@property (nonatomic, copy) void(^analyticsBlock)(void);
//清空购物车
- (void)cleanShopping;

@end

NS_ASSUME_NONNULL_END
