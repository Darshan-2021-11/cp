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

bool is0or1(u32 n) {
	u32 tt;
	bool ans = true;
	while (n > 0) {
		tt = n % 10;
		n /= 10;
		ans &= (tt == 1) || (tt == 0);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;
	u32 n, t, a[31];
	for (u32 i = 2; i <= 32; ++i) {
		t = 0;
		for (u32 j = 5; j < 6; --j) {
			t = t * 10 + ((i >> j) & 1);
		}
		a[i - 2] = t;
	}

	while (T--) [&]() {
		cin >> n;
		for (u32 i = 0; i < 31; ++i) {
			while (!is0or1(n) && n % a[i] == 0) { n /= a[i]; }
		}
		if (is0or1(n)) cout << "YES\n";
		else cout << "NO\n";
	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

