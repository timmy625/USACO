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
#define fileio freopen("hps.in", "r", stdin), freopen("hps.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int ans = 0;
int n;
int play(int a[], int b[], int i) {
	ans = max(ans, a[i] + b[n] - b[i]);
}
int main() {
    fastio;
    fileio;
        
    
	cin >> n;

	int H[n+1]; H[0] = 0;
	int P[n+1]; P[0] = 0;
	int S[n+1]; S[0] = 0;

	FOR(i, 0, n) {
		H[i+1] = H[i];
		P[i+1] = P[i];
		S[i+1] = S[i];
		char c;
		cin >> c;
		if (c == 'H') {H[i+1]++;}
		else if (c == 'P') {P[i+1]++;}
		else {S[i+1]++;}
	}


	FOR(i, 0, n) {
		play(H, P, i);
		play(H, S, i);
		play(P, S, i);
		play(P, H, i);
		play(S, P, i);
		play(S, H, i);
	}
	cout << ans << "\n";
    return 0;
}
