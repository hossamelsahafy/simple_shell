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

char **p_l(char *s);

char c_b(char *token);

int e_b(char **ts, char **env);

void execute(char **ts, char **env);

void handler(int sig);

void pipes(char *i, char *cmd[MAX_C][MAX_A], int p);

int _strlen(const char *s);

char *_strcpy(char *dest, char *src);

char *_strcat(char *dest, char *src);

int _path(int argc, char **argv, char **env);

void execute_pipes(char *cmd[MAX_C][MAX_A], int p);

void loop(char **env);
#endif
