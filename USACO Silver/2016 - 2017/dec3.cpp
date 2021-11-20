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

struct Cow {int x, y, p;};
vi adj[205];
bool vis[205];
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
    Cow cows[n];
    FOR(i, 0, n) {
        cin >> cows[i].x >> cows[i].y >> cows[i].p;
    }
    FOR(i, 0, n) {
        FOR(j, i+1, n) {
            int distX = cows[i].x - cows[j].x;
            int distY = cows[i].y - cows[j].y;
            int totalDist = distX*distX + distY*distY;
            if (totalDist <= cows[i].p*cows[i].p) {
                adj[i].pb(j);
            }
            if (totalDist <= cows[j].p*cows[j].p) {
                adj[j].pb(i);
            }
        }
    }
    int best = 0;
    FOR(i, 0, n) {
        FOR(j, 0, n) {vis[j] = false;}
        best = max(best, dfs(i, 1));
    }
    cout << best << "\n";
    return 0;
}
