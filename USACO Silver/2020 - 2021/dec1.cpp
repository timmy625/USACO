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
#define fileio freopen("template.in", "r", stdin), freopen("template.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

vi edges[100005];
bool vis[100005];
int main() {
    fastio;
    int n;
    cin >> n;
    FOR(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    ll days = 0;
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while(q.size()) {
        int u = q.front();
        q.pop();
        ll cows = 1;
        ll need = edges[u].size() - 1;
        if (u == 0) {need++;}
        while (cows < need+1) {
            cows *= 2;
            days++;
        }
        for (int v : edges[u]) {
            if (vis[v]) {continue;}
            vis[v] = true;
            days++;
            q.push(v);
        }
    }
    cout << days << "\n";
    return 0;
}
