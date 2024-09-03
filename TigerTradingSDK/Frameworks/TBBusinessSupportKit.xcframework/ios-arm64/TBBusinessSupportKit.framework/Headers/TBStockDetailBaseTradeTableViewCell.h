//
//  TBStockDetailBaseTradeTableViewCell.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/3/9.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

static NSInteger basTagNum = 10000;
@interface TBStockDetailBaseTradeTableViewCell : TBTableViewCell

/// 点击展开view
@property (nonatomic, strong) UIView *operationView;

/// 信息展示view
@property (nonatomic, strong) UIView *upperInfoView;

- (void)tradeBtnAction:(UIButton *)sender;

- (UIButton *)btnWithTitle:(NSString *)title imgName:(NSString *)imgName tag:(NSInteger)tag;

/// btn width
@property (nonatomic, assign, readonly) CGFloat btnWidth;

@end

@interface TBStockDetailBaseTradeTableViewCellItem : TBTableViewCellItem
@property (nonatomic, assign, getter=isOpened) BOOL opened;

@end

NS_ASSUME_NONNULL_END
