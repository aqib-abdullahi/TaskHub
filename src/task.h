#ifndef TASK_H
#define TASK_H

#define MAX_TASK 100

struct Task
{
    int id;
    char title[50];
    char description[200];
    char due_date[50];
};

void print_task(struct Task task);
void add_task(struct Task tasks[], int *total_tasks);
void list_task(struct Task tasks[], int total_tasks);
void remove_task(struct Task tasks[], int *total_tasks, int task_id);

#endif