//
//  TBLabel.h
//  Stock
//
//  Created by xw.long on 15/11/20.
//  Copyright © 2015年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBLabel : UILabel

+(TBLabel *)shareLabel;

@property (nonatomic, copy) NSDictionary *attribute;


@end
