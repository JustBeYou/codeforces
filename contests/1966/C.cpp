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

const uint nmax = 2e5;
set<uint> s;
uint a[nmax];

int main()
{
  prep();

  uint n;
  int t;
  cin >> t;
  while (t--)
  {
    s.clear();
    cin >> n;
    for (uint i = 0; i < n; i++)
    {
      uint x;
      cin >> x;
      s.insert(x);
    }

    if (n == 1 || s.size() == 1)
    {
      cout << "Alice\n";
      continue;
    }

    n = s.size();
    auto it = s.begin();
    for (uint i = 0; i < n; i++)
    {
      a[i] = *it;
      it++;
    }

    uint cl = 1;

    for (uint i = 1; i < n; i++)
    {
      if (a[i] == a[i - 1] + 1)
      {
        cl++;
      }
      else
      {
        break;
      }
    }

    if (cl == 1)
    {
      if (a[0] != 1)
      {
        cout << "Alice\n";
      }
      else
      {
        cout << "Bob\n";
      }
    }
    else
    {
      if (cl % 2 == 0 && a[0] == 1 && cl == n)
      {
        cout << "Bob\n";
      }
      else
      {
        cout << "Alice\n";
      }
    }
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
