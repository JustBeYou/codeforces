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

const uint nmax = 500;
uint a[nmax][nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n, m;
    cin >> n >> m;

    for (uint i = 0; i < n; i++)
    {
      for (uint j = 0; j < m; j++)
      {
        char x;
        cin >> x;
        a[i][j] = x == 'B';
      }
    }

    if (n == 1 && m == 1)
    {
      cout << "YES\n";
      continue;
    }

    if (n == 1)
    {
      cout << (a[0][0] == a[0][m - 1] ? "YES" : "NO") << "\n";
      continue;
    }

    if (m == 1)
    {
      cout << (a[0][0] == a[n - 1][0] ? "YES" : "NO") << "\n";
      continue;
    }

    if (a[0][0] == a[n - 1][m - 1] || a[0][m - 1] == a[n - 1][0])
    {
      cout << "YES\n";
      continue;
    }

    bool b[4][2] = {{0, 0},
                    {0, 0},
                    {0, 0},
                    {0, 0}};

    b[0][a[0][0]] = true;
    b[1][a[0][m - 1]] = true;
    b[2][a[n - 1][m - 1]] = true;
    b[3][a[n - 1][0]] = true;

    bool c[4][2] = {{0, 0},
                    {0, 0},
                    {0, 0},
                    {0, 0}};

    for (uint j = 0; j < m; j++)
    {
      c[0][a[0][j]] = true;
      c[2][a[n - 1][j]] = true;
    }

    for (uint i = 0; i < n; i++)
    {
      c[1][a[i][m - 1]] = true;
      c[3][a[i][0]] = true;
    }

    for (uint k = 0; k <= 1; k++)
    {
      b[0][k] |= c[0][k] & c[3][k];
      b[1][k] |= c[0][k] & c[1][k];
      b[2][k] |= c[1][k] & c[2][k];
      b[3][k] |= c[2][k] & c[3][k];
    }

    bool sol = false;
    for (uint k = 0; k <= 1; k++)
    {
      sol |= b[0][k] & b[2][k];
      sol |= b[1][k] & b[3][k];
    }

    cout << (sol ? "YES" : "NO") << "\n";
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
