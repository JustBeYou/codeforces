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

const uint nmax = 8 * 1e4;
ull a[nmax];

void brute(uint n)
{
  ull sol = 0;
  for (uint i = 0; i < n; i++)
  {
    for (uint j = i + 1; j < n; j++)
    {
      for (uint k = j + 1; k < n; k++)
      {
        ull abc[] = {a[i], a[j], a[k]};
        sort(abc, abc + 3);

        sol += __gcd(abc[0], abc[1]);
      }
    }
  }

  cout << sol << "\n";
}

void fancy(uint n)
{
  ull sol = 0;

  sort(a, a + n);

  for (uint i = 0; i < n; i++)
  {
    for (uint j = i + 1; j < n; j++)
    {
      sol += __gcd(a[i], a[j]) * (n - j - 1);
    }
  }
  cout << sol << "\n";
}

int main()
{
  prep();

  uint n;
  int t;
  cin >> t;
  while (t--)
  {
    read_array_and_size(a, n);
    fancy(n);
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
