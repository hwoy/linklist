
typedef struct _linklist
{
  struct _linklist *prevx;
  struct _linklist *forwx;
  unsigned int idx;

  struct _linklist *prevy;
  struct _linklist *forwy;
  unsigned int idy;
  void *ptr;
} linklist;

typedef struct
{
  linklist *beginx;
  linklist *endx;
  linklist *currentx;

  linklist *beginy;
  linklist *endy;
  linklist *currenty;
  unsigned int idy;
  unsigned int idx;
} assem;

#include "linklistx.h"
#include "linklisty.h"

linklist *newll (void);
void getversion (unsigned int *major, unsigned int *minor);

