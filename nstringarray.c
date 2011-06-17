/*
 * =====================================================================================
 *
 *       Filename:  nstringarray.c
 *
 *    Description:  This library contains an array for nstrings for C
 *
 *        Version:  0.01
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "nstring.h"
#include "nstringarray.h"

// Function stringarraycreate
// Implementation: This function creates an array of strings
// returns: pointer on the stringarraystructure
stringarray *stringarraynew(const unsigned int number) {
	stringarray *returnstringarray = malloc(sizeof(stringarray));
	if(!returnstringarray) {
		fputs("Error: returnstringarray couldn't be created in function stringarraycreate,  library nstringarray.c\n",  stderr);
		return(returnstringarray);
	}
	// That was the arraystructure - now to the array of elements
	returnstringarray->element = malloc(sizeof(string) * number);
	if(!returnstringarray) {
		fputs("Error: returnstringarray->element[] couldn't be created in function stringarraycreate,  library nstringarray.c\n",  stderr);
		return(returnstringarray);
	}
	returnstringarray->actualelements = number;
	// Now initialise all the stringelements
	for(unsigned int i = 0;  i < number;  ++i) {
		returnstringarray->element[i] = stringnew("");
		if(!returnstringarray->element[i]) {
			fprintf(stderr, "Error: returnstringarray->element[%d] couldn't be created in function stringarraycreate,  library nstringarray.c\n", i);
			return(returnstringarray);
		}
	}
	// All done!
	return(returnstringarray);
}
