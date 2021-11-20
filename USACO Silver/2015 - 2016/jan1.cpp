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

int main() {
    fastio;
    fileio;

    int n, k;
    cin >> n >> k;
    int A[n];
    FOR(i, 0, n) {cin >> A[i];}
    sort(A, A + n);
    int low = 0;
    int high = A[n-1] - A[0];
    int ans;
    while (low <= high) {
        int mid = (low + high)/2;
        priority_queue<int> pq;
        pq.push(A[0] + mid);
        FOR(i, 0, n) {
            if (abs(A[i] - pq.top()) > mid) {
                pq.push(A[i] + mid);
            }
        }
        if (pq.size() <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
