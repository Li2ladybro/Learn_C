#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;    //节点值
    struct ListNode* next;    // 指向下一个节点的指针
} ListNode;

int main()
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));    // 初始化头节点
    ListNode* p = head;    // 当前指针默认指向头节点

    // 构建链表并赋值
    for (int i = 1; i <= 10; i++)
    {
        p->val = i;
        p->next = (ListNode*)malloc(sizeof(ListNode));
        p = p->next;
    }
    p->next = NULL;    // 表示链表的结束

    // 第一行是一个整数M
    int m;
    scanf("%d", &m);

    // 随后M行每行包含一个整数X，表示小王子要把编号为X的玩具放在最前面
    int arr[m];
    for (int x = 0; x < m; x++)
    {
        scanf("%d", &arr[x]);
    }

    // 摆放指定编号玩具并输出结果，循环m次，一次打印一行
    ListNode* temp;
    for (int i = 0; i < m; i++)
    {
        temp = head;    // 前驱节点

        // 遍历链表寻找指定编号玩具
        p = head;
        while (p->next != NULL)
        {
            if (p->val == arr[i])    // 如果找到目标节点，退出遍历
                break;
            temp = p;
            p = p->next;
        }

        if (temp != p)    // 如果目标节点为头节点，则不处理
        {
            // 否则
            temp->next = p->next;
            p->next = head;
            head = p;
        }

        // 输出结果
        p = head;
        while (p->next != NULL)
        {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("\n");
    }

    // 释放内存
    free(temp);
    head = NULL;

    return 0;
}