#include "shell.h"

void free_args(char **args, char **front);
char *get_pid(void);
char *get_env_value(char *beginning, int len);
void variable_replacement(char **args, int *exe_ret);

/**
 * free_args - Frees up memory taken by args.
 * @args: Null-terminated double pointer containing commands/arguments.
 * @front: Double pointer to the beginning of args.
 */
void free_args(char **args, char **front)
{
	size_t a;

	for (a = 0; args[a] || args[a + 1]; a++)
		free(args[a]);

	free(front);
}

/**
 * get_pid - Gets the current process ID.
 * Description: Opens the stat file, a space-delimited file containing
 *              information about the current process. The PID is the
 *              first word in the file. The function reads the PID into
 *              a buffer and replace the space at the end with a \0 byte.
 *
 * Return: Current process ID or NULL on failure.
 */
char *get_pid(void)
{
	size_t a = 0;
	char *buffer;
	ssize_t file;

	file = open("/proc/self/stat", O_RDONLY);
	if (file == -1)
	{
		perror("Cant read file");
		return (NULL);
	}
	buffer = malloc(120);
	if (!buffer)
	{
		close(file);
		return (NULL);
	}
	read(file, buffer, 120);
	while (buffer[a] != ' ')
		a++;
	buffer[a] = '\0';

	close(file);
	return (buffer);
}

/**
 * get_env_value - Gets the value corresponding to an environmental variable.
 * @beginning: Environmental variable to search for.
 * @len: Length of the environmental variable to search for.
 *
 * Return: If the variable is not found - an empty string.
 *         Otherwise - Environmental variable value.
 *
 * Description: Variables are stored in the format VARIABLE=VALUE.
 */
char *get_env_value(char *beginning, int len)
{
	char **var_addr;
	char *replacement = NULL, *temp, *var;

	var = malloc(len + 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	_strncat(var, beginning, len);

	var_addr = _getenv(var);
	free(var);
	if (var_addr)
	{
		temp = *var_addr;
		while (*temp != '=')
			temp++;
		temp++;
		replacement = malloc(_strlen(temp) + 1);
		if (replacement)
			_strcpy(replacement, temp);
	}

	return (replacement);
}

/**
 * variable_replacement - Handles variable replacement.
 * @line: Double pointer containing the command and arguments.
 * @exe_ret: Pointer to the return value of the last executed command.
 *
 * Description: Replaces $$ with the current PID, $? with the return value
 *              of the last executed program, and envrionmental variables
 *              preceded by $ with their corresponding value.
 */
void variable_replacement(char **line, int *exe_ret)
{
	int x, y = 0, len;
	char *replacement = NULL, *old_line = NULL, *new_line;

	old_line = *line;
	for (x = 0; old_line[x]; x++)
	{
		if (old_line[x] == '$' && old_line[x + 1] &&
				old_line[x + 1] != ' ')
		{
			if (old_line[x + 1] == '$')
			{
				replacement = get_pid();
				y = x + 2;
			}
			else if (old_line[x + 1] == '?')
			{
				replacement = _itoa(*exe_ret);
				y = x + 2;
			}
			else if (old_line[x + 1])
			{
				/* extract the variable name to search for */
				for (y = x + 1; old_line[y] &&
						old_line[y] != '$' &&
						old_line[y] != ' '; y++)
					;
				len = y - (x + 1);
				replacement = get_env_value(&old_line[x + 1], len);
			}
			new_line = malloc(x + _strlen(replacement)
					  + _strlen(&old_line[y]) + 1);
			if (!line)
				return;
			new_line[0] = '\0';
			_strncat(new_line, old_line, x);
			if (replacement)
			{
				_strcat(new_line, replacement);
				free(replacement);
				replacement = NULL;
			}
			_strcat(new_line, &old_line[y]);
			free(old_line);
			*line = new_line;
			old_line = new_line;
			x = -1;
		}
	}
}