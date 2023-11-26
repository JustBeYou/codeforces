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

char v[17][17];
char h[17][17];

int main()
{
  prep();

  for (uint i = 1; i <= 16; i++)
  {
    for (uint j = 1; j <= 16; j++)
    {
      v[i][j] = h[i][j] = 'R';
    }
  }
  v[1][1] = v[1][2] = 'B';

  int t;
  cin >> t;
  while (t--)
  {
    uint n, m, k;
    cin >> n >> m >> k;

    if (m + n - 2 > k || (k - n - m) % 2 != 0)
    {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    for (uint i = 1; i <= m - 1; i++)
    {
      h[1][i] = i % 2 == 0 ? 'B' : 'R';
    }
    for (uint i = 1; i <= n - 1; i++)
    {
      v[i][m] = (m - 1 + i) % 2 == 0 ? 'B' : 'R';
    }
    h[n - 1][m - 1] = h[n][m - 1] = v[n - 1][m];
    v[n][m - 1] = v[n - 1][m] == 'B' ? 'R' : 'B';

    for (uint i = 1; i <= n; i++)
    {
      print_array(h[i] + 1, m - 1);
    }

    for (uint i = 1; i <= n - 1; i++)
    {
      print_array(v[i] + 1, m);
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
