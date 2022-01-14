#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;

class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX; // 最终的结果
        int sum = 0; // 子序列的数值之和
        int subLength = 0; // 子序列的长度
        for (int i = 0; i < nums.size(); i++) { // 设置子序列起点为i
            sum = 0;
            for (int j = i; j < nums.size(); j++) { // 设置子序列终止位置为j
                sum += nums[j];
                if (sum >= s) { // 一旦发现子序列和超过了s，更新result
                    subLength = j - i + 1; // 取子序列的长度
                    result = result < subLength ? result : subLength;
                    break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
                }
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

class Solution2 {
public:
    vector<int> minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        vector<int> resultv;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                //result = result < subLength ? result : subLength;
                if(result > subLength)
                {
                    // 更新子数组长度
                    result = subLength;
                    // 更新子数组
                    resultv.clear();
                    for (int k=i ; k <= j ; k++)
                    {
                        //cout << nums[k] << endl ;
                        resultv.push_back( nums[k] );
                    }
                    //cout << "我是分界线" << endl ;
                }
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        //return result == INT32_MAX ? 0 : result;
        // for(vector<int>::iterator it=resultv.begin(); it!=resultv.end(); it++)
        //    cout<<*it<<endl;
        // cout << "我是分界线" << endl;   
        return resultv;
    }
};

int main()
{
    int a[6] = {2,3,1,2,4,3};
    //通过数组a的地址初始化，注意地址是从0到6（左闭右开区间）
    vector<int> A(a, a+6);
    int s=7;
    int result1;// , result2;
    vector<int> resultarray;
    Solution1 s1 ;
    Solution2 s2 ;
    result1 = s1.minSubArrayLen(s,A);
    resultarray = s2.minSubArrayLen(s,A);
    cout << "result1 = " << result1 << endl;
    for(vector<int>::iterator it=resultarray.begin(); it!=resultarray.end(); it++)
       cout<<*it<<endl;
    //cout << "result2 = " << result2 << endl;
    system("pause");
    return 0;
}