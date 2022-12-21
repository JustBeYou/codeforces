#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << "; ";

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

const int nmax = 1e5;
uint a[nmax];

uint best[nmax];
int before[nmax];
uint solution[nmax];

uint distinct_values = 1;
uint normalized[nmax];

uint max_best_tree[4 * nmax];
uint norm_i_tree[4 * nmax];

void update_best(uint node, uint left, uint right, uint i)
{
  if (left == right)
  {
    cout << "update ";
    dbg(left);
    dbg(right);
    dbg(i);
    cout << endl;
    max_best_tree[node] = best[i];
    norm_i_tree[node] = i;
    return;
  }

  uint mid = (left + right) / 2;
  if (i <= mid)
  {
    update_best(2 * node, left, mid, i);
  }
  else
  {
    update_best(2 * node + 1, mid + 1, right, i);
  }

  uint best_child = max_best_tree[2 * node] > max_best_tree[2 * node + 1] ? 2 * node : 2 * node + 1;
  max_best_tree[node] = max_best_tree[best_child];
  norm_i_tree[node] = norm_i_tree[best_child];
}

int query_best_node(uint node, uint left, uint right, uint q_left, uint q_right)
{
  cout << "query ";
  dbg(left);
  dbg(right);
  dbg(q_left);
  dbg(q_right);
  cout << endl;
  if (right < q_left || q_right < left)
  {
    return -1;
  }

  if (q_left <= left && right <= q_right)
  {
    dbg(node);
    cout << endl;
    return node;
  }

  int best_left = -1, best_right = -1;
  uint mid = (left + right) / 2;

  if (q_left <= mid)
  {
    best_left = query_best_node(2 * node, left, mid, q_left, q_right);
  }

  if (mid < q_right)
  {
    best_right = query_best_node(2 * node + 1, mid + 1, right, q_left, q_right);
  }

  if (best_left == -1)
    return best_right;

  if (best_right == -1)
    return best_left;

  if (max_best_tree[best_left] > max_best_tree[best_right])
  {
    return best_left;
  }
  return best_right;
}

int find_best_j(uint norm_i)
{
  if (norm_i == 0)
    return -1;

  int best_node = query_best_node(0, 0, distinct_values, 0, norm_i - 1);
  if (best_node == -1 || max_best_tree[best_node] == 0)
  {
    return -1;
  }

  return norm_i_tree[best_node];
}

void normalization(uint n)
{
  uint copy_a[n];
  for (uint i = 0; i < n; i++)
    copy_a[i] = a[i];
  sort(copy_a, copy_a + n);

  normalized[0] = copy_a[0];
  for (uint i = 1; i < n; i++)
  {
    if (copy_a[i] != copy_a[i - 1])
    {
      normalized[distinct_values++] = copy_a[i];
    }
  }
}

uint normalize_value(uint value)
{
  uint left = 0, right = distinct_values;
  while (left < right)
  {
    uint mid = (left + right) / 2;
    if (value == normalized[mid])
      return mid;

    if (value < normalized[mid])
      right = mid;
    else
      left = mid + 1;
  }

  // This should never be reached
  throw runtime_error("invalid normalization value");
}

int main()
{
  prep();

  uint n;
  readszandarray(a, n);

  normalization(n);

  uint max_best = 0;
  int max_best_i = -1;

  for (uint i = 0; i < n; i++)
  {
    uint norm_i = normalize_value(a[i]);

    best[norm_i] = 1;
    before[norm_i] = -1;

    int j = find_best_j(norm_i);
    if (j != -1)
    {
      best[norm_i] = 1 + best[j];
      before[norm_i] = j;
    }

    if (best[norm_i] > max_best)
    {
      max_best = best[norm_i];
      max_best_i = norm_i;
    }

    update_best(0, 0, distinct_values, norm_i);
  }

  cout << max_best << "\n";
  int i = max_best - 1;
  while (i >= 0)
  {
    solution[i--] = normalized[max_best_i];
    max_best_i = before[max_best_i];
  }
  printarray(solution, max_best);

  return 0;
}

void prep()
{
  freopen("scmax.in", "r", stdin);
#ifndef DEBUG
  freopen("scmax.out", "w", stdout);
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
