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
#define fileio freopen("haybales.in", "r", stdin), freopen("haybales.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n, q;
    cin >> n >> q;
    int A[n];
    FOR(i, 0, n) {cin >> A[i];}
    sort(A, A + n);
    while (q--) {
        int a, b;
        cin >> a >> b;
        int dist = distance(lower_bound(A, A + n, a), lower_bound(A, A + n, b));
        if (b == *lower_bound(A, A + n, b)) {dist++;}
        cout << dist << "\n";
    }
    return 0;
}
 