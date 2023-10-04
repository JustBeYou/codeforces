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

const uint nmax = 2e5 + 100;
uint l[nmax], r[nmax], x[nmax];
vector<uint> pos[nmax];

void updateRange(vector<int> &count, uint i, uint j)
{
  count[i]++;
  if (j + 1 < count.size())
    count[j + 1]--;
}

void finaliseCountArray(vector<int> &count)
{
  for (uint i = 1; i < count.size(); i++)
    count[i] += count[i - 1];
}

string reverseForAll(string S, vector<pair<int, int>> ops)
{
  int N = S.length();
  vector<int> count(N, 0);
  for (auto &e : ops)
  {
    updateRange(count, e.first, e.second);
  }
  finaliseCountArray(count);
  string temp;
  for (int i = count.size() - 1; i >= 0; i--)
  {
    if (count[i] % 2 != 0)
      temp.push_back(S[i]);
  }
  uint i = 0, j = 0;
  for (i = 0; i < count.size(); i++)
  {
    if (count[i] % 2 != 0)
      S[i] = temp[j++];
  }

  return S;
}

int main()
{
  prep();

  int t;
  string s;
  cin >> t;
  while (t--)
  {
    uint n, k, q;
    cin >> n >> k >> s;
    read_array(l, k);
    read_array(r, k);
    cin >> q;
    read_array(x, q);
    for (uint i = 0; i < k; i++)
    {
      pos[i].clear();
    }

    for (uint j = 0; j < q; j++)
    {
      int i_l = 0, i_r = k - 1;
      uint i = k + 1;
      while (i_l <= i_r)
      {
        int i_m = (i_r + i_l) / 2;

        if (l[i_m] <= x[j] && x[j] <= r[i_m])
        {
          i = i_m;
          break;
        }
        else if (x[j] <= l[i_m])
        {
          i_r = i_m - 1;
        }
        else
        {
          i_l = i_m + 1;
        }
      }

      assert(i < k + 1);
      pos[i].push_back(x[j]);
    }

    for (uint i = 0; i < k; i++)
    {
      // sort(pos[i].begin(), pos[i].end());
      vector<pair<int, int>> ops;

      for (auto xj : pos[i])
      {
        uint a = min(xj, r[i] + l[i] - xj) - l[i];
        uint b = max(xj, r[i] + l[i] - xj) - l[i];
        ops.push_back({a, b});
        // cout << a << " " << b << "\n";
      }

      auto res = reverseForAll(s.substr(l[i] - 1, r[i] - l[i] + 1), ops);
      cout << res;
      // cout << "###\n";
    }
    cout << "\n";
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
