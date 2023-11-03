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
uint a[nmax];

int main()
{
  prep();

  uint n, k;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> k;
    read_array(a, n);

    if (k == 4)
    {
      uint best = 999;
      uint odd = 0, even = 0, r3 = 0;

      for (uint i = 0; i < n; i++)
      {
        if (a[i] % 4 == 0)
        {
          best = 0;
          break;
        }

        if (a[i] % 2 == 0)
        {
          even++;
        }
        else
        {
          odd++;
        }

        if (a[i] % 4 == 3)
        {
          r3++;
        }
      }

      if (even >= 2)
      {
        best = 0;
      }

      if (even == 1)
      {
        best = min(best, 1u);
      }

      if (even == 0)
      {
        best = min(best, 2u);
      }

      if (r3 >= 1)
      {
        best = min(best, 1u);
      }

      cout << best << "\n";
    }
    else
    {
      uint best = 999;

      for (uint i = 0; i < n; i++)
      {
        uint cost = (k - a[i] % k) % k;
        best = min(best, cost);
      }
      cout << best << "\n";
    }
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
