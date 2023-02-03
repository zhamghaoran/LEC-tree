#include <bits/stdc++.h>
using namespace std;
struct edge {
    int f;
    int t;
    int val;
    int nex;
}rt[100010];
int head[100010];
int cnt;
void add(int x,int y,int z) {
    rt[++ cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = z;
    rt[cnt].nex =  head[x];
    head[x] = cnt;
}
void dfs(int x,int f) {
    cout<<x<<endl;
    for (int i = head[x];i;i = rt[i].nex) {
        if (rt[i].t != f) {
            dfs(rt[i].t,x);
        }
    }
}
int main() {
    int a;
    cin>>a;
    for (int i = 1;i < a;i ++) {
        int x,y;
        cin>>x>>y;
        add(x,y,0);
        add(y,x,0);
    }
    dfs(1,0);
    return 0;
}
