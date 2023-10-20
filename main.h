#ifndef MAIN_H
#define MAIN_H

#define MAX_C 10
#define MAX_A 10
#define MAX_P 8
#define _POSIX_C_SOURCE 200809L
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<signal.h>
#include <errno.h>
#include <sys/stat.h>

/**
 * struct alias - struct to store name and value
 *
 * @name: to idntify Alias name
 *
 * @value: to identify Alias value
*/
typedef struct alias
{
	char name[100];
	char value[100];
} Alias;

/**
 * struct shell - Struct to store shell data
 *
 * @aliases: Array of aliases
 *
 * @alias_c: Number of aliases
 */

typedef struct shell
{
	Alias aliases[100];
	int alias_c;
} Shell;

extern char **environ;

char **p_l(char *l);

char c_b(char *token);

int e_b(char **ts, char **env);

void handler(int sig);

void pipes(char *i, char *cmd[MAX_C][MAX_A], int p);

void execute(char **ts, char **env);

int _strlen(const char *s);

char *_strcpy(char *dest, char *src);

char *_strcat(char *dest, char *src);

void loop(char **env);

void exe_echo(char **ts);

void exe_cat(char **ts);

char *_strchr(char *s, char c);

int _strcmp(char *s1, char *s2);

int non_interactive(char **env);

char path_handeler(char **ts, char *dir, char **env);

int exe_command(char **ts, char **env);

char *_strdup(char *s);

int handle_env(char **env);

int handle_cd(char **ts);

void comment_handeler(char *ts);

void r_v(char **ts, int exit_status, int pid);

void int_to_str(int n, char *str);

void pro_l(char *l, char **env);

int _atoi(char *s);

void handle_semi(char *i, char **env);

void s_d(char *l, char **env);

void pwd_handler(void);

void alias_handler(Shell *shell, char **ars);

void exit_handler(char **ts);

#endif
