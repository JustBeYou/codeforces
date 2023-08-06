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

const uint nmax = 101;

bool marked[nmax];
int last[nmax], sol[nmax];

int main()
{
  prep();

  uint n, k, x;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> k >> x;

    for (uint i = 0; i < nmax; i++)
    {
      marked[i] = false;
      last[i] = 0;
    }

    for (uint i = 1; i <= k; i++)
    {
      if (i == x)
      {
        continue;
      }
      marked[i] = true;
    }

    for (uint i = 0; i < nmax; i++)
    {
      for (uint j = 1; j <= k; j++)
      {
        if (j == x)
        {
          continue;
        }

        for (uint l = 1; l <= n && l + j <= n; l++)
        {
          if (marked[l])
          {
            marked[l + j] = true;
            last[l + j] = l;
          }
        }
      }
    }

    if (marked[n])
    {
      cout << "YES\n";
      uint m = 0;
      while (last[n] != 0)
      {
        sol[m++] = n - last[n];
        n = last[n];
      }
      sol[m++] = n;
      cout << m << "\n";
      print_array(sol, m);
    }
    else
    {
      cout << "NO\n";
    }
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
