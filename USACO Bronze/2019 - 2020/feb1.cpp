#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("triangles.in", "r", stdin), freopen("triangles.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
    cin >> n;
    pii coords[n];
    FOR(i, 0, n) {cin >> coords[i].fi >> coords[i].se;}
    int ans = 0;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            FOR(k, 0, n) {
                if (coords[i].fi == coords[j].fi && coords[i].se == coords[k].se) {
                    ans = max(ans, abs((coords[i].fi - coords[k].fi) * (coords[i].se - coords[j].se)));
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
