//
//  TBFont.h
//  Pods
//
//  Created by linbingjie on 2021/4/1.
//

#import <TBBaseKit/TBBaseKit.h>
#import "UIFont+TBAdditions.h"
#import "TBFontManager.h"

#ifndef TBFont_h
#define TBFont_h

#define FONTO(value)                                        [TBFontManager fonto:value]
#define FITSIZEFONTO(value)                                 [TBFontManager  fitSizeFonto:value]
#define FITSMALLSIZEFONTO(value)                            [TBFontManager fitSmallSizeFonto:value]
#define FITSMALLSIZEBoldFONTO(value)                        [TBFontManager fitSmallSizeBoldFonto:value]
#define BOLDFONTO(value)                                    [TBFontManager boldFonto:value]
#define MEDFONTO(value)                                     [TBFontManager medFonto:value]
#define NUMFONTO(value)                                     [TBFontManager numFonto:value]
#define NUMBOLDFONTO(value)                                 [TBFontManager numBoldFonto:value]

// ===== 新增 font 不跟随字号变动的宏
#define FONTO_NOADJUST(value)                               [TBFontManager fonto:value adjustFont:NO]
#define FITSIZEFONTO_NOADJUST(value)                        [TBFontManager fitSizeFonto:value adjustFont:NO]
#define FITSMALLSIZEFONTO_NOADJUST(value)                   [TBFontManager fitSmallSizeFonto:value adjustFont:NO]
#define FITSMALLSIZEBoldFONTO_NOADJUST(value)               [TBFontManager fitSmallSizeBoldFonto:value adjustFont:NO]
#define BOLDFONTO_NOADJUST(value)                           [TBFontManager boldFonto:value adjustFont:NO]
#define MEDFONTO_NOADJUST(value)                            [TBFontManager medFonto:value adjustFont:NO]
#define NUMFONTO_NOADJUST(value)                            [TBFontManager numFonto:value adjustFont:NO]
#define NUMBOLDFONTO_NOADJUST(value)                        [TBFontManager numBoldFonto:value adjustFont:NO]

#endif /* TBFont_h */
