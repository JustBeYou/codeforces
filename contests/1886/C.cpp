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

ll Sk(ll n, ll k)
{
  return n * (n + 1) / 2 - (n - k - 1) * (n - k) / 2;
}

string smallest(string s, int k)
{
  stack<char> st;
  for (auto ch : s)
  {
    while (k > 0 && !st.empty() && st.top() > ch)
    {
      st.pop();
      k--;
    }

    st.push(ch);
  }

  while (k--)
  {
    st.pop();
  }

  string r = "";
  while (!st.empty())
  {
    r += st.top();
    st.pop();
  }

  reverse(r.begin(), r.end());
  return r;
}

int main()
{
  prep();

  int t;

  // n + n - 1 + n - 2 + ... + 1

  // 1 + 2 + ... + n - k - 1 + n - k + ... + n

  // Sk = n * (n + 1) / 2 - (n - k - 1) * (n - k) / 2
  // find k st. Sk >= pos

  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    ll pos;
    cin >> pos;
    ll n = (ll)s.size();

    ll left_k = 0, right_k = n;
    ll k = -1;
    while (left_k <= right_k)
    {
      ll mid_k = (right_k + left_k) / 2;
      ll s = Sk(n, mid_k);

      if (s >= pos)
      {
        k = mid_k;
        right_k = mid_k - 1;
      }
      else
      {
        left_k = mid_k + 1;
      }
    }
    assert(k != -1);

    s = smallest(s, k);

    // cout << s << " " << pos << endl;

    pos -= Sk(n, k - 1);
    pos--;
    cout << s[pos];
  }
  cout << "\n";

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
