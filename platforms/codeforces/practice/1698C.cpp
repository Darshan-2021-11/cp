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
		int n, t, poscnt = 0, negcnt = 0, zerocnt = 0;
		bool yes = true;
		cin >> n;
		vector<int> a;
		for (int i = 0; i < n; ++i) {
			cin >> t;
			if (t == 0) ++zerocnt;
			else {
				a.emplace_back(t);
				if (t > 0) ++poscnt;
				else ++negcnt;
			}
		}
		if ((poscnt > 2) | (negcnt > 2)) {
			cout << "NO\n";
			continue;
		}
		for (int i = 0; (i < zerocnt) & (i < 3); ++i) a.emplace_back(0);
		n = a.size();
		sort(a.begin(), a.end());
		for (int i = 0; i < n - 2; ++i)
			for (int j = i + 1; j < n - 1; ++j)
				for (int k = j + 1; k < n; ++k) {
					if (!binary_search(a.begin(), a.end(), a[i] + a[j] + a[k])) yes = false;
				};
		cout << (yes ? "YES\n": "NO\n");
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

