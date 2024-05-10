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

vector<u32> SieveOfEratosthenes(u32 x)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	vector<bool> prime(x + 1, 1);
	vector<u32> nums;

	for (u32 p = 2; p * p <= x; p++) {
		// If prime[p] is not changed, then it is a prime
			// Update all multiples of p greater than or
			// equal to the square of it numbers which are
			// multiple of p and are less than p^2 are
			// already been marked.
			for (u32 i = p * p; i <= x; i += p)
				prime[i] = false;
	}
	for (u32 p = 2; p <= x; p++) {
		// If prime[p] is not changed, then it is a prime
			// Update all multiples of p greater than or
			// equal to the square of it numbers which are
			// multiple of p and are less than p^2 are
			// already been marked.
			if (prime[p]) nums.push_back(p);
		}
	return nums;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cout << std::fixed;
	cout.precision(15);

	u32 T = 1;
	cin >> T;

	vector<u32> primes = SieveOfEratosthenes(1e6);

	while (T--) {
		u32 n, t = 0;
		cin >> n;

		if (n & 1) {
			cout << 1 << ' ';
			for (u32 i = 0; i < n -1; i += 2) {
				cout << primes[t] << ' ' << primes[t] << ' ';
				++t;
			}
		} else {
			if (n == 2) cout << 2 << ' ' << 2 << ' ';
			else if (n == 4) cout << 2 << ' ' << 2 << ' ' << 3 << ' ' << 3 << ' ';
			else {
				cout << 1 << ' ' << 4 << ' ' <<  4 << ' ' << 4 << ' ';
				for (u32 i = 0; i < n - 4; i += 2) {
					cout << primes[t] << ' ' << primes[t] << ' ';
					++t;
				}
			}
		}

		cout << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

