#include "bits/stdc++.h"

using namespace std;

struct node {
    int f;
    int t;
    int nex;
} rt[500010];
int head[500010];
int cnt;
int a;
int siz[500010];
int minn;
int ans;
void add(int x, int y) {
    rt[++cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

void dfs(int x, int f) {
    siz[x] = 1;
    int NowMaxx = 0;
    for (int i = head[x];i;i = rt[i].nex) {
        if (rt[i].t != f) {
            dfs(rt[i].t,x);
            siz[x] += siz[rt[i].t];
            NowMaxx = max(NowMaxx,siz[rt[i].t]);
        }
    }
    NowMaxx = max(NowMaxx,a - siz[x]);
    if (NowMaxx < minn) {
        minn = NowMaxx;
        ans = x;
    }
}

int main() {

    cin >> a;
    int x, y;
    for (int i = 1; i < a; i++) {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    minn = 0x3f3f3f3f;    // int / 2
    dfs(1,0);
    cout<<minn;
    return 0;
}