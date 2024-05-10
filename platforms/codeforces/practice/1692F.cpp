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
		u64 count[10] { 0 };
		bool yes = false;
		u32 n, t;
		cin >> n;
		for (u32 i = 0; i < n; ++i) { cin >> t; ++count[t % 10]; }
		for (u32 i = 0; i < 10; ++i)
			for (u32 j = 0; j < 10; ++j)
				for (u32 k = 0; k < 10; ++k) {
					if ((i + j + k) % 10 != 3) continue;
					else if (count[i] && count[j] && count[k]) {
						if ((i == 1 && j == 1 && k == 1 && count[1] < 3) ||
								(i == j && count[i] == 1) ||
								(i == k && count[i] == 1) ||
								(j == k && count[j] == 1))
								continue;
						yes = true;
						goto print;
					}
				}
print:
		cout << (yes ? "YES\n": "NO\n");
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

