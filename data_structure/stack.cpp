// AcWing 828 模拟栈
// 实现一个栈，栈初始为空，支持四种操作：
// push x – 向栈顶插入一个数 x
// pop – 从栈顶弹出一个数；
// empty – 判断栈是否为空；
// query – 查询栈顶元素。
// 现在要对栈进行 M 个操作，其中的每个操作 3 和操作 4 都要输出相应的结果。

#include <iostream>
using namespace std;
const int N = 100010;
int stk[N], tt = 0;

int main(){
    int m;
    cin >> m;
    while(m--){
        string op;
        int n;
        cin >> op;
        if(op == "push"){
            int x;
            cin >> x;
            stk[++ tt] = x; // 数组第一个位置为空，用于判断栈空
        }
        else if(op == "pop"){
            tt--;
        }
        else if(op == "empty"){
            cout << (tt ? "NO" : "YES") << endl;
        }
        else{
            cout << stk[tt] << endl;
        }
    }
    return 0;
}