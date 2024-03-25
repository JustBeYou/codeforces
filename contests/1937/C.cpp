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

const uint nmax = 1e5;

uint query_max(uint i, uint j)
{
  cout << "? " << i << " " << i << " " << j << " " << j << "\n";
  cout.flush();

  char sgn;
  cin >> sgn;
  return sgn == '>' ? i : j;
}

uint query_min(uint i, uint j)
{
  cout << "? " << i << " " << i << " " << j << " " << j << "\n";
  cout.flush();

  char sgn;
  cin >> sgn;
  return sgn == '<' ? i : j;
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n;
    cin >> n;

    uint max_i = 0;
    for (uint i = 1; i < n; i++)
    {
      max_i = query_max(max_i, i);
    }

    uint max2_i = 0;
    for (uint i = 1; i < n; i++)
    {
      if (max_i == i)
        continue;

      cout << "? " << max_i << " " << max2_i << " " << max_i << " " << i << "\n";
      cout.flush();

      char sgn;
      cin >> sgn;

      if (sgn == '<')
      {
        max2_i = i;
      }
      else if (sgn == '=')
      {
        max2_i = query_min(max2_i, i);
      }
    }

    cout << "! " << max_i << " " << max2_i << "\n";
    cout.flush();
  }

  return 0;
}

void prep()
{
#ifdef DEBUG
  // freopen("input", "r", stdin);
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
