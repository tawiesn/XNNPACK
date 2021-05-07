// Auto-generated file. Do not edit!
//   Template: src/f32-vsigmoid/avx512f-p5-scalef.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include <xnnpack/common.h>
#include <xnnpack/intrinsics-polyfill.h>
#include <xnnpack/vunary.h>


void xnn_f32_vsigmoid_ukernel__avx512f_rr1_p5_scalef_nr1fma_x96(
    size_t n,
    const float* x,
    float* y,
    const void* params)
{
  assert(n % sizeof(float) == 0);

  const __m512i vsign_mask = _mm512_set1_epi32(0x80000000);
  const __m512 vlog2e = _mm512_set1_ps(0x1.715476p+0f);
  const __m512 vminus_ln2 = _mm512_set1_ps(-0x1.62E43p-1f);
  const __m512 vc5 = _mm512_set1_ps(0x1.0F9F9Cp-7f);
  const __m512 vc4 = _mm512_set1_ps(0x1.573A1Ap-5f);
  const __m512 vc3 = _mm512_set1_ps(0x1.555A80p-3f);
  const __m512 vc2 = _mm512_set1_ps(0x1.FFFDC6p-2f);
  const __m512 vc1 = _mm512_set1_ps(0x1.FFFFF6p-1f);
  const __m512 vone = _mm512_set1_ps(1.0f);

  for (; n >= 96 * sizeof(float); n -= 96 * sizeof(float)) {
    const __m512 vx0 = _mm512_loadu_ps(x);
    const __m512 vx1 = _mm512_loadu_ps(x + 16);
    const __m512 vx2 = _mm512_loadu_ps(x + 32);
    const __m512 vx3 = _mm512_loadu_ps(x + 48);
    const __m512 vx4 = _mm512_loadu_ps(x + 64);
    const __m512 vx5 = _mm512_loadu_ps(x + 80);
    x += 96;

    const __m512 vz0 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx0), vsign_mask));
    const __m512 vz1 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx1), vsign_mask));
    const __m512 vz2 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx2), vsign_mask));
    const __m512 vz3 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx3), vsign_mask));
    const __m512 vz4 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx4), vsign_mask));
    const __m512 vz5 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx5), vsign_mask));

    __m512 vn0 = _mm512_mul_ps(vz0, vlog2e);
    __m512 vn1 = _mm512_mul_ps(vz1, vlog2e);
    __m512 vn2 = _mm512_mul_ps(vz2, vlog2e);
    __m512 vn3 = _mm512_mul_ps(vz3, vlog2e);
    __m512 vn4 = _mm512_mul_ps(vz4, vlog2e);
    __m512 vn5 = _mm512_mul_ps(vz5, vlog2e);

    vn0 = _mm512_roundscale_ps(vn0, 0);
    vn1 = _mm512_roundscale_ps(vn1, 0);
    vn2 = _mm512_roundscale_ps(vn2, 0);
    vn3 = _mm512_roundscale_ps(vn3, 0);
    vn4 = _mm512_roundscale_ps(vn4, 0);
    vn5 = _mm512_roundscale_ps(vn5, 0);

    __m512 vt0 = _mm512_fmadd_ps(vn0, vminus_ln2, vz0);
    __m512 vt1 = _mm512_fmadd_ps(vn1, vminus_ln2, vz1);
    __m512 vt2 = _mm512_fmadd_ps(vn2, vminus_ln2, vz2);
    __m512 vt3 = _mm512_fmadd_ps(vn3, vminus_ln2, vz3);
    __m512 vt4 = _mm512_fmadd_ps(vn4, vminus_ln2, vz4);
    __m512 vt5 = _mm512_fmadd_ps(vn5, vminus_ln2, vz5);

    __m512 vp0 = _mm512_fmadd_ps(vc5, vt0, vc4);
    __m512 vp1 = _mm512_fmadd_ps(vc5, vt1, vc4);
    __m512 vp2 = _mm512_fmadd_ps(vc5, vt2, vc4);
    __m512 vp3 = _mm512_fmadd_ps(vc5, vt3, vc4);
    __m512 vp4 = _mm512_fmadd_ps(vc5, vt4, vc4);
    __m512 vp5 = _mm512_fmadd_ps(vc5, vt5, vc4);

    vp0 = _mm512_fmadd_ps(vp0, vt0, vc3);
    vp1 = _mm512_fmadd_ps(vp1, vt1, vc3);
    vp2 = _mm512_fmadd_ps(vp2, vt2, vc3);
    vp3 = _mm512_fmadd_ps(vp3, vt3, vc3);
    vp4 = _mm512_fmadd_ps(vp4, vt4, vc3);
    vp5 = _mm512_fmadd_ps(vp5, vt5, vc3);

    vp0 = _mm512_fmadd_ps(vp0, vt0, vc2);
    vp1 = _mm512_fmadd_ps(vp1, vt1, vc2);
    vp2 = _mm512_fmadd_ps(vp2, vt2, vc2);
    vp3 = _mm512_fmadd_ps(vp3, vt3, vc2);
    vp4 = _mm512_fmadd_ps(vp4, vt4, vc2);
    vp5 = _mm512_fmadd_ps(vp5, vt5, vc2);

    vp0 = _mm512_fmadd_ps(vp0, vt0, vc1);
    vp1 = _mm512_fmadd_ps(vp1, vt1, vc1);
    vp2 = _mm512_fmadd_ps(vp2, vt2, vc1);
    vp3 = _mm512_fmadd_ps(vp3, vt3, vc1);
    vp4 = _mm512_fmadd_ps(vp4, vt4, vc1);
    vp5 = _mm512_fmadd_ps(vp5, vt5, vc1);

    vp0 = _mm512_fmadd_ps(vp0, vt0, vone);
    vp1 = _mm512_fmadd_ps(vp1, vt1, vone);
    vp2 = _mm512_fmadd_ps(vp2, vt2, vone);
    vp3 = _mm512_fmadd_ps(vp3, vt3, vone);
    vp4 = _mm512_fmadd_ps(vp4, vt4, vone);
    vp5 = _mm512_fmadd_ps(vp5, vt5, vone);

    const __m512 ve0 = _mm512_scalef_ps(vp0, vn0);
    const __m512 ve1 = _mm512_scalef_ps(vp1, vn1);
    const __m512 ve2 = _mm512_scalef_ps(vp2, vn2);
    const __m512 ve3 = _mm512_scalef_ps(vp3, vn3);
    const __m512 ve4 = _mm512_scalef_ps(vp4, vn4);
    const __m512 ve5 = _mm512_scalef_ps(vp5, vn5);

    const __m512 vd0 = _mm512_add_ps(ve0, vone);
    const __m512 vd1 = _mm512_add_ps(ve1, vone);
    const __m512 vd2 = _mm512_add_ps(ve2, vone);
    const __m512 vd3 = _mm512_add_ps(ve3, vone);
    const __m512 vd4 = _mm512_add_ps(ve4, vone);
    const __m512 vd5 = _mm512_add_ps(ve5, vone);

    __m512 vr0 = _mm512_rcp14_ps(vd0);
    __m512 vr1 = _mm512_rcp14_ps(vd1);
    __m512 vr2 = _mm512_rcp14_ps(vd2);
    __m512 vr3 = _mm512_rcp14_ps(vd3);
    __m512 vr4 = _mm512_rcp14_ps(vd4);
    __m512 vr5 = _mm512_rcp14_ps(vd5);

    vr0 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr0, vd0, vone), vr0, vr0);
    vr1 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr1, vd1, vone), vr1, vr1);
    vr2 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr2, vd2, vone), vr2, vr2);
    vr3 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr3, vd3, vone), vr3, vr3);
    vr4 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr4, vd4, vone), vr4, vr4);
    vr5 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr5, vd5, vone), vr5, vr5);

    __m512 vf0 = _mm512_mul_ps(ve0, vr0);
    __m512 vf1 = _mm512_mul_ps(ve1, vr1);
    __m512 vf2 = _mm512_mul_ps(ve2, vr2);
    __m512 vf3 = _mm512_mul_ps(ve3, vr3);
    __m512 vf4 = _mm512_mul_ps(ve4, vr4);
    __m512 vf5 = _mm512_mul_ps(ve5, vr5);


    vf0 = _mm512_mask_sub_ps(vf0, _mm512_testn_epi32_mask(_mm512_castps_si512(vx0), vsign_mask), vone, vf0);
    vf1 = _mm512_mask_sub_ps(vf1, _mm512_testn_epi32_mask(_mm512_castps_si512(vx1), vsign_mask), vone, vf1);
    vf2 = _mm512_mask_sub_ps(vf2, _mm512_testn_epi32_mask(_mm512_castps_si512(vx2), vsign_mask), vone, vf2);
    vf3 = _mm512_mask_sub_ps(vf3, _mm512_testn_epi32_mask(_mm512_castps_si512(vx3), vsign_mask), vone, vf3);
    vf4 = _mm512_mask_sub_ps(vf4, _mm512_testn_epi32_mask(_mm512_castps_si512(vx4), vsign_mask), vone, vf4);
    vf5 = _mm512_mask_sub_ps(vf5, _mm512_testn_epi32_mask(_mm512_castps_si512(vx5), vsign_mask), vone, vf5);

    _mm512_storeu_ps(y, vf0);
    _mm512_storeu_ps(y + 16, vf1);
    _mm512_storeu_ps(y + 32, vf2);
    _mm512_storeu_ps(y + 48, vf3);
    _mm512_storeu_ps(y + 64, vf4);
    _mm512_storeu_ps(y + 80, vf5);
    y += 96;
  }
  for (; n >= 16 * sizeof(float); n -= 16 * sizeof(float)) {
    const __m512 vx = _mm512_loadu_ps(x);
    x += 16;

    const __m512 vz = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx), vsign_mask));

    const __m512 vn = _mm512_roundscale_ps(_mm512_mul_ps(vz, vlog2e), 0);

    __m512 vt = _mm512_fmadd_ps(vn, vminus_ln2, vz);

    __m512 vp = _mm512_fmadd_ps(vc5, vt, vc4);
    vp = _mm512_fmadd_ps(vp, vt, vc3);
    vp = _mm512_fmadd_ps(vp, vt, vc2);
    vp = _mm512_fmadd_ps(vp, vt, vc1);
    vp = _mm512_fmadd_ps(vp, vt, vone);

    const __m512 ve = _mm512_scalef_ps(vp, vn);
    const __m512 vd = _mm512_add_ps(ve, vone);

    __m512 vr = _mm512_rcp14_ps(vd);
    vr = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr, vd, vone), vr, vr);

    __m512 vf = _mm512_mul_ps(ve, vr);

    vf = _mm512_mask_sub_ps(vf, _mm512_testn_epi32_mask(_mm512_castps_si512(vx), vsign_mask), vone, vf);

    _mm512_storeu_ps(y, vf);
    y += 16;
  }
  if XNN_UNLIKELY(n != 0) {
    assert(n >= 1 * sizeof(float));
    assert(n <= 15 * sizeof(float));

    // Prepare mask for valid 32-bit elements (depends on n).
    n >>= 2 /* log2(sizeof(float)) */;
    const __mmask16 vmask = _cvtu32_mask16((uint16_t) ((uint32_t) (UINT32_C(1) << n) - UINT32_C(1)));

    const __m512 vx = _mm512_maskz_loadu_ps(vmask, x);
    const __m512 vz = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx), vsign_mask));

    const __m512 vn = _mm512_roundscale_ps(_mm512_mul_ps(vz, vlog2e), 0);

    __m512 vt = _mm512_fmadd_ps(vn, vminus_ln2, vz);

    __m512 vp = _mm512_fmadd_ps(vc5, vt, vc4);
    vp = _mm512_fmadd_ps(vp, vt, vc3);
    vp = _mm512_fmadd_ps(vp, vt, vc2);
    vp = _mm512_fmadd_ps(vp, vt, vc1);
    vp = _mm512_fmadd_ps(vp, vt, vone);

    const __m512 ve = _mm512_scalef_ps(vp, vn);
    const __m512 vd = _mm512_add_ps(ve, vone);

    __m512 vr = _mm512_rcp14_ps(vd);
    vr = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr, vd, vone), vr, vr);

    __m512 vf = _mm512_mul_ps(ve, vr);

    vf = _mm512_mask_sub_ps(vf, _mm512_testn_epi32_mask(_mm512_castps_si512(vx), vsign_mask), vone, vf);

    _mm512_mask_storeu_ps(y, vmask, vf);
  }
}