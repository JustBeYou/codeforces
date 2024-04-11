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

ull abs_dif(ull a, ull b)
{
  return a > b ? a - b : b - a;
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    ull a, b, r;
    cin >> a >> b >> r;

    if (a == b || r == 0)
    {
      cout << abs_dif(a, b) << "\n";
      continue;
    }

    if (a < b)
    {
      swap(a, b);
    }

    int hb = -1;
    for (int i = 63; i >= 0; i--)
    {
      if ((r >> i) & 1ULL)
      {
        hb = i;
        break;
      }
    }
    assert(hb != -1);

    bool allow_any = false;
    for (int i = hb; i >= 0; i--)
    {
      // cout << "!! " << i << endl;
      if (!allow_any && !((r >> i) & 1ULL))
      {
        allow_any |= ((r >> i) & 1ULL);
        // cout << "A\n";
        continue;
      }

      if (!((a >> i) & 1ULL) || ((b >> i) & 1ULL))
      {
        allow_any |= ((r >> i) & 1ULL);
        // cout << "B\n";
        continue;
      }

      if (abs_dif(a ^ (1ULL << i), (b ^ (1ULL << i))) < abs_dif(a, b))
      {
        // cout << "! " << i << endl;
        a ^= 1ULL << i;
        b ^= 1ULL << i;
      }
      else
      {
        allow_any |= ((r >> i) & 1ULL);
      }

      if (b > a)
      {
        swap(a, b);
      }
    }

    // cout << q << endl;
    // cout << "! " << r << " " << hb << endl;
    cout << abs_dif(a, b) << "\n";
    // cout << "===\n";
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
