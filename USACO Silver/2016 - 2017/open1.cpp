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
#define fileio freopen("pairup.in", "r", stdin), freopen("pairup.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    pii cows[n];
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        cows[i] = {y, x};
    }
    sort(cows, cows + n);
    int frontIndex = 0, frontCurr = 1;
    int backIndex = n-1, backCurr = 1;
    int ans = 0;
    while (frontIndex < backIndex) {
        frontCurr++;
        if (frontCurr > cows[frontIndex].se) {
            frontIndex++;
            frontCurr = 1;
        }
        backCurr++;
        if (backCurr > cows[backIndex].se) {
            backIndex--;
            backCurr = 1;
        }
        ans = max(cows[frontIndex].fi + cows[backIndex].fi, ans);
    }
    cout << ans << "\n";
    return 0;
}
