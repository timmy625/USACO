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
#define fileio freopen("where.in", "r", stdin), freopen("where.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

struct pcl {int u, d, l, r;};
vector<pcl> pcls;
int u, d, l, r;
bool vis[22][22];
char cow[22][22];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void ff(int a, int b) {
    vis[a][b] = true;
    FOR(i, 0, 4) {
        int newA = a + dx[i];
        int newB = b + dy[i];
        if (a < u || a >= d || b < l || b >= r || vis[newA][newB] || cow[newA][newB] != cow[a][b]) {continue;}
        ff(newA, newB);
    }
    return;
}
int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    FOR(i, 0, n) {
        string s;
        cin >> s;
        FOR(j, 0, n) {
            cow[i][j] = s[j];
        }
    }
    FOR(aa, 0, n+1) {
        FOR(bb, aa, n+1) {
            FOR(cc, 0, n+1) {
                FOR(dd, cc, n+1) {
                    u = aa; d = bb; l = cc; r = dd;
                    bool ok = true;
                    FOR(i, u, d) {
                        FOR(j, l, r) {
                            vis[i][j] = false;
                        }
                    }
                    pair<char, int> x = {'a', 0};
                    pair<char, int> y = {'a', 0};
                    FOR(i, u, d) {
                        FOR(j, l, r) {
                            if (!vis[i][j]) {
                                if (cow[i][j] == x.fi) {x.se++;}
                                else if (cow[i][j] == y.fi) {y.se++;}
                                else {
                                    if (x.fi == 'a') {x.fi = cow[i][j]; x.se++;}
                                    else if (y.fi == 'a') {y.fi = cow[i][j]; y.se++;}
                                    else {ok = false;} 
                                }
                                ff(i, j);
                            }
                        }
                    }
                    if (!((x.se == 1 && y.se >= 2) || (x.se >= 2 && y.se == 1))) {ok = false;}
                    pcl p = {u, d, l, r};
                    if (ok) {pcls.pb(p);}
                }
            }
        } 
    }
    int ans = pcls.size();
    FOR(i, 0, pcls.size()) {
        FOR(j, 0, pcls.size()) {
            if (i == j) {continue;}
            if (pcls[i].u >= pcls[j].u && pcls[i].d <= pcls[j].d && pcls[i].l >= pcls[j].l && pcls[i].r <= pcls[j].r) {ans--; break;}
        }
    }
    cout << ans << "\n";
    return 0;
}
