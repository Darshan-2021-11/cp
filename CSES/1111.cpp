#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 2'000'002;
	int n = 0, l, r, ans = INT_MIN, idx = -1, p[N];
	char a[N];
	a[n] = '#', p[n] = 1;
	while ((a[++n] = getchar()) != '\n') a[++n] = '#', p[n - 1] = p[n] = 1;
	a[n] = '\0';
	l = r = 1;
	for (int i = 1; i < n; ++i) {
		p[i] = max(1, min(r - i, p[l + r - i]));
		while (i - p[i] >= 0 && i + p[i] <= n && a[i - p[i]] == a[i + p[i]])
			++p[i];
		if (i + p[i] > r) {
			l = i - p[i], r = i + p[i];
			if (p[i] - 1 > ans) ans = p[i] - 1, idx = i - ans;
		}
	}
	while (ans) {
		if (a[idx] != '#') putchar(a[idx]), --ans;
		++idx;
	}
}
