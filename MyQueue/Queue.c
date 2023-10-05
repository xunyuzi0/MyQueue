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

	int val = 0;//临时储存出队结点数据

	QUEUE q;
	initQueue(&q);
	printQueue(&q);

	pushQueue(&q, 13);
	pushQueue(&q, -100);
	pushQueue(&q, 13);
	pushQueue(&q, 241);
	pushQueue(&q, 0);
	pushQueue(&q, 1);
	printQueue(&q);

	if (popQueue(&q, &val)) {
		printf("出队成功，出队结点数据为：%d\n", val);
	}
	printQueue(&q);
	
	pushQueue(&q, 1);
	printQueue(&q);

	if (popQueue(&q, &val)) {
		printf("出队成功，出队结点数据为：%d\n", val);
	}
	printQueue(&q);

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

	pq->rear->data = val;//赋值

	//创建一个结点，用于存储下一个rear结点
	PNODE p = (PNODE)malloc(sizeof(NODE));
	if (p == NULL) {
		printf("动态内存分配失败！！");
		exit(-1);
	}

	//rear结点内容赋空值
	p->data = NULL;
	p->pNext = NULL;

	//将p结点接到队列上
	pq->rear->pNext = p;
	pq->rear = p;
	pq->QueSize++;

	return true;
}

//实现元素出队，并通过*val返回出队的值
bool popQueue(PQUEUE pq, int* val) {

	if (isEmptyQueue(pq)) {
		printf("队列为空，元素出队失败！\n");
		return false;
	}

	*val = pq->front->data;//通过指针传值

	//临时储存待出队结点front
	PNODE p = pq->front;

	pq->front = pq->front->pNext;
	free(p);

	return true;
}


//实现队列遍历输出
void printQueue(PQUEUE pq) {

	int i = 1;

	//使用临时变量p代替front防止更改
	PNODE p = pq->front;

	if (isEmptyQueue(pq)) {
		printf("队列为空，遍历输出失败！\n");
	}
	else {

		//遍历输出
		while (p != pq->rear) {

			printf("%d:%d  ", i, p->data);
			i++;
			p = p->pNext;

		}

		printf("\n");
	}

}