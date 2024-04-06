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

const uint nmax = 1e5 + 5;
uint a[nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n, k;
    cin >> n >> k;
    k--;
    read_array(a, n);

    int lrg = -1;

    for (uint i = 0; i < k; i++)
    {
      if (a[i] > a[k])
      {
        lrg = i;
        break;
      }
    }

    if (lrg == -1)
    {
      uint sol = 0;
      for (uint i = 0; i < n; i++)
      {
        if (i == k)
          continue;
        if (a[k] > a[i])
          sol++;
        else
          break;
      }
      cout << sol << "\n";
    }
    else
    {
      int sol = lrg - 1;

      int asol = lrg > 0 ? 1 : 0;

      for (uint i = lrg + 1; i < k; i++)
      {
        if (a[k] > a[i])
        {
          asol += 1;
        }
        else
        {
          break;
        }
      }

      cout << max(sol, asol) << "\n";
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
