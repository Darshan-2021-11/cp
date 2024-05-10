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

template <typename T> struct BIT {
	vector<T> tree;
	u32 n;

	BIT(u32 size) {
		initialize(size);
	}
	BIT(vector<T> const &arr) {
		initialize(arr);
	}

	void initialize(u32 size) {
		n = size;
		tree.assign(n, T{});
	}

	void initialize(vector<T> const &arr) {
		initialize(arr.size());
		for (u32 i = 0; i < n; ++i) {
			tree[i] += arr[i];
			u32 r = i | (i + 1);
			if (r < n) tree[r] += tree[i];
		}
	}

	/**
	 * @brief Gives the prefix sum of the entire array upto index `r`
	 * @param r Rightmost index of prefix sum
	 */
	T sum(u32 r) {
		T res{};
		for (u32 i = r++; i < r; i = (i & (i + 1)) - 1)
			res += tree[i];
		return res;
	}

	/**
	 * @brief Gives the ranged sum from index `l` to `r` inclusive
	 * @param l Leftmost index of prefix sum
	 * @param r Rightmost index of prefix sum
	 */
	T sum(u32 l, u32 r) {
		return sum(r) - sum(l - 1);
	}

	/**
	 * @brief Updates the BIT to update a particular index
	 * @param idx index to change
	 * @param val value to add to the element at idx
	 */
	void update(u32 idx, T val) {
		while (idx < n) {
			tree[idx] += val;
			idx |= idx + 1;
		}
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;

	while (T--) {
		u32 n, p, t, small;
		cin >> n;
		set<u32> numbers;
		vector<u32> ans(n, 0);
		for (u32 i = 0; i < n; ++i) numbers.insert(i);

		cin >> p;
		--p;
		for (u32 i = 1; i < n; ++i) {
			cin >> t;
			--t;
			if (p > t) {
				small = *numbers.lower_bound(p - t);
				ans[small] = i;
				numbers.erase(small);
			}
			p = t;
		}
		for (u32 i = 0; i < n; ++i) {
			cout << ans[i] + 1 << ' ';
		}
		cout << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

