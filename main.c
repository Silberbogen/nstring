/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Only a testballoon for the nstring library
 *
 *        Version:  0.02
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
 *      Compiling:  clang -o nstring nstring.c main.c
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

int main(void) {
	string *teststring = stringnew("Dies ist ein Versuch!");
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
	printf("Rückgabewert: %s\n",  stringdelete(teststring) ? "Erfolg!" : "Misserfolg!");
}
