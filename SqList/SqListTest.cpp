//
// Created by Harlan on 2016/10/15.
//

#include "SqList.h"

SqList L;

int main() {

    init(&L);
    while (true) {
        printf("*****************************\n");
        printf("*         1������            *\n");
        printf("*         2��ɾ��            *\n");
        printf("*         3����ӡ            *\n");
        printf("*         4���˳�            *\n");
        printf("******************************\n");
        int op;
        scanf("%d", &op);
        switch (op) {
            case 1: {
                printf("���������λ�úͲ����ֵ���ո��������\n");
                int i;
                ElemType e;
                scanf("%d %d", &i, &e);
                Status result = insertElem(&L, i, e);
                if (result == OK)printf("����ɹ���\n");
                printf("����Ϊ��\n");
                traverse(&L);
                break;
            }
            case 2: {
                printf("������ɾ����ֵ��λ�ã�");
                int j;
                ElemType e1;
                scanf("%d", &j);
                Status result1 = deleteElem(&L, j, &e1);
                if (result1 == OK)printf("ɾ���ɹ���\n");
                printf("��ɾ����ֵΪ e = %d\n", e1);
                break;
            }
            case 3:{
                printf("����Ϊ��\n");
                traverse(&L);
                break;
            }
            case 4:
                return 0;
            default:
                break;
        }
    }
}