//
//  TBTokenManangerViewController.m
//  TigerQuoteSDK
//
//  Created by 骆鹏飞 on 2024/8/17.
//  Copyright © 2024 linbingjie. All rights reserved.
//

#import "TBTokenManangerViewController.h"


#import <TigerTradingSDK/TigerTradingSDKManager.h>
#import <TBUIKit/MBProgressHUD+Wrapper.h>


@interface TBTokenManangerViewController ()
@property (weak, nonatomic) IBOutlet UITextField *clientIdTF;
@property (weak, nonatomic) IBOutlet UITextField *codeTF;
@end

@implementation TBTokenManangerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}
- (IBAction)tapAction:(id)sender {
    [self.view endEditing:YES];
}

- (void)dismissAction {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)dismissAction:(id)sender {
    [self dismissAction];
}

- (IBAction)tokenExchangeAction:(id)sender {
    
    if (self.clientIdTF.text.length == 0) {
        [MBProgressHUD showHint:@"请输入clientid" hide:2];
        return;
    }
    
    if (self.codeTF.text.length == 0) {
        [MBProgressHUD showHint:@"请输入autorizationCode" hide:2];
        return;
    }
    
    NSString *clientId = self.clientIdTF.text;
    NSString *code = self.codeTF.text;
    
    [TigerTradingSDKManager setupBrokerClientId: clientId];
    [self exchangeAutorizationCode:code];
    
}

- (void)exchangeAutorizationCode:(NSString *)autorizationCode {
    [TigerTradingSDKManager registerAccessToken:nil idToken:nil autorizationCode:autorizationCode state:nil callBack:^(BOOL callBack, NSNumber *code, NSString *msg) {
        if (callBack) {
            [self dismissAction];
        } else {
            NSLog(@"token exchange fail");
        }
    }];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
