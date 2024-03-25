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

const uint nmax = 3e5 + 10;

struct node_data
{
  uint left;
  uint right;
};

node_data G[nmax];
char label[nmax];

struct state
{
  uint node;
  ull cost;
};

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n;
    cin >> n;
    cin >> (label + 1);

    for (uint i = 1; i <= n; i++)
    {
      uint left, right;
      cin >> left >> right;

      G[i] = {.left = left, .right = right};
    }

    queue<state> q;
    q.push({.node = 1, .cost = 0});

    ull solution = nmax * 2;
    while (!q.empty())
    {
      state fst = q.front();
      q.pop();

      auto node = G[fst.node];

      if (!node.left && !node.right)
      {
        solution = min(solution, (ull)fst.cost);
      }

      // cout << fst.node << " -> " << label[fst.node] << "\n";

      if (node.left)
      {
        q.push({.node = node.left, .cost = label[fst.node] == 'L' ? fst.cost : fst.cost + 1});
      }

      if (node.right)
      {
        q.push({.node = node.right, .cost = label[fst.node] == 'R' ? fst.cost : fst.cost + 1});
      }
    }

    cout << solution << "\n";
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
