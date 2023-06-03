#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

template <typename T>
void printarray(T v[], uint n);
template <typename T>
void printvector(vector<T> v);
template <typename T>
void readarray(T v[], uint n);
template <typename T>
void readszandarray(T v[], uint &n);
void prep();

const int nmax = 2e5 + 5;

typedef struct {
  int to, pos;
} edge;

vector<edge> tree[nmax];

int sol = 0;
void dfs(int node, int parent = 0, int time = 0, int curr = 1) {
  sol = max(sol, curr);

  for (auto next_node: tree[node]) {
    if (next_node.to == parent) continue;

    if (time > next_node.pos) {
      dfs(next_node.to, node, next_node.pos, curr + 1);
    } else {
      dfs(next_node.to, node, next_node.pos, curr);
    }

  }
}

int main()
{
  prep();

  int t;cin >>t;
  while (t--) {
    int n; cin >> n;
    sol = 0;

    for (int i =0; i <= n; i++) {
      tree[i].clear();
    }

    for (int i = 0; i < n-1; i++) {
      int x, y;
      cin >> x>>y;

      tree[x].push_back({y, i});
      tree[y].push_back({x, i});
    }


    dfs(1);

    cout << sol << "\n";
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
void printarray(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

template <typename T>
void readarray(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
    cin >> v[i];
}

template <typename T>
void readszandarray(T v[], uint &n)
{
  cin >> n;
  readarray(v, n);
}

template <typename T>
void printvector(vector<T> v)
{
  for (uint i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
