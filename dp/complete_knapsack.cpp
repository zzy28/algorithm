// AcWing 3 完全背包问题
// 有 N件物品和一个容量是 V的背包。每件物品可以用无限次。
// 第 i 件物品的体积是 vi，价值是 wi。
// 求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
// 输出最大价值。

// 朴素做法，三个for循环，会超时。
// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 1010;
// int n, m;
// int v[N], w[N];
// int f[N][N];

// int main(){
//     cin >> n >> m;
//     for(int i = 1; i <= n; i ++){
//         cin >> v[i] >> w[i];
//     }
//     for(int i = 1; i <= n; i ++){
//         for(int j = 0; j <= m; j ++){
//             for(int k = 0; k * v[i] <= j; k ++){ // 第 i 个物品用 k 次。
//                 // 由于是多重背包，当装得下第 i 个物品时，决策是：上一次装的 vs 装 k 个 （01背包是：不装 vs 装）
//                 // 会超时
//                 f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]); 
//             }
//         }    
//     }
//     cout << f[n][m] << endl;
//     return 0;
// }


// 逻辑优化（优化掉参数k）
// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 1010;
// int v[N], w[N], f[N][N];

// int main(){
//     int n, m;
//     cin >> n >> m;
//     // 数组从1开始存，0可以不用
//     for(int i = 1; i <= n; i ++){ 
//         cin >> v[i] >> w[i];
//     }
//     for(int i = 1; i <= n; i ++){
//         for(int j = 0; j <= m; j ++){
//             f[i][j] = f[i-1][j];
//             if(j - v[i] >= 0)
//                 f[i][j]=max(f[i][j], f[i][j - v[i]] + w[i]);
//         }
//     }
//     cout << f[n][m] << endl;
//     return 0;
// }


// 代码优化（一维数组等价表示）
// 最终版本
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int v[N], w[N], f[N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= n; i ++){
        for(int j = v[i]; j <= m; j ++){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}