
/// one based index

const int mx = 1009;

int bit[mx][mx];
int a[mx][mx];

void upd (int x, int yy, int val) {
  for (; x <= n; x += x&-x) {
      for (int y = yy; y <= n; y += y&-y) {
          bit[x][y] += val;
      }
  }
}

int get (int x, int yy) {
  int s = 0;
  for (; x > 0; x -= x&-x) {
      for (int y = yy; y > 0; y-=y&-y) {
          s += bit[x][y];
      }
  }
  return s;
}


