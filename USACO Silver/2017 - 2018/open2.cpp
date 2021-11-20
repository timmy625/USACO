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
#define fileio freopen("lemonade.in", "r", stdin), freopen("lemonade.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
	cin >> n;
	int w[n];
	FOR(i, 0, n) {cin >> w[i];}
	sort(w, w + n, greater<int>());

	vi line;
	int answer = 0;
	FOR(i, 0, n) {
		if (sz(line) <= w[i]) {line.pb(w[i]); answer++;}
	}
	cout << answer << "\n";
    return 0;
}
