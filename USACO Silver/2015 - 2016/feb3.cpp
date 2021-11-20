//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("pails.in", "r", stdin), freopen("pails.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int x, y, k, m;
int ans, pour;
bool performed[102][102][102];
void perform(int a, int b, int curr) {
    if (curr > k || performed[a][b][curr]) {return;}
    ans = min(ans, abs(a+b-m));
    performed[a][b][curr] = true;
    perform(x, b, curr + 1);
    perform(a, y, curr + 1);
    perform(0, b, curr + 1);
    perform(a, 0, curr + 1);
    pour = min(a, y-b);
    perform(a - pour, b + pour, curr + 1);
    pour = min(x - a, b);
    perform(a + pour, b - pour, curr + 1);
}
int main() {
    fastio;
    fileio;
    cin >> x >> y >> k >> m;
    ans = m;
    perform(0, 0, 0);
    cout << ans << "\n";
    return 0;
}
