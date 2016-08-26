// GCW: gcw_filename.c

#include <stdio.h>
#include <string.h>

#include "gcw.h"

int main(int argc, char *argv[])
{
  FILE *inf;
  char wbuf[256];
  char *c;

  inf = fopen(argv[1],"r");

  if ( inf ) {
    // skip this

    // -----BEGIN PGP SIGNED MESSAGE-----
    // Hash: SHA1
    //
    fgets(wbuf,sizeof(wbuf),inf);
    fgets(wbuf,sizeof(wbuf),inf);
    fgets(wbuf,sizeof(wbuf),inf);

    // get this - // GCW: filename
    fgets(wbuf,sizeof(wbuf),inf);
    // get rid of \n if present
    c = strchr(wbuf,'\n');
    if ( c ) *c = 0;

    // is this us??
    c = strstr(wbuf,FIND_STRING);
    if ( !c ) {
      // no, just get out
      printf("unknown");
      goto finis;
    }

    // extract file name
    c += strlen(FIND_STRING);
    printf("%s",c);
  } else {
    printf("unknown");
  }

 finis:;
  if ( inf ) close(inf);
  return 0;
}
