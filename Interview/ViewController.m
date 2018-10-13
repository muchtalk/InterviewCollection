//
//  ViewController.m
//  Interview
//
//  Created by HG on 2018/10/8.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController
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
