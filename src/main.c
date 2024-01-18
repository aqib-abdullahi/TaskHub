#include <stdio.h>
#include "task.h"
#include <stdlib.h>
#include <string.h>
// main file

int main() {
    struct Task tasks[MAX_TASK];
    int total_tasks = 0;
    int choice;
    char input[50];

    do{
        printf("------------------\n");
        printf("Task Manager\n\n");
        printf("1. Add Task\n");
        printf("2. List Task\n");
        printf("3. Remove Task\n");
        // printf("4. Save Task\n");
        printf("4. Exit\n\n");
        printf("------------------\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);

        choice = atoi(input);
        if (choice == 0 && input[0] != '0' ) {
            printf("Invalid choice. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                add_task(tasks, &total_tasks);
                save_to_file(tasks, total_tasks, "tasks.txt");
                break;
            case 2:
                list_task(tasks, total_tasks);
                break;
            case 3:
                printf("Enter Task ID: ");
                fflush(stdin);
                fgets(input, sizeof(input), stdin);
                int task_id;
                task_id = atoi(input);
                remove_task(tasks, &total_tasks, task_id);
                break;
            case 4:
                printf("Closing program... Goodbye!");
                exit;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}