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

int main()
{
  prep();

  uint n, k;
  int t;
  string s;
  cin >> t;
  while (t--)
  {
    cin >> n >> k >> s;

    map<char, uint> f;
    for (auto ch : s)
    {
      f[ch]++;
    }

    n -= k;

    for (auto &it : f)
    {
      if (it.second % 2 == 1 && k)
      {
        it.second--;
        k--;
      }
    }
    for (auto &it : f)
    {
      if (k)
      {
        if (k >= it.second)
        {
          k -= it.second;
          it.second = 0;
        }
        else
        {
          it.second -= k;
          k = 0;
        }
      }
      else
      {
        break;
      }
    }
    assert(k == 0);

    int odd = 0;
    for (auto it : f)
    {
      if (it.second % 2 != 0)
      {
        odd++;
      }
    }

    bool solved = (n % 2 == 0 && odd == 0) || (n % 2 == 1 && odd == 1);
    cout << (solved ? "YES\n" : "NO\n");
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
