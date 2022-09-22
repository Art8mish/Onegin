#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

//---------------------------------------------------------------------------
//! Create struct for program Onegin
//!
//! @param [in] input_file_name String with input file name
//!
//! @return Pointer to created struct
//!
//! @note return NULL if error
//---------------------------------------------------------------------------

struct WorkingField *CreateWorkingField(const char *input_file_name);


//---------------------------------------------------------------------------
//! Reading file by filling buffer
//!
//! @param [in] input_file_name String with input file name
//! @param [in] chars_buffer    Pointer to buffer for file
//! @param [in] chars_amount    File size (amount of chars)
//! @param [in] pointers_buffer    Pointer to buffer with pointers to lines
//!
//! @return Amount of lines
//!
//! @note return error number from enum Errors if error
//---------------------------------------------------------------------------

int ReadFile(const char *input_file_name, char *chars_buffer, size_t chars_amount, char **pointers_buffer);


//---------------------------------------------------------------------------
//! Writing lines from pointers_buffer
//!
//! @param [in] output_file_name String with output file name
//! @param [in] pointers_buffer     Pointer to buffer with pointers to lines
//! @param [in] lines_amount     Amount of lines
//!
//! @return 0 if correct complete
//!
//! @note return error number from enum Errors if error
//----------------------------------------------------------------------------

int WriteLines(const char *output_file_name, char **pointers_buffer, size_t lines_amount);


//---------------------------------------------------------------------------
//! Writing buffer of chars
//!
//! @param [in] output_file_name String with output file name
//! @param [in] chars_buffer     Pointer to buffer with chars
//! @param [in] lines_amount     Amount of lines
//!
//! @return 0 if correct complete
//!
//! @note return error number from enum Errors if error
//----------------------------------------------------------------------------

int WriteBuffer(const char *output_file_name, char *chars_buffer, size_t lines_amount);


//---------------------------------------------------------------------------
//! Counts size of file
//!
//! @param [in] file_name String with file name
//!
//! @return size of file (amount of chars)
//!
//! @note return error number from enum Errors if error
//----------------------------------------------------------------------------

int CountSize(const char *file_name);


#endif // IO_H_INCLUDED
