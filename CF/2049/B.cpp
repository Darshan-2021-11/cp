#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 500;
	int TC = 1, n, cnt[2];
	char a[N];
	bool yes;
	cin >> TC;
	while (TC--) {
		yes = true;
		cnt[0] = cnt[1] = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			switch (a[i]) {
				case 'p':
					{
						++cnt[0];
						break;
					}
				case 's':
					{
						yes &= cnt[0] == 0;
						++cnt[1];
						break;
					}
			}
		}
		if (cnt[0] && cnt[1]) {
			if (cnt[0] == 1 && a[n - 1] == 'p') {}
			else if (cnt[1] == 1 && a[0] == 's') {}
			else yes = false;
		}
		cout << (yes ? "YES\n" : "NO\n");
	}
}
