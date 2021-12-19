//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("template.in", "r", stdin), freopen("template.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

vi edges[100005];
int dfs(int u, int p) {
	int days = 0, sz = 1;
	while (sz < (u == p ? edges[u].size()+1 : edges[u].size())) {
		days++;
		sz *= 2;
	}
	for (int v : edges[u]) {
		if (v != p) {days += dfs(v, u) + 1;}
	}
	return days;
}
int main() {
    fastio;
    int n;
	cin >> n;
	FOR(i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	cout << dfs(1, 1) << "\n";
    return 0;
}
