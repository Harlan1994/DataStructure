#include <stdio.h>

/*  静态链表用一维数组表示链表便于在不设指针的高级程序语言中实现链表结构
    数组的一个分量表示一个结点,一个结点由两个域组成：
    数据域:data，用于存储要处理的数据元素
    游标域:cur,用于代替指针指示结点在数据中的位置
    特殊处理数组的第一个位置与最后一个位置
    最后一个位置的游标指标第一个有数据的结点(相当于链表的头结点)
    第一个位置的游标指标一个未使用的结点 */
#ifndef SList_H
#define SList_H
#define MAXSIZE 1000  //设定数组的最大值
typedef int ElemType; //设定数组的数据类型
typedef struct {
    ElemType data; //结点的数据域
    int cur;  //结点的游标域
} SList[MAXSIZE];

void InitList(SList l); //初始化链表
void InsertList(SList l, int i, ElemType e); //在链表的第i个位置插入元素
void DeleteList(SList l, int i); //删除链表的第i个元素
int Malloc_SLL(SList l); //申请空间
void Free_SLL(SList l); //释放空间
int GetListLength(SList l); //返回链表的长度
void Print(SList l); //打印链表
#endif //SList_H

void InitList(SList l) //初始化链表
{
    for (int i = 0; i < MAXSIZE - 1; ++i) //初始化链表的游标,使其全部形成链接
        l[i].cur = i + 1;
    l[MAXSIZE - 1].cur = 0; //初始化最后一个结点的游标为0
}

int Malloc_SLL(SList l) //申请链表的剩余空间
{
    int j = l[0].cur;
    if (l[0].cur)
        l[0].cur = l[j].cur;
    return j;
}

void Free_SLL(SList l, int j) //释放链表的空间
{
    l[j].cur = l[0].cur;
    l[0].cur = j;
}

void InsertList(SList l, int i, ElemType e) //在链表的第i个位置插入元素e
{
    if (i < 1 || i > GetListLength(l) + 1) //超出范围退出
        return;
    int k = MAXSIZE - 1; //使K为最后一个结点游标
    for (int j = 0; j < i - 1; ++j)
        k = l[k].cur;
    int v = Malloc_SLL(l); //申请空间
    if (v) //如果有空间
    {
        l[v].data = e;
        l[v].cur = l[k].cur;
        l[k].cur = v;
    }
}

void DeleteList(SList l, int i) //删除第i个位置的元素
{
    if (i < 1 || i > GetListLength(l)) //超出范围退出
        return;
    int k = MAXSIZE - 1; //K指示链表的最后一个结点
    for (int j = 0; j < i - 1; ++j) //使k指示要删除的结点的前一个结点
        k = l[k].cur;
    int temp = l[k].cur;
    l[k].cur = l[temp].cur;
    Free_SLL(l, temp);
}

int GetListLength(SList l) //返回链表的当前长度
{
    int j = 0;
    int k = l[MAXSIZE - 1].cur;
    while (k) {
        ++j;
        k = l[k].cur;
    }
    return j;
}

void Print(SList l) //打印链表
{
    int k = l[MAXSIZE - 1].cur;
    while (k) {
        printf("%d ", l[k].data);
        k = l[k].cur;
    }
    printf("\n");
}
