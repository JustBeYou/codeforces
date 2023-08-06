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

const int nmax = 2e5 + 5;

pair<ull, ull> v[nmax];

int main()
{
  prep();
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      cin >> v[i].first >> v[i].second;
      v[i].second = -v[i].second;
    }

    sort(v, v + n);

    ull x = 0;
    ull sol = 0;
    ull maxx = 0;

    map<ull, ull> f;

    for (int i = 0; i < n; i++)
    {
      v[i].second = -v[i].second;
      //      cout << v[i].first << " " << v[i].second << endl;

      auto cpx = x;
      x -= f[x];
      f[cpx] = 0;

      if (v[i].first > x and v[i].first > maxx)
      {
        sol += v[i].second;
        f[v[i].first]++;
        x++;
        maxx = max(x, maxx);
      }
    }

    cout << sol << "\n";
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
