#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    int sums[n+1];
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sums[i+1] = sums[i] + p[i];
    }
    int ans = 0;
    for (int size = 1; size <= n; size++) {
        for (int i = 0; i <= n - size; i++) {
            int sum = sums[i+size] - sums[i];
            int avg = 0;
            if (sum % size == 0) {
                avg = sum/size;
            }
            for (int j = i; j < i + size; j++) { 
                if (p[j] == avg) {ans++; break;}
            }
        }
    }
    cout << ans << "\n";
    return 0;
}