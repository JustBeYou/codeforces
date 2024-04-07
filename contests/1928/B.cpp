#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

template <typename T>
void print_array(const T v[], uint n);
template <typename T>
void print_vector(const vector<T> &v, uint n = 0);
template <typename T>
void read_array(T v[], uint n);
template <typename T>
void read_array_and_size(T v[], uint &n);
template <typename T>
void read_vector(vector<T> &v, uint n = 0);
template <typename T>
void read_vector_and_size(vector<T> &v, uint &n);
void prep();

const uint nmax = 2e5 + 10;
ull a[nmax];
pair<ull, ull> v[nmax];

int main()
{
  prep();

  int t;
  cin >> t;

  while (t--)
  {
    uint n;
    read_array_and_size(a, n);

    sort(a, a + n);

    uint m = 0;

    for (uint i = 0; i < n; i++)
    {
      if (i > 0 && a[i] == a[i - 1])
      {
        continue;
      }

      v[m++] = {a[i] + 1, a[i] + n};
    }

    sort(v, v + m);

    // for (uint i = 0; i < m; i++)
    // {
    //   cout << "(" << v[i].first << ", " << v[i].second << "), ";
    // }
    // cout << "\n===\n";

    uint s = 1;

    uint j = 0;

    for (uint i = 1; i < m; i++)
    {
      ull t = v[i].first;

      while (t > v[j].second)
      {
        j++;
      }

      s = max(s, i - j + 1);
    }

    cout << s << "\n";
  }

  return 0;
}

void prep()
{
#ifdef DEBUG
  freopen("input", "r", stdin);
#else
  ios::sync_with_stdio(false);
  cin.tie(NULL);
#endif
}

template <typename T>
void print_array(const T v[], uint n)
{
  for (uint i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << "\n";
}

template <typename T>
void read_array(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
    cin >> v[i];
}

template <typename T>
void read_array_and_size(T v[], uint &n)
{
  cin >> n;
  for (uint i = 0; i < n; i++)
    cin >> v[i];
}

template <typename T>
void read_vector(vector<T> &v, uint n)
{
  n = n == 0 ? v.size() : n;
  if (n > v.size())
  {
    v.resize(n);
  }
  for (uint i = 0; i < n; i++)
  {
    cin >> v[i];
  }
}

template <typename T>
void read_vector_and_size(vector<T> &v, uint &n)
{
  cin >> n;
  if (n > v.size())
  {
    v.resize(n);
  }
  for (uint i = 0; i < n; i++)
  {
    cin >> v[i];
  }
}

template <typename T>
void print_vector(const vector<T> &v, uint n)
{
  n = n == 0 ? v.size() : n;
  for (uint i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << "\n";
}
