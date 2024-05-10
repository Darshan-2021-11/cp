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

struct node {
	u32 p1, p2, idx;
};

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;

	while (T--) {
		u32 n, t;
		bool yes = true;
		cin >> n;
		vector<vector<u32>> count(n);
		vector<u32> p1(n), p2(n), remaining;

		for (u32 i = 0; i < n; ++i) {
			cin >> t;
			--t;
			p1[i] = t;
			count[t].emplace_back(i);
		}
		for (u32 i = 0; i < n; ++i) {
			if (count[i].size() > 2) {
				yes = false;
				break;
			}
		}
		if (!yes) {
			cout << "NO\n";
			continue;
		}
		for (u32 i = 0; i < n; ++i) {
			switch (count[i].size()) {
				case 1:
					p2[count[i].front()] = i;
					break;
				case 0:
					remaining.emplace_back(i);
			}
		}
		for (u32 i = n - 1; i < n; --i) {
			if (count[i].size() != 2) continue;
			u32 idx;
			idx = count[i][0];
			if (i < remaining.back()) {
				yes = false;
				break;
			}
			p2[idx] = remaining.back();
			idx = count[i][1];
			p2[idx] = remaining.back();
			swap(p1[idx], p2[idx]);
			remaining.pop_back();
		}

		if (yes) {
			cout<< "YES\n";
			for (u32 &i: p1) cout << i + 1 << ' ';
			cout << '\n';
			for (u32 &i: p2) cout << i + 1 << ' ';
			cout << '\n';
		} else {
			cout << "NO\n";
		}
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

