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

	u32 n, idxi = 0, idxj;
	cin >> n;
	vector<u32> a(n);
	for (auto &i: a) cin >> i;

	while (idxi + 1 < n && a[idxi] <= a[idxi + 1]) ++idxi;
	if (idxi == n - 1) {
		cout << "yes\n1 1\n";
		return 0;
	}
	idxj = idxi;
	while (idxj + 1 < n && a[idxj] >= a[idxj + 1]) ++idxj;
	if (idxj == n - 1) {
		if (!idxi) {
			cout << "yes\n" << 1 << ' ' << n << '\n';
		} else if (idxi && a[n - 1] >= a[idxi - 1])
			cout << "yes\n" << idxi + 1 << ' ' << n << '\n';
		else
			cout << "no\n";
	} else {
		if (!idxi && a[idxj + 1] >= a[idxi]) {
			u32 tmp = idxj;
			while (tmp + 1 < n && a[tmp] <= a[tmp + 1]) ++tmp;
			if (tmp == n - 1) cout << "yes\n" << idxi + 1 << ' ' << idxj + 1 << '\n';
			else 
				cout << "no\n";
		}
		else if (idxi && a[idxj] >= a[idxi - 1] && a[idxj + 1] >= a[idxi]) {
			u32 tmp = idxj;
			while (tmp + 1 < n && a[tmp] <= a[tmp + 1]) ++tmp;
			if (tmp == n - 1) cout << "yes\n" << idxi + 1 << ' ' << idxj + 1 << '\n';
			else 
				cout << "no\n";
		} else {
			cout << "no\n";
		}

	}

#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

