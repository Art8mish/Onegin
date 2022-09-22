#ifndef LIBRARIES_H_INCLUDED
#define LIBRARIES_H_INCLUDED


#include <stdlib.h>
#include <TXlib.h>
#include <sys/stat.h>
#include "sorting_func.h"
#include "io.h"

<<<<<<< HEAD
=======

#ifndef INPUT_FILE_NAME
#define INPUT_FILE_NAME "onegin.txt"
#endif

>>>>>>> 4c55c965d09fff2a65115dbaf16df65d55a4dc16

//#define SOFT_ASSERT

#ifndef SOFT_ASSERT

#define SOFT_ASSERT(condition)                                            \
            do                                                            \
            {                                                             \
                if (!(condition))                                         \
                    printf("Error in %s; file: %s; num of line: %d \n",   \
                           #condition, __FILE__, __LINE__);               \
            } while(false)
#else

#define SOFT_ASSERT(condition)

#endif

#define Assert(condition, error_type)       \
        SOFT_ASSERT(condition);             \
        do                                  \
        {                                   \
            if (!(condition))               \
            {                               \
<<<<<<< HEAD
              /*error_code = error_type;*/  \
=======
                /*error_code = error_type;*/\
>>>>>>> 4c55c965d09fff2a65115dbaf16df65d55a4dc16
                return error_type;          \
            }                               \
        } while(false)

enum Errors
{
    POINTER_IS_NULL    = -1,
    OPENING_FILE_ERROR = -2,
    STAT_ERROR         = -3
};


struct WorkingField
{
    int    chars_amount;
    char  *chars_buffer;
    char **pointers_buffer;
    int    lines_amount;
};


#endif // LIBRARIES_H_INCLUDED
