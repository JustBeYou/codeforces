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

const uint nmax = 2e5 + 50;
uint a[nmax];
uint b[nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n, m;
    cin >> n >> m;
    read_array(a, n);
    read_array(b, m);

    uint b_or = 0;
    for (uint i = 0; i < m; i++)
    {
      b_or |= b[i];
    }

    uint min_sol = 0, max_sol = 0;

    uint xor_simple = 0, xor_b_or = 0;
    for (uint i = 0; i < n; i++)
    {
      xor_simple ^= a[i];
      xor_b_or ^= a[i] | b_or;
    }

    if (n % 2 == 0)
    {
      min_sol = xor_b_or;
      max_sol = xor_simple;
    }
    else
    {

      min_sol = xor_simple;
      max_sol = xor_b_or;
    }

    cout << min_sol << " " << max_sol << "\n";
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
