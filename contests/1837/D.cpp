#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

template <typename T>
void printarray(T v[], uint n);
template <typename T>
void printvector(vector<T> v);
template <typename T>
void readarray(T v[], uint n);
template <typename T>
void readszandarray(T v[], uint &n);
void prep();

const int nmax = 2e5+1;

int coloring[nmax];

int main()
{
  prep();

  int t; cin >> t;
  while (t--) {
    int n; cin>> n;
    string s;
    cin >> s;

    if (n % 2 == 1) {
      cout << -1 << "\n";
      continue;
    }

    int left = 0, right = 0;
    for (auto c: s) {
        if (c == '(') left++;
        else right++;
    }

    if (left != right) {
      cout << -1 << "\n";
      continue;
    }

    int colors = 1;
    int st_1 = 0, st_2 = 0;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ')') {
        if (st_1 == 0) {
          st_2++;
          coloring[i] = 2;
          colors = 2;
        } else {
          st_1--;
          coloring[i] = 1;
        }
      } else {
        if (st_2 == 0) {
          st_1++;
          coloring[i] = 1;
        } else {
          st_2--;
          coloring[i] = 2;
        }
      }
    }

    bool all_2 = true;
    for (int i = 0; i < s.size(); i++) {
      all_2 = all_2 and coloring[i] == 2;
    }

    if (all_2) {
      for (int i = 0; i < s.size(); i++) {
        coloring[i] = 1;
      }
      colors = 1;
    }

    cout << colors << "\n";
    printarray(coloring, s.size());
  }

  return 0;
}

void prep()
{
#ifdef DEBUG
  freopen("input", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

template <typename T>
void printarray(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

template <typename T>
void readarray(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
    cin >> v[i];
}

template <typename T>
void readszandarray(T v[], uint &n)
{
  cin >> n;
  readarray(v, n);
}

template <typename T>
void printvector(vector<T> v)
{
  for (uint i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
