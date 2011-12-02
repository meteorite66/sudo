/*
 * Copyright (c) 2011 Todd C. Miller <Todd.Miller@courtesan.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _SUDO_TOKE_H
#define _SUDO_TOKE_H

bool append(const char *, int);
bool fill_args(const char *, int, int);
bool fill_cmnd(const char *, int);
bool fill_txt(const char *, int, int);
bool ipv6_valid(const char *s);
void yyerror(const char *);

#ifndef FLEX_SCANNER
extern int (*trace_print)(const char *msg);
#endif

#define fill(a, b)	fill_txt(a, b, 0)

/* realloc() to size + COMMANDARGINC to make room for command args */
#define COMMANDARGINC   64

/*
 * XXX - want to use debug file for lexer tracing, e.g.
 *       sudo_debug_printf2(SUDO_DEBUG_PARSER|SUDO_DEBUG_DEBUG, "%s", msg);
 *       but need to add buffering so that it is line oriented.
 */
#define LEXTRACE(msg)   do {						\
    if (trace_print != NULL)						\
	(*trace_print)(msg);						\
} while (0);

#endif /* _SUDO_TOKE_H */
