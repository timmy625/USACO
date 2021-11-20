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
#define fileio freopen("socdist.in", "r", stdin), freopen("socdist.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n, m;
    cin >> n >> m;
    pair<ll, ll> grass[m];
    FOR(i, 0, m) {cin >> grass[i].fi >> grass[i].se;}
    sort(grass, grass+m);
    ll low = 1, high = LONG_LONG_MAX;
    ll ans = 0;
    while (low <= high) { 
        ll mid = (low + high)/2;
        ll field = 0;
        ll pos = grass[field].fi, cow = 1;
        while (field < m && cow <= n) {
            if (pos + mid > grass[field].se) {field++;}
            else {pos = max(pos + mid, grass[field].fi); cow++;}
        }
        if (cow >= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
