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
#define fileio freopen("whereami.in", "r", stdin), freopen("whereami.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
	cin >> n;
	string s;
	cin >> s;

	FOR(i, 1, s.size()+1) { 
		bool ok = true;
		FOR(j, 0, s.size() - i + 1) { 
			string t1 = s.substr(j, i);
			FOR(k, j + 1, s.size() - i + 1) {
				string t2 = s.substr(k, i);
				if (t1 == t2) {ok = false; break;}
			}
			if (!ok) {break;}
		}
		if (ok) {cout << i << "\n"; break;}
	}
    return 0;
}
