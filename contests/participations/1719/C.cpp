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
int a[nmax];
vector<int> maxes;

int main()
{
  prep();
  maxes.resize(nmax);

  int t;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;

    int best;

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (a[i] == n)
      {
        best = i;
      }
    }

    maxes[0] = a[0];
    for (int i = 1; i < n; i++)
    {
      maxes[i] = max(maxes[i - 1], a[i]);
    }

    while (q--)
    {
      int i, k;
      cin >> i >> k;
      i--;

      if (i == best)
      {
        if (best <= 1)
        {
          cout << k << "\n";
        }
        else
        {
          cout << max(0, k - (best - 1)) << "\n";
        }
      }
      else if (a[i] < maxes[i])
      {
        cout << "0\n";
      }
      else
      {
        auto left = next(maxes.begin(), i);
        auto right = next(maxes.begin(), n);
        auto found = upper_bound(left, right, a[i]);
        int dist = distance(left, found);

        int sol = 0;
        if (i == 0)
        {
          sol = min(k, dist - 1);
        }
        else if (k >= 1)
        {
          sol = 1 + max(min(k - i, dist - 1), 0);
        }

        cout << sol << "\n";
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
