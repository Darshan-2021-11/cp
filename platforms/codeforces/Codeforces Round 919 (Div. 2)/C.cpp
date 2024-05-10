#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using u32 = unsigned int;
using ll = long long;
using ld = long double;
// 1. Instead of less<int>, we can also do greater<T>, less_equal<T>,
// greater_equal<T> or any other custom function to compare
// 2. Two additional functions apart from all of that from the set is:
//	a) find_by_order(n), finds `n`th element (iterator)
//	b) order_of_key(n), finds elements smaller than `n` (value)
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n, nc, t, ans, curr_gcd;
bool found, allodd;
set<int> factors;
int solve() {
	allodd = true;
	ans = 1;
	cin >> n;
	nc = n;
	int a[n], ac[n];

	for (int i = 0; i < n; ++i) {
		cin >> ac[i];
		if ((ac[i] & 1) == 0) {
			allodd = false;
		}
	}

	for (int i = 2; i <= nc; ++i) {
		if (nc % i == 0) {
			do {
				if (nc != n)
					factors.insert(i);
				nc /= i;
			} while (nc % i == 0);
		}
	}

	for (auto &j: factors) {
		found = true;
		for (int i = 0; i < n; ++i) {
			a[i] = ac[i];
		}
		curr_gcd = a[j] - a[0];
		for (int i = j + 1; i < n; ++i) {
			curr_gcd = __gcd(curr_gcd, a[i] - a[i % j]);
		}
		for (int i = 0; i < j; ++i) {
			a[i] %= curr_gcd;
		}
		for (int i = j; i < n; ++i) {
			if (a[i] % curr_gcd != a[i % j]) {
				found = false;
				break;
			}
		}
		if (found) {
			++ans;
		}
	}

	cout << ans << endl;
	factors.clear();
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1e9;
	cin >> T;
	#ifdef ONPC
		cout << "__________________________" << '\n';
	#endif
	for (int i = 0; i < T; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << '\n';
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

