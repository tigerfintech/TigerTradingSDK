//
//  TBSDKAccountPortfolioRatioShareCardView.m
//  TBTradeBusiness
//
//  Created by dulijun on 2023/4/19.
//
#if __has_include(<TBShareKit/TBCardShareView.h>)

#import <TBUIKit/TBFont.h>
#import <Masonry/Masonry.h>
#import <TBUIKit/TBAppColor.h>
#import <TBBusinessSupportKit/TBStock+TBFormat.h>
#import <TBUIKit/TBUIKit.h>

#import "TBSDKAccountPortfolioRatioShareCardView.h"
#import <TBTradeBusinessBaseKit/TBTradeAssetTodayPnLShareInfoModel.h>
#import <TBTradeBusinessBaseKit/TBTradeAPIPositionModel.h>
#import <TBTradeBusinessBaseKit/TBPositionDataManager.h>
@import ChartKLineView;
#if TB_EXAMPLE_US_TARGET
#import "TigerQuoteSDK_Example_US-Swift.h"
#else
#import "TigerQuoteSDK_Example-Swift.h"
#endif

@interface TBAccountPortfolioRatioShareCardSubView : UIView

@property (nonatomic, strong) UIView *cView;
@property (nonatomic, strong) UILabel *label1;
@property (nonatomic, strong) UILabel *label2;

@end

@implementation TBAccountPortfolioRatioShareCardSubView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.cView = [[UIView alloc] init];
        self.cView.layer.masksToBounds = YES;
        self.cView.layer.cornerRadius = 3;
        
        self.label1 = [[UILabel alloc] initWithFont:FONTO(12) color:RGBCOLOR_HEX(0x2C2E3B)];
        self.label1.adjustsFontSizeToFitWidth = NO;
        self.label2 = [[UILabel alloc] initWithFont:BOLDFONTO(12) color:RGBCOLOR_HEX(0x2C2E3B)];
        self.label2.textAlignment = NSTextAlignmentRight;
        
        [self addSubview:self.cView];
        [self addSubview:self.label1];
        [self addSubview:self.label2];

        [self.cView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.equalTo(self).offset(k_LeftOffset);
            make.centerY.equalTo(self);
            make.width.height.mas_equalTo(6);
        }];
        [self.label1 mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerY.equalTo(self);
            make.left.equalTo(self.cView.mas_right).offset(6);
            make.right.equalTo(self.label2.mas_left).offset(-5);
        }];
        [self.label2 mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerY.equalTo(self);
            make.right.equalTo(self).offset(0);
            make.width.mas_equalTo(45);
        }];
    }
    return self;
}

- (void)updateSubView:(UIColor *)color symbol:(NSString *)symbol percentStr:(NSString *)percentStr {
    self.cView.backgroundColor = color;
    self.label1.text = symbol;
    self.label2.text = percentStr;
}

@end

@interface TBSDKAccountPortfolioRatioShareCardView () <ChartViewDelegate>

@property (nonatomic, strong) PieChartView *chartView;
@property (nonatomic, strong) UIView *itemView;
@property (nonatomic, strong) UILabel *bottomLabel;

@end

@implementation TBSDKAccountPortfolioRatioShareCardView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self setupViews];
    }
    return self;
}

- (void)setupViews {
    self.backgroundColor = RGBCOLOR_HEX(0xFFFFFF);
    self.descriptionLabel.hidden = YES;
    self.stickerImageView.hidden = YES;
    self.editButton.hidden = YES;
    
    // 初始化饼状图控件
    [self addSubview:self.chartView];
    [self addSubview:self.itemView];
    [self addSubview:self.bottomLabel];
    
    [self.chartView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self).offset(60);
        make.left.equalTo(self).offset(k_LeftOffset);
        make.right.equalTo(self).offset(-k_LeftOffset);
        make.height.mas_equalTo(260);
    }];
    [self.itemView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.equalTo(self);
        make.height.mas_equalTo(27 * 3);
        make.top.equalTo(self.chartView.mas_bottom);
    }];
    [self.bottomLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self).offset(16);
        make.right.equalTo(self).offset(-16);
        make.top.equalTo(self.itemView.mas_bottom).offset(20);
    }];
}

- (void)layoutSubviews {
    NSMutableArray<TBTradeAPIPositionItemModel *> *positions = [[TBPositionDataManager sharedInstance].stockPositions mutableCopy];
    TBTradeAPIPositionItemModel *currency = [[TBTradeAPIPositionItemModel alloc] init];
    currency.positionsPercent = @(self.todayPnLInfoModel.cashBalance.doubleValue / (self.todayPnLInfoModel.securitiesTotalValue.doubleValue + self.todayPnLInfoModel.cashBalance.doubleValue));
    currency.symbol =
    currency.nameCN = TBResourcesLocalizedString(@"mobile_comm_common_cash_balance", nil);
    if (currency.positionsPercent.doubleValue >= 0) {
        [positions addObject:currency];
    }
    
    CGFloat allPercent = 0;
    for (TBTradeAPIPositionItemModel *obj in positions) {
        allPercent += obj.positionsPercent.doubleValue;
    }
    
    BOOL isEmpty = positions.count == 0;
    self.chartView.hidden = isEmpty;
    if (isEmpty) {
        self.chartView.data = nil;
        return;
    }
    [self.chartView highlightValue:nil];
    
   NSArray *result = [positions sortedArrayUsingComparator:^NSComparisonResult(TBTradeAPIPositionItemModel *obj1, TBTradeAPIPositionItemModel *obj2) {
        if (!obj2.positionsPercent || !obj1.positionsPercent) {
            return NSOrderedSame;
        }
        else {
            return [obj2.positionsPercent compare:obj1.positionsPercent];
        }
    }];
    
    [self.itemView removeAllSubviews];
    NSMutableArray *entyrs = [NSMutableArray array];
    NSMutableArray *colors = [NSMutableArray array];
    CGFloat top5Percent = 0;
    BOOL showOther = positions.count >= 6;
    NSInteger pieCount = showOther ? 6 : positions.count;
    CGFloat subViewHeight = 27;
    CGFloat subViewWidth = (self.tb_width - 16)/2;
    for (int i = 0; i < pieCount; i++) {
        TBAccountPortfolioRatioShareCardSubView *view = [[TBAccountPortfolioRatioShareCardSubView alloc] init];
        UIColor *color = [self getChartColors][i % [self getChartColors].count];
        [colors addObject:color];
        NSString *objSymbol = TBResourcesLocalizedString(@"mobile_comm_common_others", nil);
        CGFloat objPercent = 0;
        if (i == 5) {
            objPercent = allPercent - top5Percent;
            PieChartDataEntry *entry = [[PieChartDataEntry alloc] initWithValue:objPercent data:[NSString stringWithFormat:@"%d",i]];
            [entyrs addObject:entry];
            
        } else {
            TBTradeAPIPositionItemModel *model = result[i];
            objSymbol = model.nameCN;
            NSNumber *number = model.positionsPercent;
            //过滤负值
            if (number.doubleValue < 0) {
                continue;
            }
            top5Percent += number.doubleValue;
            objPercent = number.doubleValue;
            PieChartDataEntry *entry = [[PieChartDataEntry alloc] initWithValue:number.doubleValue data:[NSString stringWithFormat:@"%d",i]];
            [entyrs addObject:entry];
        }
        [view updateSubView:color symbol:objSymbol percentStr:[NSString stringWithFormat:@"%.2f%%", objPercent / allPercent * 100]];
        [self.itemView addSubview:view];
        [view mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.equalTo(self.itemView).offset(i%2*subViewWidth);
            make.height.mas_equalTo(subViewHeight);
            make.width.mas_equalTo(subViewWidth);
            make.top.equalTo(self.itemView).offset(i/2*subViewHeight);
        }];
    }
    NSInteger lineCount = (pieCount + 1)/2;
    [self.itemView mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.left.right.equalTo(self);
        make.height.mas_equalTo(subViewHeight * lineCount);
        make.top.equalTo(self.chartView.mas_bottom);
    }];
    
    // 倒序排列 防止低占比连续排列 导致展示重叠的问题
    NSMutableArray *fEntyrs = [NSMutableArray array];
    NSMutableArray *tmpEntyrs = [entyrs mutableCopy];

    NSMutableArray *fColors = [NSMutableArray array];
    NSMutableArray *tmpColors = [colors mutableCopy];

    for (int i = 0; i < entyrs.count; i++) {
        [fEntyrs addObject:tmpEntyrs.lastObject];
        [tmpEntyrs removeLastObject];
        [fColors addObject:tmpColors.lastObject];
        [tmpColors removeLastObject];
    }
    entyrs = [fEntyrs mutableCopy];
    colors = [fColors mutableCopy];
    
    PieChartDataSet *dataSet = [[PieChartDataSet alloc] initWithEntries:entyrs];
    dataSet.sliceSpace = 3.0;
    dataSet.colors = colors;

    /// 直线外延+数字的形式来展示饼图
    dataSet.valueLinePart1Length = 0.4; //比例调大一点，减缓两个label上下重叠的情况
    dataSet.valueLinePart2Length = 1;
    dataSet.yValuePosition = PieChartValuePositionOutsideSlice;
    
    dataSet.highlightEnabled = NO;
    
    PieChartData *data = [[PieChartData alloc] initWithDataSet:dataSet];
    
    NSNumberFormatter *pFormatter = [[NSNumberFormatter alloc] init];
    pFormatter.numberStyle = NSNumberFormatterPercentStyle;
    pFormatter.maximumFractionDigits = 2;
    pFormatter.minimumFractionDigits = 2;
    pFormatter.multiplier = @1.f;
    pFormatter.percentSymbol = @"%";
    dataSet.numberFormatter = pFormatter;
    [data setValueFont:NUMFONTO(14)];
    [data setValueTextColor:RGBCOLOR_HEX(0x2C2E3B)];
    
    self.chartView.data = data;
}

- (NSArray *)getChartColors {
    return @[RGBCOLOR_HEX(0x00B5FF),
             RGBCOLOR_HEX(0x37C4CC),
             RGBCOLOR_HEX(0x30BFA7),
             RGBCOLOR_HEX(0xFFE100),
             RGBCOLOR_HEX(0xFFA84B),
             RGBCOLOR_HEX(0xFF783E),
             RGBCOLOR_HEX(0xF25855),
             RGBCOLOR_HEX(0xFD5097),
             RGBCOLOR_HEX(0xB366FF),
             RGBCOLOR_HEX(0x8D7A70),
             RGBCOLOR_HEX(0x447EFF),
             RGBCOLOR_HEX(0xFF71FA),
             RGBCOLOR_HEX(0xCF550B),
             RGBCOLOR_HEX(0xE32B65),
             RGBCOLOR_HEX(0x9F46F5),
             RGBCOLOR_HEX(0x28A697),
             RGBCOLOR_HEX(0x61B21C),
             RGBCOLOR_HEX(0x44AAFF),
             RGBCOLOR_HEX(0x8E5FE4),
             RGBCOLOR_HEX(0xFFC06C),
             RGBCOLOR_HEX(0xFF9D4E)
    ];
}

- (PieChartView *)chartView {
    if (!_chartView) {
        _chartView = [[PieChartView alloc] initWithFrame:CGRectZero];
        _chartView.renderer = [[TBSDKStockPositionSharePieRenderer alloc] initWithChart:_chartView animator:_chartView.chartAnimator viewPortHandler:_chartView.viewPortHandler];

        [_chartView setBackgroundColor:[UIColor clearColor]];
        _chartView.holeColor = [UIColor clearColor];
        _chartView.usePercentValuesEnabled = YES;
        _chartView.holeRadiusPercent = 0.55;
        _chartView.transparentCircleRadiusPercent = 0.0;
        _chartView.chartDescription.enabled = NO;

        _chartView.drawCenterTextEnabled = YES;
        _chartView.rotationAngle = 180.0f;
        [_chartView setExtraOffsetsWithLeft:25 top:25 right:25 bottom:25];
        
        _chartView.drawHoleEnabled = YES;
        _chartView.rotationEnabled = YES;
        _chartView.highlightPerTapEnabled = YES;
        
        _chartView.legend.enabled = NO;
        _chartView.userInteractionEnabled = NO;
    }
    return _chartView;
}

- (UIView *)itemView {
    if (!_itemView) {
        _itemView = [[UIView alloc] init];
        _itemView.backgroundColor = [UIColor clearColor];
    }
    return _itemView;
}

- (UILabel *)bottomLabel {
    if (!_bottomLabel) {
        _bottomLabel = [[UILabel alloc] initWithFont:FONTO(12) color:RGBCOLOR_HEX(0xA6A9B6)];
        _bottomLabel.numberOfLines = 0;
        _bottomLabel.text = [NSString stringWithFormat:@"* %@",  TBResourcesLocalizedString(@"mobile_comm_common_inconsistent_ratio", nil)];
        _bottomLabel.adjustsFontSizeToFitWidth = NO;
    }
    return _bottomLabel;
}

@end
#endif
