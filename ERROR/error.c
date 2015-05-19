#include "../common.h"

void NEW_ERROR(const P_STR message, ...)
{
    printf("%s%s",KGRN,message);
}

void NEW_INFO(const P_STR format, ...)
{
	va_list arg;

	printf("INFO : ");

	va_start (arg, format);
	vfprintf (stdout, format, arg);
	va_end (arg);

	printf("\n");
}

STATUT_CODE raise_error(STATUT_CODE code, P_STR message)
{
	switch(code)
	{
		case SUCCESS:

		break;
		case FAILURE:

		break;
		case CRITICAL_FAILURE:
			perror(message);
			return code;
		break;
	}

	return code;
}
