//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("speeding.in", "r", stdin), freopen("speeding.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n, m;
    cin >> n >> m;
    int limit[100], bessie[100];
    int mile = 0;
    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;
        FOR(j, 0, a) {
            limit[mile] = b;
            mile++;
        }
    }
    mile = 0;
    FOR(i, 0, m) {
        int a, b;
        cin >> a >> b;
        FOR(j, 0, a) {
            bessie[mile] = b;
            mile++;
        }
    }
    int ans = 0;
    FOR(i, 0, 100) {
        ans = max(ans, bessie[i] - limit[i]);
    }
    cout << ans << "\n";
    return 0;
}
