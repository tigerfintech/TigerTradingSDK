//
//  TUPOpenOptionAgreementModel.h
//  StockGlobal
//
//  Created by wind on 2020/4/10.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPOpenOptionAgreementModel : JSONModel
@property (nonatomic, strong) NSNumber *idNum;
@property (nonatomic, copy) NSString *title;
@end

NS_ASSUME_NONNULL_END
