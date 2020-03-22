/*
** EPITECH PROJECT, 2020
** solver
** File description:
** new_solv
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "solveur.h"
#include "struct.h"

void display(char **maze)
{
    for (unsigned int y = 0; maze[y] != NULL; y++) {
        for (unsigned int x = 0; maze[y][x] != '\0'; x++) {
            if (maze[y][x] == 'o')
                printf("\033[1;32m%c\033[0m", maze[y][x]);
            else
                printf("%c", maze[y][x]);
        }
        if (maze[y + 1] != NULL)
            printf("\n");
    }
}

static int dir(char ***maze, pos_t pos, pos_t const size, int i)
{
    maze[0][pos.y][pos.x] = 'o';
    if (i == 200000)
        return (-1);
    if (pos.x == size.x - 1 && pos.y == size.y - 1)
        return (0);
    if (pos.x + 1 < size.x && maze[0][pos.y][pos.x + 1] == '*')
        if (dir(maze, (pos_t) {pos.y, pos.x + 1}, size, i + 1) == 0)
            return (0);
    if (pos.y + 1 < size.y && maze[0][pos.y + 1][pos.x] == '*')
        if (dir(maze, (pos_t) {pos.y + 1, pos.x}, size, i + 1) == 0)
            return (0);
    if (pos.x > 0 && maze[0][pos.y][pos.x - 1] == '*')
        if (dir(maze, (pos_t) {pos.y, pos.x - 1}, size, i + 1) == 0)
            return (0);
    if (pos.y > 0 && maze[0][pos.y - 1][pos.x] == '*')
        if (dir(maze, (pos_t) {pos.y - 1, pos.x}, size, i + 1) == 0)
            return (0);
    maze[0][pos.y][pos.x] = '0';
    return (-1);
}

static char **mod_maze(char **maze)
{
    for (int y = 0; maze[y] != NULL; y++)
        for (int x = 0; maze[y][x] != '\0'; x++)
            if (maze[y][x] == '0')
                maze[y][x] = '*';
    return (maze);
}

char **algo(char **maze, pos_t const size)
{
    int out = dir(&maze, (pos_t) {0, 0}, size, 0);

    if (out == -1) {
        write(2, "solution not found\n", 20);
        exit(84);
    }
    maze = mod_maze(maze);
    return (maze);
}