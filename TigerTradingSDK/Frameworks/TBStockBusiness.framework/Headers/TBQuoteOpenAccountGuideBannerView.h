//
//  TBQuoteOpenAccountGuideBannerView.h
//  TBStockBusiness
//
//  Created by dulijun on 2021/10/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class TBQuoteOpenAccountGuideBannerView;

@protocol TBOpenAccountWeixinGuideViewDelegate <NSObject>

- (void)didSelectedQuoteOpenAccountGuideBannerView:(TBQuoteOpenAccountGuideBannerView *)view;

@end

@interface TBQuoteOpenAccountGuideBannerViewItem : NSObject

@property (nonatomic, assign) BOOL isWatchStyle;//是否是自选样式（自选顶部banner，和其他市场 ui显示样式有区别）
@property (nonatomic, copy) NSString *imageUrlString;
@property (nonatomic, copy) NSString *titleString;
@property (nonatomic, copy) NSString *buttonString;
@property (nonatomic, assign) BOOL couldClose;//是否可以关闭
@property (nonatomic, strong) void(^bannerCloseBlock)(void);

//辅助ui相关
@property (nonatomic, strong, nullable) NSAttributedString *titleAttributedString;
@property (nonatomic, strong, nullable) NSNumber *buttonWidth;//按钮宽

@end


@interface TBQuoteOpenAccountGuideBannerView : UIView

@property (nonatomic, strong) TBQuoteOpenAccountGuideBannerViewItem *viewItem;
@property (nonatomic, weak) id<TBOpenAccountWeixinGuideViewDelegate>delegate;


@end

NS_ASSUME_NONNULL_END
