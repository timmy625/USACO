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
#define fileio freopen("wormsort.in", "r", stdin), freopen("wormsort.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

vector<pii> adj[100005];
vector<bool> visited(100005);
vi group(100005);
void dfs(int u, int w, int g) {
    visited[u] = true;
    group[u] = g;
    for (pii v : adj[u]) {
        if (v.se >= w && !visited[v.fi]) {dfs(v.fi, w, g);}
    }
}
int main() {
    fastio;
    fileio;
    int n, m;
    cin >> n >> m;
    int p[n];
    bool sorted = true;
    FOR(i, 0, n) {cin >> p[i]; if (p[i] != i+1) {sorted = false;}}
    if (sorted) {cout << -1 << "\n"; return 0;}
    int low = INT_MAX, high = 0;
    FOR(i, 0, m) {
        int a, b, w;
        cin >> a >> b >> w;
        low = min(w, low);
        high = max(w, high);
        adj[a-1].pb({b-1, w});
        adj[b-1].pb({a-1, w});
    }
    int ans;
    while (low <= high) {
        int mid = (low + high)/2;
        fill(visited.begin(), visited.end(), false);
        fill(visited.begin(), visited.end(), 0);
        int g = 1;
        FOR(i, 0, n) {
            if (!visited[i]) {dfs(i, mid, g); g++;}
        }
        bool ok = true;
        FOR(i, 0, n) {
            if (group[i] != group[p[i]-1]) {ok = false;}
        }
        if (ok) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }   
    cout << ans << "\n";
    return 0;
}
