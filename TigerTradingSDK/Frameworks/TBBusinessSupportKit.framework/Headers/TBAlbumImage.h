//
//  TBAlbumImage.h
//  TBBusinessSupportKit
//
//  Created by 秦晓强 on 2023/3/17.
//

#import <Foundation/Foundation.h>
//#import <Photos/Photos.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBAlbumImage : NSObject

@property (nonatomic, strong, nullable) NSURL     * url;
@property (nonatomic, strong) UIImage   * image;
@property (nonatomic, copy) NSString    * tagId;
@property (nonatomic, copy) NSString    * imageURL; //上传后的服务器图片地址
@property (nonatomic, assign) BOOL isGIF;///< 是否是 GIF 图片
@property (nonatomic, copy) NSData *imageData;///< 图片数据
///
//@property (nonatomic, assign) PHAssetMediaType mediaType; ///< 区分视频还是图片
@property (nonatomic, copy) NSString *videoURL; //上传后的服务器视频地址

// 区分是持仓或订单分享图片还是普通图片
@property (nonatomic, assign) BOOL isPositionOrOrderShare;
@property (nonatomic, copy) NSDictionary *positionOrOrderShareDic; // 持仓或订单分享图片携带的分享信息

@end


NS_ASSUME_NONNULL_END
