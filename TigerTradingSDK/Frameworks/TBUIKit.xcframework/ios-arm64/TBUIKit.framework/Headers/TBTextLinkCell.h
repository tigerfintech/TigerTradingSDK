//
//  TBTextLinkCell.h
//  Stock
//
//  Created by chenxin on 2019/6/5.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

@interface TBTextLinkCell : TBTableViewCell

@end

@interface TBTextLinkCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *linkText;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, assign) BOOL underlineEnabled;

@end
