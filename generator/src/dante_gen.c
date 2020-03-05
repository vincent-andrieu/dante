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

static bool error_gest(int ac, char **av, vector scale)
{
    if (scale.x <= 0 || scale.y <= 0)
        return true;
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
    char **maze = malloc(sizeof(char *) * (size_y + 1));

    if (!maze)
        return NULL;
    maze[size_y] = NULL;
    for (int i = 0; i < size_y; i++) {
        maze[i] = malloc(sizeof(char) * (size_x + 1));
        if (!maze[i])
            return NULL;
        maze[i][size_x] = '\0';
        for (int u = 0; u < size_x;maze[i][u] = WALL, u++);
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
    vector scale = {atoi(av[1]), atoi(av[2])};
    char **maze;

    srand(time(NULL));
    if (error_gest(ac, av, scale))
        return 84;
    maze = get_empty_maze(scale);
    make_maze(maze, (vector) {0, 0}, av);
    return display_maze(maze);
}