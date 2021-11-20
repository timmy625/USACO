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
#define fileio freopen("hps.in", "r", stdin), freopen("hps.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
	cin >> n;
	pii winningOptions[6] = {mp(1, 2), mp(1, 3), mp(2, 1)};
	int count[3] = {};

	FOR(i, 0, n) {
		int a, b;
		cin >> a >> b;
		if (a == b) {continue;}
		FOR(i, 0, 3) {
			bool win1 = (a == winningOptions[i].fi && b == winningOptions[i].se);
			bool win2 = (a == winningOptions[i].se && b != winningOptions[i].fi);
			bool win3 = (a != winningOptions[i].se && b == winningOptions[i].fi);
			if (win1 || win2 || win3) {count[i]++;}
		}
	}

	int ans = 0;
	FOR(i, 0, 3) {ans = max(ans, count[i]);}
	cout << ans << "\n";

    return 0;
}
