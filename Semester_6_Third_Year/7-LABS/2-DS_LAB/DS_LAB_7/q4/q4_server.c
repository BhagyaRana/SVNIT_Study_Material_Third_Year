/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "q4.h"

float *
sqrt_1_svc(float *argp, struct svc_req *rqstp)
{
	static float  result;

	/*
	 * insert server code here
	 */
	printf("Sqrt for %f is called\n",*argp);
	float err = 0.00001f;

	float a = *argp;
	float b = 2.0f;
	if(abs(b-a)<=err) b = 1.5f;

	while((b-a)>err || (a-b)>err){
		a = *argp/b;
		b = (a+b)/2;
	}
	result = a;
	return &result;
}