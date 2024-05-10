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
		u32 n, wmap = 0, wpie = 0, wmapie = 0, ans = UINT32_MAX;
		cin >> n;
		vector<char> a(n);
		for (auto &i: a) cin >> i;
		if (n < 3) { cout << 0 << '\n'; continue; }
		for (u32 i = 0; i < n - 2; ++i) {
			if (a[i] == 'm' && a[i + 1] == 'a' && a[i + 2] == 'p') ++wmap;
			if (a[i] == 'p' && a[i + 1] == 'i' && a[i + 2] == 'e') ++wpie;
		}
		if (n > 4)
			for (u32 i = 0; i < n - 4; ++i) {
				if (a[i] == 'm' && a[i + 1] == 'a' && a[i + 2] == 'p' && a[i + 3] == 'i' && a[i + 4] == 'e') ++wmapie;
			};
		ans = wmap + wpie - wmapie;
		cout << ans << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

