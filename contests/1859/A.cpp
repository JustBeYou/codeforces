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

const uint nmax = 105;
uint a[nmax], b[nmax], c[nmax];

int main()
{
  prep();

  uint n;
  int t;
  cin >> t;
  while (t--)
  {
    read_array_and_size(a, n);

    uint all_same = true;
    uint m = 0, k = 0, largest = 0;
    for (uint i = 0; i < n; i++)
    {
      all_same = all_same && a[0] == a[i];
      largest = max(largest, a[i]);
    }

    if (all_same)
    {
      cout << "-1\n";
      continue;
    }

    for (uint i = 0; i < n; i++)
    {
      if (a[i] == largest)
      {
        m++;
      }
    }

    cout << n - m << " " << m << "\n";
    for (uint i = 0; i < n; i++)
    {
      if (a[i] != largest)
        cout << a[i] << " ";
    }
    cout << "\n";
    for (uint i = 0; i < m; i++)
    {
      cout << largest << " ";
    }
    cout << "\n";
  }

  return 0;
}

void prep()
{
#ifdef DEBUG
  freopen("input", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);
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
