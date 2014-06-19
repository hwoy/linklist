#include <stdio.h>
#include "linklist.h"


int
main (void)
{
  assem as;
  unsigned int i, j;
  linklist *tmp, *tmpx, *tmpy;
  initx (&as, 0);


  for (i = 0; i < 15; i++)
    {
      addx (&as, tmpx = newll ());
      as.beginy = as.endy = tmpx;
      for (j = 0; j < 10 - 1; j++)
	{
	  addy (&as, newll ());
	}
    }


  tmpx = as.beginx;
  while (tmpx)
    {
      tmpy = tmpx;
      printf ("============= value of x =  %d ===============\n", tmpx->idx);
      while (tmpy)
	{
	  printf ("x = %d\ty = %d\n", tmpx->idx, tmpy->idy);
	  tmpy = tmpy->forwy;
	}
      tmpx = tmpx->forwx;
    }

  tmpx = as.beginx;
  while (tmpx)
    {
      tmp = tmpx;
      tmpx = tmpx->forwx;
      as.beginx = as.beginy = tmp;
      freey (&as);
    }

  return (0);
}

