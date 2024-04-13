/*
 * File: main.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 11-Sep-2023 11:52:20
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "GJK.h"
#include "main.h"
#include "GJK_terminate.h"
#include "GJK_initialize.h"

/* Function Declarations */
static void argInit_5x1_real_T(double result[5]);
static void argInit_8x1_real_T(double result[8]);
static short argInit_int16_T(void);
static double argInit_real_T(void);
static void argInit_struct0_T(struct0_T *result);
static void argInit_struct1_T(struct1_T *result);
static void main_GJK(void);

/* Function Definitions */

/*
 * Arguments    : double result[5]
 * Return Type  : void
 */
static void argInit_5x1_real_T(double result[5])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 5; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[8]
 * Return Type  : void
 */
static void argInit_8x1_real_T(double result[8])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 8; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : short
 */
static short argInit_int16_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : struct0_T *result
 * Return Type  : void
 */
static void argInit_struct0_T(struct0_T *result)
{
  double result_tmp_tmp[5];
  int i;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_5x1_real_T(result_tmp_tmp);
  for (i = 0; i < 5; i++) {
    result->XData[i] = result_tmp_tmp[i];
    result->YData[i] = result_tmp_tmp[i];
    result->ZData[i] = result_tmp_tmp[i];
  }
}

/*
 * Arguments    : struct1_T *result
 * Return Type  : void
 */
static void argInit_struct1_T(struct1_T *result)
{
  double result_tmp_tmp[8];

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_8x1_real_T(result_tmp_tmp);
  memcpy(&result->XData[0], &result_tmp_tmp[0], sizeof(double) << 3);
  memcpy(&result->YData[0], &result_tmp_tmp[0], sizeof(double) << 3);
  memcpy(&result->ZData[0], &result_tmp_tmp[0], sizeof(double) << 3);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_GJK(void)
{
  struct0_T r0;
  struct1_T r1;
  double flag;

  /* Initialize function 'GJK' input arguments. */
  /* Initialize function input argument 'shape1'. */
  /* Initialize function input argument 'shape2'. */
  /* Call the entry-point 'GJK'. */
  argInit_struct0_T(&r0);
  argInit_struct1_T(&r1);
  flag = GJK(&r0, &r1, argInit_int16_T());
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  GJK_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_GJK();

  /* Terminate the application.
     You do not need to do this more than one time. */
  GJK_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
