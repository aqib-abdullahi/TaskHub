#include "task.h"
#include <stdio.h>
#include <string.h>
/*
tasks functions
*/

void print_task(struct Task task)
{
    printf("\nID: %d\nTitle: %s\nDescription: %s\nDue Date: %s\n\n", task.id, task.title, task.description, task.due_date);
};

void add_task(struct Task tasks[], int *total_tasks)
{
    if(*total_tasks < MAX_TASK) {
        struct Task new_task;

        printf("Enter task title: ");
        fflush(stdin);
        fgets(new_task.title, sizeof(new_task.title), stdin);
        new_task.title[strcspn(new_task.title, "\n")] = '\0';

        printf("Enter task description: ");
        fflush(stdin);
        fgets(new_task.description, sizeof(new_task.description), stdin);
        new_task.description[strcspn(new_task.description, "\n")] = '\0';

        printf("Enter due date: ");
        fflush(stdin);
        fgets(new_task.due_date, sizeof(new_task.due_date), stdin);
        new_task.due_date[strcspn(new_task.due_date, "\n")] = '\0';

        new_task.id = *total_tasks + 1;

        tasks[*total_tasks] = new_task;

        (*total_tasks)++;
        printf("Task added successfully!\n\n");
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

void list_task(struct Task tasks[], int total_tasks)
{
    if (total_tasks > 0) {
        printf("\n\nTask list:\n\n");
        for (int i = 0; i < total_tasks; i++ ) {
            printf("Task ", i + 1);
            print_task(tasks[i]);
        }
    } else {
        printf("No added tasks\n");
    }
}

void remove_task(struct Task tasks[], int *total_tasks, int task_id)
{
    int found = 0;
    for (int i = 0; i < *total_tasks; i++) {
        if (tasks[i].id == task_id) {
            found = 1;
            for (int j = i; j < *total_tasks - 1; j++) {
            tasks[j] = tasks[j + 1];
        }
        (*total_tasks)--;
        printf("\nTask with [ID: %d (%s)] successfully deleted\n", task_id, tasks[i].title);
        break;
        }
    }
    if (!found) {
        printf("Task with ID %d not found\n", task_id);
    }
}

void save_to_file(struct Task tasks[], int total_tasks, const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Can't open file for writing");
        return;
    }

    for (int i = 0; i < total_tasks; i++) {
        fprintf(file, "%d, %s, %s, %s\n", tasks[i].id, tasks[i].title, tasks[i].description, tasks[i].due_date);
    }
    fclose(file);
    printf("Task saved to %s succeessfully!\n", filename);
}

void load_tasks_from_file(struct Task tasks[], int *total_tasks, const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return;
    }

    while (fscanf(file, "%d, %49[^,], %199[^,], %49[^\n]%*c", &tasks[*total_tasks].id, &tasks[*total_tasks].title, &tasks[*total_tasks].description, &tasks[*total_tasks].due_date) == 4)
    {
        (*total_tasks)++;
        if (*total_tasks >= MAX_TASK )
        {
            printf("Maximum number of tasks reached. Some tasks may not load.\n");
            break;
        }
    }
    fclose(file);
}