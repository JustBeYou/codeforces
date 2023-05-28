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

const int nmax = 101;

int p[nmax][nmax];
int freq[nmax];
int sol[nmax];

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
      for (int j = 0; j < n - 1; j++)
      {
        cin >> p[i][j];
      }
    }

    memset(freq, 0, sizeof(int) * nmax);

    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
      int x = p[i][0];
      freq[x]++;
      if (!a)
      {
        a = x;
      }
      else if (!b && a != x)
      {
        b = x;
      }
    }

    sol[0] = freq[a] > freq[b] ? a : b;
    sol[1] = freq[a] > freq[b] ? b : a;

    for (int j = 1; j < n - 1; j++)
    {
      for (int i = 0; i < n; i++)
      {
        int x = p[i][j];
        if (x != sol[j])
        {
          sol[j + 1] = x;
          break;
        }
      }
    }

    printarray(sol, n);
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
