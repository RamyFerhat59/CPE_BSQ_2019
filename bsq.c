/*
** EPITECH PROJECT, 2020
** bsq.c
** File description:
** bsq.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "my.h"

int main(int argc, char **argv)
{
    int nblines = 0;
    int fd = open(argv[1], O_RDONLY);
    size_t ch = 0;
    size_t count;
    int **map = NULL;
    int nbcolo = 0;

    if (argc != 2)
    {
        write(1, "Only 2 arguments\n", 18);
        return (84);
    }
    if (get_file_size(argv[1]) == 84)
    {
        return (84);
    }
    count = get_file_size(argv[1]);
    char buffer[count];
    ch = read(fd, buffer, count);
    nblines = countlines(buffer, count);
    nbcolo = my_strlen(buffer);
    buffer[ch] = '\0';
    //  printf("%s", buffer);
    map = read_to_tab(buffer, nblines, nbcolo);
    // if (check_map(map, nblines) == 84) {
        // write(1, "Invalid map\n", 13);
    //     return (84);
    // }
    print_map(map, nbcolo, nblines);
    free(map);
    return (0);
}

size_t get_file_size(char *argv)
{
    struct stat stats;
    size_t count = 0;
    if (stat(argv, &stats) == 0)
    {
        count = stats.st_size;
    }
    else
    {
        write(1, "Unable to get file properties\n", 31);
        return (84);
    }
    return (count);
}

int **read_to_tab(char *file, int lignes, int nbcolo)
{
    int i = 0;
    int j = -1;
    int k = 0;
    int **map_int = malloc(sizeof(int *) * (lignes + 1));

    while (file[i] != '\n' && file[i] != '\0') 
        i += 1;
    while (file[i] != '\0') {
        if (file[i] == '\n' && (j < (lignes - 1))) {
            i += 1;
            j += 1;
            map_int[j] = malloc(sizeof(int) * (nbcolo));
            k = 0;
        } 
        if (file[i] == 'o') 
            map_int[j][k] = 0;
        if (file[i] == '.') 
            map_int[j][k] = 1; 
        k += 1;
        i += 1;
    }
    map_int[j] = NULL;
    return (map_int);
}

// void swap(char *x, char *y) 
// {
//     char t = *x;

//     *x = *y;
//     *y = t;
// }

// char *reverse(char *buffer, int i, int j)
// {
//     while (i < j)
// 		swap(&buffer[i++], &buffer[j--]);

// 	return buffer;
// }

// char *itoa(int value, char *buffer, int base)
// {
//     int n = value;
//     int i = 0;

//     if (base < 2 || base > 32)
// 		return buffer;
//     while (n) {
// 		int r = n % base;
//         if (r > 10) 
// 			buffer[i++] = 65 + (r - 10);
// 		else
// 			buffer[i++] = 48 + r;
//         n = n / base;
// 	}
//     if (i == 0)
// 		buffer[i++] = '0';
//     if (value < 0 && base == 10)
// 		buffer[i++] = '-';
//     buffer[i] = '\0';
//     return reverse(buffer, 0, i - 1);
// }

int my_getnbr(char *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    return nb;
}

void free_map(int **map, int nblines)
{
    int i = 0;

    while(i < nblines){
        free(map[i]);
        i++;
    }
    free(map);
}

void print_map(int **map, int nbcolo, int nblines)
{
    int i = 0;
    int j = 0;

    for (; i < nblines - 1; i++) {
        j = 0;
        while(j < nbcolo) {
            printf("%d", map[i][j]);
            j++;
        }
        printf("\n");
    }
}

int my_strlen(char const *str)
{
    
    int charcount = 0;
    int j = 0;

    while(str[j] != '\n') {
        j++;
    }
    j++;
    while (str[j] != '\n'){
        charcount++;
        j++;
    }
    return charcount;
}

int countlines(char *buffer, size_t filesize)
{
    int nblines = 1;
    int size = filesize;
    
    for (int n = 0; n <= size; ++n) {
        if (buffer[n] == '\n') {
            nblines++;
        }
    }
    return (nblines);
}

int check_map(char **map, int nblines)
{
    int i = 0;
    int j = 0;

    for (; i < nblines - 1; i++) {   
        j = 0;
        for (; map[i][j] != '\0'; j++) {
            if (map[i][j] != '.' && map[i][j] != 'o' && map[i][j] != '\n')
                return (84);
        }
    }
    return (0);
}