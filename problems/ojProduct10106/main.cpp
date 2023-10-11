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

// template <size_t Bits = 128, typename Repr = uint64_t>
// class BigInt
// {
// public:
//   static constexpr size_t ReprBits = sizeof(Repr) * 8;

//   BigInt
//   operator*(const BigInt &rhs) const
//   {
//   }

//   friend istream &operator>>(istream &in, BigInt &object)
//   {
//     string number;
//     in >> number;

//     return in;
//   }

//   friend ostream &operator<<(ostream &out, const BigInt &object)
//   {
//     return out;
//   }

// private:
//   Repr repr[Bits / ReprBits + Bits % ReprBits != 0];
// };

template <size_t Digits = 512>
class NaiveBigInt
{
public:
  NaiveBigInt() : NaiveBigInt("0")
  {
  }

  NaiveBigInt(const string &s)
  {
    parse(s);
  }

  NaiveBigInt
  operator*(const NaiveBigInt &rhs) const
  {
    NaiveBigInt result;

    for (int i = Digits - 1, shift = 0; i >= static_cast<int>(Digits - rhs.length); i--, shift++)
    {
      for (int j = Digits - 1; j >= static_cast<int>(Digits - length); j--)
      {
        if (j < shift)
        {
          throw runtime_error("Digits precison has been exceeded (1).");
        }
        result.repr[j - shift] += repr[j] * rhs.repr[i];
      }
    }

    for (int i = Digits - 1; i > 0; i--)
    {
      if (result.repr[i] > 9)
      {
        result.repr[i - 1] += result.repr[i] / 10;
        result.repr[i] %= 10;
      }
    }

    uint i = 0;
    while (result.repr[i] == 0)
    {
      i++;
    }
    result.length = Digits - i;

    if (result.repr[0] > 9)
    {
      throw runtime_error("Digits precison has been exceeded (2).");
    }

    return result;
  }

  friend istream &operator>>(istream &in, NaiveBigInt &object)
  {
    string number;
    in >> number;
    object.parse(number);

    return in;
  }

  friend ostream &operator<<(ostream &out, const NaiveBigInt &object)
  {
    for (uint i = Digits - object.length; i < Digits; i++)
    {
      out << static_cast<char>(object.repr[i] + '0');
    }

    return out;
  }

private:
  void parse(const string &s)
  {
    length = s.length();
    memset(repr, 0, sizeof(uint) * Digits);

    for (uint i = 0; i < s.length(); i++)
    {
      if (s[i] < '0' || s[i] > '9')
      {
        throw invalid_argument("NativeBigInt must be only of digits: " + s);
      }

      repr[Digits - length + i] = s[i] - '0';
    }
  }

  size_t length;
  uint repr[Digits];
};

int main()
{
  prep();

  while (!cin.eof())
  {
    NaiveBigInt<> x, y;
    cin >> x >> y;
    cout << x * y << "\n";
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
