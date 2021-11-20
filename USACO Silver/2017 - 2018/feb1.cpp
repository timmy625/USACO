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
#define fileio freopen("reststops.in", "r", stdin), freopen("reststops.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int l, n, rf, rb;
    cin >> l >> n >> rf >> rb;
    pii stops[n];
    FOR(i, 0, n) {
        cin >> stops[i].fi >> stops[i].se;
    }
    ll prev = 0, curr = 0;
    ll currMax = 0;
    ll ans = 0;
    while (curr < n) { 
        FOR(i, curr, n) {
            if (stops[i].se >= currMax) {currMax = stops[i].se; curr = i;}
        }
        ans += currMax * (rf - rb) * (stops[curr].fi - prev);
        currMax = 0;
        prev = stops[curr].fi;
        curr++;
    }
    cout << ans << "\n";
    return 0;
}
