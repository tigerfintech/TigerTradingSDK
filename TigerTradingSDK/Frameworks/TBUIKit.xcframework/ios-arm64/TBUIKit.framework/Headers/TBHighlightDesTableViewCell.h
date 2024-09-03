//
//  TBHighlightDesTableViewCell.h
//  TBStockBusiness
//
//  Created by 骆鹏飞 on 2021/8/9.
//

#import "TBTableViewCell.h"
@class YYTextView;
#import <TBThirdParty/YYText.h>
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHighlightDesTableViewCell : TBTableViewCell <YYTextViewDelegate>

@property (nonatomic, strong) YYTextView *desText;

@end


@interface TBHighlightDesTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *desText;
@property (nonatomic, copy) NSString *highlightText;


@end

NS_ASSUME_NONNULL_END
