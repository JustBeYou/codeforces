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

const uint xmax = 1e9;
const uint nmin = 11;

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint x;
    cin >> x;

    if (x < nmin)
    {
      cout << "NO\n";
      continue;
    }

    bool good = false;

    for (uint a = 0; a <= 11; a++)
    {
      uint s = a * 111;
      if (s > x)
        break;

      for (uint b = 0; b <= 11; b++)
      {
        s += b * 11'111;
        if (s > x)
          break;

        for (uint c = 0; c <= 11; c++)
        {
          s += c * 1'111'111;
          if (s > x)
            break;

          for (uint d = 0; d <= 11; d++)
          {
            s += d * 111'111'111;
            if (s > x)
              break;

            if ((x - s) % 11 == 0)
            {
              good = true;
              a = b = c = d = 20;
            }
          }
        }
      }
    }

    if (good)
      cout << "YES\n";
    else
      cout << "NO\n";
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
