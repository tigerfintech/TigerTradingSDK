//
//  TBControlView.h
//  HppleDemo
//
//  Created by xw.long on 15/12/11.
//
//

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>
#import <TBUIKit/TFHpple.h>

// 一级评论图片添加格式
#define kCommunityPostCommentImageAppendFormat @" <img src='%@'></img>"
// 二级评论添加图片格式：查看图片
#define kCommunityPostSubCommentImageAppendFormat @" <t-t type=\"img\" src='%@'></t-t>"
// 二级评论添加链接格式：查看文章
#define kCommunityPostSubCommentLinkerAppendFormat @" <t-t type=\"a\" href='%@'></t-t>"

FOUNDATION_EXTERN NSString *const kTBTextControlViewTagTiger; ///< 老虎自定义标签 t
FOUNDATION_EXTERN NSString *const kTBTextControlViewTagTigerType;///< t 标签自定义类型
FOUNDATION_EXTERN NSString *const kTBTextControlViewTagTigerTypeImg; ///< 老虎自定义标签 类型 img 图片类型；资源 src
FOUNDATION_EXTERN NSString *const kTBTextControlViewTagTigerTypeLink; ///< 老虎自定义标签 类型 超链接 类型 查看文章；资源 href
FOUNDATION_EXTERN NSString *const kTBTextControlViewTagTigerTypeUnknow;///< 当前版本暂不支持
FOUNDATION_EXTERN NSString *const kTBTextControlViewTagTigerTypeRewardTip; ///< 悬赏帖标签


typedef NS_ENUM(NSUInteger, TBTruncaionMode) {
    TBTruncaionModeNone = 0,
    TBTruncaionModeNormal,  //仅显示3个点的截断
    TBTruncaionModeMore,    //显示3个点加查看更多
};

typedef void(^TextControlVBlock)(NSURL *url,NSDictionary *touchObj);
typedef void(^MoreButtonBlock)(void);


@interface TBTextControlView : UIView
@property (nonatomic, copy) NSString *htmlStr, *plainText, *highlightedText;
@property (nonatomic, copy) NSString *tweetID; ///< 帖子id 用于崩溃日志记录

@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, copy) NSDictionary *linkAttributes;
@property (nonatomic, copy) NSDictionary *selectedLinkAttributes;
@property (nonatomic, copy) NSString *paragraphReplacement;
@property (nonatomic, strong) NSMutableArray *textComponents, *highlightedTextComponents;
@property (nonatomic, assign) CTTextAlignment textAlignment;
@property (nonatomic, assign) CGSize optimumSize;
@property (nonatomic, assign) CTLineBreakMode lineBreakMode;
@property (nonatomic, assign) NSInteger numberOfLines;
@property (nonatomic, assign) CGFloat lineSpacing;
@property (nonatomic, assign) CGFloat headIndent;
@property (nonatomic, assign) int currentSelectedButtonComponentIndex;
@property (nonatomic, assign) CFRange visibleRange;

@property (nonatomic, assign) CGFloat renderWidth;  //需要渲染的最大宽度
@property (nonatomic, assign) BOOL highlighted;
@property (nonatomic, assign) NSInteger firstLineHeight;    //首行高度
@property (nonatomic, assign) BOOL calcHeightMode;  //是否是计算高度的模式，如果是计算高度，那么 就不会绘制内容
@property (nonatomic, assign) TBTruncaionMode truncationMode;  //是否显示省略模式
@property (nonatomic, assign) BOOL ignoreLinkMark;  //是否忽略链接的标记，比如，@，$,#

@property (nonatomic, copy) MoreButtonBlock moreButtonBlock;

-(void)textCVBlock:(TextControlVBlock )thisBlock;

- (CGSize)optimumSize;

+ (BOOL)isSupportedTagTigerTypeByCurrentVersion:(NSString *)tigerTagType;

@end
