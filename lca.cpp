#include <bits/stdc++.h>
#define N 1000010
using namespace std;
struct node {
    int f,t,nex;
}rt[N];
int head[N];
int cnt;
int a,b,c;
void add(int x,int y) {
    cnt ++;
    rt[cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}
int fa[N];
int top[N];
int siz[N];
int dep[N];
int son[N];
void dfs(int x,int f) {
    fa[x] = f;
    dep[x] = dep[f] + 1;
    siz[x] = 1;
    for(int i = head[x];i;i = rt[i].nex) {
        if(rt[i].t != f) {
            dfs(rt[i].t,x);
            siz[x] += siz[rt[i].t];
            if(siz[rt[i].t] > siz[son[x]])
                son[x] = rt[i].t;
        }
    }
}
void dfs2(int x,int topp) {
    top[x] = topp;
    if(son[x])
        dfs2(son[x],topp);
    for(int i = head[x];i;i = rt[i].nex) {
        if(rt[i].t != fa[x] && rt[i].t != son[x])
            dfs2(rt[i].t,rt[i].t);
    }
}
int LCA(int x,int y) {
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]])
            swap(x,y);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x,y);
    return x;
}
int main() {
    cin>>a>>b>>c;
    int x,y;
    for(int i = 1;i < a;i ++) {
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(c,0);
    dfs2(c,c);
    for(int i = 1;i <= b;i ++) {
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
    return 0;
}