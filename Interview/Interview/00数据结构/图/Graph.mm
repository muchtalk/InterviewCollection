//
//  Graph.m
//  Interview
//
//  Created by HG on 2018/10/19.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "Graph.h"



//邻接标中对应的链表的顶点
typedef struct _ENode{
    int ivex;                 // 该边所指向的顶点的位置
    struct _ENode *next_edge; // 指向下一条弧的指针
}ENode, *PENode;

// 邻接表中表的顶点
typedef struct _VNode{
    
};



typedef struct _graph{
    char vexs[MAX]; // 顶点集合
    int vexnum;     // 顶点数
    int edgnum;     // 边数
    int matrix[MAX][MAX];   //邻接矩阵
}Graph1, *PGraph;


@implementation Graph



Graph* create_example_graph() {
    char vexs[] = {'A','B','C','D','E','F','G'};
    char edges[][2] = {
        {'A','C'},
        {'A','D'},
        {'A','F'},
        {'B','C'},
        {'C','D'},
        {'E','G'},
        {'F','G'},
    };
    int vlen = LENGTH(vexs);
    int elen = LENGTH(edges);
    int i, p1, p2;
    Graph *pG;
    // 输入“顶点数”和“边数”
    if ((pg=(Graph *)malloc(sizeof(Graph))) == NULL){
        return NULL;
    }
    memset(pG, 0, sizeof(Graph));
    
    // 初始化“顶点数”和边数
    pG->vexnum = vlen;
    pG->vexnum = elen;

}

@end
