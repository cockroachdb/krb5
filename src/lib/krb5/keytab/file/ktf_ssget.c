/*
 * lib/krb5/keytab/file/ktf_ssget.c
 *
 * Copyright 1990 by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America may
 *   require a specific license from the United States Government.
 *   It is the responsibility of any person or organization contemplating
 *   export to obtain such a license before exporting.
 * 
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of M.I.T. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  Furthermore if you modify this software you must label
 * your software as modified software and not distribute it in such a
 * fashion that it might be confused with the original M.I.T. software.
 * M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 * 
 *
 * krb5_ktfile_start_seq_get()
 */

#include "k5-int.h"
#include "ktfile.h"

krb5_error_code KRB5_CALLCONV
krb5_ktfile_start_seq_get(context, id, cursorp)
    krb5_context context;
krb5_keytab id;
krb5_kt_cursor *cursorp;
{
    krb5_error_code retval;
    long *fileoff;

    if ((retval = krb5_ktfileint_openr(context, id)))
	return retval;

    if (!(fileoff = (long *)malloc(sizeof(*fileoff)))) {
	krb5_ktfileint_close(context, id);
	return ENOMEM;
    }
    *fileoff = ftell(KTFILEP(id));
    *cursorp = (krb5_kt_cursor)fileoff;

    return 0;
}
