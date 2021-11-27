//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("mootube.in", "r", stdin), freopen("mootube.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int sizes[100005];
int p[100005];
int dsu_f(int u) {
    if (u != p[u]) {p[u] = dsu_f(p[u]);}
    return p[u];
}
void dsu_u(int u, int v) {
    u = dsu_f(u);
    v = dsu_f(v);
    if (u == v) {return;}
    if (sizes[u] < sizes[v]) {swap(u, v);}
    p[v] = u;
    sizes[u] += sizes[v];
    return;
}
int main() {
    fastio;
    fileio;
    int n, q;
    cin >> n >> q;
    FOR(i, 0, n) {
        p[i] = i;
        sizes[i] = 1;
    }
    pair<int, pii > edgeList[n-1];
    FOR(i, 0, n-1) {
        int p, q, r;
        cin >> p >> q >> r;
        edgeList[i] = {r, {--p, --q}};
    }
    sort(edgeList, edgeList + n-1, greater< pair<int, pii> >());
    pair<int, pii > query[q];
    int ans[q];
    FOR(i, 0, q) {
        cin >> query[i].fi >> query[i].se.fi;
        query[i].se.se = i;
    }
    sort(query, query + q, greater< pair<int, pii > >());
    int currEdge = 0;
    FOR(i, 0, q) {
        int k = query[i].fi;
        while (currEdge < n-1 && edgeList[currEdge].fi >= k) {
            dsu_u(edgeList[currEdge].se.fi, edgeList[currEdge].se.se);
            currEdge++;
        }
        ans[query[i].se.se] = sizes[dsu_f(--query[i].se.fi)];
    }
    for (int val : ans) {cout << --val << "\n";}
}

 