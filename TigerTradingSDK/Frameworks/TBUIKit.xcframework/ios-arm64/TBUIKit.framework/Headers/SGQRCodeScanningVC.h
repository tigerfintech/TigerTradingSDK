//
//  SGQRCodeScanningVC.h
//  SGQRCodeExample
//
//  Created by kingsic on 17/3/20.
//  Copyright © 2017年 kingsic. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBBaseViewController.h>

@class SGQRCodeScanningVC;

@protocol SGQRCodeScanningVCDelegate <NSObject>

@required
- (void)codeScanningVC:(SGQRCodeScanningVC *)viewController successWithStringValue:(NSString *)stringValue;

@end

@interface SGQRCodeScanningVC : TBBaseViewController

@property (nonatomic, weak) id<SGQRCodeScanningVCDelegate> delegate;

@property (nonatomic, copy) void(^SuccessWithStringValueBlock)(SGQRCodeScanningVC * qrVC, NSString * stringValue);

@end
