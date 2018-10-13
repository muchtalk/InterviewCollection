//
//  InsertSortViewController.m
//  Interview
//
//  Created by HG on 11/10/2018.
//  Copyright © 2018 HG. All rights reserved.
//

#import "InsertSortViewController.h"

@interface InsertSortViewController ()

@end

@implementation InsertSortViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSMutableArray *array = [@[@(8),@(7),@(6),@(5),@(4),@(3)] mutableCopy];
    NSArray *sortedArray = [self insertSortWithArray:array];
    
    
}


- (NSArray *)insertSortWithArray:(NSMutableArray *)array{
    
    if (array.count < 1) {
        return [array copy];
    }
    
    
    for (int i = 1; i < array.count; i++) {
        
        int  j = i;
        while (j > 0 && array[j] < array[j-1]) {
            
            NSNumber *temp = array[j-1];
            array[j-1] = temp;
            array[j] = temp;
            
            j--;
        }
        
    }
    
    return [array copy];
}

@end
