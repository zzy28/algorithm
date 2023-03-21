// AcWing 830 单调栈
// 给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。

#include <iostream>
using namespace std;
const int N = 100010;
int stk[N], tt; // tt为栈顶，为零则栈空。

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        while(tt && stk[tt] >= x) tt--; // 栈不空 且 栈顶元素大于等于 x ，栈顶元素出栈，直到栈空 或者 栈顶元素小于 x 。
        if(tt) cout << stk[tt] << ' '; // 上面while循环终止条件之一：栈顶元素小于x，则该栈顶元素即为所求。
        else cout << -1 << ' '; // 上面while循环终止条件之二：栈为空，则不存在目标元素，返回 -1。
        stk[++ tt] = x;
    }
    return 0;
}