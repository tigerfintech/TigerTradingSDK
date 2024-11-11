//
//  TBStockBottomDetailView.h
//  Stock
//
//  Created by Pengfei_Luo on 16/9/12.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBView.h>
#import <TBUIKit/TBRefreshView.h>

#define kSegementHeight  40
#define kIndexHeight  40
#define kStockWatchListBottomCloseHeight 40

typedef void(^TBStockWatchListBottomIndexBlock)(BOOL upOrDown);

@protocol TBStockWatchListBottomDetailViewDelegate ;
@interface TBStockWatchListBottomDetailView : TBView

//@property (nonatomic, weak) id<TBStockWatchListBottomDetailViewDelegate> delegate;

//@property (nonatomic, strong) NSString *market;


@property (nonatomic, copy) NSArray *itemsArray;


@property (nonatomic, strong) NSMutableArray *titleArray;
@property (nonatomic, strong) NSMutableDictionary *openDataArray;
@property (nonatomic, assign) BOOL isExpansion;

@property (nonatomic, assign)BOOL isUserSelected;


- (void)setUpMarks:(NSArray *)marks withDetailData:(NSDictionary *)marksData;
- (void)firstSetUpMarks:(NSArray *)marks withDetailData:(NSDictionary *)marksData;
- (void)bottomStockIndexTaped:(TBStockWatchListBottomIndexBlock ) block;
- (void)switchMarketSegment:(NSString *)market;

- (void)pageControlChanged;
- (void)changeAppColorStyle;
@end

@protocol TBStockWatchListBottomDetailViewDelegate <NSObject>

@optional
- (void)watchlistBottomDetailViewSpreadWithSymbol:(NSString *)symbol;

@end
