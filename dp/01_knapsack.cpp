// AcWing 2 01背包问题
// 有 N件物品和一个容量是 V的背包。每件物品只能使用一次。
// 第 i 件物品的体积是 vi，价值是 wi。
// 求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
// 输出最大价值。

// 二维表示
// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 1010;

// int n, m; // 背包容量和体积
// int v[N], w[N]; // 物品的体积和价值
// int f[N][N]; // i件物品，体积不超过j的最大价值

// int main()
// {
//     cin >> n >> m;
    
//     for(int i = 1; i <= n; i ++){
//         cin >> v[i] >> w[i]; // 输入物品
//     }
    
//     for(int i = 1; i <= n; i ++){
//         for(int j = 0; j <= m; j ++){
//             //  当前背包容量装不进第i个物品，则价值等于前i-1个物品
//             if(j < v[i]) 
//                 f[i][j] = f[i - 1][j];
//             // 能装，需进行决策是否选择第i个物品
//             else    
//                 f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
//         }
//     }
//     cout << f[n][m] << endl;
//     return 0;
// }




// 一维优化
// 如果使用顺序，会先更新f[4],再更新f[7]，对于这个书包问题来讲，就是有可能，
// 在更新f[4]的时候，已经把这次能加的物品加进来了，然后更新f[7]的时候，还有可能再加一次，
// 所以必须使用逆序，保证，f[4]是没有加入新物品前，背包里的最优解。
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N];
int f[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= n; i ++){ // 由于i 只会用到 i 和 i - 1，可以优化。
        for(int j = m; j >= v[i]; j --){ // 逆序
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}