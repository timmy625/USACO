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
#define fileio freopen("blist.in", "r", stdin), freopen("blist.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

struct cow {int s, t, b;};
int main() {
    fastio;
    fileio;
        
    int n;
	cin >> n;
	cow cows[n];
	FOR(i, 0, n) {cin >> cows[i].s >> cows[i].t >> cows[i].b;}
	int total = 0;
	int current = 0;
	FOR(t, 1, 1001) {
		FOR(i, 0, n) {
			if (cows[i].s != t) {continue;}
			current += cows[i].b;
			total = max(total, current);
		}
		FOR(i, 0, n) {
			if (cows[i].t != t) {continue;}
			current -= cows[i].b;
		}
	}
	cout << total << "\n";
    return 0;
}
 