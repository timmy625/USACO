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
#define fileio freopen("planting.in", "r", stdin), freopen("planting.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
	cin >> n;
	vi adj[n]; 
	FOR(i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a-1].pb(b);
		adj[b-1].pb(a);
	}
	
	int answer = 0;
	FOR(i, 0, n) {
		answer = max(answer, sz(adj[i])+1);
	}
	cout << answer << "\n";
    return 0;
}
