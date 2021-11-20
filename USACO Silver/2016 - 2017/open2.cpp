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
#define fileio freopen("cownomics.in", "r", stdin), freopen("cownomics.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n, m;
    cin >> n >> m;
    char cows[2*n][m];
    FOR(i, 0, 2*n) {
        string s;
        cin >> s;
        FOR(j, 0, s.size()) {
            cows[i][j] = s[j];
        }
    }
    ll ans = 0;
    FOR(a, 0, m) {
        FOR(b, a+1, m) {
            FOR(c, b+1, m) {
                set<tuple<char, char, char>> s;
                FOR(i, 0, n) {
                    auto t = make_tuple(cows[i][a], cows[i][b], cows[i][c]);
                    s.insert(t);
                }
                bool ok = true;
                FOR(i, n, 2*n) {
                    auto t = make_tuple(cows[i][a], cows[i][b], cows[i][c]);
                    if (s.count(t)) {ok = false; break;}
                }
                if (ok) {ans++;}
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
