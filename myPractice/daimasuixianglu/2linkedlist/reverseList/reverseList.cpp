#include<iostream>
using namespace std;

//定义节点
struct ListNode 
{
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

//双指针法
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

//递归法：从前往后翻转指针指向
class Solution2 {
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }

};

//递归法：从后往前翻转指针指向
class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        // 边缘条件判断
        if(head == NULL) return NULL;
        if (head->next == NULL) return head;
        
        // 递归调用，翻转第二个节点开始往后的链表
        ListNode *last = reverseList(head->next);
        // 翻转头节点与第二个节点的指向
        head->next->next = head;
        // 此时的 head 节点为尾节点，next 需要指向 NULL
        head->next = NULL;
        return last;
    }
}; 

//创建链表
void createList(ListNode* pHead)
{
    ListNode* p = pHead; //p指示新插入节点的位置
    for (int i = 1; i < 6; i++) 
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
    ListNode* head = new ListNode(0);
    createList(head);

    Solution1 s1;
    ListNode* newhead1;
    newhead1 = s1.reverseList(head);

    Solution2 s2;
    ListNode* newhead2;
    newhead2 = s2.reverseList(newhead1);

    Solution3 s3;
    ListNode* newhead3;
    newhead3 = s3.reverseList(newhead2);

    //打印链表
    printList(newhead1);
    cout << "---------------"<<endl;
    printList(newhead2);
    cout << "---------------"<<endl;
    printList(newhead3);

    system("pause");
    return 0;
}