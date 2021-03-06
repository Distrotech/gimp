/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimp_pdb.c
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
 * <http://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl */

#include "config.h"

#include "gimp.h"


/**
 * SECTION: gimp
 * @title: gimp
 * @short_description: Miscellaneous procedures
 *
 * Miscellaneous procedures not fitting in any category.
 **/


/**
 * gimp_version:
 *
 * Returns the host GIMP version.
 *
 * This procedure returns the version number of the currently running
 * GIMP.
 *
 * Returns: GIMP version number.
 **/
gchar *
gimp_version (void)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gchar *version = NULL;

  return_vals = gimp_run_procedure ("gimp-version",
                                    &nreturn_vals,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    version = g_strdup (return_vals[1].data.d_string);

  gimp_destroy_params (return_vals, nreturn_vals);

  return version;
}

/**
 * gimp_getpid:
 *
 * Returns the PID of the host GIMP process.
 *
 * This procedure returns the process ID of the currently running GIMP.
 *
 * Returns: The PID.
 *
 * Since: 2.4
 **/
gint
gimp_getpid (void)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint pid = 0;

  return_vals = gimp_run_procedure ("gimp-getpid",
                                    &nreturn_vals,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    pid = return_vals[1].data.d_int32;

  gimp_destroy_params (return_vals, nreturn_vals);

  return pid;
}

/**
 * gimp_attach_parasite:
 * @parasite: The parasite to attach.
 *
 * Add a global parasite.
 *
 * This procedure attaches a global parasite. It has no return values.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.8
 **/
gboolean
gimp_attach_parasite (const GimpParasite *parasite)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-attach-parasite",
                                    &nreturn_vals,
                                    GIMP_PDB_PARASITE, parasite,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_detach_parasite:
 * @name: The name of the parasite to detach.
 *
 * Removes a global parasite.
 *
 * This procedure detaches a global parasite from. It has no return
 * values.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.8
 **/
gboolean
gimp_detach_parasite (const gchar *name)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-detach-parasite",
                                    &nreturn_vals,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_get_parasite:
 * @name: The name of the parasite to find.
 *
 * Look up a global parasite.
 *
 * Finds and returns the global parasite that was previously attached.
 *
 * Returns: The found parasite.
 *
 * Since: 2.8
 **/
GimpParasite *
gimp_get_parasite (const gchar *name)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  GimpParasite *parasite = NULL;

  return_vals = gimp_run_procedure ("gimp-get-parasite",
                                    &nreturn_vals,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    parasite = gimp_parasite_copy (&return_vals[1].data.d_parasite);

  gimp_destroy_params (return_vals, nreturn_vals);

  return parasite;
}

/**
 * gimp_get_parasite_list:
 * @num_parasites: The number of attached parasites.
 *
 * List all parasites.
 *
 * Returns a list of all currently attached global parasites.
 *
 * Returns: The names of currently attached parasites. The returned
 * value must be freed with g_strfreev().
 *
 * Since: 2.8
 **/
gchar **
gimp_get_parasite_list (gint *num_parasites)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gchar **parasites = NULL;
  gint i;

  return_vals = gimp_run_procedure ("gimp-get-parasite-list",
                                    &nreturn_vals,
                                    GIMP_PDB_END);

  *num_parasites = 0;

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    {
      *num_parasites = return_vals[1].data.d_int32;
      parasites = g_new (gchar *, *num_parasites + 1);
      for (i = 0; i < *num_parasites; i++)
        parasites[i] = g_strdup (return_vals[2].data.d_stringarray[i]);
      parasites[i] = NULL;
    }

  gimp_destroy_params (return_vals, nreturn_vals);

  return parasites;
}
