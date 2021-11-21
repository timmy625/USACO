//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("moocast.in", "r", stdin), freopen("moocast.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

vi adj[1005];
bool vis[1005];
int dfs(int u, int sz) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {sz += dfs(v, 1);}
    }
    return sz;
}
int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    pii cows[n];
    FOR(i, 0, n) {
        cin >> cows[i].fi >> cows[i].se;
    }
    ll left = 0, right = 1e10;
    ll best = right;
    while (left <= right) {
        ll mid = (left+right)/2;
        FOR(i, 0, 1005) {
            adj[i].clear();
        }
        FOR(i, 0, n) {
            vis[i] = false;
            FOR(j, i+1, n) {
                ll distX = cows[i].fi - cows[j].fi;
                ll distY = cows[i].se - cows[j].se;
                ll totalDist = distX*distX + distY*distY;
                if (totalDist <= mid) {
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        }
        if (dfs(0, 1) == n) {
            best = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << best << "\n";
    return 0;
}
