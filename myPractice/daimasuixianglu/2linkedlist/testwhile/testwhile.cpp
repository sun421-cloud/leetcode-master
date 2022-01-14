#include<iostream>
using namespace std;
 int main()
 {
     int k=0;
     while(-1) //while循环中的条件结果为正数或者负数的时候，都可以进入循环，只有结果为0的时候跳出循环。
     {
         cout<< "keyi"<< endl;
         if(k>3)
         {
             break;
         }
         k++;
     }
    
    system("pause");
    return 0;
 }