#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("mootube.in", "r", stdin), freopen("mootube.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int n, q;
vector<pii> adj[5005];
bool vis[50005];

int dfs(int u, int minK) {
    int total = 1;
    vis[u] = true;
    for (pii v : adj[u]) {
        if (!vis[v.fi] && v.se >= minK) {
            total += dfs(v.fi, minK);
        }
    }
    return total;
}

int main() {
    fastio;
    fileio;
    cin >> n >> q; 
    FOR(i, 0, n-1) {
        int a, b, r;
        cin >> a >> b >> r;
        adj[a-1].pb(mp(b-1, r));
        adj[b-1].pb(mp(a-1, r));
    }   
    FOR(i, 0, q) {
        FOR(i, 0, n) {vis[i] = false;}
        int k, v;
        cin >> k >> v;
        cout << dfs(v-1, k)-1 << "\n";
    }
    return 0;
}
