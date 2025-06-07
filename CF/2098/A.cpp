#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 11;
	int TC = 1;
	char a[N];
	cin >> TC;
	while (TC--) {
		for (int i = 1; i <= 10; ++i) cin >> a[i];
		for (int i = 1; i <= 10; ++i) {
			int mn = i;
			for (int j = i + 1; j <= 10; ++j) {
				if (a[j] >= '0' + 10 - i && a[mn] > a[j]) mn = j;
			}
			swap(a[i], a[mn]);
			cout << a[i];
		}
		cout << '\n';
	}
}
