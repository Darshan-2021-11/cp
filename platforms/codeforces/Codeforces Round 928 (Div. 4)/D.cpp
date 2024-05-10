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
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cout << std::fixed;
	cout.precision(15);

	u32 T = 1;
	cin >> T;

	while (T--) {
		u32 n, t, mask = (1u << 31) - 1, ans = 0;
		map<u32, u32> count;
		cin >> n;
		for (u32 i = 0; i < n; ++i) {
			cin >> t;
			if (count[t ^ mask]) {
				--count[t ^ mask];
				++ans;
			} else ++count[t];
		}
		for (auto &[i, j]: count) {
			ans += j;
		}
		cout << ans << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

