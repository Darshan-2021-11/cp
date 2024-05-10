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
		u64 product = 1;
		u32 n, m, l = 0, r;
		char c;
		cin >> n >> m;
		r = n;
		vector<u32> a, b; a.reserve(n), b.reserve(n);
		while (n--) {
			cin >> a.emplace_back();
		}
		n = r;
		while (n--) {
			cin >> c;
			b.emplace_back(c == 'L' ? a[l++] : a[--r]);
		}
		for (u32 i = b.size() - 1; i < b.size(); --i) {
			product = (product * b[i]) % m;
			a[i] = product;
		}
		for (u32 i = 0; i < a.size(); ++i) cout << a[i] << ' ';
		cout << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

