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
bool grid[2505][2505];
int sums[2505][2505];
bool switched(pii a, pii b) {return a.se < b.se;}
int main() {
    fastio;
    int n;
    cin >> n;
    pii cows[n];
    FOR(i, 0, n) {
        cin >> cows[i].fi >> cows[i].se;
    }
    sort(cows, cows + n);
    FOR(i, 0, n) {cows[i].fi = i;} 
    sort(cows, cows + n, switched);
    FOR(i, 0, n) {cows[i].se = i;}
    FOR(i, 0, n) {grid[cows[i].fi][cows[i].se] = true;}
    FOR(i, 1, n+1) {
        FOR(j, 1, n+1) {
            sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
            if (grid[i-1][j-1]) {sums[i][j]++;}
        }
    }
    ll ans = 0;
    FOR(l, 0, n) {
        FOR(r, l, n) {
            ll minY = min(cows[l].fi, cows[r].fi); 
            ll maxY = max(cows[l].fi, cows[r].fi);
            ll top = sums[minY+1][r+1] - sums[minY+1][l] - sums[0][r] + sums[0][l];
            ll bottom = sums[n][r+1] - sums[maxY][r+1] - sums[n][l] + sums[maxY][l];
            ans += top * bottom;
        }
    }
    cout << ++ans << "\n";
    return 0;
}
