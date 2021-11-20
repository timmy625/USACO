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
#define fileio freopen("mixmilk.in", "r", stdin), freopen("mixmilk.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int c[3], m[3];
	FOR(i, 0, 3) {cin >> c[i] >> m[i];}
	FOR(i, 0, 100) {
		int x = min(c[(i+1) % 3] - m[(i+1) % 3], m[(i) % 3]);
		m[(i) % 3] -= x; m[(i+1) % 3] += x;
	}
	cout << m[0] << "\n" << m[1] << "\n" << m[2] << "\n";
    return 0;
}
