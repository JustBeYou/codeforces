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

uint sieve[nmax];
ull pow2[nmax];
pair<uint, uint> ai[nmax];
ull g[nmax];

void calc_sieve(uint n)
{
  sieve[0] = sieve[1] = 1;

  for (uint i = 2; i <= n; i++)
  {
    if (sieve[i])
      continue;

    sieve[i] = i;

    for (uint j = 2 * i; j <= n; j += i)
    {
      sieve[j] = sieve[j] == 0 ? i : min(sieve[i], sieve[j]);
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
  cin >> n;
  for (uint i = 1; i <= n; i++)
  {
    uint x;
    cin >> x;
    ai[i] = {x, i};
  }

  calc_sieve(n + 2);
  calc_pow2(n + 2);

  ai[0] = {nmax * 2, nmax * 2};
  sort(ai + 1, ai + n + 1);

  ull sol = 0;

  set<ull> uniq_w;
  set<uint> bad_indices;

  for (uint i = n; i > 0; i--)
  {
    ull w = ai[i].first;

    g[w] += pow2[n - bad_indices.size()] - 1ULL;
    g[w] %= MOD;

    uniq_w.insert(w);

    if (i == n)
    {
      bad_indices.insert(1);
    }

    bool should_repeat;
    do
    {
      should_repeat = false;

      uint idx = ai[i].second;
      while (idx > 1)
      {
        bad_indices.insert(sieve[idx]);
        bad_indices.insert(idx);
        idx /= sieve[idx];
      }

      if (ai[i - 1].first == w)
      {
        should_repeat = true;
        i--;
      }
    } while (should_repeat && i > 0);
  }

  ull last_gw = 0;
  for (ull w : uniq_w)
  {
    ull fw = (g[w] + (MOD - last_gw)) % MOD;
    sol += (fw * w) % MOD;
    sol %= MOD;

    last_gw = g[w];
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
