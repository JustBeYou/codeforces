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
void readarray(T v[], ull n);
template <typename T>
void readszandarray(T v[], ull &n);
void prep();

const int nmax = 2 * 1e5 + 1;
ull a[nmax];
map<ull, ull> freq;

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    ull n;
    readszandarray(a, n);

    for (ull i = 0; i < n; i++)
    {
      int rhs = a[i] - (i + 1);
      freq[rhs]++;
    }

    ull sol = 0;
    for (auto it : freq)
    {
      sol += (it.second - 1) * it.second / 2;
    }
    cout << sol << "\n";
    freq.clear();
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
void readarray(T v[], ull n)
{
  for (ull i = 0; i < n; i++)
    cin >> v[i];
}

template <typename T>
void readszandarray(T v[], ull &n)
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
