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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return NULL;
    }
};

//创建链表
void createList(ListNode* pHead)
{
    ListNode* p = pHead; //p指示新插入节点的位置
    int length;
    cout << "lianbiao length" << endl;
    cin >> length ;
    for (int i = 1; i < length; i++) 
    {
        int nodeval;
        cout << "node value" << endl;
        cin >> nodeval;
        ListNode* pNewNode = new ListNode(nodeval); //新节点初始化为nodeval; 
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
    //测试数据：412351
    ListNode* head = new ListNode(4);
    createList(head);
    ListNode* enter = head->next;
    ListNode* cur = head;
    while(cur->val !=3 )
    {
        cur = cur->next;
    }
    cur->next->next = enter;

    Solution s1;
    ListNode* newhead1;
    newhead1 = s1.detectCycle(head);
    
    cout << "enter value:" << newhead1->val << endl; 
    
    system("pause");
    return 0;
}