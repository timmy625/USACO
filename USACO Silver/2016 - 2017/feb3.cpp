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
#define fileio freopen("countcross.in", "r", stdin), freopen("countcross.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int n, k, r;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool vis[105][105];
vector<pii> roads[105][105];
void ff(int a, int b) {
    if (vis[a][b] || a < 0 || a >= n || b < 0 || b >= n) {return;}
    vis[a][b] = true;
    FOR(i, 0, 4) {
        bool ok = true;
        for (pii p : roads[a][b]) {
            if (p.fi == a + dx[i] && p.se == b + dy[i]) {ok = false;}
        }
        if (!ok) {continue;}
        ff(a + dx[i], b + dy[i]);
    }
    return;
}
int main() {
    fastio;
    fileio;
    cin >> n >> k >> r;
    FOR(i, 0, r) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        roads[r1][c1].pb({r2, c2});
        roads[r2][c2].pb({r1, c1});
    }
    pii cows[k];
    FOR(i, 0, k) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cows[i] = {a, b};
    }
    int ans = 0;
    FOR(i, 0, k) {
        FOR(a, 0, n) {FOR(b, 0, n) {vis[a][b] = false;}}
        ff(cows[i].fi, cows[i].se);
        FOR(j, 0, k) {
            if (!vis[cows[j].fi][cows[j].se]) {ans++;}
        }
    }
    cout << ans/2 << "\n";
    return 0;
}
