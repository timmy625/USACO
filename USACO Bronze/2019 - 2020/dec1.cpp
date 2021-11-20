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
#define fileio freopen("gymnastics.in", "r", stdin), freopen("gymnastics.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int k, n;
	cin >> k >> n;
	int A[k][n];
	FOR(i, 0, k) {
		FOR(j, 0, n) {
			cin >> A[i][j];
		}
	}
	int ans = 0;
	FOR(i, 0, n-1) {
		FOR(j, i+1, n) {
			int a1 = A[0][i];
			int b1 = A[0][j];
			bool ok = true;
			FOR(l, 1, k) {
				int a2, b2;
				FOR(x, 0, n) {
					if (A[l][x] == a1) {a2 = x;}
					if (A[l][x] == b1) {b2 = x;}
				}
				if (a2 > b2) {ok = false; break;}
			}
			if (ok) {ans++;}
		}
	}
	cout << ans << "\n";
    return 0;
}
