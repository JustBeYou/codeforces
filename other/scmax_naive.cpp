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
uint a[nmax];
uint best[nmax];
int before[nmax];
uint solution[nmax];

int find_best_j(uint i)
{
  int best_j = -1;
  uint max_best = 0;

  for (uint j = 0; j < i; j++)
  {
    if (best[j] > max_best && a[j] < a[i])
    {
      max_best = best[j];
      best_j = j;
    }
  }

  return best_j;
}

int main()
{
  prep();

  uint n;
  readszandarray(a, n);

  uint max_best = 0;
  int max_best_i = -1;

  for (uint i = 0; i < n; i++)
  {
    int j = find_best_j(i);

    if (j == -1)
    {
      best[i] = 1;
      before[i] = -1;
    }
    else
    {
      best[i] = 1 + best[j];
      before[i] = j;
    }

    if (best[i] > max_best)
    {
      max_best = best[i];
      max_best_i = i;
    }
  }

  cout << max_best << "\n";
  uint i = max_best - 1;
  while (max_best_i != -1)
  {
    solution[i--] = a[max_best_i];
    max_best_i = before[max_best_i];
  }
  printarray(solution, max_best);

  return 0;
}

void prep()
{
  freopen("scmax.in", "r", stdin);
#ifndef DEBUG
  freopen("scmax.out", "w", stdout);
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
