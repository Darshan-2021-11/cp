
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

template <typename T>
T point_distance(T a[], T b[], int a0, int b0) {
	return sqrt(pow(a[a0] - b[b0], 2) + pow(a[a0 + 1] - b[b0 + 1], 2));
}

long double opab[8] { 0 }, distances[5], w[3];

int solve() {
	for (int i = 2; i < 8; ++i) {
		cin >> opab[i];
	}

	// OA
	distances[0] = point_distance<ld>(opab, opab, 0, 4);
	// OB
	distances[1] = point_distance<ld>(opab, opab, 0, 6);
	// PA
	distances[2] = point_distance<ld>(opab, opab, 2, 4);
	// PB
	distances[3] = point_distance<ld>(opab, opab, 2, 6);
	// AB / 2
	distances[4] = point_distance<ld>(opab, opab, 4, 6) / 2;

	// case: two points in A
	w[0] = max(distances[0], distances[2]);
	// case: two points in B
	w[1] = max(distances[1], distances[3]);
	// case: one in A and another in B, but both needs to be touching for
	// accomodating the path from O to P
	w[2] = min(
			// OA, PB, AB / 2
			max({distances[0], distances[3], distances[4]}),
			// PA, OB, AB / 2
			max({distances[1], distances[2], distances[4]})
			);

	cout << *min_element(w, w + 3) << '\n';
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// Increasing precision of ld, do:ble and float values
	cout << fixed << setprecision(10);

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

