// GCW: gcw_add_filename.c

#include <stdio.h>
#include <string.h>

#include "gcw.h"

int main(int argc, char *argv[])
{
  FILE *inf;
  char wbuf[256];
  char *c;
  FILE *outf;
  char outf_wbuf[256];

  inf = fopen(argv[1],"r");
  // get a unique output file
  sprintf(outf_wbuf,"%s_%d.tmp", argv[1], getpid());
  outf = fopen(outf_wbuf,"w+");

  if ( inf && outf ) {

    // get this - // GCW: filename
    fgets(wbuf,sizeof(wbuf),inf);
    // get rid of \n if present
    c = strchr(wbuf,'\n');
    if ( c ) *c = 0;

    // do they need the gcw header ???
    c = strstr(wbuf,FIND_STRING);
    if ( !c ) {
      // no, add header
      fprintf(outf,"%s%s\n",FIND_STRING,argv[1]);
      // get rid of the first line we read
      fprintf(outf,"%s\n",wbuf);

      // shovel inf -> outf
      while ( fgets(wbuf,sizeof(wbuf),inf) ) {
	fprintf(outf,"%s",wbuf);
      }
      goto ok;
    }

    // yes, we are done
    fclose(outf);
    outf = NULL;
    fclose(inf);
    inf = NULL;

  } else {
    goto err;
  }

 err:;
  // close files as needed
  if ( inf  ) fclose(inf);
  if ( outf ) fclose(outf);
  // remove temp file
  unlink(outf_wbuf);
  // return with error
  return 1;

 ok:
  // remove obsolete file and rename out temp file
  unlink(argv[1]);
  rename(outf_wbuf,argv[1]);

  // return happy
  return 0;
}
