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

const uint nmax = 2e5 + 5;
char a[2][nmax];
uint dp[nmax];
char sol[nmax];

enum dir
{
  dir_up = 0,
  dir_left = 1,
  dir_both = 2,
};

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n;
    cin >> n >> a[0] >> a[1];

    dp[0] = dir_both;

    for (uint i = 1; i < n; i++)
    {
      switch (dp[i - 1])
      {
      case dir_left:
        dp[i] = dir_left;
        break;

      case dir_up:
      case dir_both:
        if (a[0][i] == a[1][i - 1])
        {
          dp[i] = dir_both;
        }
        else if (a[0][i] < a[1][i - 1])
        {
          dp[i] = dir_up;
        }
        else
        {
          dp[i] = dir_left;
        }

        break;

      default:
        break;
      }
    }

    sol[n + 1] = 0;
    uint i;
    bool up = false;
    uint sol_cnt = 1;

    for (i = n - 1; i > 0; i--)
    {
      sol[i + 1] = a[1][i];

      if (dp[i] == dir_up)
      {
        up = true;
        sol[i] = a[0][i];
        break;
      }
      else if (dp[i] == dir_both)
      {
        sol_cnt++;
      }
    }

    for (; i > 0; i--)
    {
      sol[i] = a[0][i];
    }

    sol[0] = a[0][0];
    if (!up)
      sol[1] = a[1][0];

    cout << sol << "\n";
    cout << sol_cnt << "\n";
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
