//
//  QuickSortViewController.m
//  Interview
//
//  Created by HG on 09/10/2018.
//  Copyright © 2018 HG. All rights reserved.
//

#import "QuickSortViewController.h"

@interface QuickSortViewController ()

@end

@implementation QuickSortViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSMutableArray *array = [@[@4, @1 ,@7 ,@6 ,@9 ,@2 ,@8 ,@0 ,@3 ,@5] mutableCopy];
    [self quickSortWithMutableArray1:array leftIndex:0 rightIndex:array.count - 1];
    
}


// 左右指针法
//1.选取一个关键字(key)作为枢轴，一般取整组记录的第一个数/最后一个，这里采用选取序列最后一个数为枢轴。
//2.设置两个变量left = 0;right = N - 1;
//3.从left一直向后走，直到找到一个大于key的值，right从后至前，直至找到一个小于key的值，然后交换这两个数。
//4.重复第三步，一直往后找，直到left和right相遇，这时将key放置left的位置即可

- (NSInteger)partSort:(NSMutableArray *)mArray left:(NSInteger)left right:(NSInteger)right {
    
    NSInteger key = [mArray[right] integerValue];
    
    // 循环直到 left 和right 相遇
    while (left < right) {
        
        
        //问题：下面的代码为什么还要判断left < right？
        //
        //while(left < right && array[left] <= key)1
        //
        //key是整段序列最后一个，right是key前一个位置，如果array[right]这个位置的值和key相等，满足array[left] <= key，然后++left,这时候left会走到key的下标处。
        
        // 从左往右直到找到一个大于key的值
        while (left < right && [mArray[left] integerValue] <= key) {
            ++left;
        }
        
        // 从右往左找到一个小于key的值
        while (left < right && [mArray[right] integerValue] >= key) {
            --right;
        }
        
        // 交换 left 和 right 的值
        NSInteger temp = [mArray[left] integerValue];
        mArray[left] = mArray[right];
        mArray[right] = @(temp);
    }
    
    // 左右标记相遇的时候 交换 left 和 key 的值
    NSInteger temp = [mArray[left] integerValue];
    mArray[left] = @(key);
    mArray[key] = @(temp);
    return left;
}




//挖坑法
//
//选取一个关键字(key)作为枢轴，一般取整组记录的第一个数/最后一个，这里采用选取序列最后一个数为枢轴，也是初始的坑位。
//设置两个变量left = 0;right = N - 1;
//从left一直向后走，直到找到一个大于key的值，然后将该数放入坑中，坑位变成了array[left]。
//从right一直向前走 直到找到一个小于key的值，然后将该数放入坑中，坑位变成了array[right]。
//重复3和4的步骤，直到left和right相遇，然后将key放入最后一个坑位。

//---------------------
- (NSInteger)partSort2:(NSMutableArray *)mArray left:(NSInteger)left right:(NSInteger)right {
    
    NSInteger key = [mArray[right] integerValue];
    while (left < right) {
        while (left < right && [mArray[left] integerValue] <= key) {
            left++;
        }
        mArray[right] = mArray[left];
        
        while (left < right && [mArray[right] integerValue] >= key) {
            right--;
        }
        mArray[left] = mArray[right];
    }
    
    mArray[right] = @(key);
    return right;
}


- (void)quickSortWithMutableArray1:(NSMutableArray *)mutableArray leftIndex:(NSInteger)leftIndex rightIndex:(NSInteger)rightIndex{
    
    if (leftIndex >= rightIndex) {
        return;
    }
    
    NSInteger key = [self partSort2:mutableArray left:leftIndex right:rightIndex];
    [self quickSortWithMutableArray1:mutableArray leftIndex:leftIndex rightIndex:key - 1];
    [self quickSortWithMutableArray1:mutableArray leftIndex:key + 1 rightIndex:rightIndex];
}




- (void)printArray:(NSArray *)array{
    
    NSMutableString *string = [@"" mutableCopy];
    for (NSNumber *number in array) {
        [string appendString:[number stringValue]];
    }
    NSLog(@"%@",string);
}


@end
