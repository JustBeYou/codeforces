#include <bits/stdc++.h>

using namespace std;

int n, m;
int aib[15001 + 66];

inline int zeros(int x)
{
  return (x ^ (x - 1)) & x;
}

void update(int pos, int value)
{
  for (int i = pos; i <= n; i += zeros(i))
  {
    aib[i] += value;
  }
}

int query(int pos)
{
  int result = 0;

  for (int i = pos; i > 0; i -= zeros(i))
  {
    result += aib[i];
  }
  return result;
}

int main()
{
  freopen("datorii.in", "r", stdin);
  freopen("datorii.out", "w", stdout);
  scanf("%d%d", &n, &m);

  for (int i = 1, x; i <= n; i++)
  {

    scanf("%d", &x);
    update(i, x);
  }

  for (int i = 1, t, x, y; i <= m; i++)
  {

    scanf("%d%d%d", &t, &x, &y);

    if (t == 0)
    {
      update(x, -y);
    }
    else
    {
      cout << query(y) - query(x - 1) << "\n";
    }
  }

  return 0;
}