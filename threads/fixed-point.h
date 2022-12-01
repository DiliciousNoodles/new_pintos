#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#define P 17
#define Q 14
#define f 1<<Q

#define convert_to_fp(x)  (x)*(f)
#define convert_to_int_zero(x)  (x)/(f)
#define convert_to_int_nearest(x)  ((x)>=0 ? ((x)+(f)/2)/(f) : ((x)-(f)/2)/(f))
#define add_int(x,n) (x)+(n)*(f)
#define sub_int(x,n) (x)-(n)*(f)
#define mul_fp(x,y) ((int64_t)x)*(y)/(f)
#define div_fp(x,y) ((int64_t)x)*(f)/(y)

#endif /* threads/fixed-point.h */
