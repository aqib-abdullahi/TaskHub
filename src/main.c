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
        printf("\n\t\t------------------\n");
        printf("\t\tTask Manager\n\n");
        printf("\t\t1. Add Task\n");
        printf("\t\t2. List Task\n");
        printf("\t\t3. Remove Task\n");
        printf("\t\t4. Exit\n\n");
        printf("\t\t------------------\n");
        load_tasks_from_file(tasks, &total_tasks, "tasks.txt");
        printf("\nEnter your choice: ");
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