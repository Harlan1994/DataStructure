//
// Created by Harlan1994 on 2017/6/28.
//

#include "SList.h"
#include <stdio.h>

int main() {
    SList l;
    InitList(l); //初始化链表
    for (int i = 0; i < 8; ++i)
        InsertList(l, 1, i);
    Print(l); //输出链表

    InsertList(l, 3, 22); //在链表的第3个位置插入22
    Print(l);

    DeleteList(l, 7); //删除第8个位置的元素
    Print(l);
    return 0;
}