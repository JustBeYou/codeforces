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

const int nmax = 1e5 + 1;
uint u[nmax], d[nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint m;
    cin >> m;

    uint a;
    for (uint i = 1; i <= m; i++)
    {
      cin >> a;
      u[i] = a + u[i - 1];
    }

    for (uint i = 1; i <= m; i++)
    {
      cin >> a;
      d[i] = a + d[i - 1];
    }

    uint score = 0;
    for (uint q = 1; q <= m; q++)
    {
      uint x = u[m] - u[q];
      uint y = d[q - 1];

      if (score == 0)
      {
        score = max(x, y);
      }
      else
      {
        score = min(score, max(x, y));
      }
    }

    cout << score << "\n";
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
