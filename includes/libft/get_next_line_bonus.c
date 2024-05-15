/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:34:34 by mstrauss          #+#    #+#             */
/*   Updated: 2023/12/14 21:05:34 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief writes n zeroed bytes to the string s
/// @param s string to be written to
/// @param n amount of bytes to be written
void	gnl_bzero(void *s, size_t n)
{
	unsigned char	*d;

	d = s;
	while (0 < n)
		d[--n] = 0;
}

/// @brief Determines char string length
/// @param s String to measure
/// @return Length of string including Nul-terminator
int	gnl_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		;
	return (i);
}

/// @brief reads more content from file using read() until new line is reached
/// @param tmp String to be built on
/// @param buffer Location to save the rest
/// @param fd filedescriptor to read from
/// @return built string, tmp
static char	*gnl_get_more(char *tmp, char *buffer, int fd)
{
	char	*new;
	int		bytes_read;

	bytes_read = 1;
	if (tmp == NULL)
		tmp = gnl_calloc(1, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	new = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (new == NULL)
		return (free(tmp), NULL);
	while (bytes_read && gnl_strchr(tmp, '\n') == -1)
	{
		bytes_read = read(fd, new, BUFFER_SIZE);
		if (bytes_read == -1)
			return (gnl_bzero(buffer, BUFFER_SIZE), gnl_bzero(new, BUFFER_SIZE),
				free(new), NULL);
		new[bytes_read] = '\0';
		tmp = gnl_strjoin(tmp, new);
		if (tmp == NULL)
			return (free(new), free(tmp), NULL);
		if (gnl_strlen(tmp) == 0)
			return (free(new), free(tmp), NULL);
	}
	return (free(new), tmp);
}

/// @brief 		Gets the next line from the file pointed to by fd,
///				returning the corresponding following line in concurrent calls
/// @param fd 	filedescriptor to read from
/// @return 	Read line:  correct behavior
/// 			NULL: there is nothing else to read, or an error occurred
char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*tmp;
	char		*final;
	int			nl_index;

	if (fd > 1023 || fd < 0)
		return (NULL);
	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (gnl_bzero(buffer[fd], BUFFER_SIZE + 1), NULL);
	tmp = gnl_strdup(buffer[fd]);
	if (tmp == NULL)
		return (NULL);
	gnl_bzero(buffer[fd], BUFFER_SIZE);
	tmp = gnl_get_more(tmp, buffer[fd], fd);
	if (tmp == NULL)
		return (NULL);
	nl_index = gnl_strchr(tmp, '\n');
	if ((nl_index == 0 && tmp[0] != '\n') || nl_index == -1)
		return (tmp);
	final = gnl_calloc(nl_index + 2, sizeof(char));
	if (final == NULL)
		return (free(tmp), NULL);
	gnl_strlcpy(buffer[fd], &tmp[nl_index + 1], BUFFER_SIZE);
	gnl_strlcpy(final, tmp, nl_index + 2);
	return (free(tmp), final);
}
