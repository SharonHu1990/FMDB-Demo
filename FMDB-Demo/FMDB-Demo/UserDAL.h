//
//  UserDAL.h
//  FMDB-DEMO
//
//  Created by 胡晓阳 on 15/9/22.
//  Copyright © 2015年 HXY. All rights reserved.
//

#import "BaseDAL.h"
#import "FMDatabase.h"
#import "UserInfo.h"

@interface UserDAL : BaseDAL
{}

//单例模式
+(UserDAL *) defaultDAL;
@end
