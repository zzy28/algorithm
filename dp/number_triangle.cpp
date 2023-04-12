// AcWing 898 数字三角形
// 给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。

//         7
//       3   8
//     8   1   0
//   2   7   4   4
// 4   5   2   6   5

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 1e9;

int a[N][N];
int f[N][N];

int main(){
    int n;
    // 输入三角形层数
    cin >> n;
    // 输入该三角形
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= i; j ++){
            cin >> a[i][j];
        }
    }
    // 初始化dp数组为负无穷
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= i + 1; j ++){
            f[i][j] = -INF;
        }
    }
    // 第一个节点直接赋值，后续遍历从第二层开始。
    f[1][1] = a[1][1];
    for(int i = 2; i <= n; i ++){
        for(int j = 1; j <= i; j ++){
            // 每个节点的值：左上方节点 + 右上方节点
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
        }
    }
    int res = -INF;
    for(int i = 1; i <= n; i ++){
        res = max(res, f[n][i]);
    }
    cout << res << endl;
    return 0;
}