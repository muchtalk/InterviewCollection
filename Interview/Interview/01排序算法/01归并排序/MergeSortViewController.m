//
//  MergeSortViewController.m
//  Interview
//
//  Created by HG on 09/10/2018.
//  Copyright © 2018 HG. All rights reserved.
//

#import "MergeSortViewController.h"

@interface MergeSortViewController ()

@end

@implementation MergeSortViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

//链接: https://www.cnblogs.com/chengxiao/p/6194356.html
//递归实现
- (NSArray *)mergeSorWithArray:(NSMutableArray *)mArray {
    
    NSMutableArray *tempArray = [NSMutableArray arrayWithCapacity:mArray.count];//在排序前，先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
    [self sort:mArray tempArray:tempArray left:0 right:mArray.count - 1];
    return mArray;
}

- (void)sort:(NSMutableArray *)mArray tempArray:(NSMutableArray *)tempArray left:(NSInteger)left right:(NSInteger)right{
    if (left >= right){
        return;
    }
    NSInteger midIndex = (left + right)/2;
    [self sort:mArray tempArray:tempArray left:left right:midIndex]; // 左边归并排序，使得左子序列有序
    [self sort:mArray tempArray:tempArray left:midIndex+1 right:right]; // 右边归并排序，使得右子序列有序
    [self merge:mArray tempArray:tempArray left:left mid:midIndex right:right]; //将两个有序子数组合并操作
}

- (void)merge:(NSMutableArray *)mArray tempArray:(NSMutableArray *)tempArray left:(NSInteger)left mid:(NSInteger)mid right:(NSInteger)right{
    
    NSInteger i = left;    // 左序列指针
    NSInteger j = mid + 1; // 右序列指针
    NSInteger t = 0;       // 临时数组指针
    while (i <= mid && j <= right) {
        
        if ([mArray[i] intValue] <= [mArray[j] intValue]) { //  以 i 为标记 将j的值 小于等于 i的值 的移动到temparray
            tempArray[t++] = mArray[i++];
        }else{
            tempArray[t++] = mArray[j++];
        }
    }
    
    while (i <= mid) { // 当i还没走路到mid 将左边剩余元素填充进temp中
        tempArray[t++] = mArray[i++];
    }
    while (j <= right) { // 当j还没走到right 将右序列剩余元素填充进temp中
        tempArray[t++] = mArray[j++];
    }
    // 合并结束之后将 t 移到数组的头 然后做数组拷贝
    
    // 在OC 里面可以 使用 mArray = [tempArray mutableCopy]; 来代替下面的代码
    // 将temp中的元素全部拷贝到原数组中
    t = 0;
    while (left <= right) {
        mArray[left++] = tempArray[t++];
    }
    
}

//链接:https://www.jianshu.com/p/3380e35bbd5b
//链接:https://www.jianshu.com/p/8fce5bfb0013

// sort 方法的迭代实现--------------------------------------------------------------------
- (void)megerSort1:(NSMutableArray *)array {
    /**
     归并排序其实要做两件事：
     （1）“分解”——将序列每次折半划分。
     （2）“合并”——将划分后的序列段两两合并后排序。
     */
    NSMutableArray *tempArray = [NSMutableArray array];
    
    //第一趟排序是的子数组个数为ascendingArr.count
    // 拆分
    for (int i = 0; i < tempArray.count; i++) {
        // 将每个值装到一个单独的数组
        NSMutableArray *subArray = [NSMutableArray array];
        [subArray addObject:tempArray[i]];
        [tempArray addObject:subArray];
    }
    
    // 合并
    //    tempArray的个数为（当数组个数为偶数时tempArray.count/2;当数组个数为奇数时tempArray.count/2+1）;当tempArray.count == 1时，归并排序完成

    while (tempArray.count != 1) { //
        NSInteger i = 0;
        while (i < tempArray.count - 1) {
            //将i 与i+1 进行合并操作 将合并结果放入i位置上 将i+1位置上的元素删除
            NSArray *mergeArray = [self mergeArrayLeft:tempArray[i] right:tempArray[i+1]];
            tempArray[i] = mergeArray;
            [tempArray removeObject:tempArray[i+1]];
            i++;
        }
    }
}

- (NSArray *)mergeArrayLeft:(NSArray *)array1 right:(NSArray *)array2 {
    
    // firstIndex是第一段序列的下标 secondIndex是第二段序列的下标
    NSInteger i = 0;
    NSInteger j = 0;
    NSMutableArray *tempArray = [NSMutableArray array];
    while (i < array1.count && j < array2.count) {
        if ([array1[i] intValue] < [array2[j] intValue]) {
            [tempArray addObject:array1[i]];
            i++;
        }else{
            [tempArray addObject:array2[j]];
            j++;
        }
    }
    
    // 若第一段序列还没扫描完，将其全部复制到合并序列
    while (i < array1.count) {
        [tempArray addObject:array1[i]];
        i++;
    }
    
    // 若第二段序列还没扫描完，将其全部复制到合并序列
    while (j < array2.count) {
        [tempArray addObject:array2[j]];
        j++;
    }
    return [tempArray copy];
}


//
//// sort 方法的迭代实现
//
//- (void)megerSort:(NSMutableArray *)array
//{
//    /**
//     归并排序其实要做两件事：
//
//     （1）“分解”——将序列每次折半划分。
//
//     （2）“合并”——将划分后的序列段两两合并后排序。
//     */
//    //排序数组
//    NSMutableArray *tempArray = [NSMutableArray arrayWithCapacity:1];
//    //第一趟排序是的子数组个数为ascendingArr.count
//    for (NSNumber *num in array) {
//        NSMutableArray *subArray = [NSMutableArray array];
//        [subArray addObject:num];
//        [tempArray addObject:subArray];
//    }
//    /**
//     分解操作 每一次归并操作 tempArray的个数为（当数组个数为偶数时tempArray.count/2;当数组个数为奇数时tempArray.count/2+1）;当tempArray.count == 1时，归并排序完成
//     */
//    while (tempArray.count != 1) {
//        NSInteger i = 0;
//
//        //当数组个数为偶数时 进行合并操作， 当数组个数为奇数时，最后一位轮空
//        while (i < tempArray.count - 1) {
//
//            //将i 与i+1 进行合并操作 将合并结果放入i位置上 将i+1位置上的元素删除
//            tempArray[i] = [self mergeArrayLeft:tempArray[i] right:tempArray[i + 1]];
//            [tempArray removeObjectAtIndex:i + 1];
//
//            //i++ 继续下一循环的合并操作
//            i++;
//        }
//    }
//    NSLog(@"归并排序结果：%@", tempArray);
//}




@end
