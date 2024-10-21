//
//  TBStockRightLikeEmptyView.h
//  Stock
//
//  Created by 王灵博 on 2020/4/30.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBCommunityEmptyView.h>
@protocol TBStockRightLikeDelegate <NSObject>

-(void)refreshMore;

@end
NS_ASSUME_NONNULL_BEGIN

@interface TBStockRightLikeEmptyView : UIView
@property(nonatomic, weak) id<TBStockRightLikeDelegate>delegate;
-(instancetype)initWithFrame:(CGRect)frame imageName:(NSString *)imageName subTitle:(NSString *)subTitle;
- (void)showRefresh:(BOOL)refresh;
@end


NS_ASSUME_NONNULL_END
