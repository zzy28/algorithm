// AcWing 789
// 给定一个按照升序排列的长度为 n的整数数组，以及 q个查询。
// 对于每个查询，返回一个元素 k的起始位置和终止位置（位置从 0开始计数）。
// 如果数组中不存在该元素，则返回 [-1, -1]。

// 二分模板一共有两个，分别适用于不同情况。
// 算法思路：假设目标值在闭区间[l, r]中， 每次将区间长度缩小一半，当l = r时，我们就找到了目标值。

// 版本1
// 当我们将区间[l, r]划分成[l, mid]和[mid + 1, r]时，其更新操作是r = mid或者l = mid + 1;，计算mid时不需要加1。

// C++ 代码模板：
// int bsearch_1(int l, int r)
// {
//     while (l < r)
//     {
//         int mid = l + r >> 1;
//         if (check(mid)) r = mid;
//         else l = mid + 1;
//     }
//     return l;
// }
// 版本2
// 当我们将区间[l, r]划分成[l, mid - 1]和[mid, r]时，其更新操作是r = mid - 1或者l = mid;，此时为了防止死循环，计算mid时需要加1。

// C++ 代码模板：
// int bsearch_2(int l, int r)
// {
//     while (l < r)
//     {
//         int mid = l + r + 1 >> 1;
//         if (check(mid)) l = mid;
//         else r = mid - 1;
//     }
//     return l;
// }


#include <iostream>
using namespace std;
const int N = 100010;
int q[N];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i ++){
        scanf("%d", &q[i]);
    }
    while(m--){
        int k;
        scanf("%d", &k);
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(q[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if(q[l] != k) printf("-1 -1\n");
        else{
            printf("%d ", l);
            int l = 0, r = n - 1;
            while(l < r){
                int mid = l + r + 1>> 1;
                if(q[mid] <= k) l = mid;
                else r = mid - 1;
            }
            printf("%d\n", l);
        }
    }
    return 0;
}
