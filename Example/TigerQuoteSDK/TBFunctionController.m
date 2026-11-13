//
//  TBSDKAllFunctionViewController.m
//  TigerQuoteSDK
//
//  Created by linbingjie on 2025/8/13.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBFunctionController.h"
#import <TBUIKit/TBUIKit.h>

@interface TBSDKFunctionCollectionViewCell : UICollectionViewCell
@property (nonatomic, strong) UILabel *titleLabel;
@end

@implementation TBSDKFunctionCollectionViewCell

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self setupUI];
    }
    return self;
}

- (void)setupUI {
    self.contentView.backgroundColor = [UIColor whiteColor];
    self.contentView.layer.borderWidth = 0.25;
    self.contentView.layer.borderColor = [UIColor grayColor].CGColor;
    
    self.titleLabel = [[UILabel alloc] init];
    self.titleLabel.textAlignment = NSTextAlignmentCenter;
    self.titleLabel.font = [UIFont systemFontOfSize:12.0];
    self.titleLabel.numberOfLines = 0;
    self.titleLabel.textColor = [UIColor blackColor];
    [self.contentView addSubview:self.titleLabel];
    
    [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.leading.mas_equalTo(10);
        make.bottom.trailing.mas_equalTo(-10);
    }];
}

@end

@interface TBSDKFunctionSectionHeaderView : UICollectionReusableView
@property (nonatomic, strong) UILabel *titleLabel;
@end

@implementation TBSDKFunctionSectionHeaderView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self setupUI];
    }
    return self;
}

- (void)setupUI {
    self.titleLabel = [[UILabel alloc] init];
    self.titleLabel.font = [UIFont boldSystemFontOfSize:14.0];
    self.titleLabel.textColor = [UIColor blackColor];
    [self addSubview:self.titleLabel];

    [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(15);
        make.centerY.equalTo(self);
    }];
}

@end

@interface TBFunctionController () <UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>

@property (nonatomic, strong) UICollectionView *collectionView;

@end

@implementation TBFunctionController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupCustomTopBar];
    [self setupCollectionView];
}

- (void)setupCustomTopBar {
    UIView *topBar = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, [self topBarHeight])];
    topBar.backgroundColor = [UIColor whiteColor];
    topBar.layer.shadowColor = [UIColor blackColor].CGColor;
    topBar.layer.shadowOpacity = 0.05;
    topBar.layer.shadowOffset = CGSizeMake(0, 2);
    topBar.layer.shadowRadius = 2;
    [self.view addSubview:topBar];

    UIButton *backButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [backButton setTitle:@"返回" forState:UIControlStateNormal];
    backButton.titleLabel.font = [UIFont systemFontOfSize:16];
    backButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    // 设置系统返回箭头图片
    UIImage *backImage = nil;
    if (@available(iOS 13.0, *)) {
        backImage = [UIImage systemImageNamed:@"chevron.left"];
    } else {
        backImage = [UIImage imageNamed:@"back_arrow"];
    }
    if (backImage) {
        [backButton setImage:backImage forState:UIControlStateNormal];
        backButton.imageEdgeInsets = UIEdgeInsetsMake(0, -8, 0, 0);
    }
    backButton.frame = CGRectMake(15, 0, 70, 44);
    [backButton addTarget:self action:@selector(backButtonTapped) forControlEvents:UIControlEventTouchUpInside];
    [topBar addSubview:backButton];
}

- (void)backButtonTapped {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)setupCollectionView {
    UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
    layout.minimumInteritemSpacing = 0;
    layout.minimumLineSpacing = 0;
    layout.headerReferenceSize = CGSizeMake(self.view.frame.size.width, 40);
    
    self.collectionView = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:layout];
    self.collectionView.backgroundColor = [UIColor whiteColor];
    self.collectionView.dataSource = self;
    self.collectionView.delegate = self;
    self.collectionView.showsVerticalScrollIndicator = NO;
    
    [self.collectionView registerClass:[TBSDKFunctionCollectionViewCell class] forCellWithReuseIdentifier:@"TBSDKFunctionCollectionViewCell"];
    [self.collectionView registerClass:[TBSDKFunctionSectionHeaderView class] forSupplementaryViewOfKind:UICollectionElementKindSectionHeader withReuseIdentifier:@"TBSDKFunctionSectionHeaderView"];
    
    [self.view addSubview:self.collectionView];
    [self.collectionView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo([self topBarHeight]);
        make.leading.trailing.bottom.mas_equalTo(0);
    }];
}

- (CGFloat)topBarHeight {
    return 44;
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return self.sectionTitles.count;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    NSString *sectionTitle = self.sectionTitles[section];
    return self.dataSource[sectionTitle].count;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    TBSDKFunctionCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"TBSDKFunctionCollectionViewCell" forIndexPath:indexPath];

    NSString *sectionTitle = self.sectionTitles[indexPath.section];
    TBCellModel *model = self.dataSource[sectionTitle][indexPath.item];
    cell.titleLabel.text = model.title;
    return cell;
}

- (UICollectionReusableView *)collectionView:(UICollectionView *)collectionView viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath {
    if (kind == UICollectionElementKindSectionHeader) {
        TBSDKFunctionSectionHeaderView *header = [collectionView dequeueReusableSupplementaryViewOfKind:kind withReuseIdentifier:@"TBSDKFunctionSectionHeaderView" forIndexPath:indexPath];
        header.titleLabel.text = self.sectionTitles[indexPath.section];
        return header;
    }
    return nil;
}

#pragma mark - UICollectionViewDelegate

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    [self dismissViewControllerAnimated:NO completion:^{
        NSString *sectionTitle = self.sectionTitles[indexPath.section];
        TBCellModel *model = self.dataSource[sectionTitle][indexPath.item];
        if (model.action) {
            model.action();
        }
    }];
}

#pragma mark - UICollectionViewDelegateFlowLayout

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
    CGFloat itemWidth = (self.view.frame.size.width) / 5.0;
    return CGSizeMake(itemWidth, 80);
}

@end
