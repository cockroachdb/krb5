/* Copyright 1998 by the Massachusetts Institute of Technology.
 *
 * Permission to use, copy, modify, and distribute this
 * software and its documentation for any purpose and without
 * fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting
 * documentation, and that the name of M.I.T. not be used in
 * advertising or publicity pertaining to distribution of the
 * software without specific, written prior permission.
 * Furthermore if you modify this software you must label
 * your software as modified software and not distribute it in such a
 * fashion that it might be confused with the original M.I.T. software.
 * M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 */
 
 
#include <CodeFragments.h>

#include "profile.h"


OSErr InitializeProfileLib (
	CFragInitBlockPtr ibp);
void TerminateProfileLib (void);

OSErr InitializeProfileLib(
	CFragInitBlockPtr ibp)
{
	OSErr	err = noErr;
	
	/* Do normal init of the shared library */
	err = __initialize(ibp);
	
	/* Initialize the error tables */
	if (err == noErr) {
	    add_error_table(&et_prof_error_table);
	}
	
	return err;
}

void TerminateProfileLib(void)
{
    remove_error_table(&et_prof_error_table);
	__terminate();
}
