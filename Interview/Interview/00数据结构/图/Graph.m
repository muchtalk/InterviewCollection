//
//  Graph.m
//  Interview
//
//  Created by HG on 22/10/2018.
//  Copyright © 2018 HG. All rights reserved.
//

#import "Graph.h"

//ListNode
@interface ListNode : NSObject

@property (nonatomic, assign) NSUInteger weight;
@property (nonatomic, assign) NSUInteger vex;
@property (nonatomic, strong) ListNode *nextNode;

@end

@implementation ListNode
@end

//VexNode
@interface VexNode : NSObject

@property (nonatomic, assign) NSUInteger data;
@property (nonatomic, strong) ListNode *fristNode;

@end

@implementation VexNode
@end

//GraphByList
@interface GraphByList : NSObject

@property (atomic, copy) NSArray *list;
@property (atomic, assign) NSUInteger vexCount;
@property (atomic, assign) NSUInteger edgCount;

@end

@implementation GraphByList
@end




#define maxvex 100


/*
 图（graph）：图是由顶点的有穷非空集合和顶点之间边的集合组成，通常表示为：G(V,E)，其中，G表示一个图，V是图G中的顶点的集合，E是图G中边的集合。
 顶点(Vertex)：图中的数据元素。线性表中我们把数据元素叫元素，树中将数据元素叫结点。
 
 边：顶点之间的逻辑关系用边来表示，边集可以是空的。
    无向边(Edge)：若从顶点V1到V2的边没有方向，则称这条边为无向边。
    有向边(Arc)： 若从顶点V1到V2的边有方向，则称这条边为有向边，也称弧。用<V1,V2>表示，V1为狐尾(Tail)，V2为弧头(Head)。（V1，V2）≠（V2，V1）。
 
 注意：无向边用“（）”，而有向边用“< >”表示。
 无向图(Undirected graphs)：
    图中任意两个顶点之间的边都是无向边。（A,D）=（D,A）对于无向图G来说，G1=（V1,{E1}），其中顶点集合V1={A,B,C,D}；边集和E1={（A,B），（B,C），（C,D），（D,A），（A,C）}
 
 有向图(Directed graphs)：
    图中任意两个顶点之间的边都是有向边。
 
 
 简单图：    图中不存在顶点到其自身的边，且同一条边不重复出现。
 无向完全图： 无向图中，任意两个顶点之间都存在边。
 有向完全图： 有向图中，任意两个顶点之间都存在方向互为相反的两条弧。
 稀疏图：    有很少条边。
 稠密图：    有很多条边。
 权（Weight）：    与图的边或弧相关的数。
 网（Network）：   带权的图。
 子图（Subgraph）：假设G=（V,{E}）和G‘=（V',{E'}），如果V'包含于V且E'包含于E，则称G'为G的子图。
 度（Degree）：    无向图中，与顶点V相关联的边的数目。有向图中，入度表示指向自己的边的数目，出度表示指向其他边的数目，该顶点的度等于入度与出度的和。
 
 路径的长度：一条路径上边或弧的数量。
 
 连通图：图中任意两个顶点都是连通的。

 
 */


// 邻接矩阵存储结构
typedef struct {
    char vexs[100];
    int  arc[100][100];
    int  vrtex;
    int  edges;
}mgraph;



// 邻接表中 表对应的链表的顶点
typedef struct ArcNode{
    int adjvex;                 //该边所指向的顶点的位置
    int weight;                 //用于存贮权对于非网图可以不需要
    struct ArcNode *next_edge;   //指向下一条弧的指针
}ArcNode;

// 邻接表中表的顶点
typedef struct VNode{
    int data;          // 顶点信息
    ArcNode *first_edge;  // 指向下一条依附该顶点的弧
}VNode;

// 邻接表
typedef struct LGraph{
    int vexnum; // 图的顶点的数目
    int edgnum; // 图的边的数目
    VNode vexs[100];
    
}LGraph;



@implementation Graph

// 图的遍历
// 1.深度优先遍历

//记录访问标志的数组
int visitedArray[100] = {0};

void visit(LGraph *graph, int v){
    VNode vexNode = graph->vexs[v];
    printf("vex value : %d",vexNode.data);
}

// 深度优先遍历邻接表
void depth_frist_search(LGraph *graph, int vex){
    
    visit(graph,vex); // 访问vex点的值
    visitedArray[vex] = 1; // 标记v这个顶点已经访问过
    
    ArcNode *node = graph->vexs[vex].first_edge;
    while (node != NULL) {
        
        //若adjvex顶点未访问,递归访问它
        if (visitedArray[node->adjvex] == 0) {
            depth_frist_search(graph, node->adjvex);
        }
        
        node = node->next_edge;
    }
}


// 广度优先遍历邻接列表
void breadth_first_search(LGraph *graph, int v){
    int head = 0;
    int rear = 0;
    int queue[maxvex]; // 辅助队列
    int visited[maxvex]; //顶点访问标记
    int i, j, k;
    ArcNode *node;
    
    for (int i = 0; i < graph->vexnum; i++) {
        visited[i] = 0;
    }
    
    for (int i = 0; i < graph->vexnum; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            
            queue[rear++] = i;// 入队列
        }
        
        while (head != rear) {
            j = queue[head++];
            node = graph->vexs[j].first_edge;
            
            while (node != NULL) {
                k = node->adjvex;
                if (visited[k] == 0) {
                    visited[k] = 1;
                    
                    queue[rear++] = k;
                }
                node = node->next_edge;
            }
        }
    }
}




// 访问 顶点
- (void)visit:(GraphByList * )graph vex:(NSUInteger)vex{
    
}

- (void)depthFristSearch:(GraphByList *)graph vex:(NSInteger)vex{
    
    [self visit:graph vex:vex];
    visitedArray[vex] = 1;
    
    VexNode *vexNode = graph.list[vex];
    ListNode *node = vexNode.fristNode;
    
    while (node != nil) {
        if (visitedArray[node.vex] == 0) {
            [self depthFristSearch:graph vex:node.vex];
        }
        
        node = node.nextNode;
    }
}




@end
