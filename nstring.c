/*
 * =====================================================================================
 *
 *       Filename:  nstring.c
 *
 *    Description:  This library contains a string type for C
 *
 *        Version:  0.01
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
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "nstring.h"

// Function: stringnew
// Implementation: This function creates the memorylocation for a new string - and adds an \0 to the string
// Returns: pointer on the string structure
string *stringnew(const char *oldstring) {
	string *returnstring = malloc(sizeof(string));
	returnstring->length = strlen(oldstring) + 1;
	char *newstring = malloc(returnstring->length * sizeof(char));
	newstring = strncpy(newstring, oldstring,  returnstring->length - 1);  // last char is for an additional \0
	newstring[returnstring->length - 1] = '\0';
	returnstring->string = newstring;
	return(returnstring);
}

// Function stringdelete
// Implementation free the memory from the string construction
// Returns: true for full success - or false for partial or complete failure
bool stringdelete(string *givenstring) {
	if(!givenstring)	// The givenstring is a NULL-Pointer ... busted!
		return false;
	if(!givenstring->string) {	// The pointer to the string is already lost
		free(givenstring); // freeing only the string structure
		return false;
	}
	free(givenstring->string); // free the real string first
	free(givenstring); // and after that,  the string structure
	return true;
}

// Function stringadd
// Implementation of a function,  that adds more chars to a existing string
// Returns: pointer to the new string
string *stringadd(string *aimstring,  const char *newchars) {
	int length = strlen(newchars);
	// Reallocates the memory
	// If there isn't enough memory anymore, we get a NULL pointer
	if(!realloc(aimstring->string,  aimstring->length  + length)) {
		fputs("Error in function stringadd(string *,  const char *),  library nstring: reallocation of aimstring ended in a NULL-Pointer,  so no more memory could be allocated!\n",  stderr);
		return(aimstring);
	}
	// Okay, we had enough space,  let's copy the new chars,  set another \0,  change the length and return
	aimstring->string = strncat(aimstring->string, newchars, length);
	aimstring->string[aimstring->length + length - 1] = '\0';
	aimstring->length += length;
	return(aimstring);
}

// Function stringconcatenate
// Implementation concatenates string2 at the end of string1 (wrapperfunction)
// return: pointer on new string1
string *stringconcatenate(string *string1, const string *string2) {
	return(stringadd(string1, string2->string));
}

// Function stringcompare
// Implementation of a function to compare 2 given strings
// return: negativ if string1 < string2,  zero if string1  == string2,  positive if string1 > string2
int stringcompare(const string *string1, const string *string2) {
	return(strcmp(string1->string, string2->string));
}

// Function stringcollate
// Implementation of a function to compare 2 given strings by LC_COLLATE
// return: negativ if string1 < string2,  zero if string1  == string2,  positive if string1 > string2
int stringcollate(const string *string1, const string *string2) {
	return(strcoll(string1->string, string2->string));
}

