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

vector<uint> build_mex_array(const vector<uint> &a)
{
  vector<uint> mex_array(a.size());
  bitset<nmax + 1> seen;
  uint last_mex = 0;

  for (uint i = 0; i < a.size(); i++)
  {
    seen[a[i]] = true;
    while (seen[last_mex])
    {
      last_mex++;
    }
    mex_array[i] = last_mex;
  }

  return mex_array;
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    uint n;
    cin >> n;
    vector<uint> a(n);
    read_vector(a, n);

    auto mex_array_left = build_mex_array(a);

    reverse(a.begin(), a.end());
    auto mex_array_right = build_mex_array(a);
    reverse(mex_array_right.begin(), mex_array_right.end());

    int solution = -1;
    for (uint i = 0; i < a.size() - 1; i++)
    {
      if (mex_array_left[i] == mex_array_right[i + 1])
      {
        solution = i;
        break;
      }
    }

    if (solution == -1)
    {
      cout << -1 << "\n";
    }
    else
    {
      cout << 2 << "\n";
      cout << 1 << " " << solution + 1 << "\n";
      cout << solution + 2 << " " << n << "\n";
    }
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
