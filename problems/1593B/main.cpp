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
void prep();

const int nmax = 1e5;

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    ull n;
    cin >> n;

    ull n_i = n;
    int cuts_i = 0;
    int min_cuts = 9999;

    while (n_i > 0)
    {
      ull n_j = n_i / 10;
      int cuts_j = 0;
      while (n_j > 0)
      {
        if ((n_j % 10 * 10 + n_i % 10) % 25 == 0)
        {
          min_cuts = min(min_cuts, cuts_i + cuts_j);
        }

        n_j /= 10;
        cuts_j++;
      }

      n_i /= 10;
      cuts_i++;
    }

    cout << min_cuts << "\n";
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
void printvector(vector<T> v)
{
  for (uint i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
