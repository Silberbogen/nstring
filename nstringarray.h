/*
 * =====================================================================================
 *
 *       Filename:  nstringarray.c
 *
 *    Description:  This library contains an array for nstrings for C
 *
 *        Version:  0.04
 *        Created:  17.06.2011 12:34:00
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Sascha K. Biermanns (saschakb), saschakb@gmail.com
 *        Company:
 *        License:  ISC
 *
 *   Copyright (C)  2011, Sascha K. Biermanns
 *
 * ====================================================================================
 *
 *   Last changes:
 *   - 17.06.2011
 *   -- added function stringarraynew()
 *   -- added function stringarraydelete()
 *   - 18.06.2011
 *   -- added function stringarrayadd()
 *   -- added function stringarrayremove()
 *
 * ====================================================================================
 *
 *   Permission to use, copy, modify, and/or distribute this software for any
 *   purpose with or without fee is hereby granted, provided that the above
 *   copyright notice and this permission notice appear in all copies.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * =====================================================================================
 */

#ifndef _NSTRINGARRAY_H_
#define _NSTRINGARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "nstring.h"

typedef struct _stringarray {
//	string *element[];
//	string element[];
	string **element;
	unsigned int actualelements;
} stringarray;

// Function stringarraynew
// Implementation: This function creates an array of <number> strings
// returns: pointer on the stringarraystructure
stringarray *stringarraynew(const unsigned int number);

// Function stringarraydelete
// Implementation: This function deletes a complete stringarray
// returns: true if all went well and false if something went wrong
bool stringarraydelete(stringarray *givenstringarray);

// Function stringarrayadd
// Implementation: This function adds some strings to a given stringarray
// returns: pointer on the stringarraystructure or NULL-Pointer(busted)
stringarray *stringarrayadd(stringarray *givenstringarray,  const unsigned int number);

// Function stringarrayremove
// Implementation: This function removes a string from a given stringarray
// returns: bool true if all is okay or false if an error occured
bool stringarrayremove(stringarray *givenstringarray,  const unsigned int number);

#endif
