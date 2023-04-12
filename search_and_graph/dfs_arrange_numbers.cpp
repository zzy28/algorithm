// AcWing 842 排列数字
// 给定一个整数 n，将数字 1∼n排成一排，将会有很多种排列方法。
// 现在，请你按照字典序将所有的排列方法输出。

#include<iostream>

using namespace std;

const int N = 10;
int path[N];// 保存序列
int state[N];// 数字是否被用过
int n;

void dfs(int u)
{
    if(u > n)// 数字填完了，输出
    {
        for(int i = 1; i <= n; i++)// 输出方案
            cout << path[i] << " ";
        cout << endl;
    }

    for(int i = 1; i <= n; i++)// 空位上可以选择的数字为:1 ~ n
    {
        if(!state[i])// 如果数字 i 没有被用过
        {
            path[u] = i;// 放入空位
            state[i] = 1;// 数字被用，修改状态
            dfs(u + 1);// 填下一个位
            state[i] = 0;// 回溯，取出 i
        }
    }
}

int main()
{

    cin >> n;
    dfs(1);
    return 0;
}