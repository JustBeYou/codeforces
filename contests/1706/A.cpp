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

const int nmax = 51;

int main()
{
  prep();

  int t;
  cin >> t;

  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<char> s(m, 'B');

    for (int i = 0; i < n; i++)
    {
      int ai;
      cin >> ai;
      ai--;

      int pos = min(ai, m - ai - 1);

      if (s[pos] == 'B')
        s[pos] = 'A';
      else
        s[m - pos - 1] = 'A';
    }

    printvector(s);
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
    cout << v[i];
  }
  cout << "\n";
}

template <typename T>
void readarray(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
  {
    cin >> v[i];
    v[i]--;
  }
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
    cout << v[i];
  }
  cout << endl;
}
