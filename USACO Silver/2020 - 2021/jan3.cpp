//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("template.in", "r", stdin), freopen("template.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    int n;
    cin >> n;
    int A[n][n];
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> A[i][j];
        }
    }
    int colAns = 0;
    FOR(i, 0, n) {
        ll odds = 0, evens = 0;
        FOR(j, 0, n) {
            if (odd(j)) {odds += A[j][i];}
            else {evens += A[j][i];}
        }
        colAns += max(odds, evens);
    }
    int rowAns = 0;
    FOR(i, 0, n) {
        ll odds = 0, evens = 0;
        FOR(j, 0, n) {
            if (odd(j)) {odds += A[i][j];}
            else {evens += A[i][j];}
        }
        rowAns += max(odds, evens);
    }
    cout << max(colAns, rowAns) << "\n";
    return 0;
}
