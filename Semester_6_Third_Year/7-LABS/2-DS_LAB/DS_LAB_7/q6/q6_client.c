/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "q6.h"


void
arr_prog_2(char *host,int n,int* arr)
{
	CLIENT *clnt;
	arraysize  *result_1;
	arraysize  arrop_2_arg = {arr,n};

#ifndef	DEBUG
	clnt = clnt_create (host, ARR_PROG, VERSION1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = arrop_2(&arrop_2_arg, clnt);
	if (result_1 == (arraysize *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("Min:%d\nMax:%d\nAvg:%d\n",result_1->arr[0],result_1->arr[1],result_1->arr[2]);
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	int n = atoi(argv[2]);
	int arr[n];
	for(int i=0;i<n;i++)arr[i] = atoi(argv[i+3]);
	arr_prog_2 (host,n,arr);
exit (0);
}
