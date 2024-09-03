//
//  TBPictureManager.h
//  Stock
//
//  Created by yangfan on 2017/9/21.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

//图片尺寸大小控制
#define LargePicSize                                        [TBPictureManager manager].largePicSize
#define SmallPicSize                                        [TBPictureManager manager].smallPicSize
#define LargePicSizeSuffix                                  [TBPictureManager manager].largePicSuffix
#define SmallPicSizeSuffix                                  [TBPictureManager manager].smallPicSuffix

@interface TBPictureManager : NSObject

+ (instancetype)manager;

@property (nonatomic, assign) CGSize          largePicSize;     //大图尺寸
@property (nonatomic, assign) CGSize          smallPicSize;     //小图尺寸
@property (nonatomic, copy) NSString        * largePicSuffix;   //大图后缀
@property (nonatomic, copy) NSString        * smallPicSuffix;   //小图后缀

- (void)saveSetting;

@end

