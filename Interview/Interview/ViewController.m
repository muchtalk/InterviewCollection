//
//  ViewController.m
//  Interview
//
//  Created by HG on 27/09/2018.
//  Copyright © 2018 HG. All rights reserved.
//

#import "ViewController.h"


@interface ViewController ()

@end

@implementation ViewController



- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSMutableArray *array = [@[@(5),@(20),@(7),@(8),@(6),@(4),@(3)] mutableCopy];
    NSArray *sortedArray = [self insertSortWithArray:array];
    
    NSLog(@"%@",sortedArray);
}


- (NSArray *)insertSortWithArray:(NSMutableArray *)array{
    
    if (array.count < 1) {
        return [array copy];
    }
    
    for (int i = 1; i < array.count; i++) {
        
        int  j = i;
        while (j > 0 && array[j] < array[j-1]) {
            
            NSNumber *temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;
            
            j--;
        }
        
    }
    
    return [array copy];
}


@end
