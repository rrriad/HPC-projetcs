// kernels.c

#if defined(__INTEL_COMPILER)
#include <mkl.h>
#else
#include <cblas.h>
#endif

#include "types.h"

// CBLAS implementation
f64 dotprod_cblas(f64 *restrict a, f64 *restrict b, u64 n)
{
  return cblas_ddot(n, a, 1, b, 1);
}

// Baseline - naive implementation
f64 dotprod_base(f64 *restrict a, f64 *restrict b, u64 n)
{
  double d = 0.0;

  for (u64 i = 0; i < n; i++)
    d += a[i] * b[i];

  return d;
}

// Unroll4 implementation
f64 dotprod_unroll4(f64 *restrict a, f64 *restrict b, u64 n)
{
  u64 i;
  f64 sum = 0.0;

  // Unroll the loop by a factor of 4
  for (i = 0; i < n - 3; i += 4)
  {
    sum += a[i] * b[i] +
           a[i + 1] * b[i + 1] +
           a[i + 2] * b[i + 2] +
           a[i + 3] * b[i + 3];
  }

  // Handle any remaining elements
  for (; i < n; ++i)
  {
    sum += a[i] * b[i];
  }

  return sum;
}

// Unroll8 implementation
f64 dotprod_unroll8(f64 *restrict a, f64 *restrict b, u64 n)
{
  u64 i;
  f64 sum = 0.0;

  // Unroll the loop by a factor of 8
  for (i = 0; i < n - 7; i += 8)
  {
    sum += a[i] * b[i] +
           a[i + 1] * b[i + 1] +
           a[i + 2] * b[i + 2] +
           a[i + 3] * b[i + 3] +
           a[i + 4] * b[i + 4] +
           a[i + 5] * b[i + 5] +
           a[i + 6] * b[i + 6] +
           a[i + 7] * b[i + 7];
  }

  for (; i < n; ++i)
  {
    sum += a[i] * b[i];
  }

  return sum;
}

