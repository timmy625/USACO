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
#define fileio freopen("helpcross.in", "r", stdin), freopen("helpcross.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int c, n;
    cin >> c >> n;
    int t[c];
    pii cows[n];
    bool paired[n];
    FOR(i, 0, c) {cin >> t[i];}
    sort(t, t + c);
    FOR(i, 0, n) {cin >> cows[i].se >> cows[i].fi; paired[i] = false;}
    sort(cows, cows + n);
    int ans = 0;
    FOR(i, 0, c) {
        FOR(j, 0, n) {
            if (paired[j]) {continue;}
            if (t[i] < cows[j].se || t[i] > cows[j].fi) {continue;}
            paired[j] = true;
            ans++;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
