#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

/* 17 Bits used for before-decimal part */
#define P 17
/* 14 Bits used for after-decimal part */
#define Q 14
/* Fraction value */
#define FRACTION 1 << Q

/* Convert integer N to fixed point format */
#define FP_CONV(N) (N) * (FRACTION)
/* Get integer part from fixed point value F */
#define INT_CONV(F) (F) / (FRACTION)
/* Get rounded integer of fixed point value F */
#define INT_ROUND(F) ((F) >= 0 ? ((F) + (FRACTION) / 2) / (FRACTION) : ((F) - (FRACTION) / 2) / (FRACTION))

/* Add two fixed point value, A plus B */
#define FP_ADD(A, B) (A) + (B)
/* Subtract two fixed point value, A minus B */
#define FP_SUB(A, B) (A) - (B)
/* Multiply two fixed point value, A times B */
#define FP_MUL(A, B) ((int64_t)(A)) * (B) / (FRACTION)
/* Divide two fixed point value, A by B */
#define FP_DIV(A, B) ((int64_t)(A)) * (FRACTION) / (B)

/* Mixed version of Addition */
#define FP_ADD_MIX(A, N) (A) + (FRACTION) * (N)
/* Mixed version of Subtraction */
#define FP_SUB_MIX(A, N) (A) - (FRACTION) * (N)
/* Mixed version of Multiplication */
#define FP_MUL_MIX(A, N) (A) * (N)
/* Mixed version of Division */
#define FP_DIV_MIX(A, N) (A) / (N)

#endif
