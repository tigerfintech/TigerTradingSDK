//
//  TBWatchlistTableHeaderToolView.h
//  TBStockBusiness
//
//  Created by wind on 2022/8/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBWatchlistTableHeaderToolViewDelegate <NSObject>

- (void)didTappedLandscape;
- (void)didTappedGroupManage;
- (void)didTappedThumbnail;

@end

@interface TBWatchlistTableHeaderToolView : UIView
@property (nonatomic, weak) id<TBWatchlistTableHeaderToolViewDelegate> delegate;
- (void)updateView;
- (void)updateTheme;
@end

NS_ASSUME_NONNULL_END
