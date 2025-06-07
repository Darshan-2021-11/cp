#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, t, cnt, a[N];
	cin >> TC;
	while (TC--) {
		cnt = 0;
		cin >> n;
		map<int, int> mp1;
		map<int, set<int>> mp2;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (mp1.count(a[i])) {
				t = mp1[a[i]]++;
				mp2[t].erase(a[i]);
				mp2[t + 1].insert(a[i]);
			} else {
				++mp1[a[i]];
				mp2[1].insert(a[i]);
			}
			if (mp2.rbegin()->first > (i + 1) / 2) ++cnt;
		}
		cout << cnt << '\n';
	}
}
