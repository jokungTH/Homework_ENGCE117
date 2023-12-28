#include <stdio.h>
#include <stdlib.h>

struct student {
  int id;
};

struct student (*GetStudent(int *room))[10];

int main() {
    struct student (*children)[10];
    int group;
    children = GetStudent(&group);
    free(children);
    return 0;
}

struct student (*GetStudent(int *room))[10] {
    printf("Enter the Number of classrooms: ");
    scanf("%d", room);
    
    struct student (*result)[10] = (struct student (*)[10])calloc(*room, sizeof(struct student[10]));
    
    for (int i = 0; i < *room; i++) {
        printf("Classroom %d:\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d ID: ", j + 1);
            scanf("%d", &result[i][j].id);
        }
    }
    return result;
}