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

bool isPossible(const std::vector<ll> &a, ll k, ll &minX, ll &maxX)
{
  minX = std::numeric_limits<ll>::min();
  maxX = std::numeric_limits<ll>::max();

  for (ll ai : a)
  {
    ll lowerBound = 2 * k - ai;
    ll upperBound = 2 * k - ai + 2;

    minX = max(minX, lowerBound);
    maxX = min(maxX, upperBound - 1);

    if (minX > maxX)
    {
      return false;
    }
  }
  return true;
}

ll findX(const std::vector<ll> &a)
{
  ll minK = std::numeric_limits<ll>::max();
  ll maxK = std::numeric_limits<ll>::min();
  for (auto ai : a)
  {
    minK = min(ai, minK);
    maxK = max(ai, maxK);
  }

  ll result = std::numeric_limits<ll>::min();

  while (minK <= maxK)
  {
    ll k = minK + (maxK - minK) / 2;
    ll minX, maxX;
    if (isPossible(a, k, minX, maxX))
    {
      result = minX;
      break;
    }
    else
    {
      if (minX > 2 * k - a[0])
      {
        minK = k + 1;
      }
      else
      {
        maxK = k - 1;
      }
    }
  }

  return result;
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n;
    cin >> n;
    vector<ll> a(n);
    read_vector(a, n);

    vector<ll> sols;
    bool no_sol = true;
    while (no_sol)
    {
      bool all_same = true;
      for (uint i = 0; i < n - 1; i++)
      {
        if (a[i] != a[i + 1])
        {
          all_same = false;
        }
      }

      if (all_same)
      {
        break;
      }

      ll x = findX(a);

      if (x != std::numeric_limits<ll>::min())
      {
        sols.push_back(x);
        no_sol = false;
      }
      else
      {
        for (auto &ai : a)
        {
          ai /= 2;
        }
        sols.push_back(0);
      }
    }

    cout << sols.size() << "\n";
    if (sols.size() > 0 && sols.size() <= n)
    {
      print_vector(sols);
    }
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
