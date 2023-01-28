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

const ull nmax = 2e5;
ull a[nmax];

int main()
{
  prep();

  ull n, k, x;
  cin >> n >> k >> x;
  readarray(a, n);
  sort(a, a + n);

  uint joints = 0;
  for (uint i = 1; i < n; i++)
  {
    ull dif = a[i] - a[i - 1];
    if (dif > x)
    {
      a[joints++] = dif;
    }
  }

  sort(a, a + joints);

  uint unified = 0;
  for (uint i = 0; i < joints && k; i++)
  {
    ull need = a[i] / x - (a[i] % x == 0);
    if (need <= k)
    {
      unified++;
      k -= need;
    }
  }

  cout << joints - unified + 1 << "\n";

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