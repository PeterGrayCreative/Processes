// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";

int main() {
  // Your code here
  char inbuf[MSGSIZE];
  int p[2];
  if (pipe(p) < 0) {
    fprintf(stderr, "pipe failed\n");
    exit(1);
  }

  int child = fork();
  if (child < 0)
    exit(1);
  else if (child == 0) {
    write(p[1], msg1, MSGSIZE);
  } else {
    for (int i = 0; i < 3; i++) {
      read(p[0], inbuf, MSGSIZE);
      printf("% s\n", inbuf);
    }
  }
  return 0;
}
