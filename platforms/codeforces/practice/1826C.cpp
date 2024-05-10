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

void SieveOfEratosthenes(u32 n, vector<u32> &firstFactor) {
	for (u32 p = 2; p * p <= n; p++) {
		if (firstFactor[p] == -1) {
			for (u32 i = p * p; i <= n; i += p)
				if (firstFactor[i] == -1) firstFactor[i] = p;
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;
	u32 n, m;
	vector<u32> firstFactor(1e6 + 1, -1);
	SieveOfEratosthenes(1e6, firstFactor);

	while (T--) [&]() {
		cin >> n >> m;
		cout << (n != 1 && m != 1 && (m >= n || firstFactor[n] < m) ? "NO": "YES") << '\n';
	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

