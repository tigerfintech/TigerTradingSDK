//
//  TBCommunityMaskView.h
//  Stock
//
//  Created by 王昌阳 on 2019/12/24.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCommunityMaskView : UIView

@property (nonatomic, copy) void (^dismissBlock)(void);

@end

NS_ASSUME_NONNULL_END
