#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using u32 = unsigned int;
using ll = long long;
using ld = long double;
// 1. Instead of less<int>, we can also do greater<T>, less_equal<T>,
// greater_equal<T> or any other custom function to compare
// 2. Two additional functions apart from all of that from the set is:
//	a) find_by_order(n), finds `n`th element (iterator)
//	b) order_of_key(n), finds elements smaller than `n` (value)
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;

// mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct Node {
  int data;
  Node *next;
};

struct Node *reverse(Node *head) {
  if (head == NULL || head->next == NULL)
    return head;
  Node *rest = reverse(head->next);
  head->next->next = head;
  head->next = NULL;
  return rest;
}

/* NOTE: Calling this function insertNode causes TLE due to copying of
 * pointers of the struct in each iteration, slowing the program
 * significantly.
 * Instead just merge them and the time taken is near to nothing as compared
 * to using the below functions
 *
struct Node *insertNode(Node *node1, Node *node2) {
  struct Node *ptr1n = node1->next, *ptr2n = node2->next;
  while ((ptr2n != NULL) && (node1->data >= ptr2n->data)) {
    ptr2n = ptr2n->next;
    node2 = node2->next;
  }
  ptr2n = node2->next;
  node2->next = node1;
  return ptr2n;
}
struct Node *mergeResult(Node *node1, Node *node2) {
  if (node1 == NULL)
    return reverse(node2);
  else if (node2 == NULL)
    return reverse(node1);

  Node *ptr1 = node1, *ptr2 = node2, *tmp;
  bool head1 = ptr1->data < ptr2->data;
  while (ptr1 != NULL && ptr2 != NULL) {
    if (ptr1->data < ptr2->data) {
      tmp = ptr1;
      ptr1 = ptr2;
      ptr2 = tmp;
    }
    ptr1 = insertNode(ptr1, ptr2);
    ptr2 = ptr2->next;
  }
  return head1 ? reverse(node1) : reverse(node2);
}
*
*
*/
struct Node *mergeResult(Node *node1, Node *node2) {
  if (node1 == NULL)
    return reverse(node2);
  else if (node2 == NULL)
    return reverse(node1);

  Node *ptr1 = node1, *ptr2 = node2, *ptr1n, *ptr2n;
  bool head1 = ptr1->data < ptr2->data;
  while (ptr1 != NULL && ptr2 != NULL) {
    if (ptr1->data < ptr2->data) {
      swap(ptr1, ptr2);
    }
    ptr1n = ptr1->next, ptr2n = ptr2->next;
    while ((ptr2n != NULL) && (ptr1->data >= ptr2n->data)) {
      ptr2n = ptr2n->next;
      ptr2 = ptr2->next;
    }
    ptr2n = ptr2->next;
    ptr2->next = ptr1;
    ptr1 = ptr2n;
    ptr2 = ptr2->next;
  }
  return head1 ? reverse(node1) : reverse(node2);
}

int solve() { return 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1e9;
  cin >> T;
#ifdef ONPC
  cout << "__________________________" << '\n';
#endif
  for (int i = 0; i < T; i++) {
    if (solve()) {
      break;
    }
#ifdef ONPC
    cout << "__________________________" << '\n';
#endif
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)"
       << '\n';
#endif
}
