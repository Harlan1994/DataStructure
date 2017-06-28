//
// Created by Harlan1994 on 2017/6/23.
//

// 1. 以下内容可不写，在能记住的情况下，写也行
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

// 2. 指针的理解和应用
// 指针其实是一个地址
// x指的是这个地址
// *x指的是这块地址保存的内容
void exchange(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("%d %d\n", *x, *y);
}

// 3. 自增自减需要注意的地方
// ++i,先增，i++后增
void increase(){
    int i = 0;
    ++i;
    i++; // 单独使用时两者无区别
    printf("%d\n", i); // 2

    int q = i++;
    printf("%d %d\n", q, i); // 2, 3
    int p = ++i;
    printf("%d %d\n", p, i); // 4, 4
}

int main(){
    int *address;
    int p = 20;
    address = &p;   // 将p的地址赋值给address
    printf("%d\n", address == &p); // 1
    printf("%d\n", *address); // 20
    printf("%d\n", address); // 6422312

    int x = 9;
    int y = 10;
    exchange(&x, &y); // 10 9

    increase();
    return 0;
}