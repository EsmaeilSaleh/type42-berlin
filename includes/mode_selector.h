#ifndef MODE_SELECTOR_H
#define MODE_SELECTOR_H

#include "core.h"

void run_typing_session(Mode mode, LibFunc (*get_func_by_index)(int), int (*get_func_count)(void));
void run_mode(Mode mode, LibFunc *func);

#endif // MODE_SELECTOR_H