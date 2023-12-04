// kernels.h

#ifndef KERNELS_H
#define KERNELS_H

#include "types.h"

f64 dotprod_base(f64 *restrict, f64 *restrict, u64);
f64 dotprod_cblas(f64 *restrict, f64 *restrict, u64);
f64 dotprod_unroll4(f64 *restrict, f64 *restrict, u64);
f64 dotprod_unroll8(f64 *restrict, f64 *restrict, u64); // Add this line

#endif // KERNELS_H

