//
//  TBOptionalConfirmCell.h
//  Stock
//
//  Created by WCP on 2018/8/13.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//
#import <TBUIKit/TBTableViewCell.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, TBSiginStatus) {
    TBSiginStatusTextBeginEdit,  //!< 开始编辑
    TBSiginStatusTextReturn,     //!< 编辑完成
};

@interface TBOptionalConfirmCell : TBTableViewCell

@end

@interface TBOptionalConfirmCellItem : TBTableViewCellItem

@property (nonatomic, strong) UIFont *tbFont;
@property (nonatomic, strong) UIColor *tbFontColor;
@property (nonatomic, copy) NSMutableAttributedString *tbDescription;

@end

@interface TBSiginConfirmCell : TBTableViewCell

@property (nonatomic, strong) UITextField *signEdit;

@end

@interface TBSiginConfirmCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *tbDescription;

@property (nonatomic, copy) NSString *tbPlaceHoldDescription;
@end

