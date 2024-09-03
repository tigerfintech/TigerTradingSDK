//
//  TBOrderItemActionsView.h
//  Stock
//
//  Created by 王昌阳 on 2021/1/17.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBView.h>
@class TBCollectionViewCellItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBOrderItemActionsView : TBView

@property (nonatomic, copy) NSArray<TBCollectionViewCellItem *> *dataSource;///<  数据

- (instancetype)initWithIdentifiers:(NSArray<NSString *> *)identifiers;

@end

NS_ASSUME_NONNULL_END
