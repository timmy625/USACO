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
#define fileio freopen("pails.in", "r", stdin), freopen("pails.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int x, y, m;
	cin >> x >> y >> m;
	int ans = 0;
	for (int i = 0; (i * x) < m; i++) {
		for (int j = 0; (j * y) < m; j++) {
			int value = i*x + j*y;
			if (value <= m) {ans = max(ans, value);}
		}
	}
	cout << ans << "\n";
    return 0;
}
