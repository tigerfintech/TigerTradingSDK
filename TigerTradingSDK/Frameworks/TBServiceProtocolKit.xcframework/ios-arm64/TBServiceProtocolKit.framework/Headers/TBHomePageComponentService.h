//
//  TBHomePageComponentService.h
//  Pods
//
//  Created by linbingjie on 2022/5/31.
//

#ifndef TBHomePageComponentService_h
#define TBHomePageComponentService_h
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBHomePageComponentService <NSObject>

- (UIViewController *)tbHomePage_initTabViewControllerWithBlock:(nullable void (^)(UIScrollView *scrollView, BOOL isDraging))homepageScrollViewDidScrollBlock;

- (void)tbHomePage_VCScrollToTop:(UIViewController *)homePageVC;

@end

NS_ASSUME_NONNULL_END

#endif /* TBHomePageComponentService_h */

