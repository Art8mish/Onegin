
#include "include/libraries.h"

int main(void)
{
    const char *INPUT_FILE_NAME  = "txt_files/onegin.txt";
    const char *OUTPUT_FILE_NAME = "txt_files/onegin_output.txt";

    struct WorkingField *field = CreateWorkingField(INPUT_FILE_NAME);

    Assert(field != NULL, POINTER_IS_NULL);


    Sorting((*field).pointers_buffer, (*field).lines_amount, Strcmp);

    WriteLines(OUTPUT_FILE_NAME, (*field).pointers_buffer, (*field).lines_amount);

    Sorting((*field).pointers_buffer, (*field).lines_amount, ReversedStrcmp);

    WriteLines(OUTPUT_FILE_NAME, (*field).pointers_buffer, (*field).lines_amount);

    WriteBuffer(OUTPUT_FILE_NAME, (*field).chars_buffer, (*field).lines_amount);


    printf("Program completed successfully.\n");

    return 0;
}



