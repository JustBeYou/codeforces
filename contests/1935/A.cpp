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

bool smaller(string a, string b)
{
  for (uint i = 0; i < min(a.size(), b.size()); i++)
  {
    if (a[i] < b[i])
      return true;

    if (a[i] > b[i])
      return false;
  }

  return a.size() < b.size();
}

string op2(string s)
{
  reverse(s.begin(), s.end());
  return s;
}

string op1(string s)
{
  return s + op2(s);
}

int main()
{
  prep();

  int n, t;
  string s;

  cin >> t;
  while (t--)
  {
    cin >> n >> s;

    vector<string> x = {
        s,
        op1(op2(s)),
        op2(op1(s)),
        op1(op1(s)),
    };

    if (n > 2)
    {
      for (uint i = 0; i < 4; i++)
      {
        x.push_back(op1(op2(x[i])));
        x.push_back(op2(op1(x[i])));
        x.push_back(op1(op1(x[i])));
      }
    }

    sort(x.begin(), x.end(), smaller);

    cout << x[0] << "\n";
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
