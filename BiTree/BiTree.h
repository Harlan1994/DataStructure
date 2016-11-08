//
// Created by Harlan on 2016/11/8.
//

#ifndef DATASTRUCTURE_BITREE_H
#define DATASTRUCTURE_BITREE_H

#include <malloc.h>
#include <queue>
#include <stdio.h>
#include <string>

using namespace std;

typedef char TElemType;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *left, *right;
} *BiTree;

/**
 * init a tree
 * @param T
 * @param tree
 */
void init(BiTree &T) {
    T = (BiTree) malloc(sizeof(BiTNode));
    if (!T) {
        printf("Init failde\n");
        return;
    }
    T->left = T->right = NULL;
    printf("Init successfully!\n");
}

/**
 * create a tree by pre and in order sequences.
 * @param T
 * @param pre
 * @param in
 */
void createBiTree(BiTree &T, string pre, string in) {
    if (pre.length() <= 0) {
        T = NULL;
        return;
    }
    char rootData = pre[0];

    int index = in.find(rootData);

    string leftInSubstr = in.substr(0, index);
    string rightInSubstr = in.substr(index + 1);

    string leftPreSubstr = pre.substr(1, leftInSubstr.length());
    string rightPreSubstr = pre.substr(leftInSubstr.length() + 1);

    T = (BiTree) malloc(sizeof(BiTNode));
    if (T != NULL) {
        T->data = rootData;
        createBiTree(T->left, leftPreSubstr, leftInSubstr);
        createBiTree(T->right, rightPreSubstr, rightInSubstr);
    }
}

void preOrderTraverse(BiTree &T) {
    if (T) {
        printf("%c ", T->data);
        preOrderTraverse(T->left);
        preOrderTraverse(T->right);
    }
}

void inOrderTraverse(BiTree &T) {
    if (T) {
        inOrderTraverse(T->left);
        printf("%c ", T->data);
        inOrderTraverse(T->right);
    }
}

void postOrderTraverse(BiTree &T) {
    if (T) {
        postOrderTraverse(T->left);
        postOrderTraverse(T->right);
        printf("%c ", T->data);
    }
}

void levelOrderTraverse(BiTree &T) {
    queue<BiTree> que;
    BiTree p = T;
    que.push(p);
    while (!que.empty()) {
        p = que.front();
        printf("%c ", p->data);
        que.pop();
        if (p->left != NULL)que.push(p->left);
        if (p->right != NULL)que.push(p->right);
    }
}

/**
 * traverrse a bitree
 * op == 1 preorder
 * op == 2 inorder
 * op == 3 postorder
 * @param T
 * @param op
 */
void traverse(BiTree &T, int op) {
    switch (op) {
        case 1:
            preOrderTraverse(T);
            break;
        case 2:
            inOrderTraverse(T);
            break;
        case 3:
            postOrderTraverse(T);
            break;
        default:
            break;
    }
}

#endif //DATASTRUCTURE_BITREE_H
