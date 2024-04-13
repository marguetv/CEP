/*
 * File: _coder_GJK_api.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 11-Sep-2023 11:52:20
 */

#ifndef _CODER_GJK_API_H
#define _CODER_GJK_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_GJK_api.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T XData[5];
  real_T YData[5];
  real_T ZData[5];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T XData[8];
  real_T YData[8];
  real_T ZData[8];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T GJK(struct0_T *shape1, struct1_T *shape2, int16_T iterations);
extern void GJK_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray
                    *plhs[1]);
extern void GJK_atexit(void);
extern void GJK_initialize(void);
extern void GJK_terminate(void);
extern void GJK_xil_terminate(void);

#endif

/*
 * File trailer for _coder_GJK_api.h
 *
 * [EOF]
 */
