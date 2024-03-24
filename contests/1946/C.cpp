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
vector<uint> G[nmax];
uint n, k;

uint parts;
uint _check(uint node, uint parent, uint x)
{
  uint cnt = 1;

  for (auto next : G[node])
  {
    if (next == parent)
    {
      continue;
    }

    cnt += _check(next, node, x);
  }

  if (cnt >= x && parts)
  {
    parts -= 1;
    return 0;
  }

  return cnt;
}

bool check(uint x)
{
  parts = k + 1;
  _check(1, 0, x);

  return parts == 0;
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> k;

    for (uint i = 1; i <= n; i++)
    {
      G[i].clear();
    }

    for (uint i = 0; i < n - 1; i++)
    {
      uint x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }

    uint sol = 0;
    uint left = 1, right = n / (k + 1);

    while (left <= right)
    {
      uint x = (left + right) / 2;

      if (check(x))
      {
        sol = max(sol, x);
        left = x + 1;
      }
      else if (x > 0)
      {
        right = x - 1;
      }
      else
      {
        break;
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
