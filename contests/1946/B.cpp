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
ll M = 1e9 + 7;
ll a[nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n;
    ll k;
    cin >> n >> k;
    read_array(a, n);

    ll best = 0;
    ll s = 0;

    for (uint i = 0; i < n; i++)
    {
      s += a[i];
      best = max(s, best);

      if (s < 0)
      {
        s = 0;
      }
    }

    ll sol = 0;
    for (uint i = 0; i < n; i++)
    {
      sol += a[i];
    }

    if (sol < 0)
    {
      sol = M - ((-sol) % M);
    }
    sol %= M;

    // ...X X      k = 1
    // ...X X 2X   k = 2
    // ...X X 2X 4X k = 2
    // (1+...+n) * X = K n

    for (uint i = 1; i <= k; i++)
    {

      sol += best;
      sol %= M;

      best *= 2;
      best %= M;
    }

    cout << sol << "\n";
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
