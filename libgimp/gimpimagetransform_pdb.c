/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimpimagetransform_pdb.c
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl */

#include "config.h"

#include "gimp.h"


/**
 * SECTION: gimpimagetransform
 * @title: gimpimagetransform
 * @short_description: Transformations on images.
 *
 * Operations to scale, resize, crop, flip and rotate images.
 **/


/**
 * gimp_image_resize:
 * @image_ID: The image.
 * @new_width: New image width.
 * @new_height: New image height.
 * @offx: x offset between upper left corner of old and new images: (new - old).
 * @offy: y offset between upper left corner of old and new images: (new - old).
 *
 * Resize the image to the specified extents.
 *
 * This procedure resizes the image so that it's new width and height
 * are equal to the supplied parameters. Offsets are also provided
 * which describe the position of the previous image's content. All
 * channels within the image are resized according to the specified
 * parameters; this includes the image selection mask. All layers
 * within the image are repositioned according to the specified
 * offsets.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_image_resize (gint32 image_ID,
                   gint   new_width,
                   gint   new_height,
                   gint   offx,
                   gint   offy)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-image-resize",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, new_width,
                                    GIMP_PDB_INT32, new_height,
                                    GIMP_PDB_INT32, offx,
                                    GIMP_PDB_INT32, offy,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_image_resize_to_layers:
 * @image_ID: The image.
 *
 * Resize the image to fit all layers.
 *
 * This procedure resizes the image to the bounding box of all layers
 * of the image. All channels within the image are resized to the new
 * size; this includes the image selection mask. All layers within the
 * image are repositioned to the new image area.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.2
 **/
gboolean
gimp_image_resize_to_layers (gint32 image_ID)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-image-resize-to-layers",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_image_scale:
 * @image_ID: The image.
 * @new_width: New image width.
 * @new_height: New image height.
 *
 * Scale the image using the default interpolation method.
 *
 * This procedure scales the image so that its new width and height are
 * equal to the supplied parameters. All layers and channels within the
 * image are scaled according to the specified parameters; this
 * includes the image selection mask. The interpolation method used can
 * be set with gimp_context_set_interpolation().
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_image_scale (gint32 image_ID,
                  gint   new_width,
                  gint   new_height)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-image-scale",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, new_width,
                                    GIMP_PDB_INT32, new_height,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_image_scale_full:
 * @image_ID: The image.
 * @new_width: New image width.
 * @new_height: New image height.
 * @interpolation: Type of interpolation.
 *
 * Deprecated: Use gimp_image_scale() instead.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.6
 **/
gboolean
gimp_image_scale_full (gint32                image_ID,
                       gint                  new_width,
                       gint                  new_height,
                       GimpInterpolationType interpolation)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-image-scale-full",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, new_width,
                                    GIMP_PDB_INT32, new_height,
                                    GIMP_PDB_INT32, interpolation,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_image_crop:
 * @image_ID: The image.
 * @new_width: New image width: (0 < new_width <= width).
 * @new_height: New image height: (0 < new_height <= height).
 * @offx: X offset: (0 <= offx <= (width - new_width)).
 * @offy: Y offset: (0 <= offy <= (height - new_height)).
 *
 * Crop the image to the specified extents.
 *
 * This procedure crops the image so that it's new width and height are
 * equal to the supplied parameters. Offsets are also provided which
 * describe the position of the previous image's content. All channels
 * and layers within the image are cropped to the new image extents;
 * this includes the image selection mask. If any parameters are out of
 * range, an error is returned.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_image_crop (gint32 image_ID,
                 gint   new_width,
                 gint   new_height,
                 gint   offx,
                 gint   offy)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-image-crop",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, new_width,
                                    GIMP_PDB_INT32, new_height,
                                    GIMP_PDB_INT32, offx,
                                    GIMP_PDB_INT32, offy,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_image_flip:
 * @image_ID: The image.
 * @flip_type: Type of flip.
 *
 * Flips the image horizontally or vertically.
 *
 * This procedure flips (mirrors) the image.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_image_flip (gint32              image_ID,
                 GimpOrientationType flip_type)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-image-flip",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, flip_type,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_image_rotate:
 * @image_ID: The image.
 * @rotate_type: Angle of rotation.
 *
 * Rotates the image by the specified degrees.
 *
 * This procedure rotates the image.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_image_rotate (gint32           image_ID,
                   GimpRotationType rotate_type)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-image-rotate",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, rotate_type,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}