//
//  LBPhotoBrowseView.h
//  test
//
//  Created by dengweihao on 2017/8/2.
//  Copyright © 2017年 dengweihao. All rights reserved.
//

#import <UIKit/UIKit.h>
@class LBPhotoBrowserManager;

@interface LBPhotoBrowserView : UIView

@property (nonatomic , weak)UIPageControl *pageControl;

- (void)showImageViewsWithURLs:(LBUrlsMutableArray *)urls andSelectedIndex:(int)index;

- (void)showImageViewsWithImages:(LBImagesMutableArray *)images andSeletedIndex:(int)index;

//以下内容为自定义内容

@property (nonatomic , strong)UILabel * pageCountLabel; //显示总的页数及当前页数
@property (nonatomic , strong)UIButton * downloadButton; //图片下载按钮
@property (nonatomic , strong ,readonly)UIImage  * currentDisplayImage;   //当前显示的图片
@property (nonatomic , copy) void(^viewDidDisappearBlock)(void);

@property (nonatomic, weak) LBPhotoBrowserManager *browserManager;


- (void)dismiss;

@end


@interface LBScrollViewStatusModel : NSObject

@property (nonatomic , strong)NSNumber *scale;
@property (nonatomic , assign)CGPoint contentOffset;

@property (nonatomic , strong)UIImage *currentPageImage;
@property (nonatomic , strong)NSURL *url;

@property (nonatomic , strong)id opreation;

@property (nonatomic , assign)BOOL isShowing;
@property (nonatomic , assign)BOOL showPopAnimation;
@property (nonatomic , assign)int index;

@property (nonatomic, weak) LBPhotoBrowserManager *browserManager;

@property (nonatomic , copy)void (^loadImageCompletedBlock)(LBScrollViewStatusModel *loadModel,UIImage *image, NSData *data, NSError *  error, BOOL finished, NSURL *imageURL);

- (void)loadImageWithCompletedBlock:(void (^)(LBScrollViewStatusModel *loadModel,UIImage *image, NSData *data, NSError *  error, BOOL finished, NSURL *imageURL))completedBlock;
@end
