#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#define FILE_NAME "example.txt"
#define FILE_NAME "input.txt"
#define DIAL_NUM  100

int curr_numb = 50;
int total_zeros = 0;

/* returns 0 on sucess, -1 on error */
int
open_read_file()
{
  char buff[1024];
  char direction;
  int number;

  FILE* file = fopen(FILE_NAME, "r");
  assert(file);

  while(fgets(buff, 1023, file) != NULL)
  {
    if(sscanf(buff, "%1c%d", &direction, &number) != 0)
    {
      int new_numb;
      if(direction == 'R')
        new_numb = ((curr_numb + number) % DIAL_NUM);
      else if (direction == 'L')
        new_numb = ((curr_numb - number) % DIAL_NUM);
      else
        return -1;

      if(!new_numb)
        total_zeros++;

      new_numb = (new_numb + DIAL_NUM) % DIAL_NUM;
      curr_numb = new_numb;
    }
  }
  return 0;
}

int
main()
{
  if(open_read_file())
  {
    fprintf(stdout, "Failed to read from file\n");
    return -1;
  }

  printf("%d\n", total_zeros);

  return 0;
}
