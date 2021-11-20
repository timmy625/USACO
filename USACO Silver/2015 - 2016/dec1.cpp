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
#define fileio freopen("lightson.in", "r", stdin), freopen("lightson.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int n, m;
vector< pii > toggles[105][105];
bool lit[105][105];
bool vis[105][105];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans = 0;
void ff(int a, int b) {
    vis[a][b] = true;
    for (pii p : toggles[a][b]) {
        if (!lit[p.fi][p.se]) {
            lit[p.fi][p.se] = true;
            ans++;
            FOR(i, 0, 4) {
                int x = dx[i] + p.fi;
                int y = dy[i] + p.se;
                if (!(x < 0 || x >= n || y < 0 || y >= n) && vis[x][y]) {ff(p.fi, p.se); break;}
            }
        }
    }    
    FOR(i, 0, 4) {
        int x = dx[i] + a;
        int y = dy[i] + b;
        if (x < 0 || x >= n || y < 0 || y >= n || !lit[x][y] || vis[x][y]) {continue;}
        ff(x, y);
    }
    return;
}
int main() {
    fastio;
    fileio;
    cin >> n >> m;
    FOR(i, 0, m) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        toggles[x-1][y-1].pb({a-1, b-1});
    }
    lit[0][0] = true;
    ff(0, 0);
    cout << ++ans << "\n";
    return 0;
}
 