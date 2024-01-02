
#include <fcntl.h>
#include "get_next_line_bonus.h"
int main(void)
{
  int    fd[2];
  char  *next_line1;
  char  *next_line2;
  int  count;
  count = 0;
  fd[0] = open("example.txt", O_RDONLY);
  fd[1] = open("example2.txt", O_RDONLY);
  while (count < 2)
  {next_line1 = get_next_line(fd[0]);
  next_line2 = get_next_line(fd[1]);
  count++;
  printf("[%d]:%s", fd[0], next_line1);
  printf("[%d]:%s", fd[1], next_line2);
  free (next_line1);
  free (next_line2);
//   next_line = NULL;
  }
  close(fd[0]);
  close(fd[1]);
  return (0);
}