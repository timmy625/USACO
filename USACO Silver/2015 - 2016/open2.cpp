//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("diamond.in", "r", stdin), freopen("diamond.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n, k;
    cin >> n >> k;
    int sizes[n];
    FOR(i, 0, n) {cin >> sizes[i];}
    sort(sizes, sizes+n);
    int caseSizes[n];
    FOR(i, 0, n) {
        int curr = i;
        while (curr < n && sizes[curr] - sizes[i] <= k) {
            caseSizes[i] = curr - i + 1;
            curr++;
        }
    }
    int maxCase[n+1] = {};
    int currMax = 0;
    for (int i = n-1; i >= 0; i--) {
        currMax = max(caseSizes[i], currMax);
        maxCase[i] = currMax;
    }
    int ans = 0;
    FOR(i, 0, n) {
        ans = max(ans, caseSizes[i] + maxCase[min(i + caseSizes[i], n-1)]);
    }
    cout << ans << "\n";
    return 0;
}
