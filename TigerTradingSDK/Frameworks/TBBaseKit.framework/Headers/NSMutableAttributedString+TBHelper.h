//
//  TBHelper.h
//  Stock
//
//  Created by JustLee on 2019/5/21.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface  NSMutableAttributedString (TBHelper)

+ (NSMutableAttributedString *)attributeStringWithSource:(NSArray *)source;

+ (NSMutableAttributedString *)attributeStringWithSource:(NSArray *)source
                                      imageBoundsCreator:(CGRect (^)(UIImage *image, NSInteger sourceIndex))boundsCreator;

+ (NSMutableAttributedString *)attributeStringWithSource:(NSArray *)source
                                      imageBoundsCreator:(CGRect (^)(UIImage *image, NSInteger sourceIndex))boundsCreator
                                              attributes:(NSDictionary *)attributes;
@end

