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

const uint nmax = 1e5 + 5;
uint a[nmax];
uint pows[nmax];

int main()
{
  prep();

  uint n;
  int t;
  cin >> t;
  while (t--) { 
    read_array_and_size(a, n);
    memset(pows, 0, sizeof(uint)*n);

    /**
     * if a[i] > a[i + 1] find smallest k st. a[i] <= 2^k * a[i+1]
     *
     * 2^pows[i] * a[i]  ...  2^pows[i + 1] * a[i + 1]
     *
     * a[i] <= a[i + 1] -> 2^pows[i] * a[i] <= 2^pows[i] * a[i + 1] ->
     * 2^pows[i] * a[i] <= 2^k * a[i + 1] ->  a[i] <= 2^(k - pows[i]) * a[i + 1] 
     * k - pows[i] = -q -> k = pows[i] - q

     * a[i] > 2^q * a[i + 1] 
    */

    ull cost = 0;
    for (uint i = 0; i < n - 1; i++) {
      if (a[i] <= a[i + 1]) {
        uint q = 0;
        
        while (a[i] * (1ULL << q) <= a[i + 1] && q <= pows[i]) {
          q++;
        }

        pows[i + 1] = pows[i] - (q - 1);
      } else {
        uint q = 0;
        
        while (a[i] > a[i + 1] * (1ULL << q)) {
          q++;
        }

        pows[i + 1] = pows[i] + q;
      }

      cost += pows[i + 1];
    }
    // print_array(pows, n);
    // print_array(a, n);

    cout << cost << "\n";
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
