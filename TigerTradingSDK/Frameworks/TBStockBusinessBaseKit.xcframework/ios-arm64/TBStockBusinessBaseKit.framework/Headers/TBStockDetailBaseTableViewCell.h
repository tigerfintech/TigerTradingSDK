//
//  TBStockDetailBaseTableViewCell.h
//  TBStockBusiness
//
//  Created by 骆鹏飞 on 2022/6/22.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailBaseTableViewCell : TBTableViewCell

@property (nonatomic, strong) UIView *headerView;
@property (nonatomic, strong) UIView *subContentView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIButton *arrowButton;

@property (nonatomic, assign, readonly) BOOL isLiteMode;

@end

@interface TBStockDetailBaseTableViewCellItem : TBTableViewCellItem

@property (nonatomic, assign, readonly) BOOL isLiteMode;
@property (nonatomic, assign, readonly) CGFloat subContentHeight; /// 需要子类实现
@property (nonatomic, assign, readonly) CGFloat blankHeight;
@property (nonatomic, assign, readonly) CGFloat topCornerHeight;
@property (nonatomic, assign, readonly) CGFloat headerHeight;
@property (nonatomic, assign, readonly) CGFloat bottomCornerHeight;

@property (nonatomic, assign) BOOL needArrow;
@property (nonatomic, assign) BOOL needTopCorner; //上圆角
@property (nonatomic, assign) BOOL needBottomCorner; //下圆角
@property (nonatomic, assign) BOOL needHeader; // 是否需要头部大标题：e.g.成交明细、所属行业等。。。
@property (nonatomic, copy) NSString *headerName;

@property (nonatomic, copy) void(^arrowAction)(void);

@end

NS_ASSUME_NONNULL_END
