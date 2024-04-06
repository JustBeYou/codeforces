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

const uint nmax = 1e3 + 5;

ll a[nmax][nmax];
ll col_max[nmax];
ll dp[nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n, k;
    cin >> n >> k;
    memset(dp, 0, sizeof(ll) * (n + 1));
    memset(col_max, 0, sizeof(ll) * (n + 1));

    for (uint i = 0; i < n; i++)
    {
      for (uint j = i; j < n; j++)
      {
        cin >> a[i][j];
      }
    }

    for (uint i = 0; i < n; i++)
    {
      for (uint j = 0; j < n; j++)
      {
        col_max[j] = max(col_max[j], a[i][j]);
      }
    }

    dp[0] = max(0LL, a[0][0]);
    dp[1] = max(dp[0], col_max[1]);

    for (uint i = 2; i < n; i++)
    {
      dp[i] = max(
          max(dp[i - 1], dp[i - 2] + a[i][i]),
          col_max[i]);
    }

    cout << dp[n - 1] << "\n";
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
