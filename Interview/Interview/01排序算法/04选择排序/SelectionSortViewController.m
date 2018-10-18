//
//  SelectionSortViewController.m
//  Interview
//
//  Created by HG on 09/10/2018.
//  Copyright © 2018 HG. All rights reserved.
//

#import "SelectionSortViewController.h"

@interface SelectionSortViewController ()

@end

@implementation SelectionSortViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSArray *)selectionSortWithArray:(NSMutableArray *)mArray {
    
    for (int i = 0; i < mArray.count; i++) {
        NSUInteger index = i;
        
        for (int j = i + 1; i < mArray.count; j++) {
            if (mArray[index] > mArray[j]) {
                index = j;
            }
        }
        
        if (index != i) {
            NSInteger temp = [mArray[i] integerValue];
            mArray[i] = mArray[index];
            mArray[index] = @(temp);
        }
    }
    
    return [mArray copy];
}




@end
