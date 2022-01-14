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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while(n-- && fast != NULL) {
            fast = fast->next;
        }
        fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
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
    cout << p->val << " ";
    while(p->next != nullptr)
    {
        cout << p->next->val << " ";
        p = p->next;
    }
     cout << endl;
}

int main()
{

    //创建链表
    ListNode* head = new ListNode(1);
    createList(head);
    //打印链表
    //printList(head);

    Solution s1;
    int removenum;
    cout << "qingshuru:removenum"<<endl;
    cin >> removenum;
    ListNode* newhead1;
    newhead1 = s1.removeNthFromEnd(head,removenum);

    //打印链表
    cout << "delete hou lianbiao"<<endl;
      printList(newhead1);

    system("pause");
    return 0;
}