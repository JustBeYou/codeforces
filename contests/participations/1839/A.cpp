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

const int nmax = 105;
int a[nmax];
int b[nmax];
int c[nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;

    if (k == 1)
    {
      cout << n << "\n";
    }
    else if ((n - 1) % k == 0)
    {
      cout << (n - 1) / k + 1 << "\n";
    }
    else
    {
      cout << (n - 1) / k + 2 << "\n";
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
void printarray(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

template <typename T>
void readarray(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
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
