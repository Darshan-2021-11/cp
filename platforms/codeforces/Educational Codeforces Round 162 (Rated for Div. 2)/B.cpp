#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;

	while (T--) {
		ll bullets = 0;
		int n, k, t;
		bool possible = true;
		cin >> n >> k;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> t;
			a[i].first = t;
		}
		for (int i = 0; i < n; ++i) {
			cin >> t;
			if (t < 0) t *= -1;
			a[i].second = t;
		}
		sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });

		bullets = 1LL * k * a[0].second - a[0].first;
		if (bullets < 0) {
			possible = false;
			goto ans;
		}
		for (int i = 1; i < n; ++i) {
			bullets += 1LL * k * (a[i].second - a[i - 1].second) - a[i].first;
			if (bullets < 0) {
				possible = false;
				goto ans;
			}
		}
ans:
		cout << (possible ? "YES\n": "NO\n");
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

