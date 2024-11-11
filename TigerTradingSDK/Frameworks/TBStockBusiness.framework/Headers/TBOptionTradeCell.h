//
//  TBOptionTradeCell.h
//  Stock
//
//  Created by liwt on 9/24/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBBaseKit/UIView+Sizes.h>

typedef NS_ENUM(NSInteger, TBOptionDirection){
    EQUAL,
    INCREASE,
    DECREASE,
};

@interface TBOptionTradeCell : UITableViewCell

@property (nonatomic, strong) UILabel *timeLabel;
@property (nonatomic, strong) UILabel *priceLabel;
@property (nonatomic, strong) UILabel *volumeLabel;
@property (nonatomic, strong) NSNumber *direction;

- (CGFloat) cellHeight;
+ (CGFloat) commonHeight;
- (void) applyDirection:(NSNumber *)direction;

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier width:(CGFloat)width;

@end
