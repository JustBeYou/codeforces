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

const uint nmax = 2e5 + 10;
uint a[nmax], b[nmax], c[2 * nmax], ans[nmax], pos[nmax];

int lengthOfLIS(uint nums[], uint n)
{
  memset(ans, 0, sizeof(uint) * n);
  memset(pos, 0, sizeof(uint) * n);

  uint len = 1;

  ans[0] = nums[0];
  pos[0] = 0;

  for (uint i = 1; i < n; i++)
  {
    if (nums[i] > ans[len - 1])
    {
      ans[len++] = nums[i];
      pos[len - 1] = i;
    }
    else
    {
      uint low = lower_bound(ans, ans + len, nums[i]) - ans;
      ans[low] = nums[i];
      pos[low] = i;
    }
  }
  return len;
}

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

    sort(b, b + m, greater<uint>());

    bool is_decreasing = true;
    for (uint i = 0; i < n - 1; i++)
    {
      if (a[i] < a[i + 1])
      {
        is_decreasing = false;
        break;
      }
    }

    // LIS(a) = 1
    if (is_decreasing)
    {
      for (uint i = 0; i < n; i++)
      {
        c[i] = a[i];
      }
      for (uint i = 0; i < m; i++)
      {
        c[i + n] = b[i];
      }
      sort(c, c + n + m, greater<uint>());
      print_array(c, n + m);
      continue;
    }

    // LIS(a) > 1

    lengthOfLIS(a, n);
    // cout << "??? " << lenLis << endl;
    // print_array(ans, lenLis);
    // print_array(pos, lenLis);

    uint i = 0, j = 0, k = 0;
    while (j < m && b[j] >= ans[0])
    {
      c[k++] = b[j++];
    }

    while (i <= pos[0])
    {
      c[k++] = a[i++];
    }

    while (j < m)
    {
      c[k++] = b[j++];
    }

    while (i < n)
    {
      c[k++] = a[i++];
    }

    print_array(c, k);
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
