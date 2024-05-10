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
	char a[5], t;
	string s;

	while (T--) [&]() {
		for (u32 i = 0; i < 5; ++i)
			cin >> a[i];
		t = (a[0] - '0') * 10;
		t += a[1] - '0';
		t -= 12;
		if (a[0] == '0' && a[1] == '0') cout << 12 << a[2] << a[3] << a[4] << ' ' << "AM";
		else if (a[0] == '1' && a[1] == '2') cout << 12 << a[2] << a[3] << a[4] << ' ' << "PM";
		else if (a[0] == '1' && a[1] > '1') cout << a[0] - '1' << a[1] - '2' << a[2] << a[3] << a[4] << ' ' << "PM";
		else if (a[0] == '2') {
			if (t < 10)
				cout << 0 << (int)t << a[2] << a[3] << a[4] << ' ' << "PM";
			else
				cout << (int)t << a[2] << a[3] << a[4] << ' ' << "PM";
		}
		else cout << a[0] << a[1] << a[2] << a[3] << a[4] << ' ' << "AM";
		cout << '\n';
	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

