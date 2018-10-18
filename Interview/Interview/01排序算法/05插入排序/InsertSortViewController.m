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
//    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
}


// 直接插入排序 （交换法）
//https://www.cnblogs.com/chengxiao/p/6103002.html
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


//      * 希尔排序 针对有序序列在插入时采用交换法
//https://www.cnblogs.com/chengxiao/p/6104371.html
- (NSArray *)shellSortWithArray:(NSMutableArray *)array{
    
    if (array.count < 1) {
        return [array copy];
    }
    
    for (int gap = array.count / 2; gap > 0; gap /= 2) {
        
        int  j = gap;
        while (j - gap >= 0 && array[j] < array[j-gap]) {
            
            NSNumber *temp = array[j-gap];
            array[j-gap] = temp;
            array[j] = temp;
            
            j=j-gap;
        }
    }
    return [array copy];
}


//#define MAX_RECV_BUF_LEN    1024*512 //定义缓冲区大小
//#define BUFFER_HEAD_SIZE    8
//
////视频数据缓存区
//typedef struct{
//    Data    pBuffer[MAX_RECV_BUF_LEN];//用来接收的
//    uint    nReadPos;
//    uint    nWritePos;
//}T_RECV_BUFFER;

//static T_RECV_BUFFER tRecvBuffer;//定义一个缓冲变量
//
//
////2、写入数据
//
//+ (int)writeRecvBuffer:(uint8_t*)recvBuffer writeLen:(int)length{
//    if(recvBuffer ==NULL){
//        return -1;
//    }
//    int tailSize = MAX_RECV_BUF_LEN -tRecvBuffer.nWritePos;
//    if(length <= tailSize){
//        memcpy(&tRecvBuffer.recvBuffer[tRecvBuffer.nWritePos], recvBuffer, length);
//        tMediaRecvBuffer.nWritePos += length;
//    }else{//写入长度+写入位置 >缓冲
//        //如果写入数据的位置加长度超过最大缓冲，
//        //则先保存 写指针位置到MAX_RECV_BUF_LEN，再保存超出长度的数据。
//        memcpy(&tRecvBuffer.recvBuffer[tRecvBuffer.nWritePos], recvBuffer, tailSize);
//        memcpy(&tRecvBuffer.recvBuffer[0], &recvBuffer[tailSize], (length - tailSize));
//        tRecvBuffer.nWritePos = length - tailSize;
//    }
//    return0;
//}
//
//
////3、读取数据
//
//+ (int)readRecvBuffer:(uint8_t*)copyRecvBuffer readLen:(int)length{
//    int tailSize =MAX_RECV_BUF_LEN -tRecvBuffer.nReadPos;
//    if( length > tailSize){
//        //如果读取的长度超出 MAX_RECV_BUF_LEN-读指针位置
//        //则先拷贝 读指针位置到MAX_RECV_BUF_LEN，再拷贝超出长度的数据。
//        memcpy(copyRecvBuffer, &tRecvBuffer.recvBuffer[tRecvBuffer.nReadPos], tailSize);
//        memcpy(&copyRecvBuffer[MAX_RECV_BUF_LEN -tRecvBuffer.nReadPos], &tRecvBuffer.recvBuffer[0], length - tailSize);
//        tRecvBuffer.nReadPos = length - tailSize;
//    }else{
//        memcpy(copyRecvBuffer, &tRecvBuffer.recvBuffer[tRecvBuffer.nReadPos], length);
//        tRecvBuffer.nReadPos += length;
//    }
//    return0;
//}
////原文：https://blog.csdn.net/yao_shaobin/article/details/62038430?utm_source=copy
////版权声明：本文为博主原创文章，转载请附上博文链接！

@end
