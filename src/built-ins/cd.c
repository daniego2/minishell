#include "minishell.h"

int exec_cd(char **argv)
{
    if (!argv[1]) // No argumento para cd, vamos a HOME
    {
        if (chdir(getenv("HOME")) != 0)
        {
            perror("cd: No Home directory");  // Mensaje más claro
            return (1);  // Falla si no puede cambiar a HOME
        }
    }
    else
    {
        if (chdir(argv[1]) != 0)
        {
            perror("cd");  // Mensaje de error al intentar cambiar directorio
            return (1);  // Falla si no puede cambiar al directorio especificado
        }
    }
    return (0);  // Éxito si no hay errores
}
