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

const int nmax = 50;
int w[nmax];
bool used[nmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    readarray(w, n);

    int best = 0;
    for (int s = 1; s <= 2 * n; s++)
    {
      int curr_sol = 0;
      memset(used, 0, sizeof(bool) * n);

      for (int i = 0; i < n; i++)
      {
        if (used[i])
          continue;

        for (int j = i + 1; j < n; j++)
        {
          if (used[j])
            continue;

          if (w[i] + w[j] == s)
          {
            // cout << w[i] << " + " << w[j] << " = " << s << endl;
            curr_sol++;
            used[i] = used[j] = true;
            break;
          }
        }

        // printarray(used, n);
      }

      best = max(best, curr_sol);
      // cout << curr_sol << " " << best << endl;
      // cout << "------------------------\n";
    }

    cout << best << "\n";
    // cout << "================\n";
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
