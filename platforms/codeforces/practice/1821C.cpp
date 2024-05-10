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
		string s;
		u32 count[26] { 0 }, j = 0, k = 0, minsteps = UINT32_MAX, tmpsteps;
		bool flag;
		cin >> s;
		for (char &i: s) ++count[i - 'a'];
		const u32 n = s.size() + 1;
		char tmp[n];
		memcpy(tmp, s.c_str(), n);

		for (u32 i = 0; i < 26; ++i) {
			if (!count[i]) continue;
			else if (count[i] == n - 1) {
				minsteps = 0;
				break;
			}
			tmpsteps = 0;
			j = 0; k = 0;
			while(k != count[i]) {
				j = 0; k = 0;
				flag = false;
				while (tmp[j]) {
					if (tmp[j] == char('a' + i) || flag) { tmp[k++] = tmp[j]; flag = false; }
					else { flag = true; }
					++j;
				}
				tmp[k] = '\0';
				++tmpsteps;
			}
			minsteps = min(tmpsteps, minsteps);
			memcpy(tmp, s.c_str(), n);
		}
		cout << minsteps << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

