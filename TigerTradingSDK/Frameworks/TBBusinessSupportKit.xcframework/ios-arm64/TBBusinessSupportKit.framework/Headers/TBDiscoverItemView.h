//
//  TBDiscoverItemView.h
//  Stock
//
//  Created by xw.long on 16/3/4.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBView.h>


typedef NS_ENUM(NSUInteger, TBBigItemType) {
    TBBigItemTypeVertical,//图文上下结构
    TBBigItemTypeHorizontal,//图文左右结构
};

typedef NS_ENUM(NSUInteger, TBItemName) {
    TBItemNameStockHotTop = 0,         //股票热门榜
    TBItemNameStockChangeTop = 1,          //股票异动榜
    TBItemNameTigeAalligatorTop DEPRECATED_MSG_ATTRIBUTE("TCTI服务已下线, 不要再使用该枚举类型") = 2, //老虎量化榜
    TBItemNameOptionChangeTop = 3,         //期权异动榜
    TBItemNameHotTradeTop,             //热门交易榜
    TBItemNameStockCollege,            //股票学院
    TBItemNameTigerNewsletter,         //老虎研报
    TBItemNameTopic,                   //主题组合
    TBItemNameIPO,                     // 新股申购
    TBItemNameMacroCalendar,                     // 宏观经济日历
    TBItemNameCustomFilterStock,                 //自定义选股
    TBItemNameDataVane,                 //数据风向标
    TBItemNameHKBrokersSeatTracking,                 //经纪商席位
    TBItemNameStockGame,                //炒股大赛
    TBItemNameCompanyEvent,              //公司行动
    TBItemNameNewSharesHit,                  //新股打新
    TBItemNameStockRise,         //股票周期涨幅榜
    TBItemNameStockFall,         //股票周期跌幅榜
    TBItemNameStockSelect,       //股票形态选股
    TBItemNameSimilarKLine,      //相似K线

};

@protocol TBBigItemViewDelegate <NSObject>
-(void)bigItemClick:(NSInteger)index;
@end

@interface TBBigItemView : TBView

@property (nonatomic, strong) UIImageView *imgvIcon;
@property (nonatomic, strong) UILabel *labelTitle;
@property (nonatomic, assign) NSInteger itemIndex;

@property (nonatomic, weak) id<TBBigItemViewDelegate>delegate;

-(instancetype)initWithFrame:(CGRect)frame andImg:(NSString *)image title:(NSString *)title itemIndex:(NSInteger)index type:(TBBigItemType )type span:(CGFloat)span;

-(instancetype)initWithFrame:(CGRect)frame andImg:(NSString *)image title:(NSString *)title font:(UIFont *)font itemIndex:(NSInteger)index span:(CGFloat)span type:(TBBigItemType )type;

- (void)showRedIcon:(BOOL)show;

@end






@interface TBDiscoverItemViewCell : UICollectionViewCell
@property (nonatomic, assign) BOOL isHaveData;
- (void)updateTitle:(NSString *)title iConImage:(NSString *)image showSmallIcon:(BOOL)show;

@end

@protocol TBDiscoverItemViewDelegate <NSObject>

-(void)discoverItemClick:(NSInteger )selectIndex;

@end


@interface TBDiscoverItemView : TBView

@property (nonatomic, strong) NSMutableArray *collectionViewDataArray;
@property (nonatomic, weak) id<TBDiscoverItemViewDelegate>delegate;

- (void)updateItemWithTag:(NSInteger)tag hasNew:(BOOL)hasNew;
- (void)enableShowAdvisorPost:(BOOL)show;
- (void)pageControllHidden;
- (void)showPageControls;
@end
