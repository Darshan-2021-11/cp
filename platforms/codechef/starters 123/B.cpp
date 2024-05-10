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
		u32 n, q;
		bool possible;
		cin >> n >> q;
		vector<u32> a(n), b(q);
		for (u32 &i: a) cin >> i;
		for (u32 &i: b) cin >> i;
		sort(a.begin(), a.end());
		u64 maxsum = 0;
		for (u32 i = 0; i < n; ++i) maxsum += (a[i] << 1);
		for (u32 &i: b) {
			possible = false;
			for (u32 j = 0; j < n; ++j) {
				for (u32 k = 0; k < n; ++k) {
					if (j == k || possible) continue;
					if (maxsum - a[k] - a[j] == i) {
						possible = true;
						bool ak = false, aj = false;
						cout << a[k] << ' ';
						for (u32 &l: a) {
							if (l == a[k] && !ak) {
								ak = true;
								continue;
							}
							if (l == a[j] && !aj) {
								aj = true;
								continue;
							}
							cout << l << ' ';
						}
						cout << a[j] << '\n';
					}
				}
			}
			if (!possible) cout << -1 << '\n';
		}
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

