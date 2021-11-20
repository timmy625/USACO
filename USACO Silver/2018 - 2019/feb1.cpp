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
#define fileio freopen("herding.in", "r", stdin), freopen("herding.out", "w", stdout);
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
    FOR(i, 0, n) {cin >> A[i];}
    sort(A, A + n);
    int i = 0, j = 0;
    int currMax = 0;
    int ansMax;
    while (i < n) {
        if (A[j] - A[i] >= n) {i++; j = i;}
        else {currMax = max(currMax, j - i + 1); j++; if (j >= n) {break;}}
    }
    ansMax = n - currMax;
    if (currMax == n-1) {
        bool consecutive = true;
        FOR(i, 0, n-2) {if (A[i+1] != A[i] + 1) {consecutive = false;}}
        if (consecutive && A[n-1] - A[n-2] > 2) {ansMax = 2;}

        consecutive = true;
        FOR(i, 1, n-1) {if (A[i+1] != A[i] + 1) {consecutive = false;}}
        if (consecutive && A[1] - A[0] > 2) {ansMax = 2;}
    }
    int currGap = A[n-1] - A[0];
    int minGap = min(A[1] - A[0], A[n-1] - A[n-2]);
    int ones = (currGap - (n-1)) - minGap;
    cout << ansMax << "\n";
    cout << ++ones << "\n";
    return 0;
}
