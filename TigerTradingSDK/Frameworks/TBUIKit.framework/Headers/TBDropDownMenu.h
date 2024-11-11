//
//  TBDropDownMenu.h
//  Stock
//
//  Created by 马超 on 16/8/31.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef NS_ENUM(NSUInteger, TBDropDownTitleType) {
    TBDropDownTitleTypeSingleTitle,
    TBDropDownTitleTypeTitleAndDetail,
};
@interface TBDropDownMenuIndexPath : NSObject

@property (nonatomic, assign) NSInteger row;//行
@property (nonatomic, assign) NSInteger column;//列
@property (nonatomic, assign) NSInteger item;

- (instancetype)initWithColumn:(NSInteger)column row:(NSInteger)row;
- (instancetype)initWithColumn:(NSInteger)column row:(NSInteger)row item:(NSInteger)item;

+ (instancetype)indexPathWithColumn:(NSInteger)column row:(NSInteger)row;
+ (instancetype)indexPathWithColumn:(NSInteger)column row:(NSInteger)row item:(NSInteger)item;

@end

#pragma mark - TBDropMenuDataSource

@class TBDropDownMenu;
@protocol TBDropMenuDataSource <NSObject>

@required
//每个column有多少行
- (NSInteger)menu:(TBDropDownMenu *)menu numberOfRowsInColumn:(NSInteger)column;
//每个column中每行的title
- (NSString *)menu:(TBDropDownMenu *)menu titleForRowAtIndexPath:(TBDropDownMenuIndexPath *)indexPath;

@optional
//column数量,默认是1
- (NSInteger)numberOfColumnsInMenu:(TBDropDownMenu *)menu;
//对应的indexPath的图片
- (NSString *)menu:(TBDropDownMenu *)menu imageNameForRowAtIndexPath:(TBDropDownMenuIndexPath *)indexPath;
//
- (NSString *)menu:(TBDropDownMenu *)menu detailTextForRowAtIndexPath:(TBDropDownMenuIndexPath *)indexPath;
//某列某行的item数量，如果有,存在二级菜单,反之亦然
- (NSInteger)menu:(TBDropDownMenu *)menu numberOfItemsInRow:(NSInteger)row inColumn:(NSInteger)column;
//
/**
 *  如果有二级菜单，实现下列协议
 */
- (NSString *)menu:(TBDropDownMenu *)menu titleForItemsInRowAtIndexPath:(TBDropDownMenuIndexPath *)indexPath;
//内容和一级菜单雷同
- (NSString *)menu:(TBDropDownMenu *)menu imageForItemsInRowAtIndexPath:(TBDropDownMenuIndexPath *)indexPath;
//
- (NSString *)menu:(TBDropDownMenu *)menu detailTextForItemsInRowAtIndexPath:(TBDropDownMenuIndexPath *)indexPath;

/// 列表内部 tableView 展示的最大高度
- (CGFloat)menuMaxHeight:(TBDropDownMenu *)menu;

@end

#pragma mark - TBDropMenuDelegate

@protocol TBDropMenuDelegate <NSObject>

@optional
//点击事件
- (void)menu:(TBDropDownMenu *)menu didSelectRowAtIndexPath:(TBDropDownMenuIndexPath *)indexPath;

- (void)menu:(TBDropDownMenu *)menu didSelectColumnAtIndexPath:(TBDropDownMenuIndexPath *)indexPath;

@end

@interface TBDropMenuCell : UITableViewCell

@property (nonatomic, strong) UIView  * separator;
@property (nonatomic, assign) BOOL      hideSeparator;

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIImageView *selectedImageView;

@end

@interface TBDropDownMenu : UIView

@property (nonatomic, weak) id<TBDropMenuDataSource> dataSource;
@property (nonatomic, weak) id<TBDropMenuDelegate> delegate;

@property (nonatomic, assign) TBDropDownTitleType titleType;

@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *selectedTextColor;

@property (nonatomic, strong) UIColor *detailTextColor;
@property (nonatomic, strong) UIColor *indicatorColor;
@property (nonatomic, strong) UIFont *detailTextFont;
@property (nonatomic, assign) BOOL hideSeparator;       //是否隐藏分割线
@property (nonatomic, strong) UIColor *separatorColor;
@property (nonatomic, assign) NSUInteger fontSize;
@property (nonatomic, assign) BOOL font_NOAdjust;
@property (nonatomic, copy) NSArray *defaultTitleArray;
@property (nonatomic, copy) NSArray *defaultSubTitlesArray;


//当前选中的列
@property (nonatomic, strong) NSMutableArray *currentSelectedRows;
//当有二级列表时,是否调用点击代理方法
@property (nonatomic, assign) BOOL isClickHaveItemValid;
//
- (instancetype)initWithOrigin:(CGPoint)origin height:(CGFloat)height;

- (instancetype)initWithOrigin:(CGPoint)origin width:(CGFloat)width height:(CGFloat)height;

//
- (void)selectIndexPath:(TBDropDownMenuIndexPath *)indexPath;
//默认选中
- (void)selectDefaultIndexPath;
- (void)selectDefaultIndexPathColoumn:(NSInteger)column row:(NSInteger)row item:(NSInteger)item;
//
- (void)reloadData;

- (void)hideMenu;

@end
