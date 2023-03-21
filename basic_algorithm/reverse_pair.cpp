// AcWing 788
// 给定一个长度为 n的整数数列，请你计算数列中的逆序对的数量。
// 逆序对的定义如下：对于数列的第 i个和第 j个元素，如果满足 i<j且 a[i]>a[j],则其为一个逆序对；否则不是。

#include <iostream>
using namespace std;
const int N = 100010;
typedef long long LL;
int q[N], tmp[N];

LL reverse_pair(int l, int r){
    if(l >= r) return 0;
    int mid = l + r >> 1;
    LL res = reverse_pair(l, mid) + reverse_pair(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else{
            tmp[k++] = q[j++];
            res += mid - i + 1;
        }
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    for(int i = l, j = 0; i <= r; i ++, j ++){
        q[i] = tmp[j];
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &q[i]);
    }
    LL res = reverse_pair(0, n - 1);
    printf("%lld", res);
    return 0;
}