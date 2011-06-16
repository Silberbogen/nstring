/*
 * =====================================================================================
 *
 *       Filename:  nstring.h
 *
 *    Description:  This header contains interface to the nstring library
 *
 *        Version:  0.03
 *        Created:  16.06.2011 14:15:18
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
 *
 *   last changes:  16.06.2011 Initial release
 *   - 16.06.2011
 *     added string structure
 *     added function stringnew()
 *     added function stringdelete()
 *     added function stringadd()
 *     added function stringcompare()
 *	   added function stringcollate()
 *	   added function stringset()
 *
 * =====================================================================================
 */

#ifndef _NSTRING_H_
#define _NSTRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _string {
	char *string; // the pointer on text
	int length;  // the length of the text
} string;

// Function: stringnew
// Implementation: This function creates the memorylocation for a new string - and adds an \0 to the string
// Returns: pointer on the string structure
string *stringnew(const char *oldstring);

// Function stringdelete
// Implementation free the memory from the string construction
// Returns: true for full success - or false for partial or complete failure
bool stringdelete(string *givenstring);

// Function stringadd
// Implementation of a function,   that adds more chars to a existing string
// Returns: pointer to the new string
string *stringadd(string *aimstring,   const char *newchars);

// Function stringcompare
// Implementation of a function to compare 2 given strings
// return: negative if string1 <  string2
//         zero     if string1 == string2
//         positive if string1 >  string2
int stringcompare(const string *string1,  const string *string2);

// Function stringcollate
// Implementation of a function to compare 2 given strings by LC_COLLATE
// return: negativ if string1 < string2,  zero if string1  == string2,  positive if string1 > string2
int stringcollate(const string *string1, const string *string2);

// Function stringset
// Implementation of a function, that set's a new set of chars to an existing string
// Returns: pointer to the new string
string *stringset(string *aimstring,  const char *newchars);

#endif

