#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

// `d` stores the distance between the given node and all other nodes, `bc` is how many child of this current junction
// or parent node is remaining to traverse and hermioneForced is explained in switch case 1
static u32 n, t, e1, e2, c, x, d[(u32)2e5 + 1], parent[(u32)2e5 + 1], bc[(u32)2e5 + 1], hermioneForced[(u32)2e5 + 1];
// this is the adjacency list of the nodes of the given tree
static vector<u32> adj[(u32)2e5 + 1];
// `s` is the stack that we use to traverse the tree for BFS
static vector<u32> s;
// `V` is the visited node, and `W` is can Ron win from this node if chosen
static bool V[(u32)2e5 + 1], W[(u32)2e5 + 1];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> t;
  for (u32 i = 1; i < n; ++i) {
    cin >> e1 >> e2;
    adj[e1].push_back(e2);
    adj[e2].push_back(e1);
  }
  cin >> e1;
  V[e1] = true;
  for (const auto &i: adj[e1]) {
    s.emplace_back(i);
    parent[i] = e1;
    ++d[i], ++bc[e1];
  }
  while (s.size()) {
    c = s.back(); s.pop_back();
    V[c] = true;
    switch (adj[c].size()) {
      case 1:
        x = parent[c];
        // use of short circuit evaluation using `&&` to decrease hermioneForced is initially set to the total number
        // of nodes left to be traversed by the junction element, if hermione has actually has no good choice to
        // take anyway i.e. if hermioneForced == 0 (all he has is bad options to choose from), he cannot help but take
        // the worst options that lead to his losing
        W[x] |= (d[c] & 1) && (!(d[x] & 1) | (--hermioneForced[x] == 0)), --bc[x];
        while (!bc[x]) e2 = parent[x], W[e2] |= W[x] && ((!(d[e2] & 1) | --hermioneForced[e2] == 0)), --bc[e2], x = e2;
        break;
      case 2:
        // since we can only go forward a single node, we do not change the parent in order to reach to the parent
        // faster
        for (const auto &i: adj[c]) if (!V[i]) s.emplace_back(i), d[i] = d[c] + 1, parent[i] = parent[c];
        break;
      default:
        // we update the parent of the nodes if in a junction, or if more than 2 adjacent nodes are there of this
        // current node
        for (const auto &i: adj[c]) if (!V[i]) {
          d[i] = d[c] + 1;
          s.emplace_back(i);
          parent[i] = c;
          ++bc[c], ++hermioneForced[c];
        }
    }
  }
  cout << (W[e1] ? "Ron\n" : "Hermione\n");
  for (u32 i = 1; i < t; ++i) {
    cin >> e2;
    if (adj[e2].size() != 1)
      cout << ((d[e2] & 1) ^ W[e2] ? "Ron\n" : "Hermione\n");
    else {
      cout << ((adj[e2][0] & 1) ^ W[adj[e2][0]] ? "Ron\n" : "Hermione\n");
    }
  }
}
