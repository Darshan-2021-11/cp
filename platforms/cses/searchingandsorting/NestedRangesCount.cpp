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

struct range {
	u32 left, right, index;
};

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

	while (T--) {
		u32 n, left, right;
		cin >> n;
		vector<range> ranges(n);
		vector<pair<u32, u32>> l(n), r(n);
		vector<u32> contained(n, 0), contains(n, 0);
		BIT<u32> bit(n + 1);
		for (u32 i = 0; i < n; ++i) {
			cin >> left >> right;
			ranges[i] = { left, right, i };
		}
		sort(ranges.begin(), ranges.end(), [](range &x, range &y) {
				if (x.left == y.left) return x.right > y.right;
				return x.left < y.left;
				});
		for (u32 i = 0; i < n; ++i) {
			l[i] = { ranges[i].left, ranges[i].index };
			r[i] = { ranges[i].right, i };
		}
		sort(r.begin(), r.end(), [](pair<u32, u32> &x, pair<u32,u32> &y) {
				if (x.first == y.first) return x.second > y.second;
				return x.first < y.first;
				});
		// contains
		right = 0;
		while (right < n) {
			u32 index_in_sorted = r[right].second, actual_index = l[index_in_sorted].second;
			contains[actual_index] = bit.sum(r[right].second);
			bit.update(0, 1);
			bit.update(r[right].second + 1, -1);
			++right;
		}
		bit.initialize(n);
		// contained
		left = 0, right = 0;
		while (right < n) {
			if (left < n && l[left].first < r[right].first)
				bit.update(left++, 1);
			else {
				bit.update(r[right].second, -1);
				u32 index_in_sorted = r[right].second, actual_index = l[index_in_sorted].second;
				contained[actual_index] = bit.sum(r[right].second);
				++right;
			}
		}
		for (auto &i: contains) cout << i << ' ';
		cout << '\n';
		for (auto &i: contained) cout << i << ' ';
		cout << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}
