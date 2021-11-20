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
#define fileio freopen("notlast.in", "r", stdin), freopen("notlast.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
	cin >> n;

	int cows[7] = {};
	FOR(i, 0, n) {
		string s;
		int x;
		cin >> s >> x;
		if (s == "Bessie") {
			cows[0] += x;
		} else if (s == "Elsie") {
			cows[1] += x;
		} else if (s == "Daisy") {
			cows[2] += x;
		} else if (s == "Gertie") {
			cows[3] += x;
		} else if (s == "Annabelle") {
			cows[4] += x;
		} else if (s == "Maggie") {
			cows[5] += x;
		} else {
			cows[6] += x;
		}
	}
	int minV = INT_MAX;
	FOR(i, 0, 7) {minV = min(cows[i], minV);}
	int min2V = INT_MAX;
	FOR(i, 0, 7) {
		if (cows[i] > minV) {min2V = min(min2V, cows[i]);}
	}
	string ans = "";
	FOR(i, 0, 7) {
		if (cows[i] == min2V) {
			if (ans != "") {ans = "Tie";}
			else {
				if (i == 0) {
					ans = "Bessie";
				} else if (i == 1) {
					ans = "Elsie";
				} else if (i == 2)  {
					ans = "Daisy";
				} else if (i == 3)  {
					ans = "Gertie";
				} else if (i == 4)  {
					ans = "Annabelle";
				} else if (i == 5)  {
					ans = "Maggie";
				} else {
					ans = "Henrietta";
				}
			}
		}
	}
	if (ans == "") {ans = "Tie";}
	cout << ans << "\n";
    return 0;
}
 