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
#define fileio freopen("snowboots.in", "r", stdin), freopen("snowboots.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int n, b;
bool vis[250][250];
int f[250];
pii boots[250];

int dfs(int tile, int boot) {
    int best = b;
    vis[tile][boot] = true;
    if (tile == n-1) {best = min(best, boot); return best;}
    FOR(i, tile + 1, min(n, tile + boots[boot].se+1)) {
        if (f[i] <= boots[boot].fi && !vis[i][boot]) {best = min(dfs(i, boot), best);}
    }
    FOR(i, boot+1, b) {
        if (f[tile] <= boots[i].fi && !vis[tile][i]) {best = min(dfs(tile, i), best);}
    }
    return best;
}

int main() {
    fastio;
    fileio;
    cin >> n >> b;
    FOR(i, 0, n) {cin >> f[i];}
    FOR(i, 0, b) {cin >> boots[i].fi >> boots[i].se;}
    cout << dfs(0, 0) << "\n";
    return 0;
}
