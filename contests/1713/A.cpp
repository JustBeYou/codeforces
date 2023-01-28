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

<<<<<<< HEAD
=======
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int min_x = 0;
    int max_x = 0;
    int min_y = 0;
    int max_y = 0;

    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;

      min_x = min(x, min_x);
      max_x = max(x, max_x);
      min_y = min(y, min_y);
      max_y = max(y, max_y);
    }

    int sol = abs(min_x) + abs(max_x) + abs(min_y) + abs(max_y);
    sol *= 2;
    cout << sol << "\n";
  }

>>>>>>> a61c704 (problems)
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
