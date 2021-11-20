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
#define fileio freopen("closing.in", "r", stdin), freopen("closing.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

unordered_map<int, bool> M;
vi adj[3005];
void dfs(int u) { 
    M[u] = true;
    for (int v : adj[u]) {
        if (!M.count(v)) {continue;} 
        if (!M[v]) {dfs(v);}
    }
}
int main() {
    fastio;
    fileio;
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n) {M[i] = false;}
    FOR(i, 0, m) { 
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    int x;
    FOR(i, 0, n) { 
        dfs(M.begin()->fi); 
        bool connected = true;
        for (auto j : M) { 
            connected = (connected && M[j.fi]);
            M[j.fi] = false;
        }
        cout << (connected ? "YES" : "NO") << "\n";
        cin >> x;
        M.erase(--x);
    }
    return 0;
}
