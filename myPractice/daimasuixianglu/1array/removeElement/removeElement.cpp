// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
#include<iostream>
#include<vector>
using namespace std;

//暴力解法
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下表i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;

    }
};

//双指针法：快指针负责挑选数组中不等于val的值，慢指针负责指示新数组待插入元素的位置，也就是末尾的下一位。
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                //本次赋值完成后，慢指针自增指向下一个元素，如果快指针遍历到了val，不做处理，继续后移，找到非val元素，赋值到慢指针所指位置
                nums[slowIndex++] = nums[fastIndex]; //先执行操作nums[slowIndex] = nums[fastIndex]，然后执行操作slowIndex++。
            }
        }
        return slowIndex;
    }
};

int main()
{
    int a[8] = {0,1,2,2,3,0,4,2};
    //通过数组a的地址初始化，注意地址是从0到6（左闭右开区间）
    vector<int> nums(a, a+8);
    //测试
    //vector<int>::iterator itbegin=nums.begin();
    //vector<int>::iterator itend=nums.end();
    // for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++)
    //    cout<<*it<<endl;
    int val = 2;
    int result1,result2;
    Solution1 s1;
    result1=s1.removeElement(nums , val);
    Solution2 s2;
    result2=s2.removeElement(nums , val);
    cout<< result1 << endl << result2 << endl;
    system("pause");
    return 0;
}