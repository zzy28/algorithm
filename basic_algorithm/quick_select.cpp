// AcWing 786
// 给定一个长度为n的整数数列，以及一个整数 k
// 请用快速选择算法求出数列从小到大排序后的第 k个数。

#include <iostream>
using namespace std;
const int N = 100010;
int q[N];

int quick_select(int q[], int l, int r, int k)
{
    if(l >= r) return q[l];
    int mid = q[(l + r) >> 1], i = l - 1, j = r + 1;
    while(i < j)
    {
        do i++; while(q[i] < mid);
        do j--; while(q[j] > mid);
        if(i < j) swap(q[i], q[j]);
    }
    if((j - l + 1) >= k) return quick_select(q, l, j, k);
    else return quick_select(q, j + 1, r, k - (j - l + 1));
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }
    int result = quick_select(q, 0, n - 1, k);
    printf("%d", result);
    return 0;
}