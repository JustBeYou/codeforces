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

const uint nmax = 1e3;
// char A[nmax][nmax];
char B[nmax][nmax];

uint sol;
void rotate(uint n)
{
  sol = 0;
  for (uint i = 0; i < n / 2; i++)
  {
    for (uint j = i; j < n - i - 1; j++)
    {
      int m = max(max(B[i][j], B[n - 1 - j][i]), max(B[n - 1 - i][n - 1 - j], B[j][n - 1 - i]));

      sol += 4 * m - B[i][j] - B[n - 1 - j][i] - B[n - 1 - i][n - 1 - j] - B[j][n - 1 - i];

      // int temp = B[i][j];
      // B[i][j] = B[n - 1 - j][i];
      // B[n - 1 - j][i] = B[n - 1 - i][n - 1 - j];
      // B[n - 1 - i][n - 1 - j] = B[j][n - 1 - i];
      // B[j][n - 1 - i] = temp;
    }
  }
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
    for (uint i = 0; i < n; i++)
    {
      cin >> B[i];
    }
    // for (uint i = 0; i < n; i++)
    // {
    //   memcpy(B[i], A[i], sizeof(char) * n);
    // }
    rotate(n);

    // for (uint i = 0; i < n; i++)
    // {
    //   for (uint j = 0; j < n; j++)
    //   {
    //     cout << A[i][j];
    //   }
    //   cout << endl;
    // }
    // cout << "\n";
    // for (uint i = 0; i < n; i++)
    // {
    //   for (uint j = 0; j < n; j++)
    //   {
    //     cout << B[i][j];
    //   }
    //   cout << endl;
    // }

    cout << sol << "\n";
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
