#ifndef LINE_EDITOR_H
#define LINE_EDITOR_H

#include <stddef.h>

/*
 * Supported shortcuts:
 * Ctrl+A/Ctrl+E, Ctrl+H/Backspace, Ctrl+D, Ctrl+K/Ctrl+U/Ctrl+W,
 * Left/Right arrows, Home/End, Delete (ESC [ 3 ~), Enter.
 */
int read_line_edit(char *buf, size_t cap,
                   void (*redraw)(const char *buf, size_t cursor, void *ctx),
                   void *ctx);

#endif
