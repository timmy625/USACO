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
#define fileio freopen("cowsignal.in", "r", stdin), freopen("cowsignal.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int m, n, k;
	cin >> m >> n >> k;

	string signal[m];
	FOR(i, 0, m) {
		string s;
		cin >> s;
		FOR(j, 0, s.size()) {
			s.insert(j, k-1, s[j]);
			j += (k-1);
		}
		signal[i] = s;
	}
	FOR(i, 0, m) {
		FOR(j, 0, k) {cout << signal[i] << "\n";}
	}

    return 0;
}
