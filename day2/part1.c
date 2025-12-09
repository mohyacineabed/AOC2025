#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//#define FILE_NAME "example.txt"
#define FILE_NAME "input.txt"

long int invalid_sum = 0;

/* returns 0 is valid, 1 if invalid */
int
is_valid(char* n)
{
  if(n[0] == '0')
    return 1;

  int n_size = strlen(n);
  if(n_size % 2 == 0)
  {
    for(int i=0; i<n_size/2; i++)
    {
      if(n[i] == n[i+(n_size/2)])
        continue;
      else
        return 0;
    }
  }
  else
    return 0;

  return 1;
}


void
range_loop(int long n1, int long n2)
{
  long int i;
  char curr_n[64];
  for(i=n1; i<=n2; i++)
  {
    sprintf(curr_n, "%ld", i);
    if(is_valid(curr_n))
    {
      invalid_sum+=i;
    }
  }
}

int
open_read()
{
  char buff[1024];
  long int n1, n2;

  FILE* file = fopen(FILE_NAME, "r");
  assert(file);

  fgets(buff, 1024, file);

  char* ptr;
  ptr = strtok(buff, ",");

  while(ptr != NULL)
  {
    sscanf(ptr, "%ld-%ld", &n1, &n2);

    range_loop(n1, n2);

    ptr = strtok(NULL, ",");
  }

  return 0;
}


int
main()
{
  if(open_read())
  {
    fprintf(stdout, "Error openning and reading file %s\n", FILE_NAME);
    return -1;
  }

  printf("%ld\n", invalid_sum);

  return 0;
}

