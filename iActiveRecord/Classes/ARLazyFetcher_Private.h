//
//  ARLazyFetcher_Private.h
//  iActiveRecord
//
//  Created by Alex Denisov on 01.06.12.
//  Copyright (c) 2012 okolodev.org. All rights reserved.
//

#import "ARLazyFetcher.h"

static const char *joins[] = {"LEFT", "RIGHT", "INNER", "OUTER"};

static NSString * joinString(ARJoinType type)
{
    return [NSString stringWithUTF8String : joins[type]];
}

@interface ARLazyFetcher ()
{
    @private
    Class recordClass;
    NSString *sqlRequest;
    NSMutableDictionary *orderByConditions;
    BOOL useRandomOrder;
    NSMutableSet *onlyFields;
    NSMutableSet *exceptFields;
    ARJoinType joinType;
    Class joinClass;
    NSString *recordField;
    NSString *joinField;
    BOOL useJoin;
    NSNumber *limit;
    NSNumber *offset;
}

@property (nonatomic, copy) NSMutableString *whereStatement;

- (NSSet *)recordFields;

- (void)buildSql;
- (NSString *)createOrderbyStatement;
- (NSString *)createWhereStatement;
- (NSString *)createLimitOffsetStatement;
- (NSString *)createSelectStatement;
- (NSString *)createJoinedSelectStatement;
- (NSString *)createJoinStatement;

- (NSSet *)fieldsOfRecord:(id)aRecord;

@end