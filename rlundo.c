#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  // Check that we have at least one arg.
  if (argc == 1) {
    printf("You must supply a program which uses readline to run\n");
    printf("\n");
    printf("Example: %s /bin/irb\n", argv[0]);
    return 1;
  }
  // TODO: allow names without paths

  #ifdef __APPLE__
    putenv("DYLD_FORCE_FLAT_NAMESPACE=1");
    putenv("DYLD_INSERT_LIBRARIES=./librlundoable.dylib");
  #else
    putenv("LD_PRELOAD=./librlundoable.so");
  #endif

  execv(argv[1], argv + 1);    /* Note that exec() will not return on success. */
  perror("exec() failed");

  return 2;
}
