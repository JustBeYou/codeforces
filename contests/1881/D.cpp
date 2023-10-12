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

const uint nmax = 1e6 + 5;

uint ciur[nmax + 1];

void calc()
{
  ciur[1] = 1;
  for (uint i = 2; i <= nmax; i++)
  {
    if (ciur[i])
      continue;
    else
      ciur[i] = i;

    for (uint j = 2; j <= nmax / i; j++)
    {
      ciur[i * j] = i;
    }
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
    uint n;
    cin >> n;

    uint cant_split = 0;
    map<uint, uint> f;

    for (uint i = 0; i < n; i++)
    {
      uint x;
      cin >> x;

      while (x > 1)
      {
        // cout << x << " " << ciur[x] << endl;
        if (f[ciur[x]] % n == 0)
        {
          cant_split++;
        }
        else if ((f[ciur[x]] + 1) % n == 0)
        {
          cant_split--;
        }

        f[ciur[x]]++;
        x /= ciur[x];
      }
    }

    if (n == 1)
    {
      cout << "YES\n";
      continue;
    }

    cout << (cant_split ? "NO" : "YES") << "\n";
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
