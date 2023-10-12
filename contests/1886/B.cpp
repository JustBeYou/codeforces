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

double dist(int x1, int y1, int x2, int y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
  prep();

  int t;
  cin >> t;
  while (t--)
  {
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    double w_inside_a = max(dist(0, 0, ax, ay), dist(px, py, ax, ay));

    double w_inside_b = max(dist(0, 0, bx, by), dist(px, py, bx, by));

    double dist_ab = dist(ax, ay, bx, by);
    double w_o_in_a_p_in_b = max(dist(0, 0, ax, ay), dist(px, py, bx, by));
    double w_o_in_b_p_in_a = max(dist(0, 0, bx, by), dist(px, py, ax, ay));

    if (2 * w_o_in_a_p_in_b + 1e-7 < dist_ab)
    {
      w_o_in_a_p_in_b += (dist_ab - 2 * w_o_in_a_p_in_b) / 2;
    }

    if (2 * w_o_in_b_p_in_a + 1e-7 < dist_ab)
    {
      w_o_in_b_p_in_a += (dist_ab - 2 * w_o_in_b_p_in_a) / 2;
    }

    double w_inside_both = min(w_o_in_a_p_in_b, w_o_in_b_p_in_a);

    cout << setprecision(8) << min(min(w_inside_a, w_inside_b), w_inside_both) << "\n";
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
