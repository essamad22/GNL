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

char	*ft_free(char *store)
{
	free(store);
	return (NULL);
}

char *ft_line(char *str)
{
    char *line;
    int i;
    int j;

    i = -1;
    j = 1;
    if (!str || !*str)
        return (NULL);
    if (ft_strchr(str, '\n'))
        j = 2;
    line = malloc(get_len(str) +  j);
    if (!line)
        return (ft_free(str));
    while (str[++i] != '\0' && str[i] != '\n')
        line[i] = str[i];
    if (j == 2)
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char	*get_store(char *store, int fd)
{
	char	*line;
	int		i;

	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (!ft_strchr(store, '\n'))
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i < 0)
		{
			free(line);
			free(store);
			return (NULL);
		}
		else if (i == 0)
		{
			free (line);
			return (store);
		}
		line[i] = '\0';
		store = ft_strjoin(store, line);
	}
	free(line);
	return (store);
}

char    *ft_next(char *str)
{
    int i;
    char *tmp;

    if (!str)
        return (NULL);
    i = get_len(str);
    if (i - ft_strlen(str) == 0)
        return (ft_free(str));
    tmp = malloc(ft_strlen(str) - i);
    if (!tmp)
        return (ft_free(str));
    if (str[i] == '\n')
        i++;
    ft_memcpy(tmp, str + i, (ft_strlen(str) - i));
    tmp[ft_strlen(str) - i] = '\0';
    free(str);
    return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;

	store = get_store(store, fd);
	line = ft_line(store);
	store = ft_next(store);
	return (line);
}

// int main()
// {
//     int fd;

//     fd = open("file.txt", 2);
// //     atexit(leak_report);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
// //     printf("%s", get_next_line(fd));
// //     printf("%s", get_next_line(fd));
// //     // printf("%s", get_next_line(fd));
// //     // printf("%s", get_next_line(fd));
// //     // printf("%s", get_next_line(fd));
// //    // printf("%s", get_next_line(fd));

// //     // printf("%s", get_next_line(fd));
// //     // get_next_line(fd);
// //     // get_next_line(fd);
// //     // get_next_line(fd);
// //     // get_next_line(fd);
// //     // get_next_line(fd);
// //     // get_next_line(fd);
// }