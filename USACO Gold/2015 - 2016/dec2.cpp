//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("feast.in", "r", stdin), freopen("feast.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int t, a, b;
int dp[5000005][2] = {0};
int ff(int x, bool drank) {
    if (x > t) {
        return -1;
    } 
    int best = x;
    if (!dp[x+a][drank]) {ff(x+a, drank);}
    if (!dp[x+b][drank]) {ff(x+b, drank);}
    best = max(best, max(dp[x+a][drank], dp[x+b][drank]));
    if (!drank) {
        if (!dp[x/2][true]) {ff(x/2, true);}
        best = max(best, dp[x/2][true]);
    }
    dp[x][drank] = best;
    return dp[x][drank];
}
int main() {
    fastio;
    fileio;
    cin >> t >> a >> b;
    cout << ff(0, false) << "\n";
    return 0;
}
