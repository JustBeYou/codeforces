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

const uint nmax = 18;
const uint mmax = 5e5;
ull a[nmax];
pair<uint, uint> q[nmax];

void solve(uint st, uint fh)
{
}

int main()
{
  prep();

  uint n;
  read_array_and_size(a, n);

  ull s = 0;
  uint imax = 0;

  for (uint i = 0; i <= (1U << n) - 1U; i++)
  {
    ull csum = 0;
    uint streak = 0;
    for (uint j = 0; j < n; j++)
    {
      uint b = (i >> j) & 1;

      if (b)
      {
        streak++;
      }
      else
      {
        csum += streak * streak;
        csum += a[j];
        streak = 0;
      }
    }
    csum += streak * streak;

    if (csum > s)
    {
      s = csum;
      imax = i;
    }
  }

  uint m = 0;
  uint st = 0;
  uint streak = 0;
  for (uint j = 0; j < n + 1; j++)
  {
    uint b = (imax >> j) & 1;

    if (b)
    {
      streak++;
    }
    else
    {
      if (streak)
      {
        for (uint k = st; k <= j - 1; k++)
        {
          if (a[k] || streak == 1)
            q[m++] = {k, k};
        }

        if (streak > 1)
        {
          solve(st, j - 1);
        }
      }

      st = j + 1;
      streak = 0;
    }
  }

  cout << s << " " << m << "\n";
  for (uint i = 0; i < m; i++)
  {
    cout << q[i].first + 1 << " " << q[i].second + 1 << "\n";
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
