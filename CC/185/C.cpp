#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	struct comp {
		bool operator()(const std::array<int,2> &x, const std::array<int,2> &y) const {
			if (x[0] != y[0]) 
				return x[0] > y[0];
			return x[1] < y[1];
		}
	};
	int TC = 1, n, cnt, a[N];
	int64_t sum;
	cin >> TC;
	while (TC--) {
		sum = 0;
		cin >> n;
		n <<= 1;
		set<array<int, 2>, comp> s, u;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			s.insert({ a[i], i });
		}
		vector<bool> t(n);
		{
			int tmp = 0;
			auto it = s.begin();
			while (tmp < n >> 1) {
				t[(*it)[1]] = true;
				++tmp, ++it;
			}
		}
		s.clear();
		for (int i = 0; i < n; ++i) {
			if (t[i] == 0) s.insert({ a[i], i });
		}
		cnt = 1;
		for (int i = 0; i < n; ++i) {
			if (t[i] == 0) {
				s.erase({ a[i], i });
				++cnt;
			} else {
				sum += a[i], --cnt, u.insert({ a[i], i });
				if (cnt < 0) {
					cnt += 2;
					array<int, 2> x = *u.rbegin();
					sum -= x[0], t[x[1]] = false;
					u.erase(x);
					x = *s.begin();
					t[x[1]] = true;
					s.erase(x);
				}
			}
		}
		cout << sum << '\n';
	}
}
