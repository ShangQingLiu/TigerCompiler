<<<<<<< HEAD
#ifndef REALLOC_H
#define REALLOC_H
#include "assem.h"
#include "frame.h"
/* function prototype from regalloc.c */
struct RA_result {
    Temp_map coloring;
    AS_instrList il;
};
struct RA_result RA_regAlloc(F_frame f, AS_instrList il);
#endif
=======
#ifndef TIGER_REGALLOC_H_
#define TIGER_REGALLOC_H_

#include "frame.h"
#include "temp.h"
#include "assem.h"

/* function prototype from regalloc.c */
struct RA_result {Temp_map coloring; AS_instrList il;};
struct RA_result RA_regAlloc(F_frame f, AS_instrList il);

#endif // TIGER_REGALLOC_H_
>>>>>>> 8f88db788dff51a3fe06273ec249d88f8d1c967f
