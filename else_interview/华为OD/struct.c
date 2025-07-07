#include <stdio.h>
#include <stdlib.h>
struct something {
  int v;
  int b;
  int a[5];
};

void print_struct(struct something* sth) {
  printf("%p\n", sth);
  printf("%d\n", sth->v);
  printf("%d\n", sth->b);
  for(int i = 0; i < 5; i++) {
    printf("%d\t", sth->a[i]);
  }
  printf("\n");
}
int main() {
  struct something* sth;
  sth->v = 100; sth->b = 200;
  printf("%p\n", sth);
  for(int i = 0; i < 5; i++) {
    sth->a[i] = 0;
  }
  print_struct(sth);
  int a[5] = {1, 3, 5, 7, 9};
  printf("%d", *(a + 1) + 1);
}