#include<stdlib.h>
#include<string.h>
int main()
{
 int runs=2;//change to 10000
 char command[50];
 int x=0;
 for(int i=0;i<runs;i++)
 {
  strcpy( command, "gcc pr_gn1.c -lgmp -lm -o pr_gn1" );
  system(command);
  strcpy(command, "./pr_gn1");
  system(command);
  strcpy(command, "gcc att1.c -lgmp -lm -o att1" );
  system(command);
  //strcpy(command, "./att1");
  //system(comman);
  FILE *fp;
  int status;
  char path[1035];

  fp = popen("./att1", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit;
  }
 printf("testing\n");
  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL) {
    printf("%s", path);
  }
  x=x+atoi(path);
 }
 printf("x=%d\n",x);
}
