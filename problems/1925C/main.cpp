#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

template <typename T>
void print_array(const T v[], uint n);
template <typename T>
void print_vector(const vector<T> &v, uint n = 0);
template <typename T>
void read_array(T v[], uint n);
template <typename T>
void read_array_and_size(T v[], uint &n);
template <typename T>
void read_vector(vector<T> &v, uint n = 0);
template <typename T>
void read_vector_and_size(vector<T> &v, uint &n);
void prep();

const uint nmax = 1e5;
const uint kmax = 26;

uint n, k, m;
string s;

bool dp[kmax][kmax];
bool f[kmax];

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {

    cin >> n >> k >> m >> s;
    memset(dp, false, sizeof(bool) * kmax * kmax);

    if (n > m)
    {
      cout << "NO\n"
           << string(n, 'a') << "\n";
      continue;
    }

    for (uint i = 0; i < m; i++)
    {
      dp[0][s[i] - 'a'] = true;
    }

    for (uint i = 1; i < n; i++)
    {

      for (uchar c = 'a'; c < 'a' + k; c++)
      {
        memset(f, false, sizeof(bool) * kmax);
        uint g = 0;

        for (uint j = 0; j < m; j++)
        {
          if (g == k)
          {
            dp[i][c - 'a'] = true;
            break;
          }

          if (!f[s[j] - 'a'] && (uint)(s[j] - 'a') < k)
          {
            f[s[j] - 'a'] = true;
            g++;
          }
        }
      }
    }

    string b(n, 'a');
    bool sol = true;

    for (uint i = 0; i < n; i++)
    {
      for (uint j = 0; j < k; j++)
      {
        cout << dp[i][j] << " ";
        if (!dp[i][j])
        {
          b[i] = j + 'a';
          sol = false;

          // i = n;
          // j = k;
        }
      }
      cout << endl;
    }

    cout << (sol ? "YES\n" : "NO\n" + b + "\n");
  }

  return 0;
}

void prep()
{
#ifdef DEBUG
  freopen("input", "r", stdin);
#else
  ios::sync_with_stdio(false);
  cin.tie(NULL);
#endif
}

template <typename T>
void print_array(const T v[], uint n)
{
  for (uint i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << "\n";
}

template <typename T>
void read_array(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
    cin >> v[i];
}

template <typename T>
void read_array_and_size(T v[], uint &n)
{
  cin >> n;
  for (uint i = 0; i < n; i++)
    cin >> v[i];
}

template <typename T>
void read_vector(vector<T> &v, uint n)
{
  n = n == 0 ? v.size() : n;
  if (n > v.size())
  {
    v.resize(n);
  }
  for (uint i = 0; i < n; i++)
  {
    cin >> v[i];
  }
}

template <typename T>
void read_vector_and_size(vector<T> &v, uint &n)
{
  cin >> n;
  if (n > v.size())
  {
    v.resize(n);
  }
  for (uint i = 0; i < n; i++)
  {
    cin >> v[i];
  }
}

template <typename T>
void print_vector(const vector<T> &v, uint n)
{
  n = n == 0 ? v.size() : n;
  for (uint i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << "\n";
}
