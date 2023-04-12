// AcWing 897 最长公共子序列
// 给定两个长度分别为 N和 M的字符串 A和 B，求既是 A的子序列又是 B的子序列的字符串长度最长是多少。

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

char a[N], b[N];
// f[i][j] 状态表示为 a 组第 i 个和 b 组第 j 个之前的最长公共子序列长度。
int f[N][N];

int main(){
    int n, m;
    cin >> n >> m >> a + 1 >> b + 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            // a 组第 i 个和 b 组第 j 个相等，则该位置最长公共子序列为f[i - 1][j - 1] + 1
            if(a[i] == b[j]){
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else{
                // 不相等则该位置最长公共子序列为max (不包含第 i 个，不包含第 j 个)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}