//
//  TBOptionDetailPromptCell.h
//  Stock
//
//  Created by 王灵博 on 2020/4/28.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBStockPrompView;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionDetailPromptCell : TBTableViewCell
@property (nonatomic, strong) TBStockPrompView *detailPromptView;
@end

@interface TBOptionDetailPromptCellItem : TBTableViewCellItem

@end
NS_ASSUME_NONNULL_END
