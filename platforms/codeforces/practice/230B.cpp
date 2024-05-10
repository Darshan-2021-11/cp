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

vector<bool> SieveOfEratosthenes(u32 n)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	vector<bool> prime(n + 1, true);

	for (u32 p = 2; p * p <= n; p++) {
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true) {
			// Update all multiples of p greater than or
			// equal to the square of it numbers which are
			// multiple of p and are less than p^2 are
			// already been marked.
			for (u32 i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	return prime;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);
	vector<bool> prime = SieveOfEratosthenes(1e6);

	u32 T = 1;
	cin >> T;

	while (T--) {
		u64 n, t;
		bool yes = false;
		cin >> n;
		t = sqrtl(n);
		if (t * t == n && prime[t]) yes = true;
		cout << (yes && n != 1 ? "YES\n": "NO\n");
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

