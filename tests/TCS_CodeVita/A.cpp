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
	int distance = 0, min_tmp_dist, min_tmp_dist2, curr_tmp_dist;
	string g, n;
	cin >> g >> n;

	// gives minimum distance with one character and bigger one in case of conflicts
	unordered_map<char, pair<int, char>> min_dist;
	// stores the conflicting characters as true
	unordered_map<char, bool> conflict;
	char previous_good_letter = g[0], curr_tmp_char;

	// Sort the string 'g' so we find the accurate character when mapping the
	// value, by subtracting the minimum distance in case of conflicts
	sort(g.begin(), g.end());

	// storing the minimum distance from the good_string
	// if two characters have same distance from current char, we store it as
	// conflicting, and store the bigger value out of the two conflicting, for
	// deciding later on
	for (int i = 32; i < 127; ++i) {
		min_tmp_dist = INT_MAX;
		conflict[(char)i] = false;
		for (char j: g) {
			curr_tmp_dist = abs((char)i - j);
			if (curr_tmp_dist > min_tmp_dist) continue;
			else if (curr_tmp_dist == min_tmp_dist) {
				conflict[(char)i] = true;
			}
			min_tmp_dist = curr_tmp_dist;
			curr_tmp_char = j;
		}
		min_dist[(char)i] = make_pair(min_tmp_dist, curr_tmp_char);
	}

	// finding the distance and previous_good_letter
	for (char i: n) {
		auto tmp = min_dist[i];
		// skip if the current character is contained in special character, we do
		// not change the previous good character too
		if (!tmp.first) continue;

		if (conflict[i]) {
			curr_tmp_char = (char)((int)tmp.second - 2 * tmp.first);
			min_tmp_dist = abs(previous_good_letter - tmp.second);
			min_tmp_dist2 = abs(previous_good_letter - curr_tmp_char);
			if (min_tmp_dist > min_tmp_dist2) {
				distance += min_tmp_dist2;
				previous_good_letter = curr_tmp_char;
			} else {
				distance += min_tmp_dist;
				previous_good_letter = tmp.second;
			}
		} else {
			distance += tmp.first;
			previous_good_letter = tmp.second;
		}
	}

	cout << distance;
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (solve()) {
		return 1;
	}
	#ifdef ONPC
		cout << "__________________________" << "\n";
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << "\n";
	#endif
}

