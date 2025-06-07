#include <bits/stdc++.h>
using namespace std;

int get_dist(const pair<int, int>& a) {
	if (a.first % 3 == 2 && a.second % 3 == 2)
		return a.first + a.second + 2;
	return a.first + a.second;
}

struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		int sumA = get_dist(a);
		int sumB = get_dist(b);

		if (sumA != sumB) {
			return sumA < sumB;
		} else if (a.first != b.first) {
			return a.first < b.first;
		} else {
			return a.second < b.second;
		}
	}
} comparator;

void print(const pair<int, int> &pr) {
	cout << pr.first << ' ' << pr.second << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 50'000;
	int TC = 1, n, nc, unidx;
	vector<pair<int, int>> un;
	un.reserve(N);
	cin >> TC;
	set<pair<int, int>, comp> oc;

	const auto rm0 = [&]() ->void {
		print(un[unidx]);
		oc.emplace(un[unidx].first, un[unidx].second + 1);
		oc.emplace(un[unidx].first + 1, un[unidx].second);
		oc.emplace(un[unidx].first + 1, un[unidx].second + 1);
		++unidx;
	};

	const auto rm1 = [&]() ->void {
		if (!oc.size() || !comparator(*oc.begin(), un[unidx])) {
			rm0();
		} else {
			print(*oc.begin());
			oc.erase(oc.begin());
		}
	};

	while (TC--) {
		cin >> n;
		nc = n, unidx = 0;
		{
			int x = -1, y = 1;
			while (true) {
				do {
					if (!nc) break;
					++x, --y;
					un.emplace_back(3 * x + 1, 3 * y + 1);
					--nc;
				} while (y > 0);
				if (!nc) break;
				y = x + y + 2;
				x = -1;
			}
		}
		for (int i = 0, p; i < n; ++i) {
			cin >> p;
			if (p) rm1();
			else rm0();
		}
		un.clear();
		oc.clear();
	}
}
