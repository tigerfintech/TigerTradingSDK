//
//  TBAUDepthSectionHeaderView.h
//  TBStockBusiness
//
//  Created by 骆鹏飞 on 2021/12/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBAUDepthSectionHeaderView : UIView

+ (TBAUDepthSectionHeaderView *)sectionHeaderView:(NSInteger)section frame:(CGRect)frame;

@property (nonatomic, copy) void(^backAction)(void);


@end

NS_ASSUME_NONNULL_END
