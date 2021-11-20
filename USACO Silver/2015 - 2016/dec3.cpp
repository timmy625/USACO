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
#define fileio freopen("bcount.in", "r", stdin), freopen("bcount.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n, q;
	cin >> n >> q;
	int h[n+1], g[n+1], j[n+1];
	h[0] = 0, g[0] = 0, j[0] = 0;
	int hCount = 0, gCount = 0, jCount = 0;
	FOR(i, 0, n) {
		int x;
		cin >> x;
		if (x == 1) {hCount++;}
		else if (x == 2) {gCount++;}
		else if (x == 3) {jCount++;}
		h[i+1] = hCount;
		g[i+1] = gCount;
		j[i+1] = jCount;
	};

	FOR(i, 0, q) {
		int a, b;
		cin >> a >> b;

		cout << h[b] - h[a-1] << " " << g[b] - g[a-1] << " " << j[b] - j[a-1] << "\n";
	}
    return 0;
}
 