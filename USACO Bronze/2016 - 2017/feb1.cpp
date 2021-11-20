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
#define fileio freopen("crossroad.in", "r", stdin), freopen("crossroad.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
	cin >> n;
	map<int, int> M;

	int cross = 0;
	FOR(i, 0, n) {
		int a, b;
		cin >> a >> b;
		if (M.count(a) == 0) {
			M[a] = b;
		} else {
			if (b != M[a]) {cross++;}
			M[a] = b;
		}
	}
	cout << cross << "\n";
    return 0;
}
