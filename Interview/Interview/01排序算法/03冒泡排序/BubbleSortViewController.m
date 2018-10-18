//
//  BubbleSortViewController.m
//  Interview
//
//  Created by HG on 09/10/2018.
//  Copyright © 2018 HG. All rights reserved.
//

#import "BubbleSortViewController.h"

@interface BubbleSortViewController ()

@end

@implementation BubbleSortViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/* 冒泡排序法的基本思想：（以升序为例）含有n个元素的数组原则上要进行n-1次排序。对于每一躺的排序，从第一个数开始，依次比较前一个数与后一个数的大小。 如果前一个数比后一个数大，则进行交换。这样一轮过后，最大的数将会出现称为最末位的数组元素。第二轮则去掉最后一个数，对前n-1个数再按照上面的步骤找出最 大数，该数将称为倒数第二的数组元素......n-1轮过后，就完成了排序。
 ---------------------
*/
- (NSArray *)bubbleSortWithArray:(NSMutableArray *)mArray{
    
    for (int i = 0; i < mArray.count - 1; i++) {
        // 比较的趟数
        
        for (int j = 0; j < mArray.count - 1 - i; j++) {
            // 比较的次数
            
            if ([mArray[j] integerValue] > [mArray[j+1] integerValue]) {
                
                NSInteger temp = [mArray[j] integerValue];
                mArray[j+1] = mArray[j];
                mArray[j] = @(temp);
            }
        }
    }
    return [mArray copy];
}


@end
