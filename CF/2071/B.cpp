#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 250'000;
	int TC = 1, n, a[N], an;
	int64_t s, sr;
	cin >> TC;
	while (TC--) {
		cin >> n;
		sr = sqrtl(((s = n + 1) *= n) >>= 1);
		if (sr * sr == s) {
			cout << -1;
		} else {
			s = 2;
			cout << s << ' ';
			for (int i = 1; i <= n; i += 2) {
				cout << i << ' ';
				s += i;
			}
			an = 0;
			for (int i = 4; i <= n; i += 2) a[an++] = i;
			while (an) {
				for (int i = 0; i < an; ++i) {
					s += a[i];
					sr = sqrtl(s);
					if (sr * sr == s) {
						s -= a[i];
					} else {
						cout << a[i] << ' ';
						a[i] = -1;
					}
				}
				int t = 0;
				for (int i = 0; i < an; ++i) {
					if (a[i] == -1) continue;
					a[t++] = a[i];
				}
				an = t;
			}
		}
		cout << '\n';
	}
}
