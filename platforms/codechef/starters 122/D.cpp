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
	const u32 mod = 1e9 + 7;
	cin >> T;

	while (T--) {
		u64 ans = 1;
		u32 n, n2, t, random, upper, cnt = 0;
		bool possible = true;
		cin >> n;
		t = n, n2 = n * n, upper = random = (n2 - n) >> 1;
		const u32 mn = random + n;

		vector<bool> present(n * n + 1, 0);
		vector<vector<u32>> a(n, vector<u32>(n));
		for (u32 i = 0; i < n; ++i) {
			for (u32 j = 0; j < n; ++j) {
				cin >> a[i][j];
				if (a[i][j] <= n2) {
					if (a[i][j] && present[a[i][j]])
						possible = false;
					present[a[i][j]] = true;
				} else possible = false;
			}
		}
		if (!possible) {
			cout << 0 << '\n';
			continue;
		}
		for (u32 i = 0; i < n; ++i) {
			for (u32 j = 0; j < n; ++j) {
				if (i > j) {
					if (a[i][j] && a[j][i]) {
						//if (a[i][j] % mn != a[j][i] % mn) {
						if (max(a[i][j], a[j][i]) - min(a[j][i], a[i][j]) != mn) {
							possible = false;
							goto out;
						}
						--random;
					} else if (a[i][j]) {
						if (((a[i][j] > upper) && (a[i][j] <= mn)) || (a[i][j] > mn ? present[a[i][j] - mn] : present[a[i][j] + mn])) {
							possible = false;
							goto out;
						}
						--random;
					} else if (a[j][i]) {
						if (((a[j][i] > upper) && (a[j][i] <= mn)) || (a[j][i] > mn ? present[a[j][i] - mn] : present[a[j][i] + mn])) {
							possible = false;
							goto out;
						}
						--random;
					} else ++cnt;
				} else if (i == j) {
					if (a[i][j]) {
						if ((a[i][j] > upper) && (a[i][j] <= mn))
							--t;
						else {
							possible = false;
							goto out;
						}
					}
				} else break;
			}
		}
out:
		if (!possible) {
			cout << 0 << '\n';
			continue;
		} else {
			for (u32 i = 2; i <= t; ++i) ans = (ans * i) % mod;
			for (u32 i = 2; i <= random; ++i) ans = (ans * i) % mod;
			for (u32 i = 0; i < random; ++i) ans = (ans << 1) % mod;
			cout << ans << '\n';
		}
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

