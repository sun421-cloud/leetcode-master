//两两交换链表中的节点关键在于逻辑思路（就是那个示意图），逻辑思路对了，一步一步地写出来即可。
#include<iostream>
using namespace std;

//定义节点
struct ListNode 
{
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // 记录临时节点
            ListNode* tmp1 = cur->next->next->next; // 记录临时节点

            //cur->next = cur->next->next;    // 步骤一
            cur->next = tmp->next;   //步骤一
            cur->next->next = tmp;          // 步骤二
            cur->next->next->next = tmp1;   // 步骤三

            cur = cur->next->next; // cur移动两位，准备下一轮交换
        }
        return dummyHead->next;
    }
};

//创建链表
void createList(ListNode* pHead)
{
    ListNode* p = pHead; //p指示新插入节点的位置
    for (int i = 2; i <= 6; i++) 
    {
        ListNode* pNewNode = new ListNode(i); 
        pNewNode->next = NULL;
        p->next = pNewNode; //上一个节点与新建节点建立联系
        p = pNewNode; //p指示新插入节点的位置
    }
}

//打印链表
void printList(ListNode* pHead)
{
    ListNode* p = pHead;
    cout << p->val << endl;
    while(p->next != nullptr)
    {
        cout << p->next->val << endl;
        p = p->next;
    }
}

int main()
{

    //创建链表
    ListNode* head = new ListNode(1);
    createList(head);
    //打印链表
    //printList(head);

    Solution s1;
    ListNode* newhead1;
    newhead1 = s1.swapPairs(head);

    //打印链表
      printList(newhead1);

    system("pause");
    return 0;
}