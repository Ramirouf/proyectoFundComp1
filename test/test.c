#include <stdio.h>
struct student
{
  char name[50];
  int height;
};
int main()
{
  struct student stud1[2], stud2[2];
  FILE *fptr;
  int i;

  fptr = fopen("file.txt", "wb");
  for (i = 0; i < 2; ++i)
  {
    fflush(stdin);
    printf("Enter name: ");
    gets(stud1[i].name);

    printf("\nEnter height: ");
    scanf("%d", &stud1[i].height);
  }

  fwrite(stud1, sizeof(stud1), 1, fptr);
  fclose(fptr);

  fptr = fopen("file.txt", "rb");
  fread(stud2, sizeof(stud2), 1, fptr);
  for (i = 0; i < 2; ++i)
  {
    printf("Name: %s\nHeight: %d", stud2[i].name, stud2[i].height);
  }
  fclose(fptr);

  return 0;
}