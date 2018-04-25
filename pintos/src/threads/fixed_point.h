#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H

/* Basic definitions of fixed point. */

#define FP_CONST(a) ((int)(a << 16))
#define FP_ADD(a,b) (a + (b << 16))
#define FP_MULT(a,b) ((int)(((int64_t) a) * b >> 16))
#define FP_DIV(a,b) ((int)((((int64_t) a) << 16) / b))
#define FP_ROUND(a) (a >= 0 ? ((a + (1 << (16 - 1))) >> 16) \
		: ((a - (1 << (16 - 1))) >> 16))
#endif
