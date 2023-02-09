// 给定你一个长度为n的整数数列。
// 请你使用快速排序对这个数列按照从小到大进行排序。
// 并将排好序的数列按顺序输出。

#include <iostream>
using namespace std;

const int N = 100010;
int q[N];

void quick_sort(int q[], int l, int r){
    if(l >= r) return;
    int mid = q[(l + r) / 2];
    int i = l - 1;
    int j = r + 1;
    while(i < j){
        do i++;while(q[i] < mid);
        do j--;while(q[j] > mid);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main(){
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &q[i]);
    }
    quick_sort(q, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ", q[i]);
    }
}