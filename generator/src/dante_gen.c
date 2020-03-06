/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "generator.h"

static bool error_gest(int ac, char **av)
{
    if (ac == 3)
        return false;
    else if (ac == 4) {
        if (strcmp(av[3], "PERFECT") == 0)
            return false;
        else
            return true;
    }
    else
        return true;
}

static char **get_empty_maze(vector scale)
{
    int size_y = scale.y;
    int size_x = scale.x;
    printf("malloc: %i|%i\n", (size_x + 1) * 2, (size_y + 1) * 2);
    char **maze = malloc(sizeof(char *) * (size_y + 1) * 2);

    if (!maze)
        return NULL;
    maze[(size_y + 1) * 2 - 1] = NULL;
    for (int i = 0; i < (size_y + 1) * 2 - 1; i++) {
        maze[i] = malloc(sizeof(char) * (size_x + 1) * 2);
        if (!maze[i])
            return NULL;
        maze[i][(size_x + 1) * 2 - 1] = '\0';
        for (int u = 0; u < (size_x + 1) * 2 - 1; maze[i][u] = '?', u++);
    }
    return maze;
}

static int display_maze(char **maze)
{
    for (int u = 0; maze[u]; u++) {
        printf("%s\n", maze[u]);
        free(maze[u]);
    }
    free(maze);
    return 0;
}

int main(int ac, char **av)
{
    vector scale = {0};
    char **maze;

    if (error_gest(ac, av))
        return 84;
    scale = (vector) {atoi(av[1]), atoi(av[2])};
    if (scale.x <= 0 || scale.y <= 0)
        return true;
    //srand(time(NULL));
    srand(10);
    maze = get_empty_maze(scale);
    if (!maze)
        return 84;
    make_maze(maze, (vector) {0, 0}, scale);
    return display_maze(maze);
}