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

const int mod = 1e9 + 7;
int n;
string s;

int distinctSubsequence(string s) {
	long long n = s.size();
	vector<long long> dp ( n + 1 , 0 );
	dp[0] = 1;
	map<char , long long> m;
	for(long long i = 1; i < n + 1 ;i++){
		dp[i] =( 2 * dp[i - 1] + mod) % mod;
		if ( m.count(s[i - 1]) ){
			long long index = m[s[i - 1]];
			dp[ i ] = (dp[i] - dp[ index - 1] + mod) % mod;
		}
		m[s[i - 1]] = i;
	}

	return dp[n] - 1;
}

int solve() {
	cin >> n;
	cin >> s;
	sort(s.begin(), s.end());
	cout << distinctSubsequence(s) << '\n';
	s.clear();
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

