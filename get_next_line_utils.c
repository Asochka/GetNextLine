#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[j] != '\0')
		newstr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free(s1);
	free(s2);
	return (newstr);
}

char	*ft_create_line(int	*i, char	*buf, char	*word)
{
	int	j;

	j = 0;
	while (buf[i + j] && buf[i + j] != '\n')
		j++;
	word2 = malloc(j + 1 + (buf[i + j] == '\n'));
	if (!word2)
	{
		if (word[0])
			return (word);
		free(word);//!!!
		return (NULL);
	}
	j = 0;
	while (buf[i] && buf[i] != '\n')
		word2[j++] = buf[i++];
	if (buf[i] == '\n')
		word2[j++] = '\n';
	word2[j] = '\0';
	word = ft_strjoin(word, word2);
	return (word);
}

	// if (j == 0 && buf[i] == '\n')
	// {
	// 	free(word);
	// 	word = malloc(2);
	// 	word[0] = '\n';
	// 	word[1] = '\0';
	// }