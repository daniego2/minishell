/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:26:00 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/06 16:26:01 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **allocate_no_delimiter(char *str)
{
    char **result;

    result = malloc(sizeof(char *) * 2);
    if (!result)
        return (NULL);
    result[0] = ft_strdup(str);
    if (!result[0])
    {
        free(result);
        return (NULL);
    }
    result[1] = NULL;
    return (result);
}

char **allocate_with_delimiter(char *str, char *delimiter_pos)
{
    char **result;
    size_t key_len;

    key_len = delimiter_pos - str;
    result = malloc(sizeof(char *) * 3);
    if (!result)
        return (NULL);
    result[0] = malloc(key_len + 1);
    if (!result[0])
    {
        free(result);
        return (NULL);
    }
    ft_strncpy(result[0], str, key_len);
    result[0][key_len] = '\0';
    result[1] = ft_strdup(delimiter_pos + 1);
    if (!result[1])
    {
        free(result[0]);
        free(result);
        return (NULL);
    }
    result[2] = NULL;
    return (result);
}

char **ft_split_first(char *str, char delimiter)
{
    char *delimiter_pos;
    char **line;

    if (!str)
        return (NULL);
    delimiter_pos = ft_strchr(str, delimiter);
    if (!delimiter_pos)
        return (allocate_no_delimiter(str));
    line = allocate_with_delimiter(str, delimiter_pos);
    return (line);
}

t_env *get_env(char **env)
{
    int i = 0;
    char **line;
    t_env *environment = NULL;

    while (env[i] != NULL)
    {
        line = ft_split_first(env[i], '=');
        if (line && line[0])
        {
            if (!environment)
                environment = create_node(line[0], line[1]);
            else
                add_node(&environment, line[0], line[1]);
        }
        free(line[0]);
        free(line[1]);
        free(line);
        i++;
    }
    return (environment);
}
