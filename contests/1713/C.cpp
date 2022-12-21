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
vector<int> squares;
int sol[nmax];

int get_square(int n, int margin)
{
  int found = -1;
  for (auto square : squares)
  {
    if (square - n >= 0 and square - n <= margin)
    {
      found = square;
    }
  }
  assert(found != -1);
  return found;
}

int main()
{
  prep();
  for (int i = 0; i * i < 2 * nmax + 1; i++)
  {
    squares.push_back(i * i);
  }

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int k = n - 1;
    int margin = k;

    while (k >= 0 && margin >= 0)
    {
      int square = get_square(k, margin);
      int pos = square - k;
      for (int i = pos; i <= margin; i++)
      {
        sol[i] = square - i;
      }

      k = k - (margin - pos + 1);
      margin = pos - 1;
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
