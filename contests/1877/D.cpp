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

const uint nmax = 1e5 + 5;
const ull MOD = 998244353;

ull mx[nmax];
ull pow2[nmax];
ull a[nmax];

void calc_mx(uint n)
{

  for (uint i = 1; i <= n; i++)
  {
    for (uint j = i; j <= n; j += i)
    {
      // if i is black, then it's max is the max over all its multiples
      mx[i] = max(mx[i], a[j]);
    }
  }
}

void calc_pow2(uint n)
{
  pow2[0] = 1;
  pow2[1] = 2;
  for (uint i = 2; i <= n + 1; i++)
  {
    pow2[i] = (pow2[i - 1] * 2ULL) % MOD;
  }
}

int main()
{
  prep();

  uint n;
  read_array_and_size(a + 1, n);

  calc_mx(n);
  calc_pow2(n + 1);

  ull sol = 0;
  sort(mx + 1, mx + n + 1);
  for (uint i = 1; i <= n; i++)
  {
    sol += (pow2[i - 1] * mx[i]) % MOD;
    sol %= MOD;
  }
  cout << sol << "\n";

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
