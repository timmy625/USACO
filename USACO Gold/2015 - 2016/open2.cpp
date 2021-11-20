//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("closing.in", "r", stdin), freopen("closing.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int parents[200005];
int sizes[200005];
vi edges[200005];
int dsu_f(int u) {
    if (u != parents[u]) {parents[u] = dsu_f(parents[u]);}
    return parents[u];
}
void dsu_u(int u, int v) {
    u = dsu_f(u);
    v = dsu_f(v);
    if (u == v) {return;}
    if (sizes[u] < sizes[v]) {swap(u, v);}
    parents[v] = u;
    sizes[u] += sizes[v];
    return;
}
int main() {
    fastio;
    fileio;
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    int remove[n];
    bool open[n];
    FOR(i, 0, n) {cin >> remove[i]; open[i] = false; parents[i] = i; sizes[i] = 1;}
    reverse(remove, remove + n);
    bool ans[n];
    FOR(i, 0, n) {
        int u = --remove[i];
        open[u] = true;
        for (int v : edges[u]) {
            if (open[v]) {dsu_u(u, v);}
        }
        ans[i] = (sizes[dsu_f(u)] == i+1);
    }
    reverse(ans, ans + n);
    for (bool b : ans) {cout << (b ? "YES" : "NO") << "\n";}
    return 0;
}
