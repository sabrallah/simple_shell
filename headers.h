#ifndef _HEADERS_H_
#define _HEADERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* porpose of reading /buffers writing */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* porpose is chain commands*/
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* porpose is my_convnum() function */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* returning number 1 if using system getline() function */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/* toem_errors.c */
void my_printstr(char *);
int my_chrtostderr(char);
int my_chrtofd(char ch, int f_d);
int my_strtofd(char *strPtr, int f_d);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *my_strstart(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *my_strlimit(char *, char *, int);
char *my_strconc(char *, char *, int);
char *my_strfin(char *, char);

/* toem_tokenizer.c */
char **mystrdil(char *, char *);

/* toem_realloc.c */
void my_freestr(char **);
void *my_ralloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int my_free(void **);

/* toem_atoi.c */
int myInteractive(info_t *);
int mydelimiter(char, char *);
int myalphabetic(int);
int my_covert_int(char *);

/* toem_errors1.c */
int my_strtoint(char *);
void my_erroprint(info_t *, char *);
int my_decimprint(int, int);
char *my_convnum(long int, int, int);
void my_rmcomment(char *);

/* toem_builtin.c */
int my_exitshell(info_t *);
int my_chgdir(info_t *);
int my_disphelp(info_t *);

/* toem_builtin1.c */
int my_histoir(info_t *);
int my_builtalias(info_t *);

/*toem_getline.c */
ssize_t my_input(info_t *);
int my_lineget(info_t *, char **, size_t *);
void my_interrupt(int);

/* toem_getinfo.c */
void my_infodel(info_t *);
void my_setinf(info_t *, char **);
void my_freinf(info_t *, int);

/* toem_environ.c */
char *my_getenv(info_t *, const char *);
int my_prinenv(info_t *);
int my_initenv(info_t *);
int my_rmenv(info_t *);
int my_popenvir(info_t *);

/* toem_getenv.c */
char **my_envcopy(info_t *);
int my_delenv(info_t *, char *);
int my_envsett(info_t *, char *, char *);

/* toem_history.c */
char *my_history_get(info_t *myinfo);
int my_writhisto(info_t *myinfo);
int my_histread(info_t *myinfo);
int my_histori_make(info_t *myinfo, char *bufPtr, int my_linecount);
int my_histor_renum(info_t *infoPtr);

/* toem_lists.c */
list_t *my_appen_nod(list_t **, const char *, int);
size_t my_strvalue(const list_t *);
int my_remov_node_index(list_t **, unsigned int);
void my_listdest(list_t **);

/* toem_lists1.c */
size_t my_lilen(const list_t *);
char **my_conv_strin(list_t *);
size_t my_listpr(const list_t *);
list_t *my_find_node(list_t *, char *, char);
ssize_t my_get_index(list_t *, list_t *);

/* toem_vars.c */
int my_chain(info_t *, char *, size_t *);
void my_chkchain(info_t *, char *, size_t *, size_t, size_t);
int resolve_alias(info_t *);
int my_resolvar(info_t *);

#endif

