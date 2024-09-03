//
//  TBPhotoBrowser.h
//  Stock
//
//  Created by chenxin on 2018/8/28.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBPhotoBrowser : NSObject

+ (instancetype)showWebImages:(NSArray<NSString *> *)images selectedIndex:(NSInteger)index inView:(UIView *)view;

+ (instancetype)showLocalImages:(NSArray<UIImage *> *)images selectedIndex:(NSInteger)index inView:(UIView *)view;
//enableDownload表示是否允许显示下载按钮
+ (instancetype)showLocalImages:(NSArray<UIImage *> *)images selectedIndex:(NSInteger)index inView:(UIView *)view enableDownload:(BOOL)enableDownload;
+ (instancetype)showLocalImages:(NSArray<UIImage *> *)images selectedIndex:(NSInteger)index inView:(UIView *)view enableDownload:(BOOL)enableDownload disappearBlock:(void(^)(void))disappearBlock;

/// 大图浏览中添加 评论按钮
/// @param images 图片
/// @param index 下标
/// @param view view
/// @param commentCount 评论数
/// @param commentBlock nil
/// @param downloadBlock nil

+ (instancetype)showWebImages:(NSArray<NSString *> *)images
                selectedIndex:(NSInteger)index
                       inView:(UIView *)view
                 commentCount:(NSInteger)commentCount
               commentHandler:(dispatch_block_t)commentBlock
              downloadHandler:(dispatch_block_t)downloadBlock;

- (void)updateCommentCount:(NSInteger)commentCount;

- (void)dimissPhotoBrowser;

@end
