//
//  TBStockMarketSegmentedControl.h
//  Stock
//
//  Created by 王灵博 on 2020/8/11.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBThirdParty/HMSegmentedControl.h>
@class TBStockHMScrollView;
NS_ASSUME_NONNULL_BEGIN
@interface TBStockHMScrollView : UIScrollView

@end
typedef NS_ENUM(NSInteger, TBStockSegmentType) {
    TBStockSegmentMarketType = 0,  //市场页
    TBStockSegmentDetailType ,    //个股详情页
    TBStockSegmentTypeHomePage ,  //首页
};

@interface TBStockMarketSegmentedControl : HMSegmentedControl
@property(nonatomic,assign)TBStockSegmentType segType;
@property(nonatomic,assign)BOOL hasBackLayer;
@property(nonatomic,assign)CGFloat backHeight;
@property(nonatomic,assign)CGFloat cornerRadius;
@property(nonatomic,strong)UIColor *backColor;
@property(nonatomic,strong)UIColor *selectionbackColor;
@property(nonatomic,strong)TBStockHMScrollView *scrollView;
@end

NS_ASSUME_NONNULL_END
