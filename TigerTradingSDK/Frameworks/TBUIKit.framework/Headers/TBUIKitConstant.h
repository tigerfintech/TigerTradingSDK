//
//  TBUIKitConstant.h
//  Stock
//
//  Created by liwt on 10/9/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//



#ifndef TBUIKitConstant_h
#define TBUIKitConstant_h

#import <TBUIKit/TBAppColor.h>

#define COLOR_ACCOUNT_BACKGROUND                            [TBAppColor lightBackgroundColor]
#define COLOR_GRAY_BACKGROUND                               [TBAppColor grayBackgroundColor]

//--------------------

#pragma mark - Basic Color

#define COLOR_CELL_DETAIL                                   COLOR_SELECTED

#define COLOR_SEPERATE_LINE                                 RGBCOLOR_HEX(0x494756)


#define COLOR_TRADE_TITLE                                   [TBAppColor tradeTitleColor]
#define COLOR_PLACEHOLDER_TEXT                              [TBAppColor placeHolderColor]
#define COLOR_LOGIN_BACKGROUND_DARK                         [TBAppColor loginDarkBackgroundColor]
#define COLOR_TAB_BACKGROUND                                [TBAppColor tabBarBackgroundColor]
#define COLOR_SHALLOW_BLUE                                  [TBAppColor shallowBlueColor]
#define COLOR_SHALLOW_ORANGE                                [TBAppColor shallowOrangeColor]
#define COLOR_DARK_BLUE                                     [TBAppColor darkBlueColor]

#define COLOR_REFRESH_FOOTER                                RGBCOLOR_HEX(0x8c9192)
#define COLOR_WHITE_SELECTED_CELL                           RGBCOLOR_HEX(0xF3F3F3)

#define TEXT_COLOR                                          COLOR_TEXT_COMMON


#define COLOR_VIEW_DISABLE                                  [TBAppColor viewDisabledColor]
#define COLOR_POST_LIST_BOTTOM_SEPARATOR                    [TBAppColor colorFromDark:0x14151C white:0xE6E6E9]
#define COLOR_BADGE_BACKGROUND                              [TBAppColor badgeBackgroundColor]
#define COLOR_BADGE_TEXT                                    [TBAppColor badgeTextColor]

#pragma mark - 6.5.9全新视觉规范
//APP的主题色，当前与yellowColor相当
#define COLOR_THEME                                         [TBAppColor themeColorB4]
#define COLOR_TEXT_STYLE1                                   [TBAppColor themeColorB1]
#define COLOR_TEXT_STYLE2                                   [TBAppColor themeColorB2]
#define COLOR_TEXT_STYLE3                                   [TBAppColor themeColorB3]

#pragma mark
#define CONTENT_BACKGROUND_COLOR_WITH_ALPHA                 [UIColor colorWithRed:(28)/255.0f green:(36)/255.0f blue:(41)/255.0f alpha:0.1]
#define CONTENT_BACKGROUND_COLOR_WITH_ALPHA_ZERO            [UIColor colorWithRed:(28)/255.0f green:(36)/255.0f blue:(41)/255.0f alpha:0.0]
#define INCREASE_PRICE_COLOR_WITH_ALPHA                     [UIColor colorWithRed:(245)/255.0f green:(92)/255.0f blue:(69)/255.0f alpha:0]
#define DISCREASE_PRICE_COLOR_WITH_ALPHA                    [UIColor colorWithRed:(51)/255.0f green:(184)/255.0f blue:(51)/255.0f alpha:0]

#define BTN_COLOR                                           RGBCOLOR_HEX(0x2173E1)
#define WARNING_TIP_TEXT_COLOR                              RGBCOLOR_HEX(0xC33C55)
#define SETTING_BACKGROUND_COLOR                            RGBCOLOR_HEX(0x2C2A35)


#define TABLE_VIEW_CELL_SELECTED_COLOR                      RGBCOLOR_HEX(0x101010)

#define TABBAR_BACKGROUND_COLOR                             RGBCOLOR_HEX(0x202020)



#define CONTENT_BACKGROUND_COLOR                            RGBCOLOR_HEX(0x181818)

#define OPERATION_VIEW_DISABLE_TEXT_COLOR                   RGBCOLOR_HEX(0x3D3D41)


#define NAVIGATION_BAR_TITLE_COLOR                          RGBCOLOR_HEX(0x9AAEB8)
#define CUSTOM_BLUE_COLOR                                   RGBCOLOR_HEX(0x3556B2)
#define CUSTOM_ORANGE_COLOR                                 RGBCOLOR_HEX(0xCCB439)

/// MARK- V3.2，样式统一颜色修改
#define CUSTOM_SEGEMENT_BACKGROUDCOLOR                      RGBCOLOR_HEX(0x211E24)





#define SECTION_BGVIEW_BACKGROUND_COLOR                     RGBCOLOR_HEX(0x42414C)
#define NAVIGATOR_COLOR                                     RGBCOLOR_HEX(0x1E1E1E)

#define SEARCH_BACKGROUND_COLOR                             RGBCOLOR_HEX(0x1D1D1D)
#define SEGMENT_CONTROL_COLOR                               RGBCOLOR_HEX(0x222222)
#define SEGMENT_BACKGROUND_COLOR                            RGBCOLOR_HEX(0x282828)
#define TRADE_ACTION_BAR_BACKGROUND_COLOR                   RGBCOLOR_HEX(0x1F1F1F)


#define SINGLE_LINE_IN_STOCK_DETAIL                         RGBCOLOR_HEX(0x4A3A3D)

#define LINE_COLOR_MA1                                      RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_MA2                                      RGBCOLOR_HEX(0xCAA16C)
#define LINE_COLOR_MA3                                      RGBCOLOR_HEX(0x3784B4)
#define LINE_COLOR_MA4                                      RGBCOLOR_HEX(0X999CFF)
#define LINE_COLOR_MA5                                      RGBCOLOR_HEX(0X19B6B5)

#define LINE_COLOR_EMA1                                     RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_EMA2                                     RGBCOLOR_HEX(0xCAA16C)
#define LINE_COLOR_EMA3                                     RGBCOLOR_HEX(0x3784B4)

#define LINE_COLOR_BOLL_UPPER                               RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_BOLL_MID                                 RGBCOLOR_HEX(0xCAA16C)
#define LINE_COLOR_BOLL_DOWN                                RGBCOLOR_HEX(0x3784B4)

#define LINE_COLOR_BOLL_KLINE                               RGBCOLOR_HEX(0x3784B4)
#define LINE_COLOR_MACD_DIFF                                RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_MACD_DEM                                 RGBCOLOR_HEX(0xCAA16C)

#define LINE_COLOR_KDJ_K                                    RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_KDJ_D                                    RGBCOLOR_HEX(0xCAA16C)
#define LINE_COLOR_KDJ_J                                    RGBCOLOR_HEX(0x3784B4)

#define LINE_COLOR_RSI_1                                    RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_RSI_2                                    RGBCOLOR_HEX(0xCAA16C)
#define LINE_COLOR_RSI_3                                    RGBCOLOR_HEX(0x3784B4)

#define LINE_COLOR_OBV                                      RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_CCI                                      RGBCOLOR_HEX(0xBEA07C)

#define LINE_COLOR_AR                                       RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_BR                                       RGBCOLOR_HEX(0xCAA16C)

// TODO: 定义 DMI, WR, EMV, DMA 的颜色
#define LINE_COLOR_DI1                                      RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_DI2                                      RGBCOLOR_HEX(0xCAA16C)
#define LINE_COLOR_ADX                                      RGBCOLOR_HEX(0x3784B4)
#define LINE_COLOR_ADXR                                     RGBCOLOR_HEX(0xFFFFFF)

#define LINE_COLOR_WR10                                     RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_WR6                                      RGBCOLOR_HEX(0xCAA16C)

#define LINE_COLOR_EMV                                      RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_EMVA                                     RGBCOLOR_HEX(0xCAA16C)

#define LINE_COLOR_DDD                                      RGBCOLOR_HEX(0xA83876)
#define LINE_COLOR_AMA                                      RGBCOLOR_HEX(0xCAA16C)

#define COLOR_ACCOUNT_BUTTON_TITLE                     RGBCOLOR_HEX(0x171717)
//

#define COLOR_CHART_BORDER                                  [[UIColor lightGrayColor] colorWithAlphaComponent:0.55]

#pragma mark Color 

#define COLOR_ORDER_BUY                                     RGBCOLOR_HEX(0xE2884A)
#define COLOR_ORDER_SELL                                    RGBCOLOR_HEX(0x45CCCE)

#define COLOR_ORDER_BUY_INCREASE                            [TBStock getIncreaseColor]
#define COLOR_ORDER_SELL_DECREASE                           [TBStock getDecreaseColor]


#define COLOR_BACKGROUND_COMMON                             [UIColor blackColor]

#define COLOR_TEXT_LOGIN_BUTTON                             RGBCOLOR_HEX(0x332C2F)

#define COLOR_MENU_SELECTED                                 RGBCOLOR_HEX(0x282828)
#define COLOR_DARD_GREY                                     RGBCOLOR_HEX(0x707070)
#define COLOR_SECOND_MENU                                   RGBCOLOR_HEX(0xA4A3A3)
#define COLOR_TITLE_DARK1                                   RGBCOLOR_HEX(0x333333)
#define COLOR_SEPARATOR_GRAY                                RGBCOLOR_HEX(0xD9D9D9)
#define COLOR_TEXTBG_WHITE                                  RGBCOLOR_HEX(0xF4F4F4)

#define COLOR_ACCOUNT_LINE                                  RGBCOLOR_HEX(0x313131)
#define COLOR_PLACEHOLDER                                   RGBCOLOR_HEX(0x898989)
#define COLOR_EDIT_UNUSE                                    RGBCOLOR_HEX(0x808080)
#define COLOR_SEGMENTC_LINE                                 RGBCOLOR_HEX(0x181818)
#define COLOR_OPTION_CALL_BACKGROUND                        RGBCOLOR_HEX(0x251D2A)
#define COLOR_OPTION_PUT_BACKGROUND                         RGBCOLOR_HEX(0x1E262B)


#define POP_VIEW_BACKGROUND_COLOR                           [UIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:0.8]
#define POP_VIEW_TITLE_COLOR                                RGBCOLOR_HEX(0x333333)
#define POP_VIEW_TEXT_COLOR                                 RGBCOLOR_HEX(0x666666)
#define POP_VIEW_TEXT2_COLOR                                RGBCOLOR_HEX(0x999999)
#define POP_VIEW_BUTTON_COLOR                               RGBCOLOR_HEX(0xCCCCCC)

#define POP_VIEW_BLACK_COLOR                                RGBCOLOR_HEX(0x4F5364)
#define POP_VIEW_YELLOW_COLOR                               RGBCOLOR_HEX(0xF8CC00)
#define POP_VIEW_RED_COLOR                                  RGBCOLOR_HEX(0xFD4E50)
#define POP_VIEW_WIDTH                                      270


#define TB_POP_VIEW_TITLE_COLOR                                RGBCOLOR_HEX(0x2C2E3B)
#define TB_POP_VIEW_SUBTITLE_COLOR                             RGBCOLOR_HEX(0x4F5364)
#define TB_POP_VIEW_EXTRA_TITLE_COLOR                          RGBCOLOR_HEX(0xA6A9B6)

#define TB_POP_VIEW_BACKGROUND_COLOR                           RGBCOLOR_HEX(0xF7F7FA)
#define TB_POP_VIEW_ALERT_RED                                  RGBCOLOR_HEX(0xFD4E50)

#define TB_POP_ONE_BUTTON_WIDTH                                200
#define TB_POP_ONE_BUTTON_HEIGHT                               40
#define TB_POP_TWO_BUTTON_WIDTH                                125

#define TB_POP_VIEW_WIDTH                                      300
#define TB_POP_BUTTON_CORNERRADIUS                             20
#define TB_POP_VIEW_CORNERRADIUS                               10

#define TB_POP_VIEW_EDGE_SPACE                                 20

#define TB_POP_VIEW_TITLE_FONT                          BOLDFONTO(16)
#define TB_POP_VIEW_TITLE_FONT20                        BOLDFONTO(20)
#define TB_POP_VIEW_SUBTITLE_FONT                       FONTO(14)
#define TB_POP_VIEW_EXTRATITLE_FONT                     FONTO(12)

#pragma mark Top_Left_Right_Bottom_Span_Size
#define k_RectScreen                                        ([[UIScreen mainScreen] bounds])
#define autoFitScreen(x) x*(IS_IPHONE_5_OR_LESS ? [UIScreen mainScreen].bounds.size.width/375.0 : 1)

#define allAutoFitScreen(x) x*[UIScreen mainScreen].bounds.size.width/375.0

#define k_OrderCell_Name_Width                           (SCREEN_WIDTH - k_LeftOffset*2)*111/345
#define k_OrderCell_Other_Width                          (SCREEN_WIDTH - k_LeftOffset*2)*73/345
#define k_OrderCell_Item_Space                           (SCREEN_WIDTH - k_LeftOffset*2)*5/345

#define k_OrderCell_CodeImage_Space                       4

#define k_SpanIn                                            (k_RectScreen.size.width/80)
#define k_SpanLeft                                          (k_SpanIn * 2)
#define k_SpanVertical                                      (k_SpanIn)
#define k_SpanHorizontal                                    (k_SpanIn)
#define k_Cell_Portrait_w                                   (40)
#define k_Cell_Picture_w                                    (90)
#define k_Cell_Picture_h                                    (60)
#define k_Font_SmallTitle                                   (15.0f)
#define k_Font_SmallsubTitle                                (14.0f)
#define k_Font_BigTitle                                     (16.0f)
#define k_Font_BigSubTitle                                  (15.0f)
#define k_font_newsTitle                                    (17.0f)
#define k_font_newsSubTitle                                 (14.0f)
#define k_font_newsContent                                  (15.0f)
#define k_MarginH                                           (15.0f) //水平

// 列表分割条高度
#define kTableViewSectionSpace                              (6.0f)
// 列表标题栏高度
#define kTableViewSectionHeaderHeight                       (35.0f)

#define kTableViewSectionHeaderHeight40                     (40.0f)
//水平间距
#define k_HorzMargin                                        (10.0f)

#define kTBTableViewCellDefaultHeight                       (44.0f)

// 下单页 cell 高度
#define kPlaceOrderCellHeight                               (50.0f)

#define kPlaceOrderCellTitleHeight                          (50.0f)

// 下单页说明栏 cell 高度
#define kPlaceOrderPromptCellHeight                         (25.0f)
// 下单页 cell 分割线高度
#define kPlaceOrderCellSeparatorHeight                      K_1PX

#define kPlaceOrderRoundDemon                               0.1

#define k_PostLeft                                          (15.0f)
#define k_PostTop                                           (12.0f)
#define k_PostSmallTop                                      (12.0f)
#define k_PostMargin                                        (10.0f)

#pragma mark font size

#define FONT_CN_NAME                                        15.0f
#define FONT_ENG_NAME                                       12.0f
#define FONT_NUM                                            17.0f
#define FONT_YELLOW                                         16.0f
#define FONT_DETAIL                                         14.0f
#define FONT_CELL                                           15.0f
#define FONT_BIG                                            20.0f
#define FONT_MIN                                            10.0f
#define FONT_ME_DEFAULT                                     (15.0f)
#define FONT_ACCOUNT_DEFAULT                                14.0f
#define FONT_CELLTITLE                                      BOLDFONTO(17.f)
#define FONT_CELLCONTENT                                    FONTO(14.f)
#define FONT_ENG_BIGNAME                                    13.0f
#define FONT_ENG_SMALLNAME                                  11.0f
#define FONT_12                                             12.0f
#define FONT_INPUTTEXT                                      FONTO(14)
#define CornerRadius_Normal                                 4.0f
#pragma mark - Height
#define IPHONE6_HEIGHT                                      (667.f)

#define K_1PX                                               (1.f / [UIScreen mainScreen].scale)

#define TB_CHART_LINE_WIDTH                                 (1.0f)
#define DiscoverCellSpace                                   6

#define ZoomButtonMargin                    6
#define TB_Currency_CutomerHeight                               62
#define TB_BANNER_ASPECT_RATIO                                   (210.0/1035.0) ///< banner高宽比
#define TB_BANNER_ASPECT_RATIO_LARGE                             (250.0/1035.0) ///< banner高宽比-大

//资产信息
#define ACCOUNT_TITLE_BOLD16                                     BOLDFONTO(16.f)
#define ACCOUNT_TITLE_MED18                                      MEDFONTO(18.f)
#define ACCOUNT_TITLE_NORMAl14                                   FONTO(14.f)
#define ACCOUNT_TITLE_NORMAl12                                   FONTO(12.f)
#define ACCOUNT_TITLE_BOLD12                                     BOLDFONTO(12.f)
#define ACCOUNT_TITLE_NUMBOLD12                                  NUMBOLDFONTO(12)

#define CIRCLE_PURPLE                                            RGBCOLOR_HEX(0x447EFF)
#define CIRCLE_GREEN                                             RGBCOLOR_HEX(0x0FE1DF)
#define CIRCLE_YELLOW                                            RGBCOLOR_HEX(0xF8AC00)
#define CIRCLE_ORANGE                                            RGBCOLOR_HEX(0xFF6825)
#define CIRCLE_RED                                               RGBCOLOR_HEX(0xFF3750)
#define CIRCLE_BLUE                                              RGBCOLOR_HEX(0x447EFF)
#define CIRCLE_HKOPT                                              RGBCOLOR_HEX(0xF8E100)
#define CIRCLE_AUSTK                                              RGBCOLOR_HEX(0x477C4A)
#define CIRCLE_SISTK                                              RGBCOLOR_HEX(0x3D3E95)
#define CIRCLE_CCDIGI                                             RGBCOLOR_HEX(0x909DDB)

#define TB_BACKGROUND_WHITE                                      [UIColor whiteColor]
#define COLOR_POP_BACKGROUND                                     [TBAppColor popBackGroundColor]
#define TB_ORDER_LIST_SUBCOLOR                                   COLOR_TEXT_STYLE2


#define TB_APP_IPO_RED_COLOR                                    [TBAppColor colorFromDark:0xFF3750 white:0xFD4E50]

#define TB_APP_IPO_CONTENT_BG_COLOR                                    [TBAppColor colorFromDark:0x2C2E3B white:0xFFFFFF]

//**********************************************TBStockDetailUtils文件*********************************//

/// 详情页各类字号定义
// 用于标的价格
#define kStockDetailHeaderFont1 NUMFONTO(40)
#define kStockDetailHeaderFont2 FONTO(14)
// 用于盘前盘后的标的价格
#define kStockDetailNUMFont16 NUMFONTO(16)
#define KStockDetailNUMFont15 NUMFONTO(15)
#define KStockDetailNUMFont14 NUMFONTO(14)
#define KStockDetailNUMFont13 NUMFONTO(13)
#define KStockDetailNUMFont12 NUMFONTO(12)
#define KStockDetailNUMFont10 NUMFONTO(10)
#define KStockDetailNUMFont30 NUMFONTO(30)
// 用于盘前盘后的标的价格（不跟随字号变化）
#define kStockDetailNUMFont16_NOADJUST NUMFONTO_NOADJUST(16)
#define KStockDetailNUMFont15_NOADJUST NUMFONTO_NOADJUST(15)
#define KStockDetailNUMFont14_NOADJUST NUMFONTO_NOADJUST(14)
#define KStockDetailNUMFont13_NOADJUST NUMFONTO_NOADJUST(13)
#define KStockDetailNUMFont12_NOADJUST NUMFONTO_NOADJUST(12)
#define KStockDetailNUMFont10_NOADJUST NUMFONTO_NOADJUST(10)
#define KStockDetailNUMFont30_NOADJUST NUMFONTO_NOADJUST(30)


#define KStockDetailNUMBoldFont11 NUMBOLDFONTO(11)
#define KStockDetailNUMBoldFont12 NUMBOLDFONTO(12)
#define KStockDetailNUMBoldFont14 NUMBOLDFONTO(14)
#define KStockDetailNUMBoldFont30 NUMBOLDFONTO(30)
#define KStockDetailNUMBoldFont15 NUMBOLDFONTO(15)
#define KStockDetailNUMBoldFont20 NUMBOLDFONTO(20)
#define KStockDetailNUMBoldFont16 NUMBOLDFONTO(16)
#define KStockDetailNUMBoldFont13 NUMBOLDFONTO(13)
///  底部tab字号
// 新闻、公告、财务、资料、分析、主要指标、做空数据、页面类型、分类主标题
#define kStockDetailMainTitleFont BOLDFONTO(22)
#define kStockDetailMainTitleColor [TBAppColor commonTextColor]
#define kStockDetailMainTitleHeight (40.f)

#define kStockDetailNewsNoticeTitleFont BOLDFONTO(15)
#define kStockDetailSegementTitleFont BOLDFONTO(15)
#define kStockDetailBoldTitle13 BOLDFONTO(13)

#define kChartAxisValueColor [TBAppColor subtitleColor]
#define kStockDetailTitleColor [TBAppColor titleColor]

#define kStockDetailFont3 FONTO(15)
// 一些类型分类内容文字字号
#define kStockDetailFont4 FONTO(14)
// 图表内数字显示以及一些分类下注释说明，部分图表时间（比如利润表）
#define kStockDetailFont5 FONTO(12)
#define kStockDetailFont5_NOADJUST FONTO_NOADJUST(12)
// 图表时间。五档明细内文字字号
#define kStockDetailFont6 FONTO(10)

#define kStockDetailFont13 FONTO(13)
#define kStockDetailFont11 FONTO(11)

#define kStockDetailBoldFont15 BOLDFONTO(15)

#define kStockDetailRedColor RGBCOLOR_HEX(0xFF6825)
#define kStockDetailHighRedColor RGBCOLOR_HEX(0xFF3750)
#define kStockDetailGreenColor RGBCOLOR_HEX(0x6DD0D4)
#define kStockDetailBlueColor RGBCOLOR_HEX(0x447EFF)

#define kStockDrtailStarColor RGBCOLOR_HEX(0xF8CC00)
#define kLeftToRightSpace (15.f)


// 666666 --- 7E829C
#define kStockTitleColor COLOR_TITLE

#define kStockLineBorderColor [TBAppColor lineBorderColor]

#define kStockChartViewHeight (200.f)



#endif /* ConstantUI_h */
