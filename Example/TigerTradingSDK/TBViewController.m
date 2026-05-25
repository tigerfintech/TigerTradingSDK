//
//  TBViewController.m
//  TigerTradingSDK
//
//  Created by luopengfei on 08/30/2024.
//  Copyright (c) 2024 luopengfei. All rights reserved.
//

#import "TBViewController.h"
#import "TBCellModel.h"

#import <TigerTradingSDK/TigerTradingSDKManager.h>
#import <TigerTradingSDK/TigerTradingSDKSettingManager.h>

#import "TBTokenManangerViewController.h"
#import <TBBaseKit/TBBaseKit.h>
#import <TBNetworking/TBHttpRequestManager.h>
@import TBUIKit;

@interface TBViewController () <UITableViewDelegate, UITableViewDataSource, TigerTradingSDKDelegate>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray<TBCellModel *> *dataSource;

@end

@implementation TBViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    // token 过期处理通知

    // 初始化数据源
    [self setupDataSource];
    
    // 初始化TableView
    [self setupTableView];
    
    TigerTradingSDKManager.delegate = self;    
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    if (self.navigationController) {
        [self.navigationController setNavigationBarHidden:NO animated:animated];
    }
}

/// token 过期处理
/// example 工程处理token过期弹出token 交换页面；
/// 实际使用时需要实现自己的token交换逻辑
- (void)tokenExpired {
    // 交换token
//    [TigerTradingSDKManager registerAccessToken:@"" idToken:@"" autorizationCode:@"" state:@"" callBack:^(BOOL) {
//        
//    }];
}

- (void)viewWillLayoutSubviews {
    [super viewWillLayoutSubviews];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    if (self.navigationController) {
        [self.navigationController setNavigationBarHidden:YES animated:animated];
    }
}

- (void)setupDataSource {
    // Create data source
    TBCellModel *skinModel = [[TBCellModel alloc] initWithTitle:@"Switch Skin" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Select Skin"
                                                                                 message:@"Please choose a skin style"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *whiteSkinAction = [UIAlertAction actionWithTitle:@"Use Light Skin"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            // Handle selection of light skin
            NSLog(@"Selected Light Skin");
            [TigerTradingSDKSettingManager setAppColorStyle:TigerTradingSDKAppearTypeLight];
        }];
        UIAlertAction *blackSkinAction = [UIAlertAction actionWithTitle:@"Use Dark Skin"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            // Handle selection of dark skin
            NSLog(@"Selected Dark Skin");
            [TigerTradingSDKSettingManager setAppColorStyle:TigerTradingSDKAppearTypeDark];
        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // Handle cancellation
            NSLog(@"Selection Cancelled");
        }];
        [alertController addAction:whiteSkinAction];
        [alertController addAction:blackSkinAction];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *langModel = [[TBCellModel alloc] initWithTitle:@"Select Language" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Select Language"
                                                                                 message:@"Please choose a language"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *autoAction = [UIAlertAction actionWithTitle:@"Auto"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            NSLog(@"Selected Auto");
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeAuto];
        }];
        UIAlertAction *enAction = [UIAlertAction actionWithTitle:@"English"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeEnglish];
        }];
        
        UIAlertAction *zhHansAction = [UIAlertAction actionWithTitle:@"Simplified Chinese"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeZhHans];
        }];
        UIAlertAction *zhHantAction = [UIAlertAction actionWithTitle:@"Traditional Chinese"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeZhHant];
        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // Handle cancellation
            NSLog(@"Selection Cancelled");
        }];
        [alertController addAction:autoAction];
        [alertController addAction:enAction];
        [alertController addAction:zhHansAction];
        [alertController addAction:zhHantAction];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *switchRedUPGreenDown = [[TBCellModel alloc] initWithTitle:@"Switch Price Change Colors" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Select Price Change Color"
                                                                                 message:@"Please choose a color scheme"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *redUpGreenDownAction = [UIAlertAction actionWithTitle:@"Red Up, Green Down"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteIncreaseColorType:TigerTradingSDKIncreaseColorTypeRed];
        }];
        UIAlertAction *greenUpRedDownAction = [UIAlertAction actionWithTitle:@"Green Up, Red Down"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteIncreaseColorType:TigerTradingSDKIncreaseColorTypeGreen];

        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // Handle cancellation
            NSLog(@"Selection Cancelled");
        }];
        [alertController addAction:redUpGreenDownAction];
        [alertController addAction:greenUpRedDownAction];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *versionModel = [[TBCellModel alloc] initWithTitle:@"Get SDK Version" action:^{
        NSString *strVersion = [TigerTradingSDKManager sdkVersion];
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"SDK Version"
                                                                                 message:strVersion
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // Handle cancellation
            NSLog(@"Selection Cancelled");
        }];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];
        
    TBCellModel *openSearchVC = [[TBCellModel alloc] initWithTitle:@"Open Search Page" action:^{
        [TigerTradingSDKManager openSearchViewController:self];
    }];
    
    TBCellModel *openOrdersList = [[TBCellModel alloc] initWithTitle:@"Go to Order List" action:^{
        [TigerTradingTradeManager openOrderListViewController:self];
        
    }];
    
    TBCellModel *tupLoginVCModel = [[TBCellModel alloc] initWithTitle:@"TUPLogin OR Homepage" action:^{
        [TigerTradingSDKManager openLoginViewController:self success:^{
            
        } failure:^(NSError * _Nonnull) {
            
        }];
    }];
    
    TBCellModel *logoutModel = [[TBCellModel alloc] initWithTitle:@"Logout" action:^{
        [TigerTradingSDKManager sdkLogout];
    }];
    self.dataSource = @[
        tupLoginVCModel,
        logoutModel,
        skinModel,
        langModel,
        switchRedUPGreenDown,
        openSearchVC,
        openOrdersList,
        versionModel
    ];
}


- (void)setupTableView {
    // 创建TableView
    self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    
    // 注册Cell
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"Cell"];
    
    // 将TableView添加到视图中
    [self.view addSubview:self.tableView];
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];
    
    // 获取对应的模型
    TBCellModel *model = self.dataSource[indexPath.row];
    cell.textLabel.text = model.title;
    
    return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    // 获取对应的模型
    TBCellModel *model = self.dataSource[indexPath.row];
    
    // 执行对应的点击事件
    if (model.action) {
        model.action();
    }
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

@end
