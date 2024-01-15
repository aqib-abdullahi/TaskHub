#include "task.h"
#include <stdio.h>
/*
tasks functions
*/

void print_task(struct Task task) {
    printf("ID: %d\nTitle: %s\nDescription: %s\nDue Date: %s\n\n", task.id, task.title, task.description, task.due_date);
};

void add_task(struct Task tasks[], int *total_tasks) {
    if(*total_tasks < MAX_TASK) {
        struct Task new_task;

        printf("Enter task title: ");
        scanf("%[^\n]", new_task.title);

        printf("Enter task description: ");
        scanf(" %[^\n]", new_task.description);

        printf("Enter due date: ");
        scanf(" %[^\n]", new_task.due_date);

        new_task.id = *total_tasks + 1;

        tasks[*total_tasks] = new_task;

        (*total_tasks)++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}