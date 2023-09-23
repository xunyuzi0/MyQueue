#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// ！！链式队列！！
//本程序完成了链式队列数据结构及部分算法



//队列每个元素的结点，链式队列结点与链表相同
typedef struct NODE {

	int data;//数据域
	struct NODE* pNext;//指针域

}NODE, * PNODE;


//队列结构体
typedef struct Queue {

	PNODE front;//指向队列头
	PNODE rear;//指向队列尾
	int QueSize;//队列元素个数

}QUEUE,*PQUEUE;


bool initQueue(PQUEUE);
bool isEmptyQueue(PQUEUE);
bool pushQueue(PQUEUE, int);
bool popQueue(PQUEUE, int*);
void printQueue(PQUEUE);


int main() {

	QUEUE q;
	init(&q);



	return 0;
}


//实现链式队列的初始化
bool initQueue(PQUEUE pq) {

	//创建一个结点
	PNODE p = (PNODE)malloc(sizeof(NODE));
	if (p == NULL) {
		printf("动态内存分配失败！！");
		exit(-1);
	}

	//赋值内容为空
	p->data = NULL;
	p->pNext = NULL;

	//将队列结构体变量中PNODE指针指向p
	//并标记大小为0，完成初始化
	pq->front = p;
	pq->rear = p;
	pq->QueSize = 0;

}


//实现队列判空，空返回true，非空返回false
bool isEmptyQueue(PQUEUE pq) {

	return(pq->QueSize == 0);

}

//实现元素入队
bool pushQueue(PQUEUE pq, int val) {



}

//实现元素出队，并通过*val返回出队的值
bool popQueue(PQUEUE pq, int* val) {



}


//实现队列遍历输出
void printQueue(PQUEUE pq) {

	int i = 1;

	//使用临时变量p代替front防止更改
	PNODE p = pq->front;

	if (isEmptyQueue(pq)) {
		printf("队列为空，遍历输出失败！");
	}
	else {

		//遍历输出
		while (p != pq->rear) {

			printf("%d:%d  ", i, p->data);
			i++;
			p = p->pNext;

		}
	}

}