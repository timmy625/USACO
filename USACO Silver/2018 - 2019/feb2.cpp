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
#define fileio freopen("paintbarn.in", "r", stdin), freopen("paintbarn.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int sums[1005][1005];
int main() {
    fastio;
    fileio;
    int n, k;
    cin >> n >> k;
    FOR(i, 0, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        sums[x1][y1]++;
        sums[x1][y2]--;
        sums[x2][y1]--;
        sums[x2][y2]++;
    }
    int ans = 0;
    FOR(i, 1, 1002) {
        FOR(j, 1, 1002) {
            sums[i][j] += sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
            if (sums[i][j] == k) {ans++;}
        }
    }
    cout << ans << "\n";    
    return 0;
}
 