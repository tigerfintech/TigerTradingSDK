//
//  CRMark.h
//  Pods
//
//  Created by Sergey Chuchukalo on 08/25/2016.
//
//  Copyright © 2016 Cleveroad Inc. All rights reserved.

#import <Foundation/Foundation.h>

@interface CRMark : NSObject <NSCopying>

typedef NS_ENUM(NSUInteger, CRRulerMarkAlignment) {
    CRRulerMarkAlignmentBottom = 0,
    CRRulerMarkAlignmentCenter,
    CRRulerMarkAlignmentTop,
};

@property (nonatomic) CGFloat frequency; // 每隔多少出现一个
@property (nonatomic) CGSize size; // 刻度size
@property (nonatomic) UIColor *color;
@property (nonatomic) UIFont *font;
@property (nonatomic) UIColor *textColor;
@property (nonatomic) CRRulerMarkAlignment alignment;
@property (nonatomic) CRRulerMarkAlignment textAlignment;
@property (nonatomic) CGPoint textOffset;
@property (nonatomic) CGPoint offset;

@end
