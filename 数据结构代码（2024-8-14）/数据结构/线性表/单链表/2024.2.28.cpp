#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;    //�ڵ�ֵ
    struct ListNode* next;    // ָ����һ���ڵ��ָ��
} ListNode;

int main()
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));    // ��ʼ��ͷ�ڵ�
    ListNode* p = head;    // ��ǰָ��Ĭ��ָ��ͷ�ڵ�

    // ����������ֵ
    for (int i = 1; i <= 10; i++)
    {
        p->val = i;
        p->next = (ListNode*)malloc(sizeof(ListNode));
        p = p->next;
    }
    p->next = NULL;    // ��ʾ����Ľ���

    // ��һ����һ������M
    int m;
    scanf("%d", &m);

    // ���M��ÿ�а���һ������X����ʾС����Ҫ�ѱ��ΪX����߷�����ǰ��
    int arr[m];
    for (int x = 0; x < m; x++)
    {
        scanf("%d", &arr[x]);
    }

    // �ڷ�ָ�������߲���������ѭ��m�Σ�һ�δ�ӡһ��
    ListNode* temp;
    for (int i = 0; i < m; i++)
    {
        temp = head;    // ǰ���ڵ�

        // ��������Ѱ��ָ��������
        p = head;
        while (p->next != NULL)
        {
            if (p->val == arr[i])    // ����ҵ�Ŀ��ڵ㣬�˳�����
                break;
            temp = p;
            p = p->next;
        }

        if (temp != p)    // ���Ŀ��ڵ�Ϊͷ�ڵ㣬�򲻴���
        {
            // ����
            temp->next = p->next;
            p->next = head;
            head = p;
        }

        // ������
        p = head;
        while (p->next != NULL)
        {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("\n");
    }

    // �ͷ��ڴ�
    free(temp);
    head = NULL;

    return 0;
}