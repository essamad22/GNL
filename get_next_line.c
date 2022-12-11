/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:19:42 by aakhtab           #+#    #+#             */
/*   Updated: 2022/12/06 16:19:44 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_line(char *str)
{
    char *line;
    int i;
    int j;

    i = 0;
    j = 0;
    if (ft_strchr(str, '\n'))
        j = 2;
    else
        j = 1;
    line = malloc(get_len(str) + j);
    while (str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\n';
    line[++i] = '\0';
    return (line);
}
char *get_store(char *str, int fd)
{
    char *line;
    int buf;

    line = malloc(BUFFER_SIZE + 1);
    if (!line)
        return (NULL);
    while (!ft_strchr(line, '\n'))
    {
        buf = read(fd, line, BUFFER_SIZE);
        if (buf < 0)
        {
            free(line);
            free(str);
            return (NULL);
        }
        if (buf == 0)
        {
            free(line);
            return (str);
        }
        line[buf] = 0;
        str = ft_strjoin(str ,line);
    }
    free(line);
    return (str);
}

char    *ft_next(char *str)
{
    int i;
    // char *tmp;

    i = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    if(str[i] == '\n')
        i++;
    str += i;
    return (str);
}

char *get_next_line(int fd)
{
    static char *store;
    char *line;

    store = get_store(store, fd);
    //printf("|%s|\n", store);
    line = get_line(store);
    store = ft_next(store);
   // printf("|%s|\n", store);
    
    return (line);
}

int main()
{
    int fd;

    fd = open("file.txt", 2);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
   // printf("%s", get_next_line(fd));

    // printf("%s", get_next_line(fd));
    // get_next_line(fd);
    // get_next_line(fd);
    // get_next_line(fd);
}
