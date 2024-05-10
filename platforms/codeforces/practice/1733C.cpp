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
		u32 n, t, p;
		bool firstodd, isSorted = true;
		cin >> n;
		vector<u32> odd, even;
		cin >> p;
		firstodd = p & 1;
		for (u32 i = 1; i < n; ++i) {
			if (t & 1) odd.push_back(i);
			else even.push_back(i);
			cin >> t;
			if (t < p) isSorted = false;
			p = t;
		}
		if (t & 1) odd.push_back(n);
		else even.push_back(n);

		if (isSorted) {
			cout << 0 << '\n';
			continue;
		}
		cout << n - 1 << '\n';
		const u32 oddsize = odd.size();
		const u32 evensize = even.size();
		if (firstodd) {
			if (oddsize > 1)
				for (u32 i = oddsize - 1; i > 0; --i) {
					cout << odd[i - 1] << ' ' << odd[i] << '\n';
				};
			if (evensize && oddsize) {
				if (odd[0] > even[0])
					cout << even[0] << ' ' << odd[0] << '\n';
				else
					cout << odd[0] << ' ' << even[0] << '\n';
			}
			if (evensize > 1)
				for (u32 i = 0; i < evensize - 1; ++i) {
					cout << even[i] << ' ' << even[i + 1] << '\n';
				};
		} else {
			if (evensize > 1)
				for (u32 i = evensize - 1; i > 0; --i) {
					cout << even[i - 1] << ' ' << even[i] << '\n';
				};
			if (evensize && oddsize) {
				if (odd[0] > even[0])
					cout << even[0] << ' ' << odd[0] << '\n';
				else
					cout << odd[0] << ' ' << even[0] << '\n';
			}
			if (oddsize > 1)
				for (u32 i = 0; i < oddsize - 1; ++i) {
					cout << odd[i] << ' ' << odd[i + 1] << '\n';
				};
		}
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

