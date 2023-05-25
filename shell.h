#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <ctype.h>
#include <errno.h>

#define STORAGE_SIZE 1024
extern char **environ;


char *my_copy_str(char *dss, const char *sourssing);
char **split_string(char *stringing, const char *sprt, int *wrdsN);
char *my_input_read();
size_t my_lenstr_get(const char *strringX);
void my_free_world(char **wrding, int numberW);

/* checks */
int my_files_exit(const char *pathing);
char *my_get_dirct_pat(const char *pathing, const char *commanding);
char *my_copy_get();

/* project fork */
int my_execute_forking(char **wordArray, char *uInput,
char *shellN, int cntrr, int n);
char *my_full_get_path(const char *commanding);
void my_execmdwithexecve(char *cmd, char **arr_of_words);
void my_waitkidproce(pid_t pidding, int *stt);
void my_execute_bin(char **wordArray);

/* Str manipulations */
char *my_cat_str(char *dess, const char *sourssing);
char *my_dupl_strin(const char *strr);
int my_cmp_str(const char *sttOne, const char *sttTwo, size_t nbr);
int my_atoy(const char *strr);

/*strings*/
ssize_t my_get_line(char **str, size_t *szzStr,
FILE *reading);
int my_read_input(char *reading);
void *my_re_allocation(void *VoidPointer, size_t szz);
void my_buf_upto(char **buffing, size_t *sezing, char *bff, size_t unicId);
void *my_memry_copy(void *destX, const void *resur, size_t bytNumber);


/**get red of exit , env setting, unenv setting*/
int my_handle_cmd(char **wordArr, char *uInput,
char *sh_name, int cnt, int n);
void my_hand_envs(void);
int my_env_set(const char *envN, const char *nvvl, int envOver);
int my_unsetenvs(const char *envvN);

/*get red of routing*/
void my_cd_comd(char **wordArra);

/* function of file H */
char *my_envvars(const char *envChar, char **envPtr);
void my_error(const char *message);
char *my_getdir(const char *pathing);
char *my_handlecwd();
void my_swit_currdir(const char *drtrPointer);
void my_execommndewithexecve(char *commnde, char **wordArray);

/*cmprair function*/
int my_cmp_strn(const char *one, const char *two);

/*multiplee comandes*/
int my_exec_cmd(char *uInput, char *shell, int contre);

void my_print_err(char *contry, char *sh, char *commanding, char *messaging);
int my_valid_word(char *string);
char *myint_to_string(int numbrX);
void my_handle_sign(int sigging);
void my_handle_exit(char **wordArray, char *uInput,
char *shellN, int contre, int nX);
void my_exerr(char **wordArray, int contr, char *shell);
int my_digit(int y);
#endif

