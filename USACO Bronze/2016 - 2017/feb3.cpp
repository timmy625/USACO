#include <bits/stdc++.h>
using namespace std;

int main() {
	//file input/output
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
	//actual input
    int n;
	cin >> n;
	pair<int, int> times[n];
	for (int i = 0; i < n; i++) {
		cin >> times[i].first >> times[i].second;
	}
	//sorts array by the first value (arriving time)
	sort(times, times + n);

	//process is simulated
	int currentTime = 0;
	int i = 0;
	//loops through each of the cows
	while (i < n) {
		//checks if the cow has already arrived
		if (currentTime > times[i].first) {
			//"waits" for however long it takes that cow to process
			currentTime += times[i].second;
		} else {
			//jumps to the time after the cow has finished processing once its arrived
			currentTime = times[i].first + times[i].second;
		}
		i++;
	}

	cout << currentTime << "\n";
    return 0;
}
