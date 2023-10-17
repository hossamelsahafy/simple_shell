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
#include <errno.h>
#include <sys/stat.h>

extern char **environ;

char **p_l(char *s);

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

int non_interactive(char *l, char **env);

char path_handeler(char **ts, char *dir, char **env);

void exe_command(char **ts, char **env);
#endif
