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
#define fileio freopen("berries.in", "r", stdin), freopen("berries.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int mod;
bool cmp(int a, int b) {return a % mod > b % mod;}
int main() {
    fastio;
    fileio;
    int n, k;
    cin >> n >> k;
    int b[n];
    FOR(i, 0, n) {cin >> b[i];}
    int ans = 0;
    FOR(i, 1, 1001) {
        mod = i;
        int curr = 0;
        int currAns = 0;
        FOR(j, 0, n) {
            curr += b[j]/mod;
        }
        int bs = min(curr, k);
        currAns = max(bs - k/2, 0) * mod;
        sort(b, b + n, cmp);
        int j = 0;
        while (bs < k && j < n) {
            bs++;
            if (bs > k/2) {currAns += b[j] % mod;}
            j++;
        }
        ans = max(ans, currAns);
    }
    cout << ans << "\n";
    return 0;
}
