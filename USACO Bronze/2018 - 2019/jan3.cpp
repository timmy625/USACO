#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("guess.in", "r", stdin), freopen("guess.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
    cin >> n;
    vector<string> A[n];
    FOR(i, 0, n) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        while (x--) {
            cin >> s;
            A[i].pb(s);
        }
    }
    int ans = 0;
    FOR(i, 0, n-1) {
        FOR(j, i+1, n) {
            int same = 0;
            FOR(a, 0, A[i].size()) {
                FOR(b, 0, A[j].size()) {
                    if (A[i][a] == A[j][b]) {
                        same++;
                        break;
                    }
                }
            }
            ans = max(ans, same);
        }
    }
    cout << ans+1 << "\n";
    return 0;
}
