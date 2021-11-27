//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("promote.in", "r", stdin), freopen("promote.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int A[4][2];
    FOR(i, 0, 4) {
        cin >> A[i][0] >> A[i][1];
    }
    int g_p = A[3][1] - A[3][0];
    int s_g = A[2][1] - A[2][0] + g_p;
    int b_s = A[1][1] - A[1][0] + s_g;
    cout << b_s << "\n" << s_g << "\n" << g_p << "\n";
    return 0;
}
 