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
#define fileio freopen("cowtip.in", "r", stdin), freopen("cowtip.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

bool cows[10][10];
void flipCows(int x, int y) {
	FOR(i, 0, x+1) {
		FOR(j, 0, y+1) {
			cows[i][j] = !cows[i][j];
		}
	}
}
int main() {
    fastio;
    fileio;
        
    int n;
	cin >> n;
	int flips = 0;
	FOR(i, 0, n) {
		string s;
		cin >> s;
		FOR(j, 0, s.size()) {cows[i][j] = s[j] - '0';}
	}

	for (int i = n-1; i >= 0; i--) {
		for (int j = n-1; j >= 0; j--) {
			if (cows[i][j]) {flipCows(i, j); flips++;}
		}
	}
	cout << flips << "\n";
    return 0;
}
