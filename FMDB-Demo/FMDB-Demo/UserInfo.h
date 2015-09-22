//
//  UserInfo.h
//  FMDB-DEMO
//
//  Created by 胡晓阳 on 15/9/22.
//  Copyright © 2015年 HXY. All rights reserved.
//

#import "BaseEntity.h"

@interface UserInfo : BaseEntity

@property(nonatomic, copy) NSString *ID;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *fullName;

@end
