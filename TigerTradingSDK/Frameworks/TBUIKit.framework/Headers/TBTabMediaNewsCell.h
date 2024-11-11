//
//  TBTabMediaNewsCell.h
//  Stock
//
//  Created by WCP on 2017/10/11.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

typedef NS_ENUM (NSInteger, MediaNewsCellType) {
    MediaNewsCellTypeHeader,             //!< header
    MediaNewsCellTypePositionStock,      //!< 股票持仓
    MediaNewsCellTypeCell,               //!< 正常cell
    MediaNewsCellTypeLastCell,           //!< 最后一个cell
    TBInterestCellHeader,                //!< cel
    TBInterestCell,                //!< cel
};

@interface TBTabMediaNewsHeader : TBTableViewCell

@end

@interface TBTabMediaNewsCell : TBTableViewCell

@end

@protocol TBTabMediaNewsCell <NSObject>


/**
 新闻标题

 @return  新闻标题
 */
- (NSString *)title;

/**
 新闻日期

 @return 新闻日期
 */
- (NSString *)date;

/**
 评级
 
 @return 看好、看空
 */
- (NSString *)ratingLabelString;

/**
 评级Label的颜色
 
 @return 评级Label的颜色
 */
- (UIColor *)ratingLabelColor;

/*
 * Cell的点击
 */
- (TTURLAction *)tableViewCellAction;

@end
@interface TBTabMediaNewsCellItem : TBTableViewCellItem

@property (nonatomic, copy)  NSString *headerLeftTitle;
@property (nonatomic, copy)  NSString *headerRightTitle;
//统计需求
@property (nonatomic, copy)  NSString *symbol;

@property (nonatomic, strong) id<TBTabMediaNewsCell> dataSource;

@property (nonatomic, assign) MediaNewsCellType mediaNewsCellType;    //!< 媒体新闻
@end
