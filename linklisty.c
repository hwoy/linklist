#include "linklist.h"
#include <stdlib.h>

void
inity (assem * asmb, unsigned int id)
{
  asmb->beginy = asmb->endy = asmb->currenty = (linklist *) 0;
  asmb->idy = id;
}

void
addy (assem * asmb, linklist * lst)
{
  lst->prevy = lst->forwy = (linklist *) 0;
  if (!asmb->beginy)
    {
      asmb->beginy = lst;
      asmb->endy = lst;
      lst->idy = 0;
    }
  else
    {
      asmb->endy->forwy = lst;
      lst->prevy = asmb->endy;
      asmb->endy = lst;
      lst->idy = lst->prevy->idy + 1;
    }

}



void
freey (assem * asmb)
{
  linklist *tmp;
  asmb->currenty = asmb->beginy;
  while (asmb->currenty)
    {

      tmp = asmb->currenty;
      asmb->currenty = asmb->currenty->forwy;
      free (tmp);
    }

}

void
freeally (assem * asmb)
{
  linklist *tmp;
  asmb->currenty = asmb->beginy;
  while (asmb->currenty)
    {

      tmp = asmb->currenty;
      asmb->currenty = asmb->currenty->forwy;
      free (tmp->ptr);
      free (tmp);
    }
}

unsigned int
numelementy (assem * asmb)
{
  return (asmb->endy->idy + 1);
}

linklist *
findbyidy (assem * asmb, unsigned int id)
{
  asmb->currenty = asmb->beginy;
  while (asmb->currenty)
    {
      if (id == asmb->currenty->idy)
	{
	  return (asmb->currenty);
	}
      asmb->currenty = asmb->currenty->forwy;
    }
  return (0);
}

int
replacey (assem * asmb, linklist * lst, unsigned int id)
{
  linklist *tmp;
  if (!(tmp = findbyidy (asmb, id)))
    {
      return (0);
    }
  if (asmb->beginy == asmb->endy)
    {
      asmb->beginy = asmb->endy = (linklist *) 0;
      addy (asmb, lst);
    }
  else if (tmp == asmb->beginy)
    {
      tmp->forwy->prevy = lst;
      lst->prevy = tmp->prevy;
      lst->forwy = tmp->forwy;
      asmb->beginy = lst;
    }
  else if (tmp == asmb->endy)
    {
      tmp->prevy->forwy = lst;
      lst->prevy = tmp->prevy;
      lst->forwy = tmp->forwy;
      asmb->endy = lst;
    }
  else
    {
      tmp->prevy->forwy = lst;
      tmp->forwy->prevy = lst;
      lst->prevy = tmp->prevy;
      lst->forwy = tmp->forwy;
    }
  lst->idy = tmp->idy;
  free (tmp);
  return (1);
}

int
deletey (assem * asmb, unsigned int id)
{
  linklist *tmp;
  if (!(tmp = findbyidy (asmb, id)))
    {
      return (0);
    }
  else if (asmb->beginy == asmb->endy)
    {
      asmb->beginy = asmb->endy = (linklist *) 0;
    }
  else if (tmp == asmb->beginy)
    {
      tmp->forwy->prevy = tmp->prevy;
      asmb->beginy = tmp->forwy;
    }
  else if (tmp == asmb->endy)
    {
      tmp->prevy->forwy = tmp->forwy;
      asmb->endy = tmp->prevy;
    }
  else
    {
      tmp->prevy->forwy = tmp->forwy;
      tmp->forwy->prevy = tmp->prevy;
    }
  asmb->currenty = tmp->forwy;
  while (asmb->currenty)
    {
      asmb->currenty->idy--;
      asmb->currenty = asmb->currenty->forwy;
    }
  free (tmp);
  return (1);
}

int
inserty (assem * asmb, linklist * lst, unsigned int id)
{
  linklist *tmp;
  if (!(tmp = findbyidy (asmb, id)))
    {
      return (0);
    }
  if ((asmb->beginy == asmb->endy) || (tmp == asmb->endy))
    {
      addy (asmb, lst);
      return (1);
    }
  else
    {
      lst->prevy = tmp;
      lst->forwy = tmp->forwy;

      tmp->forwy->prevy = lst;
      tmp->forwy = lst;

    }

  asmb->currenty = lst;
  while (asmb->currenty)
    {
      asmb->currenty->idy = asmb->currenty->prevy->idy + 1;
      asmb->currenty = asmb->currenty->forwy;
    }
  return (1);
}

