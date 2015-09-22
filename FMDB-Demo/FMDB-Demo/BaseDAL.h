//
//  BaseDAL.h
//  FMDB-DEMO
//
//  Created by 胡晓阳 on 15/9/22.
//  Copyright © 2015年 HXY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMDatabase.h"
#import "BaseEntity.h"

@interface BaseDAL : NSObject
{
    NSString *pathToDatabase;
}

#pragma 数据库相关属性 @property (nonatomic, strong) NSString *pathToDatabase; 
@property (nonatomic, readonly) FMDatabase *database; // 数据库操作对象
@property (nonatomic, strong) NSString *tableName;//表名称
@property (nonatomic, strong) NSString *primaryKey;//主键
@property (nonatomic, strong) NSString *sortField;//排序，默认为主键
@property (nonatomic, assign, getter=isDescending) BOOL descending;//是否降序查询

//将DataReader的属性值转化为实体类的属性值，返回实体类(子类必须重写）
-(id) rsToEntity:(FMResultSet *)rs;
//将实体对象的属性值转化为字典列表对应的键值(子类必须重写）
-(NSDictionary *) dictByEntity:(BaseEntity *) info;


#pragma 基础操作接口 
//根据指定对象的ID,从数据库中删除指定对象
- (BOOL) deleteById:(id) key;
//根据指定条件,从数据库中删除指定对象
- (BOOL) deleteByCondition:(NSString *) condition;
//更新对象属性到数据库中
-(BOOL) update:(BaseEntity *) info byKey:(id) key;
//插入指定对象到数据库中
-(BOOL) insert:(BaseEntity *) info;
//插入指定对象到数据库中,并返回最后插入的ID
-(NSInteger) insert2:(BaseEntity *) info;
//查询数据库,检查是否存在指定ID的对象
- (BaseEntity *) findById:(id) key;
//根据条件查询数据库,如果存在返回第一个对象
-(BaseEntity *) findSingle:(NSString *) condition;
//根据条件查询数据库,如果存在返回第一个对象
-(BaseEntity *) findSingle:(NSString *) condition orderBy:(NSString *) orderBy;
//根据条件查询数据库,并返回对象集合
- (NSArray *) find:(NSString *) condition;
//根据条件查询数据库,并返回对象集合
- (NSArray *) find:(NSString *) condition orderBy:(NSString *) orderBy;
//获取表的全部数据
- (NSArray *) getAll;
//获取表的全部数据
- (NSArray *) getAll:(NSString *) orderBy;
//获取某字段数据字典列表
-(NSArray *) getFieldList:(NSString *) fieldName;
//获取表的所有记录数量
-(int) getRecordCount;
//根据条件，获取表查询的记录数量
-(int) getRecordCount:(NSString *) condition;
//根据条件，判断是否存在记录
-(BOOL) isExistRecord:(NSString *)condition;
//查询数据库,检查是否存在指定键值的对象
-(BOOL) isExist:(NSString *)fieldName value:(id) value;
//根据主键和字段名称，获取对应字段的内容
-(NSString *) getFieldValue:(NSString *)key fieldName:(NSString *)fieldName;
//执行SQL查询语句，返回查询结果的所有记录的第一个字段,用逗号分隔。
-(NSString *) sqlValueList:(NSString *)query;

#pragma 数据库初始化函数及关闭操作
//根据SQLite数据库地址初始化数据库
-(id) initWithPath:(NSString *)filePath;
//根据SQLite数据库名称初始化数据库
-(id) initWithFileName:(NSString *)fileName;
// 关闭连接
-(void) close;


@end
