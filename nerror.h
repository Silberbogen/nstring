/*
 * =====================================================================================
 *
 *       Filename:  nerror.h
 *
 *    Description:  This header contains a rudimentary errorhandling
 *
 *        Version:  0.01
 *        Created:  22.06.2011 08:51:00
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Silviof <silviof@port1024.net>
 *        Company:
 *        License:  ISC
 *
 *   Copyright (C)  2011, Silviof
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
 *   last changes:  22.06.2011 Initial release
 *
 * =====================================================================================
 */

#if !defined(_NERROR_H_)
#define _NERROR_H_

typedef enum _nerror {
	ERROR_NONE,			/* all right */
	ERROR_MEMORY,			/* something with error */
	ERROR_MEMORY_FULL,		/* memory is full */
	ERROR_ALREADY_ALLOCATED, 	/* the object doesnt point to NULL */
	/* ... */
} nerror;

#endif /* !defined(_NERROR_H_) */

