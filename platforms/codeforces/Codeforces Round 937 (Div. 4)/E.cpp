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

	u32 T = 1, n, sum;
	cin >> T;

	while (T--) [&]() {
		string s;
		vector<u32> factors;
		cin >> n;
		cin >> s;
		for (u32 factor = 1; factor <= n; ++factor) {
			if (n % factor != 0) continue;
			sum = 0;
			for (u32 i = 0; i < factor; ++i) {
				u32 count[26] { 0 };
				for (u32 j = i; j < n; j += factor) ++count[s[j] - 'a'];
				sum += *max_element(count, count + 26);
			}
			if (sum + 1 >= n) {
				cout << factor << '\n';
				return;
			}
		}
	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

