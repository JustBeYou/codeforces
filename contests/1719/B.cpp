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

int main()
{
  prep();
  int t;
  cin >> t;
  while (t--)
  {
    uint n, k;
    cin >> n >> k;
    k = k % 4;

    if (k == 0)
    {
      cout << "NO\n";
    }
    else if (k == 1 or k == 3)
    {
      cout << "YES\n";
      for (uint i = 1; i <= n; i += 2)
      {
        cout << i << " " << i + 1 << "\n";
      }
    }
    else if (k == 2)
    {
      cout << "YES\n";
      for (uint i = 1; i <= n; i += 4)
      {
        cout << i + 1 << " " << i << "\n";
        if (i + 2 <= n)
        {
          cout << i + 2 << " " << i + 3 << "\n";
        }
      }
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
