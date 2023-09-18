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

  string line;
  map<char, uint> big;
  big['A'] = big['B'] = big['C'] = 0;

  for (int i = 0; i < 3; i++)
  {
    cin >> line;
    if (line[1] == '>')
    {
      big[line[0]]++;
    }
    else
    {
      big[line[2]]++;
    }
  }

  int f[4] = {0, 0, 0, 0};
  for (auto e : big)
  {
    f[e.second]++;
  }

  if (f[0] != 1 || f[1] != 1 || f[2] != 1)
  {
    cout << "Impossible\n";
    return 0;
  }

  for (auto e : big)
  {
    if (e.second == 0)
    {
      cout << e.first;
    }
  }

  for (auto e : big)
  {
    if (e.second == 1)
    {
      cout << e.first;
    }
  }

  for (auto e : big)
  {
    if (e.second == 2)
    {
      cout << e.first;
    }
  }

  cout << "\n";

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
