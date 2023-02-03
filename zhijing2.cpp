#include "bits/stdc++.h"

using namespace std;
struct node {
    int f;
    int t;
    int val;
    int nex;
} rt[100010];
int head[100010];
int cnt;

void add(int x, int y, int z) {
    rt[++cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = z;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

int maxx[100010];
int SecondMaxx[1000010];
int ans;

void dfs(int x, int f) {
    for (int i = head[x]; i; i = rt[i].nex) {
        if (rt[i].t != f) {
            dfs(rt[i].t, x);
        }
    }
    for (int i = head[x]; i; i = rt[i].nex) {
        if (rt[i].t != f) {
            if (maxx[rt[i].t] + rt[i].val > maxx[x]) {
                SecondMaxx[x] = maxx[x];
                maxx[x] = maxx[rt[i].t] + rt[i].val;
            } else if (maxx[rt[i].t] + rt[i].val > SecondMaxx[x]) {
                SecondMaxx[x] = maxx[rt[i].t] + rt[i].val;
            }
        }
    }
    ans = max(ans, maxx[x] + SecondMaxx[x]);
}

int main() {
    int a;
    cin >> a;
    int x, y, z;
    for (int i = 1; i < a; i++) {
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}