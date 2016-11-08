//
// Created by Harlan on 2016/11/8.
//
#include "BiTree.h"

int main(){
    BiTree T;
    init(T);
    createBiTree(T, "ABDECFG", "DBEAFCG");
    preOrderTraverse(T);
    printf("\n");
    inOrderTraverse(T);
    printf("\n");
    postOrderTraverse(T);
    printf("\n");
    levelOrderTraverse(T);
    return 0;
}