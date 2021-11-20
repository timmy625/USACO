#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("angry.in", "r", stdin), freopen("angry.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int n;
ll A[105];
ll explodeR(int start, ll power) {
    int right = start;
    if (right < n-1) {
        while (A[right+1] <= A[start] + power) {
            right++;
            if (right == n-1) {break;}
        }
        if (right != start) {right = explodeR(right, ++power);}
    }
    return right;
}
ll explodeL(int start, ll power) {
    int left = start;
    if (left > 0) {
        while (A[left-1] >= A[start] - power) {
            left--;
            if (left == 0) {break;}
        }
        if (left != start) {left = explodeL(left, ++power);}
    }
    return left;
}
int main() {
    fastio;
    fileio;
        
    cin >> n;
    FOR(i, 0, n) {cin >> A[i];}
    sort(A, A + n);
    ll ans = 0;
    FOR(i, 0, n) {
        ans = max(ans, explodeR(i, 1) - explodeL(i, 1) + 1);
    }
    cout << ans << "\n";
    return 0;
}
