//
//  TBOrderItemActionCollectionViewCell.h
//  Stock
//
//  Created by 王昌阳 on 2021/1/17.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBCollectionViewCell.h>
#import <TBTradeBusinessBaseKit/TBOrderStatusConstants.h>
#import <TBUIKit/TBCollectionViewCellItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOrderItemActionCollectionViewCell : TBCollectionViewCell

@end

@interface TBOrderItemActionCollectionViewCellItem : TBCollectionViewCellItem

@property (nonatomic, assign) CGSize itemSize;

@property (nonatomic, copy) NSString *imageName;
@property (nonatomic, copy) NSString *selectedImageName;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) UIColor *titleColor;

@property (nonatomic, assign) BOOL selected;///< 是否是特殊状态

@property (nonatomic, assign) TBOrderTableCellButtonTag actionType;///< 事件类型

+ (instancetype)actionModelWithActionType:(TBOrderTableCellButtonTag)actionType;

@end

NS_ASSUME_NONNULL_END
