/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _Q6_H_RPCGEN
#define _Q6_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct arraysize {
	int *arr;
	int size;
};
typedef struct arraysize arraysize;

#define ARR_PROG 0x20000005
#define VERSION1 2

#if defined(__STDC__) || defined(__cplusplus)
#define arrop 1
extern  arraysize * arrop_2(arraysize *, CLIENT *);
extern  arraysize * arrop_2_svc(arraysize *, struct svc_req *);
extern int arr_prog_2_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define arrop 1
extern  arraysize * arrop_2();
extern  arraysize * arrop_2_svc();
extern int arr_prog_2_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_arraysize (XDR *, arraysize*);

#else /* K&R C */
extern bool_t xdr_arraysize ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_Q6_H_RPCGEN */