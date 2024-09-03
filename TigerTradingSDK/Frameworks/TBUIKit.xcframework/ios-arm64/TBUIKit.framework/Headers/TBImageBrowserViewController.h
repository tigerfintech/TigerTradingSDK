//
//  TBImageBrowserViewController.h
//  Stock
//
//  Created by ChenXin on 17/2/23.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import "TBBaseViewController.h"
#import <UIKit/UIKit.h>

@protocol TBImageBrowserViewControllerDelegate;

@interface TBImageBrowserViewController : TBBaseViewController

@property (nonatomic, assign) BOOL allowsDelete;         //!< allowsDelete和deleteAfterMakeSuer只能设置一个，否则以deleteAfterMakeSuer有效

@property (nonatomic, assign) BOOL deleteAfterMakeSuer;  //!< 确认后删除

@property (nonatomic, assign) BOOL addWaterMark;

@property (nonatomic, weak) id <TBImageBrowserViewControllerDelegate> delegate;

- (void)loadImages:(NSArray *)images;

- (void)showImageAtIndex:(NSInteger)imageIndex inViewController:(UIViewController *)viewCtrl;

@end

@protocol TBImageBrowserViewControllerDelegate <NSObject>

@optional

- (void)imageBrowserViewControllerDidDeleteImageAtIndex:(NSInteger)imageIndex;

@end
