#include<iostream>
//#include<vector>
//#include<algorithm>
using namespace std;

struct ListNode 
{
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

//直接使用原来的链表来进行移除节点操作：
class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 删除头结点
        while (head != NULL && head->val == val) { // 注意这里不是if
            ListNode* tmp = head;
            head = head->next;
            delete tmp; 
        }

        // 删除非头结点
        ListNode* cur = head;
        while (cur != NULL && cur->next!= NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

//设置一个虚拟头结点在进行移除节点操作：
class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

void createList(ListNode* pHead)
{
    ListNode* p = pHead; //p指示新插入节点的位置
    int length;
    cout << "请输入链表的长度" << endl;
    cin >> length ;
    for (int i = 1; i < length; i++) 
    {
        int nodeval;
        cout << "请输入新建节点的值" << endl;
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
    cout << p->val << endl;
    while(p->next != nullptr)
    {
        cout << p->next->val << endl;
        p = p->next;
    }
}

int main()
{
    int val;
    cout << "请输入要移除的值" << endl;
    cin >> val;

    //创建链表
    int headval;
    cout << "请输入头结点的值" << endl;
    cin >> headval;
    ListNode* head = new ListNode(headval);
    createList(head);

    //移除特定值
    //程序运行过程中出现如下问题：
    //移除非头节点程序正常运行;
    //移除头结点的时候：分别运行两种方法一切正常，一起运行程序卡住；
    //将第一种方法中删除头结点部分的语句“delete tmp;”注释掉，程序正常运行；
    //为什么？
    //注释掉语句“delete tmp;”时，当删除头结点的时候，只是将新链表的头指针指向第二个节点；
    //可是头结点仍然在内存里，此时，使用第二种方法，它仍然可以找到头结点，并找到第二个节点，生成新的链表；
    //然而，当手动释放掉头结点的内存的时候，这时候第二种方法利用head中的地址找到的是已经释放的内存，属于非法访问。
    Solution1 s1;
    ListNode* newhead1;
    newhead1 = s1.removeElements(head, val);

    Solution2 s2;
    ListNode* newhead2;
    newhead2 = s2.removeElements(head, val);

    //打印链表
    printList(newhead1);
    cout << "---------------"<<endl;
    printList(newhead2);

    system("pause");
    return 0;
}