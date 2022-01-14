// 水果加篮问题思路：不停地往篮子里面加水果，直到不能加为止；删除远离待加入水果的水果（保留靠近待加入水果的水果）；加水果；删除水果；循环往复。

#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;

// 滑动窗口法
class Solution1 
{
public:
    int totalFruit(vector<int>& fruits) 
    {
        int left = 0,right = 0,ans = 0;
        int ln = fruits[left],rn = fruits[right];
        while(right < fruits.size())
        {
            if(fruits[right] == rn || fruits[right] == ln)
            {
                ans = max(ans,right + 1 - left);
                right++;
            }
            else
            {
                left = right - 1;
                ln = fruits[left]; //ln代表离新加入的水果比较近的水果，也就是不应该被移除的水果。
                while(left >= 2 && fruits[left - 1] == ln) 
                    left--;
                rn = fruits[right];
                // ans = max(ans,right + 1 - left); //right + 1 - left的值顶多与ans相等
            }
        }
        return ans;
    }
};

int main()
{
    int a[16] = {0,1,2,2,1,2,1,6,6,7,8,7,8,9,10,1};
    //通过数组a的地址初始化，注意地址是从0到6（左闭右开区间）
    vector<int> A(a, a+16);
    int result1;
    Solution1 s1 ;
    result1 = s1.totalFruit(A);
    cout << "result1 = " << result1 << endl;
    system("pause");
    return 0;
}