//
//  TBHTMLStringParser.h
//  TBToolsKit
//
//  Created by linbingjie on 2021/7/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHTMLStringParser : NSObject

//将attributedString转化为服务器可识别的html字符串
+ (NSString *)parseHtmlFromAttributedString:(NSAttributedString *)attributedText;

@end

NS_ASSUME_NONNULL_END
