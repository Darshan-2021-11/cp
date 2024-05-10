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
		int n, count0 = 0, count1t, count0t = 0, idx = INT_MAX;
		cin >> n;
		ld d = ld(n) / 2;
		vector<char> a(n);
		for (char &i: a) {
			cin >> i;
			if (i == '0') ++count0;
		}
		if (count0 == n) idx = n;
		else if (n - count0 == n) idx = 0;
		else if (count0 <= n >> 1) idx = 0;
		else idx = n;
		count1t = n - count0;

		for (int i = 1; i <= n; ++i) {
			if (a[i - 1] == '0') ++count0t;
			else --count1t;
			if (count0t >= ((i + 1) >> 1) && (count1t >= (n + 1 - i) >> 1)) {
				ld dt = abs((ld(n) - ld(i << 1)) / 2);
				if (abs(dt - d) <= 1e-6) {}
				if (dt < d) idx = i, d = dt;
			}
		}
		cout << idx << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}
