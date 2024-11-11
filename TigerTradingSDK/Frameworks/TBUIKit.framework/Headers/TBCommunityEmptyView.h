//
//  TBCommunityEmptyView.h
//  Stock
//
//  Created by 马超 on 16/6/14.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void (^TBImageActionBlock) (void);
@interface TBCommunityEmptyView : UIView

@property (nonatomic, copy) NSString *imageName;
@property (nonatomic, copy) NSString *subTitle;
@property (nonatomic, assign) BOOL      networkFailedMode;  //网络加载出错模式

@property (nonatomic, copy) NSString *networkFailedImageName;///< 指定的网络加载出错时显示的图片
@property (nonatomic, assign) CGSize networkFailedImageSize;///< 指定宽高

@property (nonatomic, strong) NSNumber *topOffset;

- (instancetype)initWithFrame:(CGRect)frame imageName:(NSString *)imageName subTitle:(NSString *)subTitle;

- (void)setImageEnableClick:(BOOL)enable back:(TBImageActionBlock)callBack;

@end
