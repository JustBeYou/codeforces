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
int n, m;

int query(int x, int y)
{
  if (x < 1 || x > n || y < 1 || y > m)
  {
    return -1;
  }
  cout << "? " << x << " " << y << "\n";
  cout.flush();
  int d;
  cin >> d;
  return d;
}

void sol(int x, int y)
{
  cout << "! " << x << " " << y << "\n";
  cout.flush();
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;

    int d1 = query(1, 1);
    int d2 = query(n, m);
    int d3 = query(1, m);

    int y1 = (d1 + m - d3 + 1) / 2;
    int x1 = d1 - y1 + 2;

    int y2 = (d2 + 1 - 2 * m + d3 - n) / (-2);
    int x2 = m + n - d2 - y2;

    int d4 = query(x1, y1);
    if (d4 == 0)
    {
      sol(x1, y1);
    }
    else
    {
      sol(x2, y2);
    }
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
