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
		u32 n;
		bool isSorted = true;
		cin >> n;
		vector<u32> a(n);
		vector<u32> b; b.reserve(n >> 1);
		cin >> a[0];
		if (a[0] > 9) { b.emplace_back(a[0] / 10); b.emplace_back(a[0] % 10); }
		else b.emplace_back(a[0]);

		for (u32 i = 1; i < n; ++i) {
			cin >> a[i];
			if (a[i] < a[i - 1]) [&] {
				const u32 k1 = b.size() - 1;
				for (u32 j = 0; j < k1; ++j) if (b[j] > b[j + 1]) { isSorted = false; break; }
				if (a[i] < b.back()) { isSorted = false; }
			}();
			if (a[i] > 9) { b.emplace_back(a[i] / 10); b.emplace_back(a[i] % 10); }
			else b.emplace_back(a[i]);
		}
		if (isSorted) cout << "YES\n";
		else cout << "NO\n";
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

