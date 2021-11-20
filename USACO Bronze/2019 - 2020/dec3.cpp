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
#define fileio freopen("lineup.in", "r", stdin), freopen("lineup.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
	cin >> n;
	pair<string, string> order[n];
	FOR(i, 0, n) {
		string s;
		cin >> order[i].fi >> s >> s >> s >> s >> order[i].se;
	}
	string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	sort(cows, cows + 8);

	do {
		bool ok = true;
		FOR(i, 0, n) {
			if (abs(distance(find(cows, cows + 8, order[i].fi), find(cows, cows + 8, order[i].se))) != 1) {ok = false; break;}
		}
		if (ok) {
			FOR(i, 0, 8) {
				cout << cows[i] << "\n";
			}
			break;
		}
	} while(next_permutation(cows, cows+8));

    return 0;
}
