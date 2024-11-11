//
//  TBHeaderPicDisplay.h
//  Stock
//
//  Created by xw.long on 15/11/13.
//  Copyright © 2015年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBView.h"


typedef NS_ENUM(NSUInteger, TBPicDisplayType) {
    TBPicDisplayTypeInNews = 2,
    TBPicDisplayTypeInDiscover = 4,
    TBPicDisplayTypeInTopic = 6,
    TBPicDisplayTypeInFundHome = 7,
    TBPicDisplayTypeInLiveList = 8,
    TBPicDisplayTypeInOfficialHome = 9,
    TBPicDisplayTypeTigerVaultHome = 10,
};

typedef NS_ENUM(NSUInteger, TBLinkEvent) {
    TBLinkEventNews,
    TBLinkEventImportantNews,
    TBLinkEventNotice,
    TBLinkEventPost,
    TBLinkEventWeb,
    TBLinkEventTopic,
    TBLinkEventNativeURL,
};

typedef void(^PicDisplayBlock)(id obj,TBLinkEvent linkEvent);
typedef void(^TBBannerDidShowBlock)(NSInteger bannerIndex);
typedef void(^TBBannerDidClickBlock)(NSInteger bannerIndex);

@interface TBHeaderPicDisplay : TBView

@property (nonatomic, copy) NSArray *arrBannerInfo;

@property (nonatomic, strong) TBBannerDidShowBlock bannerDidShowBlock;
@property (nonatomic, strong) TBBannerDidClickBlock bannerDidClickBlock;
@property (nonatomic, strong) void(^bannerCloseBlock)(NSInteger bannerIndex);

@property(nonatomic,assign)BOOL timerLoop;

// 默认循环滚动时间，设置默认值位4 吧
@property (nonatomic,assign)NSTimeInterval timerSeconds;
@property (nonatomic,assign)TBPicDisplayType displayType;

-(void)picDisplay:(PicDisplayBlock )thisBlock;

-(instancetype)initWithFrame:(CGRect)frame andType:(TBPicDisplayType )displayType;

@end
