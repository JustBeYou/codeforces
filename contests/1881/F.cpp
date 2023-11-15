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

const uint nmax = 2e5 + 100;
vector<uint> G[nmax];

uint mark[nmax];
uint d1[nmax];
uint d2[nmax];

void dfs1(uint root, uint parent = 0)
{
  for (auto next : G[root])
  {
    if (next == parent)
    {
      continue;
    }
    d1[next] = d1[root] + 1;
    dfs1(next, root);
  }
}

void dfs2(uint root, uint parent = 0)
{
  for (auto next : G[root])
  {
    if (next == parent)
    {
      continue;
    }
    d2[next] = d2[root] + 1;
    dfs2(next, root);
  }
}

int main()
{
  prep();

  uint n, k;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> k;
    for (uint i = 1; i <= n; i++)
    {
      G[i].clear();
      mark[i] = 0;
      d1[i] = d2[i] = 0;
    }

    for (uint i = 0; i < k; i++)
    {
      uint u;
      cin >> u;
      mark[i] = u;
    }

    for (uint i = 0; i < n - 1; i++)
    {
      uint u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    if (k == 1)
    {
      cout << "0\n";
      continue;
    }

    dfs1(mark[0]);
    uint u = 0;
    for (uint i = 0; i < k; i++)
    {
      if (d1[u] < d1[mark[i]])
        u = mark[i];
    }

    dfs2(u);
    uint v = 0;
    for (uint i = 0; i < k; i++)
    {
      if (d2[v] < d2[mark[i]])
        v = mark[i];
    }

    cout << (d2[v] / 2 + d2[v] % 2) << "\n";
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
