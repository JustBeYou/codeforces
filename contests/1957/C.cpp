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

const uint nmax = 3e5;
const ull MOD = 1e9 + 7;
ull fact[nmax];

ull modinv(ull x)
{
  return x == 1 ? 1 : MOD - MOD / x * modinv(MOD % x) % MOD;
}

ull comb(ull n, ull k)
{
  if (k == 0 || k == n)
    return 1;

  ull r = fact[n] * modinv(fact[k]);
  r %= MOD;
  r = r * modinv(fact[n - k]);
  r %= MOD;
  return r;
}

void calc()
{
  fact[0] = 1;
  fact[1] = 1;

  for (ull i = 2; i < nmax; i++)
  {
    fact[i] = i * fact[i - 1];
    fact[i] %= MOD;
  }
}

int main()
{
  prep();
  calc();

  int t;
  cin >> t;
  while (t--)
  {
    ull n, k;
    cin >> n >> k;
    for (ull i = 0; i < k; i++)
    {
      ull r, c;
      cin >> r >> c;

      if (r == c)
      {
        n--;
      }
      else
      {
        n -= 2;
      }
    }

    if (n == 1)
    {
      cout << "1\n";
      continue;
    }

    ull sol = 0;
    for (ull a = 0; 2ULL * a <= n; a++)
    {
      ull b = n - 2ULL * a;

      ull csol = (((a > 0 ? fact[2 * a] : 1) % MOD) * comb(n, b)) % MOD;
      sol += csol;
      sol %= MOD;

      assert(2 * a + b == n);
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
