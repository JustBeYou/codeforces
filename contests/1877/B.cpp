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

const uint nmax = 1e5 + 10;

pair<ull, ull> ba[nmax];

int main()
{
  prep();

  uint n;
  int t;
  cin >> t;
  while (t--)
  {
    ull p;
    cin >> n >> p;

    for (uint i = 0; i < n; i++)
    {
      cin >> ba[i].second;
    }
    for (uint i = 0; i < n; i++)
    {
      cin >> ba[i].first;
    }

    sort(ba, ba + n);

    ull cost = p;
    ull r = 1;
    for (uint i = 0; i < n && r < n; i++)
    {
      if (ba[i].first >= p)
      {
        break;
      }

      if (i >= r)
      {
        cost += p;
        r++;
      }

      if (ba[i].second + r >= n)
      {
        cost += (n - r) * ba[i].first;
        r = n;
      }
      else
      {
        cost += ba[i].first * ba[i].second;
        r += ba[i].second;
      }
    }

    if (r < n)
    {
      cost += p * (n - r);
    }

    cout << cost << "\n";
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
