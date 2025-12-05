#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#define FILE_NAME "example.txt"
#define FILE_NAME "input.txt"
#define DIAL_NUM  100

int curr_numb = 50;
int total_zeros = 0;

void
rotate_right(int n)
{
  for(int i = 0; i < n; i++)
  {
    curr_numb = (curr_numb + 1 + DIAL_NUM) % DIAL_NUM;
    if((!curr_numb))
      total_zeros++;
  }
}
    
void
rotate_left(int n)
{
  for(int i = 0; i < n; i++)
  {
    curr_numb = (curr_numb - 1 + DIAL_NUM) % DIAL_NUM;
    if((!curr_numb))
      total_zeros++;
  }
}

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
      if(direction == 'R')
        rotate_right(number);
      else if (direction == 'L')
        rotate_left(number);
      else
        return -1;
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
