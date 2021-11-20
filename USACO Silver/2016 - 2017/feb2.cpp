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
#define fileio freopen("maxcross.in", "r", stdin), freopen("maxcross.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

bool signals[100005];
int main() {
    fastio;
    fileio;
    int n, k, b;
    cin >> n >> k >> b;
    FOR(i, 0, b) {
        int x;
        cin >> x;
        signals[x-1] = true;
    }
    int sums[n+1];
    sums[0] = 0;
    FOR(i, 1, n+1) {
        signals[i] ? sums[i] = sums[i-1] + 1 : sums[i] = sums[i-1];
    } 
    int ans = INT_MAX;
    FOR(i, 0, n-k+1) {
        ans = min(ans, sums[i+k] - sums[i]);
    }
    cout << ans << "\n";
    return 0;
}
