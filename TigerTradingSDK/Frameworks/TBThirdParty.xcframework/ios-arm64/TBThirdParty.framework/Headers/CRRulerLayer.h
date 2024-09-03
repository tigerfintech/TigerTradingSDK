//
//  CRRulerLayer.h
//  Pods
//
//  Created by Sergey Chuchukalo on 08/25/2016.
//
//  Copyright © 2016 Cleveroad Inc. All rights reserved.

#import <QuartzCore/QuartzCore.h>
#import "CRMark.h"

@protocol CRRulerLayerMarkDelegate <NSObject>

@optional
- (NSString *)rulerTextAtIndex:(NSInteger)index mark:(CRMark *)mark;
- (UIColor *)rulerLineColorAtIndex:(NSInteger)index mark:(CRMark *)mark;
- (UIColor *)rulerTextColorAtIndex:(NSInteger)index mark:(CRMark *)mark;

@end

@interface CRRulerLayer : CALayer

typedef struct CRRange {
    CGFloat location;
    CGFloat length;
} CRRange;

@property (nonatomic) CRRange rulerRange;
@property (nonatomic, assign) CGFloat spacingBetweenMarks;
@property (nonatomic, assign) CGFloat sideOffset;

@property (nonatomic) CRMark *minorMark;
@property (nonatomic) CRMark *middleMark;
@property (nonatomic) CRMark *majorMark;

@property (nonatomic, weak) id <CRRulerLayerMarkDelegate> markDelegate;

@end
