#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t TC = 1, n, k, ans, sum, a[N];
	char s[N];
	cin >> TC;
	while (TC--) {
		mx = INT64_MIN;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> s[i];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		ans = a[0], sum = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') sum = 0;
			sum += a[i];
			ans = max(ans, sum);
			sum = max(sum, 0);
		}
		if (sum > k) {
			cout << "No\n";
			continue;
		}
		if (sum == k) goto print;
print:
	}
}
