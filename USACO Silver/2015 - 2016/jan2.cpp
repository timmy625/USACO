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
#define fileio freopen("div7.in", "r", stdin), freopen("div7.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    int sums[n+1] = {};
    int smallest[7] = {};
    int largest[7] = {};
    FOR(i, 0, n) {
        int x;
        cin >> x;
        sums[i+1] = sums[i] + (x % 7);
        sums[i+1] %= 7;
        x = sums[i+1];
        if (!smallest[x]) {smallest[x] = i+1;}
        largest[x] = i+1;
    }
    int ans = 0;
    FOR(i, 0, 7) {ans = max(ans, largest[i] - smallest[i]);}
    cout << ans << "\n";
    return 0;
}
