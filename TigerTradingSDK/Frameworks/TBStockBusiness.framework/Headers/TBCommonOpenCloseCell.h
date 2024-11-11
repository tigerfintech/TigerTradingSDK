//
//  TBCommonOpenCloseCell.h
//  Stock
//
//  Created by 王灵博 on 2020/12/22.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCommonOpenCloseCell : TBTableViewCell

@end


@interface TBCommonOpenCloseCellItem : TBTableViewCellItem
@property(nonatomic, assign)CGFloat rowHeight;
@property(nonatomic, assign)BOOL select;
@end


NS_ASSUME_NONNULL_END
