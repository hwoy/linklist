#include "linklist.h"
#include <stdlib.h>

void
initx (assem * asmb, unsigned int id)
{
  asmb->beginx = asmb->endx = asmb->currentx = (linklist *) 0;
  asmb->idx = id;
}

void
addx (assem * asmb, linklist * lst)
{
  lst->prevx = lst->forwx = (linklist *) 0;
  if (!asmb->beginx)
    {
      asmb->beginx = lst;
      asmb->endx = lst;
      lst->idx = 0;
    }
  else
    {
      asmb->endx->forwx = lst;
      lst->prevx = asmb->endx;
      asmb->endx = lst;
      lst->idx = lst->prevx->idx + 1;
    }

}



void
freex (assem * asmb)
{
  linklist *tmp;
  asmb->currentx = asmb->beginx;
  while (asmb->currentx)
    {

      tmp = asmb->currentx;
      asmb->currentx = asmb->currentx->forwx;
      free (tmp);
    }

}

void
freeallx (assem * asmb)
{
  linklist *tmp;
  asmb->currentx = asmb->beginx;
  while (asmb->currentx)
    {

      tmp = asmb->currentx;
      asmb->currentx = asmb->currentx->forwx;
      free (tmp->ptr);
      free (tmp);
    }
}

unsigned int
numelementx (assem * asmb)
{
  return (asmb->endx->idx + 1);
}

linklist *
findbyidx (assem * asmb, unsigned int id)
{
  asmb->currentx = asmb->beginx;
  while (asmb->currentx)
    {
      if (id == asmb->currentx->idx)
	{
	  return (asmb->currentx);
	}
      asmb->currentx = asmb->currentx->forwx;
    }
  return (0);
}

int
replacex (assem * asmb, linklist * lst, unsigned int id)
{
  linklist *tmp;
  if (!(tmp = findbyidx (asmb, id)))
    {
      return (0);
    }
  if (asmb->beginx == asmb->endx)
    {
      asmb->beginx = asmb->endx = (linklist *) 0;
      addx (asmb, lst);
    }
  else if (tmp == asmb->beginx)
    {
      tmp->forwx->prevx = lst;
      lst->prevx = tmp->prevx;
      lst->forwx = tmp->forwx;
      asmb->beginx = lst;
    }
  else if (tmp == asmb->endx)
    {
      tmp->prevx->forwx = lst;
      lst->prevx = tmp->prevx;
      lst->forwx = tmp->forwx;
      asmb->endx = lst;
    }
  else
    {
      tmp->prevx->forwx = lst;
      tmp->forwx->prevx = lst;
      lst->prevx = tmp->prevx;
      lst->forwx = tmp->forwx;
    }
  lst->idx = tmp->idx;
  free (tmp);
  return (1);
}

int
deletex (assem * asmb, unsigned int id)
{
  linklist *tmp;
  if (!(tmp = findbyidx (asmb, id)))
    {
      return (0);
    }
  else if (asmb->beginx == asmb->endx)
    {
      asmb->beginx = asmb->endx = (linklist *) 0;
    }
  else if (tmp == asmb->beginx)
    {
      tmp->forwx->prevx = tmp->prevx;
      asmb->beginx = tmp->forwx;
    }
  else if (tmp == asmb->endx)
    {
      tmp->prevx->forwx = tmp->forwx;
      asmb->endx = tmp->prevx;
    }
  else
    {
      tmp->prevx->forwx = tmp->forwx;
      tmp->forwx->prevx = tmp->prevx;
    }
  asmb->currentx = tmp->forwx;
  while (asmb->currentx)
    {
      asmb->currentx->idx--;
      asmb->currentx = asmb->currentx->forwx;
    }
  free (tmp);
  return (1);
}

int
insertx (assem * asmb, linklist * lst, unsigned int id)
{
  linklist *tmp;
  if (!(tmp = findbyidx (asmb, id)))
    {
      return (0);
    }
  if ((asmb->beginx == asmb->endx) || (tmp == asmb->endx))
    {
      addx (asmb, lst);
      return (1);
    }
  else
    {
      lst->prevx = tmp;
      lst->forwx = tmp->forwx;

      tmp->forwx->prevx = lst;
      tmp->forwx = lst;

    }

  asmb->currentx = lst;
  while (asmb->currentx)
    {
      asmb->currentx->idx = asmb->currentx->prevx->idx + 1;
      asmb->currentx = asmb->currentx->forwx;
    }
  return (1);
}

