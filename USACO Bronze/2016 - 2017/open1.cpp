#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("lostcow.in", "r", stdin), freopen("lostcow.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int x, y;
    cin >> x >> y;
    int ans = 0, dist = 1, pos = x;
    bool forward = true, found = false;
    while (!found) {
        int currentPos = pos;
        pos += dist * (forward ? 1 : -1);
        if (min(currentPos, pos) <= y && y <= max(currentPos, pos)) {ans += abs(y - currentPos); break;}
        ans += dist;
        dist = 3 * abs(pos - x);
        forward = !forward;
    }
    cout << ans << "\n";
    return 0;
}
