// AcWing 895 最长上升子序列
// 给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。(非连续)

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N], f[N];

int main(){
    // 给定 n 个数
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++){
        // 初始化，每个子序列至少为1
        f[i] = 1;
        for(int j = 1; j < i; j ++){
            // j 从 1 到 i - 1， 如果a[j] < a[i]， 说明a[j]和a[i]可以构成子序列。
            // 更新状态，f[j] + 1
            if(a[j] < a[i]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i ++){
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}