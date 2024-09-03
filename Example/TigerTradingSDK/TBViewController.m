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

@interface TBViewController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray<TBCellModel *> *dataSource;

@end

@implementation TBViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    // token 过期处理通知
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(tokenExpired) name:TigerTradingSDKLoginTokenExpiredNotification object:nil];

    // 初始化数据源
    [self setupDataSource];
    
    // 初始化TableView
    [self setupTableView];
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

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)setupDataSource {
    // 创建数据源
    TBCellModel *model1 = [[TBCellModel alloc] initWithTitle:@"切换皮肤" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"选择皮肤"
                                                                                 message:@"请选择一个皮肤样式"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *whiteSkinAction = [UIAlertAction actionWithTitle:@"使用浅色皮肤"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            // 处理选择白皮肤的逻辑
            NSLog(@"选择了浅色皮肤");
            [TigerTradingSDKSettingManager setAppColorStyle:TigerTradingSDKAppearTypeLight];
        }];
        UIAlertAction *blackSkinAction = [UIAlertAction actionWithTitle:@"使用深色皮肤"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            // 处理选择黑皮肤的逻辑
            NSLog(@"选择了深色皮肤");
            [TigerTradingSDKSettingManager setAppColorStyle:TigerTradingSDKAppearTypeDark];
        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:whiteSkinAction];
        [alertController addAction:blackSkinAction];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *langModel = [[TBCellModel alloc] initWithTitle:@"选择语言" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"选择语言"
                                                                                 message:@"请选择语言"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *autoAction = [UIAlertAction actionWithTitle:@"Auto"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            NSLog(@"选择了自动");
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeAuto];
        }];
        UIAlertAction *enAction = [UIAlertAction actionWithTitle:@"English"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeEnglish];
        }];
        
        UIAlertAction *zhHansAction = [UIAlertAction actionWithTitle:@"简体中文"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeZhHans];
        }];
        UIAlertAction *zhHantAction = [UIAlertAction actionWithTitle:@"繁体中文"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeZhHant];
        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:autoAction];
        [alertController addAction:enAction];
        [alertController addAction:zhHansAction];
        [alertController addAction:zhHantAction];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *modelColor = [[TBCellModel alloc] initWithTitle:@"切换涨跌色" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"选择涨跌色"
                                                                                 message:@"请选择一个涨跌颜色"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *whiteSkinAction = [UIAlertAction actionWithTitle:@"使用红涨绿跌"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteIncreaseColorType:TigerTradingSDKIncreaseColorTypeRed];
        }];
        UIAlertAction *blackSkinAction = [UIAlertAction actionWithTitle:@"使用绿涨红跌"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteIncreaseColorType:TigerTradingSDKIncreaseColorTypeGreen];

        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:whiteSkinAction];
        [alertController addAction:blackSkinAction];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *versionModel = [[TBCellModel alloc] initWithTitle:@"获取SDK版本号" action:^{
        NSString *strVersion = [TigerTradingSDKManager sdkVersion];
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"版本号"
                                                                                 message:strVersion
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *tokenModel = [[TBCellModel alloc] initWithTitle:@"保存Token" action:^{
        TBTokenManangerViewController *vc = [[TBTokenManangerViewController alloc] init];
        if (self.navigationController) {
            [self.navigationController pushViewController:vc animated:YES];
        }
        else {
            [self presentViewController:vc animated:YES completion:nil];
        }
//        [self presentViewController:vc animated:YES completion:nil];
    }];
        
    TBCellModel *model3 = [[TBCellModel alloc] initWithTitle:@"打开搜索页面" action:^{
        [TigerTradingSDKManager openSearchViewController:self];
    }];
    
    TBCellModel *model4 = [[TBCellModel alloc] initWithTitle:@"跳转首页" action:^{
        NSLog(@"Tapped on Item 4");
        // 实现对应的逻辑
        [TigerTradingSDKManager openHomePageViewController: self];
        
    }];
    
    TBCellModel *model5 = [[TBCellModel alloc] initWithTitle:@"跳转订单列表" action:^{
        NSLog(@"Tapped on Item 4");
        // 实现对应的逻辑
        [TigerTradingSDKManager openOrderListViewController: self];
        
    }];
    
    self.dataSource = @[
        model1,
        langModel,
        modelColor,
        versionModel,
        tokenModel,
        model4,
        model3,
        model5
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
