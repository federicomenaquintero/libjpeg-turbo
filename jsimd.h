/*
 * jsimd.h
 *
 * Copyright 2009 Pierre Ossman <ossman@cendio.se> for Cendio AB
 * Copyright (C) 2011, 2014, D. R. Commander.
 * Copyright (C) 2015-2016, 2018, Matthieu Darbois.
 *
 * Based on the x86 SIMD extension for IJG JPEG library,
 * Copyright (C) 1999-2006, MIYASAKA Masaru.
 * For conditions of distribution and use, see copyright notice in jsimdext.inc
 *
 */

#include "jchuff.h"             /* Declarations shared with jcphuff.c */

/* Downsampler arguments for the downsampling functions.
 *
 * The smoothing_factor is ignored by the non-smooth downsamplers.
 */
struct jpeg_downsampler_args {
  int max_h_samp_factor;
  int max_v_samp_factor;
  int smoothing_factor;
};

EXTERN(int) jsimd_can_rgb_ycc(void);
EXTERN(int) jsimd_can_rgb_gray(void);
EXTERN(int) jsimd_can_ycc_rgb(void);
EXTERN(int) jsimd_can_ycc_rgb565(void);
EXTERN(int) jsimd_c_can_null_convert(void);

EXTERN(void) jsimd_rgb_ycc_convert(struct jpeg_color_converter_input *input,
                                   JSAMPIMAGE output_buf,
                                   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_rgb_gray_convert(struct jpeg_color_converter_input *input,
                                    JSAMPIMAGE output_buf,
                                    JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_ycc_rgb_convert(struct jpeg_color_deconverter_input *input,
                                   JSAMPIMAGE input_buf, JDIMENSION input_row,
                                   JSAMPARRAY output_buf, int num_rows);
EXTERN(void) jsimd_ycc_rgb565_convert(struct jpeg_color_deconverter_input *input,
                                      JSAMPIMAGE input_buf,
                                      JDIMENSION input_row,
                                      JSAMPARRAY output_buf, int num_rows);
EXTERN(void) jsimd_c_null_convert(struct jpeg_color_converter_input *input,
                                  JSAMPIMAGE output_buf, JDIMENSION output_row,
                                  int num_rows);

EXTERN(int) jsimd_can_h2v2_downsample(void);
EXTERN(int) jsimd_can_h2v1_downsample(void);

EXTERN(void) jsimd_h2v2_downsample(JDIMENSION image_width,
                                   struct jpeg_downsampler_args args,
                                   jpeg_component_info *compptr,
                                   JSAMPARRAY input_data,
                                   JSAMPARRAY output_data);

EXTERN(int) jsimd_can_h2v2_smooth_downsample(void);

EXTERN(void) jsimd_h2v2_smooth_downsample(JDIMENSION image_width,
                                          struct jpeg_downsampler_args args,
                                          jpeg_component_info *compptr,
                                          JSAMPARRAY input_data,
                                          JSAMPARRAY output_data);

EXTERN(void) jsimd_h2v1_downsample(JDIMENSION image_width,
                                   struct jpeg_downsampler_args args,
                                   jpeg_component_info *compptr,
                                   JSAMPARRAY input_data,
                                   JSAMPARRAY output_data);

EXTERN(int) jsimd_can_h2v2_upsample(void);
EXTERN(int) jsimd_can_h2v1_upsample(void);
EXTERN(int) jsimd_can_int_upsample(void);

EXTERN(void) jsimd_h2v2_upsample(JDIMENSION output_width,
                                 struct jpeg_upsampler_args args,
                                 jpeg_component_info *compptr,
                                 JSAMPARRAY input_data,
                                 JSAMPARRAY *output_data_ptr);
EXTERN(void) jsimd_h2v1_upsample(JDIMENSION output_width,
                                 struct jpeg_upsampler_args args,
                                 jpeg_component_info *compptr,
                                 JSAMPARRAY input_data,
                                 JSAMPARRAY *output_data_ptr);
EXTERN(void) jsimd_int_upsample(JDIMENSION output_width,
                                struct jpeg_upsampler_args args,
                                jpeg_component_info *compptr,
                                JSAMPARRAY input_data,
                                JSAMPARRAY *output_data_ptr);

EXTERN(int) jsimd_can_h2v2_fancy_upsample(void);
EXTERN(int) jsimd_can_h2v1_fancy_upsample(void);

EXTERN(void) jsimd_h2v2_fancy_upsample(JDIMENSION output_width,
                                       struct jpeg_upsampler_args args,
                                       jpeg_component_info *compptr,
                                       JSAMPARRAY input_data,
                                       JSAMPARRAY *output_data_ptr);
EXTERN(void) jsimd_h2v1_fancy_upsample(JDIMENSION output_width,
                                       struct jpeg_upsampler_args args,
                                       jpeg_component_info *compptr,
                                       JSAMPARRAY input_data,
                                       JSAMPARRAY *output_data_ptr);

EXTERN(int) jsimd_can_h2v2_merged_upsample(void);
EXTERN(int) jsimd_can_h2v1_merged_upsample(void);

EXTERN(void) jsimd_h2v2_merged_upsample(JDIMENSION output_width,
                                        struct jpeg_upsampler_args args,
                                        JSAMPIMAGE input_buf,
                                        JDIMENSION in_row_group_ctr,
                                        JSAMPARRAY output_buf);
EXTERN(void) jsimd_h2v1_merged_upsample(JDIMENSION output_width,
                                        struct jpeg_upsampler_args args,
                                        JSAMPIMAGE input_buf,
                                        JDIMENSION in_row_group_ctr,
                                        JSAMPARRAY output_buf);

EXTERN(int) jsimd_can_huff_encode_one_block(void);

EXTERN(JOCTET *) jsimd_huff_encode_one_block(void *state, JOCTET *buffer,
                                             JCOEFPTR block, int last_dc_val,
                                             c_derived_tbl *dctbl,
                                             c_derived_tbl *actbl);

EXTERN(int) jsimd_can_encode_mcu_AC_first_prepare(void);

EXTERN(void) jsimd_encode_mcu_AC_first_prepare
  (const JCOEF *block, const int *jpeg_natural_order_start, int Sl, int Al,
   JCOEF *values, size_t *zerobits);

EXTERN(int) jsimd_can_encode_mcu_AC_refine_prepare(void);

EXTERN(int) jsimd_encode_mcu_AC_refine_prepare
  (const JCOEF *block, const int *jpeg_natural_order_start, int Sl, int Al,
   JCOEF *absvalues, size_t *bits);
