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

int v[nmax];

map<int, int> find_sequences(int n) {
  map<int, int > m;

  int last = -1;
  int sz = 0;

  for (int i = 0; i < n; i++) {
    if (v[i] == last) {
      sz++;
      m[last] = max(m[last], sz);
    } else {
      m[last] = max(m[last], sz);

      last = v[i];
      sz = 1;
    }
  }

  m[last] = max(m[last], sz);

  return m;
}

int main()
{
  prep();

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;

    readarray(v, n);
    auto map_a = find_sequences(n);

    // for (auto x: map_a) {
    //   cout << x.first << " " << x.second << endl;
    // }

  // cout << "---\n";
    readarray(v, n);
    auto map_b = find_sequences(n);


    // for (auto x: map_b) {
    //   cout << x.first << " " << x.second << endl;
    // }

    int sol = 0;
    for (auto elem: map_a) {
      // cout << elem.first << " "  << elem.second << " " <<  map_b[elem.first] << endl;
      sol = max(sol, elem.second + map_b[elem.first]);
    }

    for (auto elem: map_b) {
      sol = max(sol, elem.second + map_a[elem.first]);
    }

    cout << sol << "\n";
    // cout << endl;
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
