/* dirname - extract the directory name from a path	Author: Peter Holzer */

/* Dirname -- extract directory part from a path name
 *
 * Peter Holzer (hp@vmars.tuwien.ac.at)
 *
 * $Log: dirname.c,v $
 * Revision 1.1  1994/02/12  16:15:02  hjp
 * Initial revision
 *
 */

#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  char *p;
  char *path;

  if (argc != 2) {
	fprintf(stderr, "Usage: %s path\n", argv[0]);
	return(1);
  }
  path = argv[1];
  p = path + strlen(path);
  while (p > path && p[-1] == '/') p--;	/* trailing slashes */
  while (p > path && p[-1] != '/') p--;	/* last component */
  while (p > path && p[-1] == '/') p--;	/* trailing slashes */
  if (p == path) {
	printf(path[0] == '/' ? "/\n" : ".\n");
  } else {
	printf("%.*s\n", (int) (p - path), path);
  }
  return(0);
}
