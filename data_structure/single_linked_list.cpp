// AcWing 826 数组模拟链表
// 实现一个单链表，链表初始为空，支持三种操作：
// 向链表头插入一个数；
// 删除第 k 个插入的数后面的数；
// 在第 k 个插入的数后插入一个数。
// 现在要对该链表进行 M 次操作，进行完所有操作后，从头到尾输出整个链表。

// 输入：
// 第一行包含整数 M，表示操作次数。
// 接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种：
// H x，表示向链表头插入一个数 x
// D k，表示删除第 k 个插入的数后面的数（当 k 为 0 时，表示删除头结点）。
// I k x，表示在第 k 个插入的数后面插入一个数 x（此操作中 k均大于 0）。

#include <iostream>
using namespace std;

const int N = 100010;

int idx,head,e[N],ne[N];

//向链表头插入一个元素
void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

//删除第 k 个插入的数后面的数
void delete_after_k(int k){
    ne[k] = ne[ne[k]];
}

//在第 k 个插入的数后插入一个数
void add_after_k(int x, int k){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

int main(){
    head = -1;
    idx = 0;
    int m;
    cin >> m;
    while(m--){
        int k, x;
        char op;
        cin >> op;
        if(op == 'H'){
            cin >> x;
            add_to_head(x);
        }else if(op == 'D'){
            cin >> k;
            if(!k) head = ne[head];
            delete_after_k(k - 1);
        }
        else{
            int k,x;
            cin >> k >> x;
            add_after_k(x, k - 1);
        }
    }
    for(int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    return 0;
}