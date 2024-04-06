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

const uint nmax = 2e5 + 5;

ull diff(ull a, ull b, ull n)
{
  return a >= b ? a - b : n - (b - a);
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    ull n, x, y;
    cin >> n >> x >> y;

    set<ull> xs;

    for (ull i = 0; i < x; i++)
    {
      ull v;
      cin >> v;
      xs.insert(v - 1);
    }

    for (auto it = xs.begin(); it != xs.end() && y; it++)
    {
      auto a = *it;
      auto nx = next(it, 1);
      auto b = nx == xs.end() ? *xs.begin() : *nx;

      auto d = diff(b, a, n) - 1;

      if (d < 2)
        continue;

      if (d % 2 == 0)
      {
        for (ull i = (a + 2) % n; i != diff(b, 1, n) && y; i = (i + 2) % n)
        {
          if (xs.find(i) == xs.end())
          {
            xs.insert(i);
            y--;
          }
        }
      }
      else
      {
        for (ull i = (a + 2) % n; i != b && y; i = (i + 2) % n)
        {
          if (xs.find(i) == xs.end())
          {
            xs.insert(i);
            y--;
          }
        }
      }
    }

    ull sol = xs.size() - 2;

    for (auto it = xs.begin(); it != xs.end(); it++)
    {
      auto a = *it;
      auto nx = next(it, 1);
      auto b = nx == xs.end() ? *xs.begin() : *nx;

      if (diff(b, a, n) == 2)
      {
        sol++;
      }
    }

    cout << sol << "\n";
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
