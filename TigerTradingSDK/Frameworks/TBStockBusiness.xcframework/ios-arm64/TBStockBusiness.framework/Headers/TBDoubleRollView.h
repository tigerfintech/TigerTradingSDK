//
//  TBDoubleRollView.h
//  Stock
//
//  Created by dull grass on 2019/12/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TBDoubleRollView;
@class TBDoubleRollCell;
@class TBOptionExpiryItemModel;
@class TBOptionChainDetailItemViewModel;

NS_ASSUME_NONNULL_BEGIN

@protocol TBDoubleRollViewDataSource <NSObject>
@required

/// 策略
- (NSString *)optionStrategy;

/**
 call put 多少行
 @param optionView optionView description
 @param section section description
 @return return value description
 */
- (NSInteger)optionView:(TBDoubleRollView *)optionView numberOfRowsInSection:(NSInteger)section;

//计算T型的列表指标
//Row:tableCell位置
//col:collectionCell位置
//isLeft：T型的左边还是右
- (void)updateDoubleCellDataWithRow:(NSInteger)row
                                col:(NSInteger)col
                             isLeft:(BOOL)isLeft
                      completeBlock:(void(^)(TBOptionChainDetailItemViewModel * _Nullable model))completeBlock;

- (NSArray *)optionView:(BOOL)left cellForRow:(NSIndexPath*)indexPath;

/**
 标题栏
 */
- (NSArray *)optionViewTitles;

- (NSInteger)seperateRow;

- (NSInteger)callLineSeparateRow;

- (NSInteger)putLineSeparateRow;

/**
 行权价

 @param optionView optionView description
 @param indexRow indexRow description
 @return return value description
 */
- (NSString *)optionView:(TBDoubleRollView *)optionView cellForStrikeItemAtIndexRow:(NSIndexPath *)indexRow;


/**
 是否展示旧期权

 @param optionView optionView description
 @param indexRow indexRow description
 @return return value description
 */
- (BOOL)optionView:(TBDoubleRollView *)optionView cellForDisplayOldOptionAtIndexRow:(NSIndexPath *)indexRow;


/**
 返回旧期权symbol

 @param optionView optionView description
 @param indexRow indexRow description
 @return return value description
 */
- (NSString *)optionView:(TBDoubleRollView *)optionView cellForOldSymbolItemAtIndexRow:(NSIndexPath *)indexRow;

- (BOOL)optionView:(TBDoubleRollView *)optionView callSelectedAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)optionView:(TBDoubleRollView *)optionView putSelectedAtIndexPath:(NSIndexPath *)indexPath;

// ???: 重复了?
- (void)doubleViewScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)doubleViewScrollViewDidEndDecelerating:(UIScrollView *)scrollView;

@end

@protocol TBDoubleRollViewDelegate <NSObject>

- (void)doubleViewScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)doubleViewScrollViewDidEndDecelerating:(UIScrollView *)scrollView;
- (void)doubleViewDidSelectOption:(NSDictionary *)optionInfo atIndexPath:(NSIndexPath *)indexPath;

@end

@interface TBDoubleRollView : UIView
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, weak) id<TBDoubleRollViewDataSource> dataSource;
@property (nonatomic, weak) id<TBDoubleRollViewDelegate> delegate;

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *optionSymbol;
@property (nonatomic, copy) NSString *market;

@property (nonatomic, copy) NSString *symbolCN;
@property (nonatomic, strong) TBOptionExpiryItemModel *currentExpiry;

@property (nonatomic, assign) BOOL needResetLoaction;

@property (nonatomic, assign) BOOL scrollEnable;
@property (nonatomic, assign) BOOL isReloading;


- (void)reloadData;

- (void)reloadDoubleRowAtIndex:(NSIndexPath*)indexPath;

@end

NS_ASSUME_NONNULL_END
