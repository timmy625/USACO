//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("paint.in", "r", stdin), freopen("paint.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c < a) {
        swap(a, c);
        swap(b, d);
    }
    int ans;
    if (c < b) {
        ans = max(b, d)-a;
    } else {
        ans = d-c + b-a;
    }
    cout << ans << "\n";
    return 0;
}
