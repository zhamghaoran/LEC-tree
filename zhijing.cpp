#include "bits/stdc++.h"
#define N 100010
using namespace std;

struct node{
    int f,t,val,nex;
}rt[N];
int head[N];
int cnt;
void add(int x,int y,int z) {
    rt[++ cnt].f  =x;
    rt[cnt].t = y;
    rt[cnt].val = z;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}
int dis;
int num;
void dfs(int x,int f,int distance) {
    for (int i = head[x];i;i = rt[i].nex) {
        if (rt[i].t != f) {
            if (distance + rt[i].val > dis) {
                dis = distance + rt[i].val;
                num = rt[i].t;
            }
            dfs(rt[i].t,x,distance + rt[i].val);
        }
    }
}
int main() {
    int a;
    cin>>a;
    int x,y,z;
    for (int i = 1;i < a;i ++) {
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0,0);
    dis = 0;
    dfs(num,0,0);
    cout<<dis;
    return 0;
}
