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
string s;
uint n, q;

ull f(ull sz)
{
  return sz * (sz + 1) / 2 - 1;
}

struct
{
  char ch['z' - 'a' + 1];
} seen_left[nmax], seen_right[nmax];

uint query(uint l, uint r)
{
  uint s = 0;
  for (char ch = 'a'; ch <= 'z'; ch++)
  {
    s += seen_left[r].ch[ch - 'a'] && seen_right[l].ch[ch - 'a'];
  }
  return s;
}

vector<int> manacher_odd(string s)
{
  int n = s.size();
  s = "$" + s + "^";
  vector<int> p(n + 2);
  int l = 1, r = 1;
  for (int i = 1; i <= n; i++)
  {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while (s[i - p[i]] == s[i + p[i]])
    {
      p[i]++;
    }
    if (i + p[i] > r)
    {
      l = i - p[i], r = i + p[i];
    }
  }
  return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s)
{
  string t;
  for (auto c : s)
  {
    t += string("#") + c;
  }
  auto res = manacher_odd(t + "#");
  return vector<int>(begin(res) + 1, end(res) - 1);
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> q;
    cin >> s;

    for (uint i = 0; i < n; i++)
    {
      for (char ch = 'a'; ch <= 'z'; ch++)
      {
        seen_left[i].ch[ch - 'a'] = seen_right[i].ch[ch - 'a'] = false;
      }
    }

    for (uint i = 0; i < n; i++)
    {
      seen_left[i].ch[s[i] - 'a'] = true;

      if (i > 0)
      {
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          seen_left[i].ch[ch - 'a'] |= seen_left[i - 1].ch[ch - 'a'];
        }
      }
    }
    for (int i = n - 1; i >= 0; i--)
    {
      seen_right[i].ch[s[i] - 'a'] = true;

      if (i < n - 1)
      {
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          seen_right[i].ch[ch - 'a'] |= seen_right[i + 1].ch[ch - 'a'];
        }
      }
    }

    auto palin = manacher(s);

    for (uint i = 0; i < q; i++)
    {
      uint l, r;
      cin >> l >> r;
      uint c = query(l - 1, r - 1);
      if (c != 1)
      {
        uint sz = r - l + 1;
        if (palin[l + r - 2] - 1 >= (r - l + 1))
        {
          sz--;
        }
        cout << f(sz) << "\n";
      }
      else
      {
        cout << 0 << "\n";
      }
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
