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

// Function stringarraynew
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

// Function stringarraydelete
// Implementation: This function deletes a complete stringarray
// returns: true if all went well and false something went wrong.
bool stringarraydelete(stringarray *givenstringarray) {
	bool allwell = true;
	if(!givenstringarray) // The givenstringarray is a NULL-Pointer ... busted!
		return false;
	// freeing all the substrings
	for(unsigned int i=0;  i < givenstringarray->actualelements;  ++i)
		if(!stringdelete(givenstringarray->element[i]))
				allwell = false;
	// and last freeing the givenstringarray itself
	free(givenstringarray);
	// done - now return if there have been any problems
	return(allwell);
}

// Function stringarrayadd
// Implementation: This function adds some strings to a given stringarray
// returns: pointer on the stringarraystructure or NULL-Pointer(busted)
stringarray *stringarrayadd(stringarray *givenstringarray,  const unsigned int number) {
	string **safetyptr; // for realloc

	printf("Bin in stringarrayadd.\n");
	// is the boundary of unsigned int crossed?
	if((givenstringarray->actualelements + number) < (givenstringarray->actualelements || number)) {
		fputs("Error: number of elements bigger then unsigend int in function stringarrayadd,  library nstringarray.c\n",  stdout);
		return(givenstringarray);
	}
	// reallocating memory
	safetyptr = realloc(givenstringarray->element, givenstringarray->actualelements * sizeof(string));
	if(!safetyptr) {
		fputs("Error: safetyptr is a NULL-pointer in function stringarrayadd,  library nstringarray.c\n",  stderr);
		return(givenstringarray);
	}
	givenstringarray->element = safetyptr;
	// Now initialise all the stringelements
	for(unsigned int i = givenstringarray->actualelements;  i < (givenstringarray->actualelements + number);  ++i) {
		givenstringarray->element[i] = stringnew("");
		if(!givenstringarray->element[i]) {
			fprintf(stderr, "Error: givenstringarray->element[%d] couldn't be created in function stringarrayadd,  library nstringarray.c\n", i);
			return(givenstringarray);
		}
	}
	// Ah,  all went well! Adding the new strings
	givenstringarray->actualelements += number;
	// All done!
	return(givenstringarray);
}


