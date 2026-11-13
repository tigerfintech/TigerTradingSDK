//
//  TBSDKAllFunctionViewController.m
//  TigerQuoteSDK
//
//  Created by linbingjie on 2025/8/13.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBSDKAllFunctionViewController.h"
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#import <TBUIKit/TBUIKit.h>

// 自定义CollectionViewCell
@interface TBCustomCollectionViewCell : UICollectionViewCell
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UILabel *titleLabel;
@end

@implementation TBCustomCollectionViewCell

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self setupUI];
    }
    return self;
}

- (void)setupUI {
    // 创建ImageView
    self.imageView = [[UIImageView alloc] init];
    self.imageView.contentMode = UIViewContentModeScaleAspectFit;
    self.imageView.clipsToBounds = YES;
    self.imageView.layer.cornerRadius = 8.0;
    [self.contentView addSubview:self.imageView];
    
    // 创建Label
    self.titleLabel = [[UILabel alloc] init];
    self.titleLabel.textAlignment = NSTextAlignmentCenter;
    self.titleLabel.font = [UIFont systemFontOfSize:14.0];
    self.titleLabel.textColor = [UIColor blackColor];
    self.titleLabel.numberOfLines = 1;
    [self.contentView addSubview:self.titleLabel];
    
    // 设置约束
    self.imageView.translatesAutoresizingMaskIntoConstraints = NO;
    self.titleLabel.translatesAutoresizingMaskIntoConstraints = NO;
    
    [NSLayoutConstraint activateConstraints:@[
        [self.imageView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor constant:8],
        [self.imageView.leadingAnchor constraintEqualToAnchor:self.contentView.leadingAnchor constant:8],
        [self.imageView.trailingAnchor constraintEqualToAnchor:self.contentView.trailingAnchor constant:-8],
        [self.imageView.heightAnchor constraintEqualToAnchor:self.imageView.widthAnchor],
        
        [self.titleLabel.topAnchor constraintEqualToAnchor:self.imageView.bottomAnchor constant:8],
        [self.titleLabel.leadingAnchor constraintEqualToAnchor:self.contentView.leadingAnchor constant:4],
        [self.titleLabel.trailingAnchor constraintEqualToAnchor:self.contentView.trailingAnchor constant:-4],
        [self.titleLabel.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor constant:-8]
    ]];
}

@end

@interface TBSDKAllFunctionViewController () <UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>

@property (nonatomic, strong) UICollectionView *collectionView;
@property (nonatomic, strong) NSArray *dataArray;

@end

@implementation TBSDKAllFunctionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor systemPinkColor];
    [self setupData];
    [self setupCollectionView];
}

- (void)setupData {
    
    [TigerTradingTradeManager fetchAllFunctionDataSources:YES success:^(NSArray<TigerTradingAllFunctionModel *> * _Nonnull items) {
        self.dataArray = items;
        [self.collectionView reloadData];
    } failure:^(NSError * _Nonnull error) {
        
    }];

}

- (void)setupCollectionView {
    // 创建布局
    UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
    layout.minimumInteritemSpacing = 10;
    layout.minimumLineSpacing = 20;
    layout.sectionInset = UIEdgeInsetsMake(20, 20, 20, 20);
    
    // 计算item大小
    CGFloat itemWidth = (self.view.frame.size.width - 60) / 5; // 3列，左右边距各20，中间间距10
    layout.itemSize = CGSizeMake(itemWidth, itemWidth + 40); // 图片宽度 + 文字高度 + 间距
    
    // 创建CollectionView
    self.collectionView = [[UICollectionView alloc] initWithFrame:self.view.bounds collectionViewLayout:layout];
    self.collectionView.backgroundColor = [UIColor whiteColor];
    self.collectionView.dataSource = self;
    self.collectionView.delegate = self;
    self.collectionView.showsVerticalScrollIndicator = NO;
    
    // 注册自定义cell
    [self.collectionView registerClass:[TBCustomCollectionViewCell class] forCellWithReuseIdentifier:@"CustomCell"];
    
    [self.view addSubview:self.collectionView];
    
    // 设置约束
    self.collectionView.translatesAutoresizingMaskIntoConstraints = NO;
    [NSLayoutConstraint activateConstraints:@[
        [self.collectionView.topAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.topAnchor],
        [self.collectionView.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [self.collectionView.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor],
        [self.collectionView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor]
    ]];
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return self.dataArray.count;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    TBCustomCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"CustomCell" forIndexPath:indexPath];
    
    TigerTradingAllFunctionModel *model = self.dataArray[indexPath.item];
    cell.titleLabel.text = model.title;
    
    // 设置图片（这里使用系统图标作为示例，实际项目中应该使用真实的图片资源）
    NSString *imageName = model.imageName;
    
    cell.imageView.image = [UIImage tb_imageNamed:imageName];
    
    return cell;
}

#pragma mark - UICollectionViewDelegate

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    TigerTradingAllFunctionModel *model = self.dataArray[indexPath.item];
    [TigerTradingTradeManager allfunctionAction:model];
}


#pragma mark - UICollectionViewDelegateFlowLayout

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
    CGFloat itemWidth = (self.view.frame.size.width - 60) / 5;
    return CGSizeMake(itemWidth, itemWidth + 40);
}

@end
