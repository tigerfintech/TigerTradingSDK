//
//  TBPopupsInfoModel.h
//  Stock
//
//  Created by charming on 2019/12/17.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@interface TBPopupsSymbolInfoModel : JSONModel
@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy) NSString *prospectusUrl;
@property (nonatomic, copy) NSString *closingDate;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *listDate;
@property (nonatomic, strong) NSNumber *maxPrice;
@property (nonatomic, strong) NSNumber *marginRate;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, strong) NSNumber *expectedOfferingSize;
@property (nonatomic, strong) NSNumber *minQty;
@property (nonatomic, copy) NSString *openingDate;
@property (nonatomic, strong) NSNumber *minPrice;
@property (nonatomic, copy) NSString *ipoName;
@property (nonatomic, copy) NSString *market;
@end


@interface TBPopupsInfoModel : JSONModel

@property (nonatomic, strong) NSNumber *popId;
@property (nonatomic, copy) NSString *summary;
@property (nonatomic, strong) NSNumber *position;
@property (nonatomic, strong) NSNumber *type;
@property (nonatomic, strong) NSNumber *frequency;
@property (nonatomic, strong) NSNumber *jump_type;
@property (nonatomic, copy) NSString *jump_link;
@property (nonatomic, copy) NSString *cover_img_url;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSArray *symbol_info;

@end
