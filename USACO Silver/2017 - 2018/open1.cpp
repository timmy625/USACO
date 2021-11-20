//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("sort.in", "r", stdin), freopen("sort.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

bool cmp(pair<pii, int> a, pair<pii, int> b) {
    if (a.fi.fi != b.fi.fi) {return a.fi.fi < b.fi.fi;}
    else {return a.se < b.se;}
}
int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    pair<pii, int> A[n];
    FOR(i, 0, n) {cin >> A[i].fi.fi; A[i].fi.se = A[i].fi.fi; A[i].se = i;}
    sort(A, A + n, cmp);
    int ans = 0;
    FOR(i, 0, n) {A[i].fi.fi = i;}
    FOR(i, 0, n) {
        ans = max(ans, A[i].se - A[i].fi.fi);
    }
    cout << ++ans << "\n";
    return 0;
}
