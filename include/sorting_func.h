#ifndef SORTING_FUNC_H_INCLUDED
#define SORTING_FUNC_H_INCLUDED

//---------------------------------------------------------------------------
//! Sorts lines in buffer of lines with BubbleSort
//!
//! @param [in] lines_buffer Pointer to buffer with pointers to lines
//! @param [in] lines_amount Amount of lines
//! @param [in] strcmp_type  Pointer to function of comparison
//!
//! @return 0 if correct complete
//!
//! @note return error number from enum Errors if error
//---------------------------------------------------------------------------

int Sorting(char **lines_buffer, size_t lines_amount, int (*strcmp_type)(char *str1, char *str2));

//---------------------------------------------------------------------------------
//!
//! Compares two strings from left to right
//!
//! @param [in] str1 Pointer to the first string
//! @param [in] str2 Pointer to the second string
//!
//! @return Difference of first different symbols codes in ASCII
//!
//! @note Returns 0 if strings are similar
//!       Returns positive number if first string is longer than second string;
//!       Returns negative number if second string is longer than first string;
//! @note Return -1 if pointer is NULL
//---------------------------------------------------------------------------------

int Strcmp(char *str1, char *str2);


//---------------------------------------------------------------------------------
//!
//! Compares two strings from right to left
//!
//! @param [in] str1 Pointer to the first string
//! @param [in] str2 Pointer to the second string
//!
//! @return Difference of first different symbols codes in ASCII
//!
//! @note Returns 0 if strings are similar
//!       Returns positive number if first string is longer than second string;
//!       Returns negative number if second string is longer than first string;
//! @note Return -1 if pointer is NULL
//---------------------------------------------------------------------------------

int ReversedStrcmp(char *str1, char *str2);

#endif // SORTING_FUNC_H_INCLUDED
