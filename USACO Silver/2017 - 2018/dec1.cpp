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
#define fileio freopen("homework.in", "r", stdin), freopen("homework.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
    cin >> n;
    int A[n];
    int sums[n+1]; sums[0] = 0;
    int mins[n+1]; mins[0] = INT_MAX;
    FOR(i, 0, n) {cin >> A[i];}
    reverse(A, A + n);
    FOR(i, 0, n) {
        sums[i+1] = sums[i] + A[i];
        mins[i+1] = min(mins[i], A[i]);
    }
    
    vi ans;
    double maxV = 0;
    FOR(i, 1, n-1) {
        int score = sums[n-i] - mins[n-i];
        double avg = (double) score;
        avg /= (double) (n-i-1);
        if (maxV == avg) {ans.pb(i);}
        else if (avg > maxV) {
            maxV = max(maxV, avg); 
            ans.clear(); 
            ans.resize(0);
            ans.pb(i);
        }
    }
    for (int value : ans) {cout << value << "\n";}
    return 0;
}
