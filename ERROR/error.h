#ifndef H_ERROR
#define H_ERROR

typedef int STATUT_CODE;

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void NEW_ERROR(const P_STR format, ...);

void NEW_INFO(const P_STR format, ...);

STATUT_CODE raise_error(STATUT_CODE code, P_STR message);

#define CRITICAL_FAILURE -1
#define SUCCESS 0
#define FAILURE 1


#endif
