
#include "../include/libraries.h"

struct WorkingField *CreateWorkingField(const char *input_file_name)
{
    struct WorkingField *field = (struct WorkingField*) calloc(1, sizeof(struct WorkingField));

    (*field).chars_amount    = CountSize(input_file_name) + 2;

    (*field).chars_buffer    = (char*)  calloc((*field).chars_amount, sizeof(char));

    (*field).pointers_buffer = (char**) calloc((*field).chars_amount, sizeof(char*));

    (*field).lines_amount    = ReadFile(input_file_name, (*field).chars_buffer,         \
                                        (*field).chars_amount, (*field).pointers_buffer);

    Assert((*field).chars_buffer != NULL, NULL);
    Assert((*field).pointers_buffer != NULL, NULL);

    Assert((*field).lines_amount != POINTER_IS_NULL, NULL);
    Assert((*field).lines_amount != OPENING_FILE_ERROR, NULL);
    Assert((*field).lines_amount >= 0, NULL);

    return field;
}


int ReadFile(const char *input_file_name, char *chars_buffer, size_t chars_amount, char **pointers_buffer)
{
    Assert(input_file_name != NULL, POINTER_IS_NULL);
    Assert(pointers_buffer != NULL, POINTER_IS_NULL);
    Assert(chars_buffer != NULL, POINTER_IS_NULL);

    FILE *input_file = fopen(input_file_name, "r");

    Assert(input_file != NULL, OPENING_FILE_ERROR);

    fread(chars_buffer, 1, chars_amount, input_file);

    fclose(input_file);


    int lines_count = 0;
    bool empty_string = true;

    for (unsigned int chars_count = 0; chars_count < chars_amount; chars_count++)
    {
        if (*chars_buffer == EOF)
            break;

        if (*chars_buffer != '\n' && empty_string == true)
        {
            *(pointers_buffer++) = chars_buffer;

            empty_string = false;
        }

        if (*chars_buffer == '\n' && empty_string == false)
        {

            *chars_buffer = '\0';

            lines_count++;

            empty_string = true;
        }

        chars_buffer++;
    }

    *chars_buffer = '\0';

    lines_count++;

    return lines_count;
}


int WriteLines(const char *output_file_name, char **pointers_buffer, size_t lines_amount)
{
    Assert(output_file_name != NULL, POINTER_IS_NULL);
    Assert(pointers_buffer != NULL, POINTER_IS_NULL);

    FILE *output_file = fopen(output_file_name, "a");

    Assert(output_file != NULL, OPENING_FILE_ERROR);

    for (unsigned int index = 0; index < lines_amount; index++)
    {
        char *str_address = *pointers_buffer++;

        fprintf(output_file, "%s\n", str_address);
    }

    fclose(output_file);

    return 0;
}

int WriteBuffer(const char *output_file_name, char *chars_buffer, size_t lines_amount)
{
    Assert(output_file_name != NULL, POINTER_IS_NULL);
    Assert(chars_buffer != NULL, POINTER_IS_NULL);

    FILE *output_file = fopen(output_file_name, "a");

    Assert(output_file != NULL, OPENING_FILE_ERROR);

    char *str = chars_buffer;

    for (unsigned int index = 0; index < lines_amount; index++)
    {
        while (*str != '\0')
            str++;

        *str = '\n';
    }

    str = '\0';

    fprintf(output_file, "%s\n", chars_buffer);

    fclose(output_file);

    return 0;
}


int CountSize(const char *file_name)
{
    Assert(file_name != NULL, POINTER_IS_NULL);

    struct stat file_stat;

    int error_check = stat(file_name, &file_stat);

    Assert(error_check != -1, STAT_ERROR);

    return file_stat.st_size;
}
