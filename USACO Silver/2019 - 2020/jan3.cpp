//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("wormsort.in", "r", stdin), freopen("wormsort.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

vector< pii > adj[100005];
bool vis[100005];
int comps[100005] = {};
void dfs(int u, int w, int c) {
    vis[u] = true;
    comps[u] = c;
    for (pii p : adj[u]) {
        if (!vis[p.fi] && p.se >= w) {dfs(p.fi, w, c);}
    }
    return;
}
int main() {
    fastio;
    fileio;
    int n, m;
    cin >> n >> m;
    int p[n];
    FOR(i, 0, n) {cin >> p[i];}
    FOR(i, 0, m) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a-1].pb({b-1, w});
        adj[b-1].pb({a-1, w});
    }
    int left = 0, right = 1e9;
    int best = left;
    while (left <= right) {
        int mid = (left + right)/2;
        FOR(i, 0, n) {vis[i] = false; comps[i] = 0;}
        int comp = 1;
        FOR(i, 0, n) {
            if (!vis[i]) {dfs(i, mid, comp); comp++;}
        }
        bool ok = true;
        FOR(i, 0, n) {
            if (comps[i] != comps[p[i]-1]) {ok = false; break;}
        }
        if (ok) {
            best = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << (best == 1e9 ? -1 : best) << "\n";
    return 0;
}
