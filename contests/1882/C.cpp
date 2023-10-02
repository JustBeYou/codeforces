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
ll v[nmax];

int main()
{
  prep();

  uint n;
  int t;
  cin >> t;
  while (t--)
  {
    read_array_and_size(v, n);

    int first_good = n;
    for (uint i = 0; i < n; i++)
    {
      if (i % 2 == 0 && v[i] > 0)
      {
        first_good = i;
        break;
      }
    }
    // cout << "fst " << first_good << endl;

    ll sol = 0;
    for (uint i = first_good; i < n; i++)
    {
      if (v[i] > 0)
        sol += v[i];
    }

    ll best_right = 0;
    ll right_sum = 0;
    for (int i = first_good - 1; i >= 0; i--)
    {
      // cout << "i: " << i << " "
      //      << "rs = " << right_sum << endl;

      if (i % 2 == 0)
      {
        if (v[i] + right_sum > best_right)
        {
          best_right = v[i] + right_sum;
        }
      }
      else
      {
        if (right_sum > best_right)
        {
          best_right = right_sum;
        }
        if (v[i] > 0)
          right_sum += v[i];
      }
    }

    cout << sol + best_right << "\n";
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