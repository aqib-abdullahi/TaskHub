#include "task.h"
#include <stdio.h>
// main file

int main() {
    struct Task tasks[MAX_TASK];
    int total_tasks = 0;
    int choice;

    do{
        printf("Task Manager\n");
        printf("1. Add Task\n");
        printf("2. List Task\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(tasks, &total_tasks);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("Closing program... Goodbye!");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}