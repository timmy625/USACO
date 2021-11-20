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
#define fileio freopen("citystate.in", "r", stdin), freopen("citystate.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    pair<string, string> p[n];
    map<string, vector<string>> m;
    FOR(i, 0, n) {
        string s, t;
        cin >> s >> t;
        if (s.substr(0, 2) == t) {continue;}
        m[s.substr(0, 2)].pb(t);
        p[i] = {s.substr(0, 2), t};
    }
    ll ans = 0;
    FOR(i, 0, n) {
        for (string s : m[p[i].se]) {
            if (s == p[i].fi) {ans++;}
        }
    }
    cout << ans/2 << "\n";
    return 0;
}
