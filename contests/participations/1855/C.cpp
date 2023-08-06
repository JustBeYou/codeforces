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

const int nmax = 20 + 1;

int a[nmax];
int b[nmax];

void solve_pos(vector<pair<int, int>> &sol, int c[], int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (c[i] < c[i - 1])
    {
      sol.push_back({i, i - 1});
      c[i] += c[i - 1];
    }
  }
}

void solve_neg(vector<pair<int, int>> &sol, int c[], int n)
{
  for (int i = n - 1; i >= 1; i--)
  {
    if (c[i] > c[i + 1])
    {
      sol.push_back({i, i + 1});
      c[i] += c[i + 1];
    }
  }
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int max_val = 0, max_i = 0;
    int min_val = 0, min_i = 0;

    for (int i = 1; i <= n; i++)
    {
      int x;
      cin >> x;
      a[i] = b[i] = x;

      if (x < min_val)
      {
        min_val = x;
        min_i = i;
      }
      else if (x > max_val)
      {
        max_val = x;
        max_i = i;
      }
    }

    vector<pair<int, int>> sol;
    if (n == 1)
    {
      // nothing to do
    }
    else if (max_val == 0)
    {
      // all negative
      solve_neg(sol, a, n);
      printarray(a + 1, n);
    }
    else if (min_val == 0)
    {
      // all positive
      solve_pos(sol, b, n);
      printarray(b + 1, n);
    }
    else
    {
      // mixed

      // simulate all positive
      vector<pair<int, int>> pos_sol;
      while (abs(a[max_i]) < abs(a[min_i]))
      {
        pos_sol.push_back({max_i, max_i});
        a[max_i] += a[max_i];
      }

      for (int i = 1; i <= n; i++)
      {
        if (a[i] < 0)
        {
          pos_sol.push_back({i, max_i});
          a[i] += a[max_i];
        }
      }

      solve_pos(pos_sol, a, n);

      // simulate all negative
      vector<pair<int, int>> neg_sol;
      while (abs(b[min_i]) < abs(b[max_i]))
      {
        neg_sol.push_back({min_i, min_i});
        b[min_i] += b[min_i];
      }

      for (int i = 1; i <= n; i++)
      {
        if (b[i] > 0)
        {
          b[i] += b[min_i];
          neg_sol.push_back({i, min_i});
        }
      }

      solve_neg(neg_sol, b, n);

      if (pos_sol.size() < neg_sol.size())
      {
        sol = pos_sol;
        printarray(a + 1, n);
      }
      else
      {
        sol = neg_sol;
        printarray(b + 1, n);
      }
    }

    cout << sol.size() << "\n";
    for (auto p : sol)
    {
      cout << p.first << " " << p.second << "\n";
    }
    // cout << "\n";
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
  // for (uint i = 0; i < n; i++)
  // {
  //   cout << v[i] << " ";
  // }
  // cout << endl;
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
