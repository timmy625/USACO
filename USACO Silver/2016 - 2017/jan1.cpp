#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("cowdance.in", "r", stdin), freopen("cowdance.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n, maxT;
    cin >> n >> maxT;
    int d[n];
    FOR(i, 0, n) {cin >> d[i];}
    int start = 1, end = n;
    int ans = n;
    while (start <= end) {
        int mid = (start + end)/2;
        priority_queue<int, vi, greater<int> > pq;
        int cow = 0;
        int t = 0;
        while (pq.size() < mid) {pq.push(d[cow]); cow++;}
        while (pq.size()) {
            t = pq.top();
            pq.pop();
            if (cow < n) {pq.push(d[cow] + t); cow++;}
        }
        if (t <= maxT) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
