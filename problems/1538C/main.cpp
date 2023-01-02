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

const int nmax = 2 * 1e5;
uint a[nmax];

int argmin(uint x, uint n)
{
  uint left = 0, right = n;
  int found = -1;
  while (left < right)
  {
    uint mid = (left + right) / 2;

    if (a[mid] >= x)
    {
      found = mid;
      right = mid;
    }
    else
    {
      left = mid + 1;
    }
  }

  return found;
}

int argmax(uint x, uint n)
{
  uint left = 0, right = n;
  int found = -1;
  while (left < right)
  {
    uint mid = (left + right) / 2;

    if (a[mid] <= x)
    {
      found = mid;
      left = mid + 1;
    }
    else
    {
      right = mid;
    }
  }
  return found;
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n, l, r;
    cin >> n >> l >> r;
    for (uint i = 0; i < n; i++)
      cin >> a[i];

    sort(a, a + n);

    ull solution = 0;
    for (uint i = 0; i < n; i++)
    {
      if (a[i] > r)
        continue;

      int k = argmin(l < a[i] ? 0 : l - a[i], n);
      int q = argmax(r - a[i], n);

      if (k == -1 || q == -1 || k > q)
        continue;

      solution += q - k + 1;
      if (a[k] <= a[i] && a[i] <= a[q])
      {
        solution -= 1;
      }
    }

    cout << solution / 2 << "\n";
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
