#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

template <typename T>
void printarray(T v[], uint n);
template <typename T>
void printvector(vector<T> v);
template <typename T>
void readarray(T v[], uint n);
template <typename T>
void readszandarray(T v[], uint &n);
void prep();

const int nmax = 2 * 1e5 + 1;
<<<<<<< HEAD
uint h[nmax];
=======
ull h[nmax];
>>>>>>> a61c704 (problems)

int main()
{
  prep();
<<<<<<< HEAD

=======
>>>>>>> a61c704 (problems)
  int t;
  cin >> t;
  while (t--)
  {
    uint n;
    readszandarray(h, n);
<<<<<<< HEAD
    sort(h, h + n);

    if (n == 2)
    {
      printarray(h, n);
      continue;
    }

    uint min_diff = numeric_limits<uint>::max();
    uint best_i = 0;
    for (uint i = 0; i < n - 1; i++)
    {
      uint diff = h[i + 1] - h[i];
      if (diff < min_diff)
      {
        min_diff = diff;
        best_i = i;
      }
    }

    for (uint i = best_i + 1; i < n; i++)
    {
      cout << h[i] << " ";
    }

    for (uint i = 0; i < best_i + 1; i++)
    {
      cout << h[i] << " ";
    }

    cout << "\n";
=======
    sort(h + 1, h + n + 1);

    ull min_diff = numeric_limits<ull>::max();
    int best_i = 0;
    for (int i = 1; i <= n; i++)
    {
      if (h[i + 1] - h[i] < min_diff)
      {
        best_i = i;
        min_diff = h[i + 1] - h[i];
      }
    }

    if (n == 2)
      printarray(h, n);
    else
    {
      cout << h[best_i] << " ";
      for (int i = best_i + 2; i <= n; i++)
        cout << h[i] << " ";
      for (int i = 1; i < best_i; i++)
        cout << h[i] << " ";
      cout << h[best_i + 1] << " ";
      cout << "\n";
    }
>>>>>>> a61c704 (problems)
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
void printarray(T v[], uint n)
{
<<<<<<< HEAD
  for (uint i = 0; i < n; i++)
=======
  for (uint i = 1; i <= n; i++)
>>>>>>> a61c704 (problems)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

template <typename T>
void readarray(T v[], uint n)
{
<<<<<<< HEAD
  for (uint i = 0; i < n; i++)
=======
  for (uint i = 1; i <= n; i++)
>>>>>>> a61c704 (problems)
    cin >> v[i];
}

template <typename T>
void readszandarray(T v[], uint &n)
{
  cin >> n;
  readarray(v, n);
}

template <typename T>
void printvector(vector<T> v)
{
  for (uint i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
