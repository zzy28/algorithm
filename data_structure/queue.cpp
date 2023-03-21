// AcWing 829
// 实现一个队列，队列初始为空，支持四种操作：
// push x – 向队尾插入一个数 x
// pop – 从队头弹出一个数；
// empty – 判断队列是否为空；
// query – 查询队头元素。
// 现在要对队列进行 M个操作，其中的每个操作 3和操作 4都要输出相应的结果。

#include <iostream>

using namespace std;

const int N = 100010;

int m;
int q[N], hh = 0, tt = -1;

int main()
{
    cin >> m;

    while (m -- )
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            q[ ++ tt] = x;
        }
        else if (op == "pop") hh ++ ;
        else if (op == "empty") cout << (hh <= tt ? "NO" : "YES") << endl;
        else cout << q[hh] << endl;
    }

    return 0;
}