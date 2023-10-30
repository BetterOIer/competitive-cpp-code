#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long x, y, z;
    cin >> x >> y >> z;
    if (x < y && y < z) {
      vector<long long> v;
      while (z > 0) {
        v.push_back(z % y);
        z /= y;
      }
      long long p = 1, ans = 0;
      for (long long i = 0; i < v.size(); i++) {
        ans += v[i] * p;
        p *= x;
      }
      if (ans == y || (ans == 1 && x == 1)) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else if (x == y) {
      if (y == z) {
        if (z == 1) {
          cout << "-1\n";
        } else {
          cout << "2\n";
        }
      } else {
        cout << "0\n";
      }
    } else if (y == z) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }
  return 0;
}
