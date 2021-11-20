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
#define fileio freopen("template.in", "r", stdin), freopen("template.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    int A[n+1];
    int save[n];
    FOR(i, 0, n) {
        cin >> A[i];
        save[i] = -1;
    }
    sort(A, A + n, greater<int>());
    A[n] = 0;
    int curr = ((A[0]+11)/12)*12;
    int traveled = 0;
    k--;

    int i = 0;
    while (i < n+1) { 
        traveled += (curr - A[i]);
        curr = A[i];
        if (i != n) {
            int firstJump = (A[i]/12)*12;
            if (firstJump < A[i+1]) {save[i] = 0;}
            else {
                int secondJump = ((A[i+1]+11)/12)*12;
                save[i] = firstJump - secondJump;
            }
        }
        i++;
    }
    sort(save, save + n, greater<int>());
    int saving = 0;
    FOR(i, 0, k) {
        saving += save[i];
    }
    cout << traveled - saving << "\n";
    return 0;
}