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

int main() {
    fastio;
    ll n, k, l;
	cin >> n >> k >> l;
	ll c[n];
	FOR(i, 0, n) {
		cin >> c[i];
	}
	sort(c, c + n, greater<ll>());
	ll low = 0, high = n;
	ll ans;
	while (low <= high) {
		ll mid = (low + high)/2;
		ll totalIncrease = 0;
		bool ok = true;
		FOR(i, 0, mid) {
			totalIncrease += max((ll) 0, mid-c[i]);
			ok = ok && (mid-c[i] <= k);
		}
		if (totalIncrease > k*l) {ok = false;}
		if (ok) {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	cout << ans << "\n";
    return 0;
}
