#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
public:
    vector<int> sortedSquares(vector<int> A) { // vector<int> sortedSquares(vector<int>& A) 引用的方式传入向量B的数据，会改变B向量的值，指向同一块内存。
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i]; // 等效于A[i] = A[i] * A[i];
        }
        //sort(A.begin(),A.begin()+5);//对前5个排序 
	    sort(A.begin(),A.end());//快速排序 默认的从小到大排序,可以不写less() 
	    //sort(A.begin(),A.end(),greater<int>());//从大到小排列 
        return A;
    }
};

class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0); //向量名:result，元素个数：A.size()，初始值：0；
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i]; //最终k=-1,int类型包含负数、0和正数。
                i++;
            }
        }
        //return k;
        return result;
    }
};

int main()
{
    int a[5] = {-7,-3,2,3,11};
    //通过数组a的地址初始化，注意地址是从0到6（左闭右开区间）
    vector<int> B(a, a+5);
    vector<int> result1 , result2;
    //测试
    //vector<int>::iterator itbegin=nums.begin();
    //vector<int>::iterator itend=nums.end();
    Solution1 s1 ;
    Solution2 s2 ;
    //暴力解法
    result1 = s1.sortedSquares(B);
    for(vector<int>::iterator it=result1.begin(); it!=result1.end(); it++)
       cout<<*it<<endl;
    //双指针法
    //打印k的值
    // int k;
    // k = s2.sortedSquares(B);
    // cout<< k <<endl;
    //打印最终结果
    result2 = s2.sortedSquares(B);
    for(vector<int>::iterator it=result2.begin(); it!=result2.end(); it++)
       cout<<*it<<endl;
    system("pause");
    return 0;
}