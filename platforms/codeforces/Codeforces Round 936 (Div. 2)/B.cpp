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

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;
	ll max_sum, ans, t;
	int a[(int)2e5 + 10], n, k;
	const int mod = (int)1e9 + 7;

	while (T--) [&]() {
		max_sum = 0, t = 0, ans = 0;
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			t = max(t + a[i], (ll)a[i]);
			max_sum = max(t, max_sum);
		}
		max_sum = max(max_sum, 0ll);
		ans = (binpow(2, k, mod) + mod - 1) % mod;
		ans = ((ans % mod) * (max_sum % mod)) % mod;
		for (int i = 0; i < n; ++i)
			ans = (ans + a[i]) % mod;
		cout << ((ans + mod) % mod) << '\n';
	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

