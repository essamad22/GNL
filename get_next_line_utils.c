/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:02:27 by aakhtab           #+#    #+#             */
/*   Updated: 2022/12/07 21:02:29 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "leak_hunter.h

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	i = 0;
	if (p1 == p2)
		return (dst);
	while (n > 0)
	{
		p1[i] = p2[i];
		n--;
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s1);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, len + 1);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*new_str;
	size_t	i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!str1 && !str2)
		return (NULL);
    else if (!str1)
        return (ft_strdup(str2));
    else if (!str2)
        return (ft_strdup(str1));
	i = ft_strlen(str1) + ft_strlen(str2);
	new_str = malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str1, ft_strlen(str1));
	ft_memcpy((new_str + ft_strlen(str1)), str2, ft_strlen(str2));
	new_str[i] = '\0';
	free(str1);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != (unsigned char )c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

int get_len(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}