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

/**
 * struct listingstr - a singl linked list struct
 * @numInt: fielded number
 * @strChar: string pointer
 * @nxt: ti pointshte nexting node
 */
typedef struct listingstr
{
	int numInt;
	char *strChar;
	struct listingstr *nxt;
} listing_t;

/**
 * struct passinginfo - pseudo-arguements, passing into a function,
 * allow  prototype of uniform for pointer function struct.
 * @argChar: generat string from getingline arguements to be containing
 * @argvChar: string array generat from argChar
 * @pathChar: path string for current command.
 * @argcInt: count of argument
 * @line_countInt: count of error
 * @err_numInt: code of error for exits function
 * @linecount_flagInt: input line in case counting
 * @fnameChar: filename program
 * @envList: linked list is localy copying of environing
 * @environChar: modife custom environ coping from envList
 * @historyList: node history
 * @aliasList: node alias
 * @env_changedInt: change in case environing
 * @statusInt: status returned of last exec'd commanding
 * @cmd_bufChar: pointer address to cmd_bufChar, in case of chain
 * @cmd_buf_typeInt: CMD_typing || and &&.
 * @readfdInt: from fd which to reading line input.
 * @histcountInt: line history counting numbers
 */
typedef struct passinginfo
{
	char *argChar;
	char **argvChar;
	char *pathChar;
	int argcInt;
	unsigned int line_countInt;
	int err_numInt;
	int linecount_flagInt;
	char *fnameChar;
	listing_t *envList;
	listing_t *historyList;
	listing_t *aliasList;
	char **environChar;
	int env_changedInt;
	int statusInt;

	char **cmd_bufChar; /* cmd pointer and mangement porpose of memory */
	int cmd_buf_typeInt; /* CMD_typing or, and, andlin */
	int readfdInt;
	int histcountInt;
} info_pass;


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
int myInteractive(info_pass *);
int mydelimiter(char, char *);
int myalphabetic(int);
int my_covert_int(char *);

/* toem_errors1.c */
int my_strtoint(char *);
void my_erroprint(info_pass *, char *);
int my_decimprint(int, int);
char *my_convnum(long int, int, int);
void my_rmcomment(char *);

/* toem_builtin.c */
int my_exitshell(info_pass *);
int my_chgdir(info_pass *);
int my_disphelp(info_pass *);

/* toem_builtin1.c */
int my_histoir(info_pass *);
int my_builtalias(info_pass *);

/*toem_getline.c */
ssize_t my_input(info_pass *);
int my_lineget(info_pass *, char **, size_t *);
void my_interrupt(int);

/* toem_getinfo.c */
void my_infodel(info_pass *);
void my_setinf(info_pass *, char **);
void my_freinf(info_pass *, int);

/* toem_environ.c */
char *my_getenv(info_pass *, const char *);
int my_prinenv(info_pass *);
int my_initenv(info_pass *);
int my_rmenv(info_pass *);
int my_popenvir(info_pass *);

/* toem_getenv.c */
char **my_envcopy(info_pass *);
int my_delenv(info_pass *, char *);
int my_envsett(info_pass *, char *, char *);

/* toem_history.c */
char *my_history_get(info_pass *myinfo);
int my_writhisto(info_pass *myinfo);
int my_histread(info_pass *myinfo);
int my_histori_make(info_pass *myinfo, char *bufPtr, int my_linecount);
int my_histor_renum(info_pass *infoPtr);

/* toem_lists.c */
listing_t *my_appen_nod(listing_t **, const char *, int);
size_t my_strvalue(const listing_t *);
int my_remov_node_index(listing_t **, unsigned int);
void my_listdest(listing_t **);

/* toem_lists1.c */
size_t my_lilen(const listing_t *);
char **my_conv_strin(listing_t *);
size_t my_listpr(const listing_t *);
listing_t *my_find_node(listing_t *, char *, char);
ssize_t my_get_index(listing_t *, listing_t *);

/* toem_vars.c */
int my_chain(info_pass *, char *, size_t *);
void my_chkchain(info_pass *, char *, size_t *, size_t, size_t);
int resolve_alias(info_pass *);
int my_resolvar(info_pass *);

#endif

