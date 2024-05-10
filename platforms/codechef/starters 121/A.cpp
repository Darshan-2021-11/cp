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
		u32 n;
		cin >> n;
		u32 a[n];
		for (u32 i = 0; i < n; ++i) cin >> a[i];
		if (n > 3) cout << "YES\n";
		else switch (n) {
			case 1:
				cout << "YES\n";
				break;
			case 2:
				if (a[0] > a[1]) cout << "NO\n";
				else cout << "YES\n";
				break;
			case 3:
				if ((a[1] > a[0] && a[1] > a[2]) || (a[1] < a[0] && a[1] < a[2])) cout << "NO\n";
				else cout << "YES\n";
				break;
			default: //never reaches
				break;
		}
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

