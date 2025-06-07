#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'000;
	int TC = 1, cnt[2];
	string s;
	bool alt;
	s.reserve(N);
	cin >> TC;
	while (TC--) {
		alt = true;
		cnt[0] = cnt[1] = 0;
		cin >> s;
		++cnt[s[0] == '1'];
		for (int i = 1; i < s.size(); ++i) {
			++cnt[s[i] == '1'];
			if (s[i] == s[i - 1]) {
				alt = false;
			}
		}
		if (alt) {
			cout << 0 << '\n';
		} else if (abs(cnt[0] - cnt[1]) == (s.size() & 1)) {
			cout << 1 << '\n';
		} else {
			cout << (abs(cnt[0] - cnt[1]) == 2 + (s.size() & 1) ? 2 : 3) << '\n';
		}
	}
}
