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

const uint nmax = 1e5 + 50;
uint a[nmax];
const uint invalid = nmax * 2;

uint sxy[nmax];
uint exy[nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n, k;
    cin >> n >> k;
    read_array(a, n);
    for (uint i = 1; i <= k + 1; i++)
    {
      sxy[i] = exy[i] = invalid;
    }

    for (uint i = 0; i < n; i++)
    {
      if (sxy[a[i]] == invalid)
        sxy[a[i]] = i;
      exy[a[i]] = i;
    }

    uint maxi = invalid;
    for (uint i = k; i > 0; i--)
    {
      if (sxy[i] == invalid)
        continue;

      if (maxi == invalid)
        maxi = exy[i];

      sxy[i] = min(sxy[i], sxy[i + 1]);
      maxi = max(maxi, exy[i]);
    }

    for (uint i = 1; i <= k; i++)
    {
      if (sxy[i] == invalid)
        cout << "0 ";
      else
      {
        cout << (exy[i] - sxy[i] + 1) * 2 << " ";
      }
    }
    cout << "\n";
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
