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

const int nmax = 1e5;
uint a[nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n;
    readszandarray(a, n);

    uint a_min = a[0], i_min = 0;

    for (uint i = 0; i < n; i++)
    {
      if (a[i] < a_min)
      {
        a_min = a[i];
        i_min = i;
      }
    }

    cout << n - 1 << "\n";

    uint x = a_min;
    for (uint j = 0; j < i_min; j++)
    {
      uint y = a_min + i_min - j;
      cout << i_min + 1 << " " << j + 1 << " " << x << " " << y << "\n";
    }

    for (uint j = i_min + 1; j < n; j++)
    {
      uint y = a_min + j - i_min;
      cout << i_min + 1 << " " << j + 1 << " " << x << " " << y << "\n";
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
