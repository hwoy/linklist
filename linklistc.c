#include "linklist.h"
#include <stdlib.h>
#define VERSION_MAJOR 1
#define VERSION_MINOR 55



linklist *
newll (void)
{
  return (malloc (sizeof (linklist)));
}


void
getversion (unsigned int *major, unsigned int *minor)
{
  *major = VERSION_MAJOR;
  *minor = VERSION_MINOR;
}

