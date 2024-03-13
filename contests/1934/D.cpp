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

const uint nmax = 1e5;

void solve(ull n, ull m, vector<ull> &sol)
{
  for (int i = 63; i > 0; i--)
  {
    uint v = (n >> i) & 1;
    if (!v)
      continue;

    uint u = (m >> i) & 1;

    if (v == u)
    {
      sol.push_back(m);
      break;
    }

    for (int j = i - 1; j >= 0; j--)
    {
      uint w = (n >> j) & 1;
      uint p = (m >> j) & 1;

      if (!w && !p)
      {
        continue;
      }
      else if (!w && p)
      {
        break;
      }
      else if (w && p)
      {
        sol.push_back(m);
        break;
      }
      else if (w && !p)
      {
      }
      else
      {
        assert(0);
      }
    }

    break;
  }
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    ull n, m;
    cin >> n >> m;

    vector<ull> sol;
    sol.push_back(n);
    solve(n, m, sol);

    if (sol.at(sol.size() - 1) == m)
    {
      cout << sol.size() - 1 << "\n";
      for (auto x : sol)
      {
        cout << x << " ";
      }
      cout << "\n";
    }
    else
    {
      cout << "-1\n";
    }
  }

  return 0;
}

void prep()
{
#ifdef DEBUG
  assert(freopen("input", "r", stdin) != 0);
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
