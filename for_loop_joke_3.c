#include <stdio.h>

int main()
{
  int i = 0;
Loop:
  if (!(i < 100))
    goto End;
  i++;
  printf("%d", i);
  goto Loop;
End:
  return 0;
}
