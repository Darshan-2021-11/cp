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
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;

	while (T--) {
		u32 possible_ans[26], ans = UINT32_MAX;
		for (u32 &i: possible_ans) i = UINT32_MAX;
		string s;
		cin >> s;
		const u32 n = s.size();
		vector<vector<u32>> alphabets(26, vector<u32>(n + 1, 0));
		for (u32 i = 0; i < n; ++i) {
			u32 t = s[i] - 'a';
			++alphabets[t][i + 1];
		}
		for (u32 i = 0; i < 26; ++i) {
			for (u32 j = 1; j <= n; ++j) {
				alphabets[i][j] += alphabets[i][j - 1];
			}
			const u32 req = alphabets[i][n];
			if (req) {
				//cout << req << '\t';
				//for (u32 j = 1; j <= n; ++j) cout << alphabets[i][j] << ' ';
				for (u32 j = 1; j + req - 1 <= n; ++j) {
					possible_ans[i] = min(possible_ans[i], req - (alphabets[i][j + req - 1] - alphabets[i][j - 1]));
				}
			}
			ans = min(ans, possible_ans[i]);
		}
		cout << ans << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

