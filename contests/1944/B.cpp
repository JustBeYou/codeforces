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

const uint nmax = 5e4 + 5;

int a[2 * nmax];
int freq_l[nmax];
int freq_r[nmax];
int l[2 * nmax];
int r[2 * nmax];

int main()
{
  prep();

  uint n, k;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> k;
    read_array(a, 2 * n);
    memset(freq_l, 0, sizeof(int) * (n + 1));
    memset(freq_r, 0, sizeof(int) * (n + 1));
    memset(l, 0, sizeof(int) * (n + 1));
    memset(r, 0, sizeof(int) * (n + 1));

    for (uint i = 0; i < n; i++)
    {
      freq_l[a[i]]++;
      freq_r[a[i + n]]++;
    }

    uint lk = 0, rk = 0;

    for (uint i = 0; i <= n; i++)
    {
      if (freq_l[i] == 2 && lk + 1 < 2 * k)
      {
        l[lk] = l[lk + 1] = i;
        lk += 2;
      }
      else if (freq_r[i] == 2 && rk + 1 < 2 * k)
      {
        r[rk] = r[rk + 1] = i;
        rk += 2;
      }
    }

    for (uint i = 0; i <= n; i++)
    {
      if (freq_l[i] == 1 && lk < 2 * k && rk < 2 * k)
      {
        l[lk] = r[rk] = i;
        lk += 1;
        rk += 1;
      }
    }

    uint lxor = 0, rxor = 0;
    for (uint i = 0; i < 2 * k; i++)
    {
      assert(l[i] != 0 && r[i] != 0);
      lxor ^= l[i];
      rxor ^= r[i];
    }

    print_array(l, 2 * k);
    print_array(r, 2 * k);

    assert(lxor == rxor);
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
