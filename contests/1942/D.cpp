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
const uint kmax = 5 * 1e3 + 5;

ll a[nmax][nmax];
ll col_max[nmax][nmax];
vector<ll> dp[nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n, k;
    cin >> n >> k;
    for (uint i = 0; i < n; i++)
    {
      dp[i].clear();
      memset(col_max[i], 0, sizeof(ll) * (n + 1));
    }

    for (uint i = 0; i < n; i++)
    {
      for (uint j = i; j < n; j++)
      {
        cin >> a[i][j];
        col_max[j][i] = a[i][j];
      }
    }

    for (uint i = 0; i < n; i++)
    {
      print_array(col_max[i], i);
    }

    for (uint i = 0; i < n; i++)
    {
      // sort(col_max[i], col_max[i] + n - i, greater<ll>());
      // print_array(col_max[i], n);
    }

    dp[0].push_back(max(0LL, a[0][0]));
    dp[1].push_back(dp[0][0]);
    dp[1].push_back(col_max[1][0]);
    dp[1].push_back(col_max[1][1]);
    sort(dp[1].begin(), dp[1].end(), greater<ll>());
    dp[1].pop_back();

    for (uint i = 0; i < n; i++)
    {
      uint l = i > 15 ? k : min(k, 1U << i);
      for (uint j = 0; j < k; j++)
      {
        /**
         * dp[i] = max(
          max(dp[i - 1], dp[i - 2] + a[i][i]),
          col_max[i]);
        */
      }

      print_vector(dp[i]);
    }

    cout << "===\n";
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
