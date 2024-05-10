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

u32 sumOfDigits(u32 n) {
	u32 sum = 0;
	while (n) sum += n % 10, n /= 10;
	return sum;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cout << std::fixed;
	cout.precision(15);

	u32 T = 1;
	cin >> T;
	u32 sum[6] = { 1, 46, 901, 13501, 180001, 2250001 };

	while (T--) {
		u32 n, p, d, i, j;
		u64 ans = 0;
		cin >> n;
		for (i = 5; i < 6; --i) {
			p = pow(10u, i), d = n / p, n %= p;
			for (j = 0; j < d; ++j) {
				ans += sum[i] + j * p;
			}
			if (d)
				ans += j * n;
		}
		cout << ans << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

