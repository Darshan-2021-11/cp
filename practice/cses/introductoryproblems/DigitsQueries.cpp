#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif

/* Fastest Code if sorted by time in the question in CSES :)
#include <stdio.h>

using u32 = unsigned int;
unsigned long long k;
unsigned long long value[19] = {
    0ULL,
    9ULL,
    189ULL,
    2889ULL,
    38889ULL,
    488889ULL,
    5888889ULL,
    68888889ULL,
    788888889ULL,
    8888888889ULL,
    98888888889ULL,
    1088888888889ULL,
    11888888888889ULL,
    128888888888889ULL,
    1388888888888889ULL,
    14888888888888889ULL,
    158888888888888889ULL,
    1688888888888888889ULL,
    17888888888888888889ULL,
};
unsigned long long l[20] = {
    0ULL,
    9ULL,
    99ULL,
    999ULL,
    9999ULL,
    99999ULL,
    999999ULL,
    9999999ULL,
    99999999ULL,
    999999999ULL,
    9999999999ULL,
    99999999999ULL,
    999999999999ULL,
    9999999999999ULL,
    99999999999999ULL,
    999999999999999ULL,
    9999999999999999ULL,
    99999999999999999ULL,
    999999999999999999ULL,
    9999999999999999999ULL,
};
u32 q, t, u;
char number[20];

int main() {
  scanf("%u", &q);
  for (u32 i = 0; i < q; ++i) {
    t = 18;
    scanf("%lld", &k);
    while (k <= value[t])
      --t;
    k -= value[t];
    ++t;
    u = k % t;
    // number at that position
    k = l[t - 1] + (k / t) + (u > 0);
    sprintf(number, "%lld", k);
    printf("%c\n", number[(u - 1 + t) % t]);
  }
  return 0;
}
 */

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

u32 q, t, u;

vector<unsigned long long> value;
unsigned long long k, l;
int solve() {
	cin >> q;
	for (u32 i = 0; i < q; ++i) {
		t = value.size() - 1, l = 1;
		cin >> k;
		while (k <= value[t]) --t;
		k -= value[t];
		for (u32 j = 0; j < t; ++j) l *= 10;
		++t, --l;
		u = k % t;
		
		cout << to_string(l + (k / t) + (u > 0))[(u - 1 + t) % t] << '\n';
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	t = 1, l = 9, k = 9;
	value.push_back(0);
	for (value.push_back(k);;) {
		++t;
		l *= 10;
		k += l * t;
		if (k > value.back()) {
			value.push_back(k);
		} else {
			break;
		}
	}
	#ifdef ONPC
		cout << "__________________________" << '\n';
	#endif
	solve();
	#ifdef ONPC
		cout << "__________________________" << '\n';
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

