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

ull calc_k(ull y, ull M, ull x)
{
  if ((y / 2) % M != 0)
  {
    return 0;
  }

  ull k = y / 2ULL / M + 1;

  if (k < x)
  {
    return 0;
  }

  return k;
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    ull n, x;
    cin >> n >> x;

    unordered_set<ull> s;

    // case asc
    ull y = n - x;

    for (ull M = 1; y % 2 == 0 && M <= sqrt(y); M++)
    {
      if (y % M != 0)
      {
        continue;
      }

      ull k = calc_k(y, M, x);
      if (k)
      {
        s.insert(k);
      }

      k = calc_k(y, y / M, x);
      if (k)
      {
        s.insert(k);
      }
    }

    // case dsc
    y = n + x - 2;

    for (ull M = 1; y % 2 == 0 && M <= sqrt(y); M++)
    {
      if (y % M != 0)
      {
        continue;
      }

      ull k = calc_k(y, M, x);
      if (k)
      {
        s.insert(k);
      }

      k = calc_k(y, y / M, x);
      if (k)
      {
        s.insert(k);
      }
    }

    cout << s.size() << "\n";
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
