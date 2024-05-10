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
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cout << std::fixed;
	cout.precision(15);

	u32 T = 1;
	cin >> T;
	enum index { C = 0, D, H, S };

	while (T--) {
		u32 n;
		char ts;
		bool possible = true;
		string t;
		cin >> n;
		cin >> ts;
		const u32 nc = n << 1;
		unordered_map<char, vector<string>> cards;
		vector<string> ans;
		ans.reserve(nc);

		for (u32 i = 0; i < nc; ++i) {
			cin >> t;
			cards[t[1]].emplace_back(t);
		}
		for (auto &[i, j]: cards) {
			sort(j.begin(), j.end());
			if (i == ts) continue;
			if (j.size() & 1) {
				if (cards[ts].size() == 0) {
					possible = false;
					break;
				}
				ans.emplace_back(j.back());
				ans.emplace_back(cards[ts].back());
				j.pop_back();
				cards[ts].pop_back();
			}
			for (string &k: j) {
				ans.emplace_back(k);
			}
		}
		for (string &k: cards[ts]) ans.emplace_back(k);
		if (!possible) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for (u32 i = 0; i < ans.size(); i += 2) {
			cout << ans[i] << ' ' << ans[i + 1] << '\n';
		}
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}
