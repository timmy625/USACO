#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(long long i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("fenceplan.in", "r", stdin), freopen("fenceplan.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

pii cows[100005];
vi adj[100005];
bool visited[100005];
int maxX, maxY, minX, minY;

void dfs(int u) {
    visited[u] = true;
    maxX = max(maxX, cows[u].fi);
    minX = min(minX, cows[u].fi);
    maxY = max(maxY, cows[u].se);
    minY = min(minY, cows[u].se);
    for (int v : adj[u]) {
        if (!visited[v]) {dfs(v);}
    }
    return;
}

int main() {
    fastio;
    fileio;
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n) {
        cin >> cows[i].fi >> cows[i].se;
        visited[i] = false;
    }
    FOR(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    int best = INT_MAX;
    FOR(i, 0, n) {
        if (visited[i]) {continue;}
        maxX = 0; maxY = 0; minX = INT_MAX; minY = INT_MAX;
        dfs(i);
        best = min(best,  2 * (maxX - minX + maxY - minY));
    }
    cout << best << "\n";
    return 0;
}
