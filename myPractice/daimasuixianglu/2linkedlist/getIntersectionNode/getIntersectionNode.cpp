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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL) { // 求链表A的长度
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL) { // 求链表B的长度
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 让curA为最长链表的头，lenA为其长度
        if (lenB > lenA) {
            swap (lenA, lenB);
            swap (curA, curB);
        }
        // 求长度差
        int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        while (gap--) {
            curA = curA->next;
        }
        // 遍历curA 和 curB，遇到相同则直接返回
        while (curA != NULL) {
            //cout << "1" << endl; //前期测试用；
            if (curA == curB) {
                //从运行结果可以看出，这段程序并没有被执行；
                //原因是在创建链表的时候，a和b是分别创建的，所以它们并没有共用部分节点，
                //所以虽然某些节点的值是一样的，可是地址是不一样的，而本程序的设定就是不仅值一样，地址也是一样的，也即是共用某些节点;
                //同时，由于并没有相交点，所以在主函数中打印相交点的值的时候会出现错误；
                cout << "Intersection value:" << curA->val << endl;
                cout << "xiangjiaodian dizhi:" << curA << endl;
                return curA; //返回相交点的地址
            }
            curA = curA->next;
            curB = curB->next;
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
    //测试数据： a:09124 b:324
    ListNode* heada = new ListNode(0);
    createList(heada);
    ListNode* headb = new ListNode(3);
    //createList(heada); //a和b没有相交点
    ListNode* cur = heada;
    while(cur->val != 2)
    {
        cur = cur->next;
    }
    headb->next = cur; //a和b共用节点2、4；
    //打印链表
    printList(heada);
    printList(headb);

    Solution s1;
    ListNode* newhead1;
    newhead1 = s1.getIntersectionNode(heada,headb);
    
    //第一次尝试出现错误：出项异常。segmentation fault 原因：创建了没有相交点的两个链表；
    cout << "Intersection value:" << newhead1->val << endl; 
    

    system("pause");
    return 0;
}
