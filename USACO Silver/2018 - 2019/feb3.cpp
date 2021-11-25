//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("revegetate.in", "r", stdin), freopen("revegetate.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

vector< pair<int, char> > adj[100005];
bool type[100005] = {};
bool vis[100005] = {};
string ans = "1";
void dfs(int u) {
    vis[u] = true;
    for (pair<int, char> p : adj[u]) {
        if (vis[p.fi]) {
            if (p.se == 'S' && type[p.fi] != type[u]) {ans = "-";}
            else if (p.se == 'D' && type[p.fi] == type[u]) {ans = "-";}
        } else {
            if (p.se == 'S') {type[p.fi] = type[u];}
            else {type[p.fi] = !type[u];}
            dfs(p.fi);
        }
    }
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
        adj[a-1].pb({b-1, c});
        adj[b-1].pb({a-1, c});
    }
    FOR(i, 0, n) {
        if (!vis[i]) {
            ans += '0';
            type[i] = true;
            dfs(i);
        }
    }
    cout << (ans[0] == '-' ? "0" : ans) << "\n";
    return 0;
}
