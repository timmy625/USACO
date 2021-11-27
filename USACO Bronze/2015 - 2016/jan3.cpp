//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("mowing.in", "r", stdin), freopen("mowing.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    int A[2005][2005] = {};
    pii fj = {1002, 1002};
    int ans = 1e9, time = 0;;
    FOR(i, 0, n) {
        char c;
        int x;
        cin >> c >> x;
        FOR(j, 0, x) {
            time++;
            if (c == 'W') {fj.se--;}
            else if (c == 'E') {fj.se++;}
            else if (c == 'N') {fj.fi--;}
            else if (c == 'S') {fj.fi++;}
            if (A[fj.fi][fj.se]) {ans = min(ans, time - A[fj.fi][fj.se]);}
            A[fj.fi][fj.se] = time;
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
    return 0;
}
 