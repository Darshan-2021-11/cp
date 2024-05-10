#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
// #include <bits/stdc++.h>
#include "bits/stdc++.h"
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
	size_t n, t, cc;
	ll score;
	bool last_not_reached = true;
	cin >> n;

	/* 1st approach (n ^ 2) */
/*
	int a[n];
	int b[n];
	bool not_first_time;
	for (size_t i = 0; i < n; ++i) {
		cin >> a[i];
		++count[a[i]];
		b[i] = a[i]
	}
	sort(b, b + n);
	for (size_t i = 0; i < n; ++i) {
		score = a[i], t = 0;
		not_first_time = false;
		for (size_t j = 0; j < n; ++j) {
			if (b[j] > score)
				break;
			else if (a[i] != b[j]) {
				++t, score += b[j];
			} else {
				if (not_first_time)
					++t, score += b[j];
				else
					not_first_time = true;
			}
		}
		cout << t << ' ';
	}
*/

	/* 2nd approach (n log n) */
	/* <Map uses more time and space */
/*
	int a[n];
	map<size_t, size_t> count;
	for (size_t i = 0; i < n; ++i) {
		cin >> a[i];
		++count[a[i]];
	}

	auto ci = count.begin();
	auto it = ci;
	cc = (*it).second;
	t = cc - 1;
	score = (*it).first * cc;
	++it;

	for (; ci != count.end(); ++ci) {
		while (last_not_reached) {
			if (it == count.end()) {
				last_not_reached = false;
			} else if (((*it).first <= score) || ci == it) {
				cc = (*it).second;
				score += (*it).first * cc;
				t += cc;
				++it;
			} else
				break;
		}
		(*ci).second = t;
	}
	for (int i = 0; i < n; ++i) {
		cout << count[a[i]] << ' ';
	}
*/
	/* 3rd approach (n log n) */
	/* Using Vector, takes less time and space */
	cout << '\n';
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TET = 1e9;
	cin >> TET;
	for (int i = 1; i <= TET; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << "\n";
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << "\n";
	#endif
}

