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
#define fileio freopen("revegetate.in", "r", stdin), freopen("revegetate.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

bool vis[100005];
bool colors[100005];
vector< pair<int, char> > edges[100005];

bool dfs(int u, bool color) {
    bool ok = true;
    vis[u] = true;
    colors[u] = color;
    for (pair<int, char> p : edges[u]) {
        if (vis[p.fi]) {
            if (p.se == 'S' && colors[u] != colors[p.fi]) {ok = false;}
            else if (p.se == 'D' && colors[u] == colors[p.fi]) {ok = false;}
        }
        else {ok = ok && dfs(p.fi, (p.se == 'S' ? color : !color));}
    }
    return ok;
}

int main() {
    fastio;
    fileio;
    int n, m;
    cin >> n >> m;
    FOR(i, 0, m) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        edges[a-1].pb({b-1, c});
        edges[b-1].pb({a-1, c});
    }
    int ans = 0;
    FOR(i, 0, n) {
        if (!vis[i]) {
            if (dfs(i, true)) {ans++;}
            else {ans = 0; break;}
        }
    }
    if (ans != 0) {
        cout << 1;
        while (ans--) {cout << 0;}
        cout << "\n"; 
    } else {
        cout << 0 << "\n";
    }
    return 0;
}
 