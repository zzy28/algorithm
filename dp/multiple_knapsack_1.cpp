// 有 N种物品和一个容量是 V 的背包。
// 第 i种物品最多有 si件，每件体积是 vi，价值是 wi。
// 求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
// 输出最大价值。

// 朴素做法
// 数据范围是100，所以不会超时，下一题数据范围会扩大
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int v[N], w[N], s[N];
int f[N][N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> v[i] >> w[i] >> s[i];
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= m; j ++){
            // 多一个 k <= s[i] 的终止循环判断，因为物品有个数限制
            for(int k = 0; k <= s[i] && j >= v[i] * k; k ++){
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}