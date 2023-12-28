#include <stdio.h>

struct student {
  int id;
};

void GetStudent(struct student child[][10], int *room);

int main() {
  struct student children[20][10];
  int group;
  GetStudent(children, &group);
  return 0;
}

void GetStudent(struct student child[][10], int *room) {
    printf("Enter the Number of classrooms: ");
    scanf("%d", room);
    
    for (int i = 0; i < *room; i++) {
        printf(" %d:\n", i + 1);
        for (int j = 0; j < 10; j++) {
          printf("Student %d ID: ", j + 1);
          scanf("%d", &child[i][j].id);
        }
    }
}