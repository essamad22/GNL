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
// #include "leak_hunter.h"

char *get_line(char *str)
{
    char *line;
    int i;
    int j;

    i = 0;
    j = 1;
    if (!str || !*str)
        return (NULL);
    if (ft_strchr(str, '\n'))
        j = 2;
    line = malloc(get_len(str) +  j);
    if (!line)
    {
        free(str);
        return (NULL);
    }
    while (str[i] != '\0' && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    if (j == 2)
        line[i++] = '\n';
    line[i] = '\0';
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
    char *tmp;

    i = 0;
    if (!str)
        return (NULL);
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    if(str[i] == '\n')
        i++;
    tmp = malloc(ft_strlen(str + i) + 1);
    if (!tmp)
    {
        free(str);
        return (NULL);
    }
    ft_memcpy(tmp, str + i, (ft_strlen(str) - i));
    // printf("|1%s1|\n", tmp);
    // printf("|%s|\n", str);
    free(str);
    str = NULL;
    return (tmp);
}

char *get_next_line(int fd)
{
    static char *store;
    char *line;

    store = get_store(store, fd);
    line = get_line(store);
    store = ft_next(store);
    return (line);
}

// int main()
// {
//     int fd;

//     fd = open("file.txt", 2);
//     // atexit(leak_report);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//    // printf("%s", get_next_line(fd));

//     // printf("%s", get_next_line(fd));
//     // get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
// }