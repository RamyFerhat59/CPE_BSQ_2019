/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
# define MY_H_


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

size_t get_file_size(char *argv);
int **file_to_map(int nblines, char *buffer, int nbcolo);
int my_strlen(char const *str);
int countlines(char *buffer, size_t filesize);
void print_map(int **map, int nbcolo, int nblines);
void free_map(int **map, int nblines);
int my_getnbr(char  *str);
void swap(char *x, char *y);
char *reverse(char *buffer, int i, int j);
char *itoa(int value, char* buffer, int base);
char **transform_tab(char **map, int nblines);
int **read_to_tab(char *file, int lignes, int nbcolo);







#endif /* !MY_H_ */
