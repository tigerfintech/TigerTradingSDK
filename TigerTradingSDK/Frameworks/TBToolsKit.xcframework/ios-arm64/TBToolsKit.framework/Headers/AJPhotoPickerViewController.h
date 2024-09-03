//
//  AJPhotoPickerViewController.h
//  AJPhotoPicker
//
//  Created by AlienJunX on 15/11/2.
//  Copyright (c) 2015 AlienJunX
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>
#import <Photos/Photos.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import <AVKit/AVKit.h>

@class AJPhotoPickerViewController;
@protocol AJPhotoPickerProtocol <NSObject>
@optional
//选择完成
- (void)photoPicker:(AJPhotoPickerViewController *)picker didSelectAssets:(NSArray *)assets;

//点击选中
- (void)photoPicker:(AJPhotoPickerViewController *)picker didSelectAsset:(PHAsset*)asset;

//取消选中
- (void)photoPicker:(AJPhotoPickerViewController *)picker didDeselectAsset:(PHAsset*)asset;

//点击相机按钮相关操作
- (void)photoPickerTapCameraAction:(AJPhotoPickerViewController *)picker;

//取消
- (void)photoPickerDidCancel:(AJPhotoPickerViewController *)picker;

//超过最大选择项时
- (void)photoPickerDidMaximum:(AJPhotoPickerViewController *)picker;

//低于最低选择项时
- (void)photoPickerDidMinimum:(AJPhotoPickerViewController *)picker;

//选择过滤
- (void)photoPickerDidSelectionFilter:(AJPhotoPickerViewController *)picker;

//选择添加k线
- (void)photoPickerDidSelectionAddKLine:(AJPhotoPickerViewController *)picker;

@end


@interface AJPhotoPickerViewController : UIViewController

@property (weak, nonatomic) id<AJPhotoPickerProtocol> delegate;

//navigation bar背景色
@property (nonatomic, strong) UIColor     * navBarBgColor;
//navigation bar文字颜色
@property (nonatomic, strong) UIColor     * navBarTitleColor;
//状态栏样式
@property (nonatomic, assign) UIStatusBarStyle statusBarStyle;

//选择过滤
@property (nonatomic, strong) NSPredicate *selectionFilter;

//资源过滤
//@property (nonatomic, strong) ALAssetsFilter *assetsFilter;

//选中的项
@property (nonatomic, strong) NSMutableArray *indexPathsForSelectedItems;

//最多选择项
@property (nonatomic, assign) NSInteger maximumNumberOfSelection;

//最少选择项
@property (nonatomic, assign) NSInteger minimumNumberOfSelection;

//显示空相册
@property (nonatomic, assign) BOOL showEmptyGroups;

//是否开启多选
@property (nonatomic, assign) BOOL multipleSelection;

// 是否显示添加 K 线图功能，默认不显示
@property (nonatomic, assign) BOOL showAddKLine;

@property (nonatomic, assign) BOOL isEnglishMode;


@property (nonatomic, assign) BOOL showVideo; // 是否显示视频

+ (void)requestAssetImage:(PHAsset *)asset fromiCloud:(BOOL)fromiCloud resultHandler:(void(^)(UIImage * image))resultHandler;

//获取图片并设置最大图片内存大小（非尺寸）,单位为字节
+ (void)requestAssetImage:(PHAsset *)asset fromiCloud:(BOOL)fromiCloud maxCapacity:(CGFloat)maxCapacity resultHandler:(void(^)(UIImage * image))resultHandler;

+ (void)requestAssetImageURL:(PHAsset *)asset fromiCloud:(BOOL)fromiCloud maxCapacity:(CGFloat)maxCapacity resultHandler:(void(^)(NSData * data,UIImage * image,NSURL * url,BOOL isGif))resultHandler;

// 获取视频相关信息
+ (void)requestAssetVideoURL:(PHAsset *)asset
               resultHandler:(void(^)(NSURL * videoUrl, UIImage *videoImage))resultHandler;

+ (void)removeLocalVideoAssetsCaches;

@end
