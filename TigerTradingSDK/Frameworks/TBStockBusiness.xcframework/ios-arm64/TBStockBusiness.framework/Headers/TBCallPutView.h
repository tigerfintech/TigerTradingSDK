//
//  TBCallPutView.h
//  Stock
//
//  Created by dull grass on 2019/12/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCallPutView : UIView
@property(nonatomic, copy)NSString *market;
@property(nonatomic, assign)BOOL showBottomLine;
@property(nonatomic, strong) NSNumber *chainIV;
//@property (nonatomic, assign) BOOL barABtest;
- (void)changeAppColorStyle;
@end

NS_ASSUME_NONNULL_END
