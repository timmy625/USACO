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
#define fileio freopen("moocast.in", "r", stdin), freopen("moocast.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int n;
pii coords[1005];
bool vis[1005];
int dfs(int u, int x) {
    vis[u] = true;
    int currSize = 1;
    FOR(v, 0, n) {
        if (vis[v]) {continue;}
        int distX = abs(coords[u].fi - coords[v].fi);
        int distY = abs(coords[u].se - coords[v].se);
        if ((distX*distX + distY*distY) <= x) {
            currSize += dfs(v, x);
        }
    }
    return currSize;
}
int main() {
    fastio;
    fileio;
    cin >> n;
    FOR(i, 0, n) {
        cin >> coords[i].fi >> coords[i].se;
    }
    int low = 1, high = 1e9;
    int ans;
    while (low <= high) {
        int mid = (low + high)/2;
        FOR(i, 0, n) {vis[i] = false;}
        if (dfs(0, mid) == n) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
