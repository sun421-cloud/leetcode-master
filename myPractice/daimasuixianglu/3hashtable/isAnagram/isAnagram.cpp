#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //数组初始化
        //举例：int a[5] = {0};    //全部初始化为0，[0, 0, 0, 0, 0]
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;
    }
};

int main() {
    //测试数据
    string s = "aet", t = "eae";
    Solution s1;
    bool result = s1.isAnagram(s, t);
    cout << result << endl; //1-true 0-false;
    
    system("pause");
    return 0;
}