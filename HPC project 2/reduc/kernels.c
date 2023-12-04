#if defined(__INTEL_COMPILER)
#include <mkl.h>
#else
#include <cblas.h>
#endif

#include "types.h"


f64 reduc_base(f64 *restrict a, u64 n)
{
    double d = 0.0;

    for (u64 i = 0; i < n; i++)
        d += a[i];

    return d;
}

f64 reduc_cblas(f64 *restrict a, u64 n)
{
  f64 _b= 1;
  return cblas_ddot(n, a, 1, &_b, 0);
}


f64 reduc_unroll4(f64 *restrict a, u64 n)
{
    double d = 0.0;

    u64 i;
    for (i = 0; i < n - 3; i += 4)
    {
        d += a[i] + a[i + 1] + a[i + 2] + a[i + 3];
    }

    
    for (; i < n; i++)
    {
        d += a[i];
    }

    return d;
}

f64 reduc_unroll8(f64 *restrict a, u64 n)
{
    double d = 0.0;

    u64 i;
    for (i = 0; i < n - 7; i += 8)
    {
        d += a[i] + a[i + 1] + a[i + 2] + a[i + 3] + a[i + 4] + a[i + 5] + a[i + 6] + a[i + 7];
    }

    
    for (; i < n; i++)
    {
        d += a[i];
    }

    return d;
}
