
#define INPUT_FILE_NAME "onegin.txt"
#define OUTPUT_FILE_NAME "onegin_output.txt"

#include "libraries.h"

int main(void)
{
    struct WorkingField *field = CreateWorkingField(INPUT_FILE_NAME);

    Assert(field != NULL, POINTER_IS_NULL);


    Sorting((*field).lines_buffer, (*field).lines_amount, Strcmp);

    WriteLines(OUTPUT_FILE_NAME, (*field).lines_buffer, (*field).lines_amount);

    Sorting((*field).lines_buffer, (*field).lines_amount, ReversedStrcmp);

    WriteLines(OUTPUT_FILE_NAME, (*field).lines_buffer, (*field).lines_amount);

    WriteBuffer(OUTPUT_FILE_NAME, (*field).chars_buffer, (*field).lines_amount);


    CleanPointerBuffer((*field).lines_buffer);
    CleanCharBuffer((*field).chars_buffer);

    printf("Program completed successfully.\n");

    return 0;
}



