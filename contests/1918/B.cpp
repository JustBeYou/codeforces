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
uint a[nmax];
uint b[nmax];
uint c[nmax];
pair<uint, uint> v[nmax];

ull inversions(uint arr[], uint n)
{
  ull inv = 0;
  for (uint i = 0; i < n; i++)
  {
    for (uint j = i + 1; j < n; j++)
    {
      if (arr[i] > arr[j])
      {
        inv++;
      }
    }
  }

  return inv;
}

int main()
{
  prep();

  uint n;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    read_array(a, n);
    read_array(b, n);

    for (uint i = 0; i < n; i++)
    {
      v[i].first = a[i];
      v[i].second = i;
    }
    sort(v, v + n);
    for (uint i = 0; i < n; i++)
    {
      c[i] = b[v[i].second];
    }

    for (uint i = 0; i < n; i++)
    {
      cout << v[i].first << " ";
    }
    cout << endl;
    print_array(c, n);
    // cout << inversions(c, n) << endl;
    // cout << "===\n";
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
