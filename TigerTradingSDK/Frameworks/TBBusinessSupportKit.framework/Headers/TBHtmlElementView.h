//
//  TBHtmlElementView.h
//  Stock
//
//  Created by xw.long on 15/11/5.
//  Copyright © 2015年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/RTLabel.h>
#import <TBUIKit/TFHpple.h>
#import <TBUIKit/XPathQuery.h>
#import "TBTextControlView.h"

typedef NS_ENUM(NSUInteger, RichViewEvent) {
    RichViewEventLoadDone,
    RichViewEventLink,
    RichViewEventUrl,
    RichViewEventLongPress,
    RichViewEventTap,
    RichViewEventImgClick,
    RichViewEventMore,
    RichViewEventPost,
    RichViewEventNews,
    RichViewEventImportantNews,
    RichViewEventVideo,
    RichViewEventLive,
    RichViewEventCourse,
    RichViewEventWeMedia,
};

typedef void(^HtmlElementBlock)(NSURL *url, id rtLabel,RichViewEvent event, NSString *appendInfo);


@interface TBHtmlElementView : UIView


-(instancetype)initWithFrame:(CGRect)frame andWebType:(BOOL)webType;

@property (nonatomic, strong) TBTextControlView * myTextCV;
@property (nonatomic, copy) NSString *htmlStr;
@property (nonatomic, copy) NSString *tweetID;

@property (nonatomic, assign) BOOL webViewType;


@property (nonatomic, strong) UIFont *font;

@property (nonatomic, strong) UIColor *textColor;

@property (nonatomic, assign) NSInteger numberOfLines;

@property (nonatomic, assign) CGFloat lineSpacing;

@property (nonatomic, assign) CGFloat headIndent;

@property (nonatomic, assign) CTLineBreakMode lineBreakMode;

@property (nonatomic, assign) CGFloat renderWidth;  //需要渲染的最大宽度

@property (nonatomic, assign) NSInteger firstLineHeight;    //首行高度

@property (nonatomic, assign) BOOL htmlRemote;

@property (nonatomic, assign) BOOL calcHeightMode;  //是否是计算高度的模式，如果是计算高度，那么 就不会绘制内容

@property (nonatomic, assign) TBTruncaionMode truncationMode;  //是否显示省略模式

@property (nonatomic, assign) CTTextAlignment textAlignment;

@property (nonatomic, assign) BOOL ignoreLinkMark;  //是否忽略链接的标记，比如，@，$,#

+(instancetype)shareHtmlElementView;

@property (nonatomic, copy) NSArray *arrImgElement;

@property (nonatomic, copy) MoreButtonBlock moreButtonBlock;

@property (nonatomic, assign) BOOL contentVerticalCenter;///< 垂直居中

- (NSString *)plainText;

-(void)htmlView:(HtmlElementBlock )thisBlock;

- (void)clear;

+ (NSString *)preprocessHtmlString:(NSString *)htmlStr;

@end
