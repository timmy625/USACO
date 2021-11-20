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
#define fileio freopen("convention.in", "r", stdin), freopen("convention.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fileio;
    fastio;
    int n, m, c;
    cin >> n >> m >> c;
    int cows[n];
    FOR(i, 0, n) {cin >> cows[i];}
    sort(cows, cows + n);
    int low = 0, high = 1e9;
    int ans;
    while (low <= high) {
        int mid = (low + high)/2;
        int amount = 1;
        int sz = 1;
        int cow = 0;
        int begin = cows[cow];
        cow++;
        while (cow < n) {
            if (sz < c) {
                if (cows[cow] - begin <= mid) {
                    sz++;
                    cow++;
                    continue;
                }
            }
            amount++;
            sz = 1;
            begin = cows[cow];
            cow++;
        }
        if (amount <= m) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
