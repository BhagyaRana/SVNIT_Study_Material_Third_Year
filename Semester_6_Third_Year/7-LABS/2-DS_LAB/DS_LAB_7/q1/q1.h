/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _Q1_H_RPCGEN
#define _Q1_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


#define PALINDROME_PROG 0x4562877
#define VERSION1 1

#if defined(__STDC__) || defined(__cplusplus)
#define palindrome 1
extern  int * palindrome_1(char **, CLIENT *);
extern  int * palindrome_1_svc(char **, struct svc_req *);
extern int palindrome_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define palindrome 1
extern  int * palindrome_1();
extern  int * palindrome_1_svc();
extern int palindrome_prog_1_freeresult ();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_Q1_H_RPCGEN */