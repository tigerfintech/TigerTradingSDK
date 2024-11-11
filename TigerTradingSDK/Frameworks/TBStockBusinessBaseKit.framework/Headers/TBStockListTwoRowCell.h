//
//  TBStockListTwoRowCell.h
//  Stock
//
//  Created by zhenglanchun on 2021/5/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBBaseModelBuryingPointModel;
@class TBStockListTwoRowView;

NS_ASSUME_NONNULL_BEGIN


@class TBBaseModelBuryingPointModel;

@interface TBStockListTwoRowCellItem : TBTableViewCellItem

/// 列的数量，默认3列 （TBStockListViewColType）
@property (nonatomic, strong) NSNumber * colType;


// MARK: get方法，子类实现
- (NSNumber *)displayColType;

- (NSString *)displayLeftTopText;
- (UIColor *)displayLeftTopTextColor;
- (UIImage *)displayLeftBottomOneImage;
- (NSString *)disPlayLeftBottomTwoText;
- (UIImage *)displayLeftBottomThreeImage;
- (BOOL)displayLeftBottomThreeImageHidden;
- (UIFont *)displayLeftTopFont;
- (UIFont *)displayLeftBottomTwoFont;

- (NSString *)displayMiddleTopOneText;
- (NSAttributedString *)displayMiddleTopOneAttrText;
- (NSString *)displayMiddleBottomOneText;
- (UIColor *)displayMiddleBottomOneTextColor;
- (UIFont *)displayMiddleTopOneFont;
- (UIFont *)displayMiddleBottomOneFont;
- (BOOL)displayMiddleTopOneHidden;
- (NSNumber *)updateMiddleBottomOneLeading;


- (NSString *)displayMiddleTopTwoText;
- (UIColor *)displayMiddleTopTwoTextColor;
- (NSString *)displayMiddleBottomTwoText;
- (UIColor *)displayMiddleBottomTwoTextColor;

- (NSString *)displayRightTopText;
- (NSString *)displayRightBottomText;
- (UIColor *)displayRightTopTextColor;
- (UIColor *)displayRightBottomTextColor;
- (BOOL)displayRightTopHidden;
- (UIFont *)displayRightTopFont;
- (UIFont *)displayRightBottomFont;
- (NSNumber *)updateRightBottomLeading;


// MARK: 存储属性
// 左侧
@property (nonatomic, copy) NSString * leftTopText;
@property (nonatomic, strong) UIImage * leftBottomOneImage;
@property (nonatomic, copy) NSString * leftBottomTwoText;
@property (nonatomic, strong) UIImage * leftBottomThreeImage;
@property (nonatomic, assign) BOOL leftBottomThreeImageHidden;
@property (nonatomic, strong) UIFont * leftTopFont;
@property (nonatomic, strong) UIColor * leftTopTextColor;
@property (nonatomic, strong) UIFont * leftBottomTwoFont;
@property (nonatomic, strong) NSNumber * leftBottomTwoLabelLeading;

// 中间
@property (nonatomic, copy) NSString *middleTopOneText;
@property (nonatomic, strong) UIColor *middleTopOneTextColor;
@property (nonatomic, copy) NSString * middleBottomOneText;
@property (nonatomic, strong) UIColor * middleBottomOneTextColor;
@property (nonatomic, assign) BOOL middleTopOneHidden; // 默认NO
@property (nonatomic, strong) UIFont * middleTopOneFont;
@property (nonatomic, strong) UIFont * middleBottomOneFont;
@property (nonatomic, copy) NSAttributedString *middleTopOneAttrText;
@property (nonatomic, strong) NSNumber * middleBottomOneLeading;

@property (nonatomic, copy) NSString * middleTopTwoText;
@property (nonatomic, strong) UIColor * middleTopTwoTextColor;
@property (nonatomic, copy) NSString * middleBottomTwoText;
@property (nonatomic, strong) UIColor * middleBottomTwoTextColor;

// 右侧
@property (nonatomic, copy) NSString * rightTopText;
@property (nonatomic, copy) NSString * rightBottomText;
@property (nonatomic, strong) UIColor * rightTopTextColor;
@property (nonatomic, strong) UIColor * rightBottomTextColor;
@property (nonatomic, assign) BOOL rightTopHidden; // 默认NO
@property (nonatomic, strong) UIFont *rightTopFont;
@property (nonatomic, strong) UIFont *rightBottomFont;
@property (nonatomic, strong) NSNumber * rightBottomLeading;

@property (nonatomic, copy) NSString *arriveFrom;

@property (nonatomic, assign) BOOL adjustSecondColumnLayoutInEnglish; /// Default:NO

@property(nonatomic, strong)TBBaseModelBuryingPointModel *buryingPointModel;

@end


@interface TBStockListTwoRowCell : TBTableViewCell

@property (nonatomic, strong) TBStockListTwoRowView *stockListView;

@end

NS_ASSUME_NONNULL_END
