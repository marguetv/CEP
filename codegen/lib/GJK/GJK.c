/*
 * File: GJK.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 11-Sep-2023 11:52:20
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "GJK.h"

/* Function Declarations */
static void support(const double shape1_XData[5], const double shape1_YData[5],
                    const double shape1_ZData[5], const double shape2_XData[8],
                    const double shape2_YData[8], const double shape2_ZData[8],
                    const double v[3], double point[3]);

/* Function Definitions */

/*
 * Support function to get the Minkowski difference.
 * Arguments    : const double shape1_XData[5]
 *                const double shape1_YData[5]
 *                const double shape1_ZData[5]
 *                const double shape2_XData[8]
 *                const double shape2_YData[8]
 *                const double shape2_ZData[8]
 *                const double v[3]
 *                double point[3]
 * Return Type  : void
 */
static void support(const double shape1_XData[5], const double shape1_YData[5],
                    const double shape1_ZData[5], const double shape2_XData[8],
                    const double shape2_YData[8], const double shape2_ZData[8],
                    const double v[3], double point[3])
{
  int idx;
  double dotted[5];
  int k;
  boolean_T exitg1;
  double ex;
  int iidx;
  double b_dotted[8];
  double d0;
  int b_iidx;

  /*  function point = support(shape1,shape2,v) */
  /*  %Support function to get the Minkowski difference. */
  /*  point1 = getFarthestInDir(shape1, v); */
  /*  point2 = getFarthestInDir(shape2, -v); */
  /*  point = point1 - point2; */
  /*  end */
  for (idx = 0; idx < 5; idx++) {
    dotted[idx] = (shape1_XData[idx] * v[0] + shape1_YData[idx] * v[1]) +
      shape1_ZData[idx] * v[2];
  }

  if (!rtIsNaN(dotted[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!rtIsNaN(dotted[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    iidx = 0;
  } else {
    ex = dotted[idx - 1];
    iidx = idx - 1;
    idx++;
    for (k = idx; k < 6; k++) {
      d0 = dotted[k - 1];
      if (ex < d0) {
        ex = d0;
        iidx = k - 1;
      }
    }
  }

  for (idx = 0; idx < 8; idx++) {
    b_dotted[idx] = -((shape2_XData[idx] * v[0] + shape2_YData[idx] * v[1]) +
                      shape2_ZData[idx] * v[2]);
  }

  if (!rtIsNaN(b_dotted[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!rtIsNaN(b_dotted[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    b_iidx = 0;
  } else {
    ex = b_dotted[idx - 1];
    b_iidx = idx - 1;
    idx++;
    for (k = idx; k < 9; k++) {
      d0 = b_dotted[k - 1];
      if (ex < d0) {
        ex = d0;
        b_iidx = k - 1;
      }
    }
  }

  point[0] = shape1_XData[iidx] - shape2_XData[b_iidx];
  point[1] = shape1_YData[iidx] - shape2_YData[b_iidx];
  point[2] = shape1_ZData[iidx] - shape2_ZData[b_iidx];
}

/*
 * GJK Gilbert-Johnson-Keerthi Collision detection implementation.
 *  Returns whether two convex shapes are are penetrating or not
 *  (true/false). Only works for CONVEX shapes.
 *
 *  Inputs:
 *    shape1:
 *    must have fields for XData,YData,ZData, which are the x,y,z
 *    coordinates of the vertices. Can be the same as what comes out of a
 *    PATCH object. It isn't required that the points form faces like patch
 *    data. This algorithm will assume the convex hull of the x,y,z points
 *    given.
 *
 *    shape2:
 *    Other shape to test collision against. Same info as shape1.
 *
 *    iterations:
 *    The algorithm tries to construct a tetrahedron encompassing
 *    the origin. This proves the objects have collided. If we fail within a
 *    certain number of iterations, we give up and say the objects are not
 *    penetrating. Low iterations means a higher chance of false-NEGATIVES
 *    but faster computation. As the objects penetrate more, it takes fewer
 *    iterations anyway, so low iterations is not a huge disadvantage.
 *
 *  Outputs:
 *    flag:
 *    true - objects collided
 *    false - objects not collided
 *
 *
 *    This video helped me a lot when making this: https://mollyrocket.com/849
 *    Not my video, but very useful.
 *
 *    Matthew Sheen, 2016
 * Arguments    : const struct0_T *shape1
 *                const struct1_T *shape2
 *                short iterations
 * Return Type  : double
 */
double GJK(const struct0_T *shape1, const struct1_T *shape2, short iterations)
{
  double flag;
  static const double v[3] = { 0.8, 0.5, 1.0 };

  double b[3];
  static const double dv0[3] = { -0.8, -0.5, -1.0 };

  double a[3];
  int b_flag;
  double ab_idx_0;
  double c_idx_0;
  double ab_idx_1;
  double c_idx_1;
  double ab_idx_2;
  double c_idx_2;
  double acp[3];
  double b_acp[3];
  int i;
  int exitg1;
  int i0;
  double acd_idx_2;
  double ac_idx_1;
  double ac_idx_0;
  double acd_idx_1;
  double ac_idx_2;
  double acd_idx_0;
  double abp_idx_0;
  double abp_idx_1;
  double abp_idx_2;
  boolean_T guard1 = false;
  double abc_idx_0;
  double abc_idx_1;
  double abc_idx_2;
  boolean_T exitg2;

  /* Point 1 and 2 selection (line segment) */
  /* Construct the first line of the simplex */
  support(shape1->XData, shape1->YData, shape1->ZData, shape2->XData,
          shape2->YData, shape2->ZData, v, b);
  support(shape1->XData, shape1->YData, shape1->ZData, shape2->XData,
          shape2->YData, shape2->ZData, dv0, a);

  /* Point 3 selection (triangle) */
  b_flag = 0;

  /* So far, we don't have a successful triangle. */
  /* First try: */
  ab_idx_0 = b[0] - a[0];
  c_idx_0 = b[0];
  b[0] = a[0];
  ab_idx_1 = b[1] - a[1];
  c_idx_1 = b[1];
  b[1] = a[1];
  ab_idx_2 = b[2] - a[2];
  c_idx_2 = b[2];
  b[2] = a[2];
  acp[0] = ab_idx_1 * -a[2] - ab_idx_2 * -a[1];
  acp[1] = ab_idx_2 * -a[0] - ab_idx_0 * -a[2];
  acp[2] = ab_idx_0 * -a[1] - ab_idx_1 * -a[0];

  /*  v is perpendicular to ab pointing in the general direction of the origin. */
  b_acp[0] = acp[1] * ab_idx_2 - acp[2] * ab_idx_1;
  b_acp[1] = acp[2] * ab_idx_0 - acp[0] * ab_idx_2;
  b_acp[2] = acp[0] * ab_idx_1 - acp[1] * ab_idx_0;
  support(shape1->XData, shape1->YData, shape1->ZData, shape2->XData,
          shape2->YData, shape2->ZData, b_acp, a);
  i = 0;
  do {
    exitg1 = 0;
    i0 = iterations - 1;
    if (i <= i0) {
      /* iterations to see if we can draw a good triangle. */
      /* Time to check if we got it: */
      acd_idx_2 = b[0] - a[0];
      ac_idx_1 = c_idx_0 - a[0];
      ac_idx_0 = b[1] - a[1];
      acd_idx_1 = c_idx_1 - a[1];
      ac_idx_2 = b[2] - a[2];
      ab_idx_0 = c_idx_2 - a[2];

      /* Normal to face of triangle */
      ab_idx_1 = ac_idx_0 * ab_idx_0 - ac_idx_2 * acd_idx_1;
      ab_idx_2 = ac_idx_2 * ac_idx_1 - acd_idx_2 * ab_idx_0;
      acd_idx_0 = acd_idx_2 * acd_idx_1 - ac_idx_0 * ac_idx_1;

      /* Perpendicular to AB going away from triangle */
      abp_idx_0 = ac_idx_0 * acd_idx_0 - ac_idx_2 * ab_idx_2;
      abp_idx_1 = ac_idx_2 * ab_idx_1 - acd_idx_2 * acd_idx_0;
      abp_idx_2 = acd_idx_2 * ab_idx_2 - ac_idx_0 * ab_idx_1;

      /* Perpendicular to AC going away from triangle */
      acp[0] = ab_idx_2 * ab_idx_0 - acd_idx_0 * acd_idx_1;
      acp[1] = acd_idx_0 * ac_idx_1 - ab_idx_1 * ab_idx_0;
      acp[2] = ab_idx_1 * acd_idx_1 - ab_idx_2 * ac_idx_1;

      /* First, make sure our triangle "contains" the origin in a 2d projection */
      /* sense. */
      /* Is origin above (outside) AB?    */
      guard1 = false;
      if ((abp_idx_0 * -a[0] + abp_idx_1 * -a[1]) + abp_idx_2 * -a[2] > 0.0) {
        /* Throw away the furthest point and grab a new one in the right direction */
        c_idx_0 = b[0];
        acp[0] = abp_idx_0;
        b[0] = a[0];
        c_idx_1 = b[1];
        acp[1] = abp_idx_1;
        b[1] = a[1];
        c_idx_2 = b[2];
        acp[2] = abp_idx_2;
        b[2] = a[2];

        /* cross(cross(ab,ao),ab); */
        /* Is origin above (outside) AC? */
        guard1 = true;
      } else if ((acp[0] * -a[0] + acp[1] * -a[1]) + acp[2] * -a[2] > 0.0) {
        b[0] = a[0];
        b[1] = a[1];
        b[2] = a[2];

        /* cross(cross(ac,ao),ac); */
        guard1 = true;
      } else {
        b_flag = 1;
        exitg1 = 1;
      }

      if (guard1) {
        support(shape1->XData, shape1->YData, shape1->ZData, shape2->XData,
                shape2->YData, shape2->ZData, acp, a);
        i++;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  flag = b_flag;

  /* Point 4 selection (tetrahedron) */
  if (b_flag == 1) {
    /* Only bother if we could find a viable triangle. */
    /* Now, if we're here, we have a successful 2D simplex, and we need to check */
    /* if the origin is inside a successful 3D simplex. */
    /* So, is the origin above or below the triangle? */
    flag = 0.0;

    /* Normal to face of triangle */
    ac_idx_2 = b[0] - a[0];
    acd_idx_2 = c_idx_0 - a[0];
    ac_idx_0 = b[1] - a[1];
    ac_idx_1 = c_idx_1 - a[1];
    acd_idx_1 = b[2] - a[2];
    ab_idx_0 = c_idx_2 - a[2];
    acp[0] = ac_idx_0 * ab_idx_0 - acd_idx_1 * ac_idx_1;
    ab_idx_1 = acd_idx_1 * acd_idx_2 - ac_idx_2 * ab_idx_0;
    acp[1] = acd_idx_1 * acd_idx_2 - ac_idx_2 * ab_idx_0;
    ab_idx_2 = ac_idx_2 * ac_idx_1 - ac_idx_0 * acd_idx_2;
    acp[2] = ac_idx_2 * ac_idx_1 - ac_idx_0 * acd_idx_2;
    if ((acp[0] * -a[0] + ab_idx_1 * -a[1]) + ab_idx_2 * -a[2] > 0.0) {
      /* Above */
      abc_idx_0 = c_idx_0;
      c_idx_0 = b[0];
      b[0] = a[0];
      abc_idx_1 = c_idx_1;
      c_idx_1 = b[1];
      b[1] = a[1];
      abc_idx_2 = c_idx_2;
      c_idx_2 = b[2];
      b[2] = a[2];
      support(shape1->XData, shape1->YData, shape1->ZData, shape2->XData,
              shape2->YData, shape2->ZData, acp, a);

      /* Tetrahedron new point */
    } else {
      /* below */
      abc_idx_0 = b[0];
      b_acp[0] = -(ac_idx_0 * ab_idx_0 - acd_idx_1 * ac_idx_1);
      b[0] = a[0];
      abc_idx_1 = b[1];
      b_acp[1] = -ab_idx_1;
      b[1] = a[1];
      abc_idx_2 = b[2];
      b_acp[2] = -ab_idx_2;
      b[2] = a[2];
      support(shape1->XData, shape1->YData, shape1->ZData, shape2->XData,
              shape2->YData, shape2->ZData, b_acp, a);

      /* Tetrahedron new point */
    }

    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i <= i0)) {
      /* Allowing 10 tries to make a good tetrahedron. */
      /* Check the tetrahedron: */
      ab_idx_0 = b[0] - a[0];
      ac_idx_0 = c_idx_0 - a[0];
      abp_idx_0 = abc_idx_0 - a[0];
      ab_idx_1 = b[1] - a[1];
      ac_idx_1 = c_idx_1 - a[1];
      abp_idx_1 = abc_idx_1 - a[1];
      ab_idx_2 = b[2] - a[2];
      ac_idx_2 = c_idx_2 - a[2];
      abp_idx_2 = abc_idx_2 - a[2];

      /* We KNOW that the origin is not under the base of the tetrahedron based on */
      /* the way we picked a. So we need to check faces ABC, ABD, and ACD. */
      /* Normal to face of triangle */
      acp[0] = ab_idx_1 * ac_idx_2 - ab_idx_2 * ac_idx_1;
      acp[1] = ab_idx_2 * ac_idx_0 - ab_idx_0 * ac_idx_2;
      acp[2] = ab_idx_0 * ac_idx_1 - ab_idx_1 * ac_idx_0;
      guard1 = false;
      if ((acp[0] * -a[0] + acp[1] * -a[1]) + acp[2] * -a[2] > 0.0) {
        /* Above triangle ABC */
        /* No need to change anything, we'll just iterate again with this face as */
        /* default. */
        guard1 = true;
      } else {
        acd_idx_0 = ac_idx_1 * abp_idx_2 - ac_idx_2 * abp_idx_1;
        acd_idx_1 = ac_idx_2 * abp_idx_0 - ac_idx_0 * abp_idx_2;
        acd_idx_2 = ac_idx_0 * abp_idx_1 - ac_idx_1 * abp_idx_0;

        /* Normal to face of triangle */
        ac_idx_0 = acd_idx_0 * -a[0];
        if ((ac_idx_0 + acd_idx_1 * -a[1]) + acd_idx_2 * -a[2] > 0.0) {
          /* Above triangle ACD */
          /* Make this the new base triangle. */
          b[0] = c_idx_0;
          acp[0] = acd_idx_0;
          c_idx_0 = abc_idx_0;
          b[1] = c_idx_1;
          acp[1] = acd_idx_1;
          c_idx_1 = abc_idx_1;
          b[2] = c_idx_2;
          acp[2] = acd_idx_2;
          c_idx_2 = abc_idx_2;
          guard1 = true;
        } else if ((ac_idx_0 + acd_idx_1 * -a[1]) + acd_idx_2 * -a[2] < 0.0) {
          acp[0] = abp_idx_1 * ab_idx_2 - abp_idx_2 * ab_idx_1;
          acp[1] = abp_idx_2 * ab_idx_0 - abp_idx_0 * ab_idx_2;
          acp[2] = abp_idx_0 * ab_idx_1 - abp_idx_1 * ab_idx_0;

          /* Normal to face of triangle */
          if ((acp[0] * -a[0] + acp[1] * -a[1]) + acp[2] * -a[2] > 0.0) {
            /* Above triangle ADB */
            /* Make this the new base triangle. */
            c_idx_0 = b[0];
            b[0] = abc_idx_0;
            c_idx_1 = b[1];
            b[1] = abc_idx_1;
            c_idx_2 = b[2];
            b[2] = abc_idx_2;
            guard1 = true;
          } else {
            flag = 1.0;
            exitg2 = true;
          }
        } else {
          guard1 = true;
        }
      }

      if (guard1) {
        /* try again: */
        if ((acp[0] * -a[0] + acp[1] * -a[1]) + acp[2] * -a[2] > 0.0) {
          /* Above */
          abc_idx_0 = c_idx_0;
          c_idx_0 = b[0];
          b[0] = a[0];
          abc_idx_1 = c_idx_1;
          c_idx_1 = b[1];
          b[1] = a[1];
          abc_idx_2 = c_idx_2;
          c_idx_2 = b[2];
          b[2] = a[2];
          support(shape1->XData, shape1->YData, shape1->ZData, shape2->XData,
                  shape2->YData, shape2->ZData, acp, a);

          /* Tetrahedron new point */
        } else {
          /* below */
          abc_idx_0 = b[0];
          b_acp[0] = -acp[0];
          b[0] = a[0];
          abc_idx_1 = b[1];
          b_acp[1] = -acp[1];
          b[1] = a[1];
          abc_idx_2 = b[2];
          b_acp[2] = -acp[2];
          b[2] = a[2];
          support(shape1->XData, shape1->YData, shape1->ZData, shape2->XData,
                  shape2->YData, shape2->ZData, b_acp, a);

          /* Tetrahedron new point */
        }

        i++;
      }
    }
  }

  return flag;
}

/*
 * File trailer for GJK.c
 *
 * [EOF]
 */
