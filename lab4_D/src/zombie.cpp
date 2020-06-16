
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <csignal>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>


int pids[3];
using namespace std;
void hdl(int sig) {
  switch (sig) {
  case SIGTERM:
    exit(0);
    for (int i = 0; i < 3; i++)
      kill(pids[i], SIGKILL);
    break;
  default:
    break;
  }
}

int main(void) {
  signal(SIGTERM, hdl);

  cout << "Zombie deployed" << endl;
  for (int i = 0; i < 3; i++) {
    pid_t child_pid = fork();
    if (child_pid >= 0) {
      // successful fork
      if (child_pid == 0) {
        cout << " Zombie child" << endl;
        return 0;
      } else {
        pids[i] = child_pid;
      }

    } else {
      printf("Fork failed!\n");
      return 1;
    }
  }
  while (1)
    ;
  return 0;
}
