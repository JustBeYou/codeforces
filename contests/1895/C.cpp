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

const uint nmax = 2e5 + 5;

uint calc(const string &si)
{
  uint x = 0;
  for (auto ch : si)
  {
    x += ch - '0';
  }
  return x;
}

int main()
{
  prep();

  uint n;
  cin >> n;
  vector<string> s(n);
  read_vector(s);

  map<uint, uint> f[6];

  ull sol = n;

  for (auto si : s)
  {
    f[si.size()][calc(si)]++;
    // cout << si << " -> " << si.size() << " " << calc(si) << "\n";
  }

  for (auto si : s)
  {
    // match with self
    sol += f[si.size()][calc(si)] - 1;

    for (uint j = 1; j <= 5; j++)
    {
      uint m = si.size() + j;
      if (m % 2 == 1 || j >= si.size())
      {
        continue;
      }

      // left match
      uint lft = calc(si.substr(si.size() - m / 2)) - calc(si.substr(0, si.size() - m / 2));
      sol += f[j][lft];

      // right match
      uint rgt = calc(si.substr(0, m / 2)) - calc(si.substr(m / 2));
      sol += f[j][rgt];
    }
  }

  cout << sol << "\n";

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
