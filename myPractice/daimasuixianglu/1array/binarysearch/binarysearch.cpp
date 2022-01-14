#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在[middle + 1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};

int main()
{
    int a[6] = {-1,0,3,5,9,12};
    //通过数组a的地址初始化，注意地址是从0到6（左闭右开区间）
    vector<int> nums(a, a+6);
    //测试
    //vector<int>::iterator itbegin=nums.begin();
    //vector<int>::iterator itend=nums.end();
    for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++)
       cout<<*it<<endl;
    int target = 9;
    int result1,result2;
    Solution1 s1;
    result1=s1.search(nums , target);
    Solution2 s2;
    result2=s2.search(nums , target);
    cout<< result1 << endl << result2 << endl;
    system("pause");
    return 0;
}