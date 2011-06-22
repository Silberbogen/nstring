/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Only a testballoon for the nstring library
 *
 *        Version:  0.07
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
 *      Compiling:  clang -o nstring nstringarray.c nstring.c main.c
 *
 * ====================================================================================
 *
 *   Last changes:
 *   - 17.06.2011
 *   -- implemented a first test for stringarraynew
 *   -- implemented a test for stringarraydelete
 *   - 18.06.2011
 *   -- could remove 2 bugs in nstring.c,  function stringadd() and stringset() -
 *      my thanks go to Wolfgang Wallner (icefire) for helping me
 *   -- Testing the stringarrayadd() function
 *   -- Testing the stringarrayremove() function
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
#include <stdbool.h>
#include "nstring.h"
#include "nstringarray.h"

int main(void) {
	string *teststring = stringnew("Dies ist ein Versuch!");
	if(!teststring) {
		fprintf(stderr, "Failure in creation of string object\n");
	}
	printf("%s\n",  teststring->string);
	printf("Länge: %d\n",  teststring->length);
	teststring = stringadd(teststring, " Und dann noch einer!");
	printf("%s\n",  teststring->string);
	printf("Länge: %d\n",  teststring->length);
	string *teststring2 = stringnew("Der zweite Versuch!");
	printf("Ergebnis des Vergleichs: %d\n", stringcompare(teststring,  teststring2));
	teststring = stringadd(teststring, " Nochmal!");
	printf("%s\n",  teststring->string);
	printf("Länge: %d\n",  teststring->length);
	teststring = stringset(teststring, "Alles auf Anfang!");
	printf("%s\n",  teststring->string);
	printf("Länge: %d\n",  teststring->length);
	stringdelete(teststring2);
	printf("Rückgabewert: %s\n",  stringdelete(teststring) ? "Erfolg!" : "Misserfolg!");

	stringarray *teststringarray = stringarraynew(5);
	stringset(teststringarray->element[1], "Dies ist der neue Inhalt!");
	for(int i=0;  i < teststringarray->actualelements;  ++i)
		printf("%d. %s\n", i+1,  teststringarray->element[i]->string);
	printf("Rückgabewert: %s\n",  stringarraydelete(teststringarray) ? "Erfolg!" : "Misserfolg!");

	stringarray *teststringarray2 = stringarraynew(12);
	stringset(teststringarray2->element[1], "Dies ist der neue Inhalt!");
	stringset(teststringarray2->element[6], "Element[6] geändert (also das 7.)");
	stringset(teststringarray2->element[0], "Und noch Element[0] (also das 1.)");
	for(int i=0;  i < teststringarray2->actualelements;  ++i)
		printf("%d. %s\n", i+1,  teststringarray2->element[i]->string);
	teststringarray2 = stringarrayadd(teststringarray2,  3);
	stringset(teststringarray2->element[14], "Und noch Element[14] (also das 15.)");
	stringset(teststringarray2->element[2], "Dann noch das Element[2] (das 3.)");
	for(int i=0;  i < teststringarray2->actualelements;  ++i)
		printf("%d. %s\n", i+1,  teststringarray2->element[i]->string);
	teststringarray2 = stringarrayadd(teststringarray2,  2);
	stringarrayremove(teststringarray2, 6);
		for(int i=0;  i < teststringarray2->actualelements;  ++i)
		printf("%d. %s\n", i+1,  teststringarray2->element[i]->string);
	printf("Rückgabewert: %s\n",  stringarraydelete(teststringarray2) ? "Erfolg!" : "Misserfolg!");
}
