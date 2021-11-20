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
#define fileio freopen("mountains.in", "r", stdin), freopen("mountains.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

bool cmp(pii a, pii b) {
    if (a.fi != b.fi) {return a.fi < b.fi;}
    return a.se > b.se;
}
int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    pii mtns[n];
    bool seen[n];
    FOR(i, 0, n) {
        seen[i] = true;
        int a, b;
        cin >> a >> b;
        mtns[i].fi = a-b;
        mtns[i].se = a+b;
    }
    sort(mtns, mtns + n, cmp);
    int currMax = INT_MIN;
    FOR(i, 0, n) {
        if (mtns[i].se <= currMax) {seen[i] = false;}
        currMax = max(currMax, mtns[i].se);
    }
    int ans = 0;
    for (bool b : seen) {if (b) {ans++;}}
    cout << ans << "\n";
    return 0;
}
