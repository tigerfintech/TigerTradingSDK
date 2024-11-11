//
//  TBNewOptionGuideBannerCell.h
//  TBStockBusiness
//
//  Created by zlc on 2023/2/6.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBNewOptionGuideBannerCellItem : TBTableViewCellItem

@property (nonatomic, assign) CGFloat topMargin;
@property (nonatomic, assign) CGFloat bottomMargin;

@property (nonatomic, copy) NSString *imageUrl;

// 点击关闭后的操作，比如个性化物料通知服务端不再展示，UI刷新仍通过handleActionForCell处理
@property (nonatomic, strong) void(^closeBlock)(void);

@end


@interface TBNewOptionGuideBannerCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
