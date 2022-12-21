#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

template <typename T>
void printarray(T v[], uint n);
template <typename T>
void printvector(vector<T> v);
template <typename T>
void readarray(T v[], uint n);
template <typename T>
void readszandarray(T v[], uint &n);
void prep();

const int nmax = 1e5 + 1;
bool prime[nmax];

void compute_primes(int n)
{
  prime[0] = prime[1] = false;
  for (int i = 2; i <= n; i++)
    prime[i] = true;

  for (int i = 2; i <= n; i++)
  {
    if (not prime[i])
      continue;
    for (int j = 2 * i; j <= n; j += i)
    {
      prime[j] = false;
    }
  }
}

int main()
{
  prep();
  int n;
  cin >> n;

  if (n == 1)
  {
    cout << "1\n";
    cout << "1\n";
  }
  else if (n == 2)
  {
    cout << "1\n";
    cout << "1 1\n";
  }
  else
  {
    compute_primes(n + 1);
    cout << "2\n";

    for (int i = 2; i <= n + 1; i++)
    {
      if (prime[i])
        cout << "1 ";
      else
        cout << "2 ";
    }
    cout << "\n";
  }

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
void printarray(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

template <typename T>
void readarray(T v[], uint n)
{
  for (uint i = 0; i < n; i++)
    cin >> v[i];
}

template <typename T>
void readszandarray(T v[], uint &n)
{
  cin >> n;
  readarray(v, n);
}

template <typename T>
void printvector(vector<T> v)
{
  for (uint i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
