/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "q5.h"


void
swap_prog_1(char *host,int a,int b)
{
	CLIENT *clnt;
	intpair  *result_1;
	intpair  swap_1_arg = {a,b};

#ifndef	DEBUG
	clnt = clnt_create (host, SWAP_PROG, VERSION1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = swap_1(&swap_1_arg, clnt);
	if (result_1 == (intpair *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("a: %d , b: %d \n",result_1->a,result_1->b);

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 4) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	int a = atoi(argv[2]);
	int b = atoi(argv[3]);
	swap_prog_1 (host,a,b);
exit (0);
}
