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

const uint nmax = 1e9 + 5;

uint solbrut(uint n)
{
  uint sol = nmax + 1;

  for (uint a = 0; a <= 16; a++)
  {
    for (uint b = 0; b <= 6; b++)
    {
      for (uint c = 0; c <= 3; c++)
      {
        for (uint d = 0; d <= 3; d++)
        {
          for (uint e = 0; e <= 2; e++)
          {
            if (a + b * 3 + c * 6 + d * 10 + e * 15 == n)
            {
              sol = min(sol, a + b + c + d + e);
            }
          }
        }
      }
    }
  }

  return sol;
}

int main()
{
  prep();

  uint n;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;

    uint sol = solbrut(n);
    uint c[] = {1, 3, 6, 10, 15};
    for (uint i = 0; i < 5; i++)
    {
      sol = min(sol, n / c[i] + solbrut(n % c[i]));

      if (n / c[i] > 0)
      {
        sol = min(sol, n / c[i] - 1 + solbrut(n % c[i] + c[i]));
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
