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
#define fileio freopen("milkvisits.in", "r", stdin), freopen("milkvisits.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

string s;
vi edges[100005];
bool vis[100005];
int comps[100005];
void dfs(int u, int totalComps) {
    vis[u] = true;
    comps[u] = totalComps;
    for (int v : edges[u]) {
        if (vis[v] || (s[v] != s[u])) {continue;}
        dfs(v, totalComps);
    }
}
int main() {
    fastio;
    fileio;
    int n, m;
    cin >> n >> m >> s;
    FOR(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    int totalComps = 0;
    FOR(i, 0, n) {
        if (!vis[i]) {dfs(i, ++totalComps);}
    }
    FOR(i, 0, m) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        char ans = '0';
        if (comps[a] == comps[b]) {
            if (s[a] == c) {ans = '1';}
        } else {
            ans = '1';
        }
        cout << ans;
    }
    return 0;
}
 