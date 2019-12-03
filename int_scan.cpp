#include "int_scan.hpp"

static const int OCT=8;
static const int DEC=10;
static const int HEX=16;

/*
The function returns a member of the Base enumeration, which represents the base of the input string.
If the input string starts with the character 0 (zero), then the input string represents an octal number.
If the input string starts with the characters 0x or 0X (zero x/X), then the input string represents a hexadecimal
number.
If the input string does not have one of these prefixes, then the input string represents a decimal number.
The function starts looking for the prefix from the index specified by the position pointer.
The function also returns the position of the next character of the input to be read after the prefix (if it exists).
*/
static int check_base(const char *input, int *position)
{
    int pos=0;
    if (input[pos]!='0')
    {
        *position=pos;
        return DEC;
    }
    else
    {
        pos++;
        if (input[pos]=='x' || input[pos]=='X')
        {
            pos++;
            *position=pos;
            return HEX;
        }
        else
        {
            *position=pos;
            return OCT;
        }
    }
}

/*
The function returns the integer value of the digit character passed as an argument.
The digit's base is 10.
If the digit is out of bounds, the function returns -1.
*/
static int base10_char_to_dec(char digit)
{
    if ('0'<=digit && digit<='9')
        return digit-'0';
    else
        return -1;
}

/*
The function returns the integer value of the digit character passed as an argument.
The digit's base is 8.
If the digit is out of bounds, the function returns -1.
*/
static int base8_char_to_dec(char digit)
{
    if ('0'<=digit && digit<='7')
        return digit-'0';
    else
        return -1;
}

/*
The function returns the integer value of the digit character passed as an argument.
The digit's base is 16.
If the digit is out of bounds, the function returns -1.
Both uppercase and lowercase letters a-f and A-F are considered to be valid.
*/
static int base16_char_to_dec(char digit)
{
    if ('0'<=digit && digit<='9')
        return digit-'0';
    else if ('a'<=digit && digit<='f')
        return 10+digit-'a';
    else if ('A'<=digit && digit<='F')
        return 10+digit-'A';
    else
        return -1;
}

/*
The function returns the integer value of the digit character passed as an argument depending on the digit's base.
The digit's base is specified by the num_base argument of the function
If the digit is out of bounds, the function returns -1.
*/
static int char_to_dec(char digit, const int num_base)
{
    if (num_base==DEC)
        return base10_char_to_dec(digit);
    else if (num_base==OCT)
        return base8_char_to_dec(digit);
    else
        return base16_char_to_dec(digit);
}

/*
This function checks for overflow when the next digit of the input string is taken into consideration.
The digit's decimal value is passed as an argument.
If there is overflow, the function returns true.
Otherwise the function returns false.
This function computes the new value of the numerical sequnence when the next digit of the input string is taken
into consideration. The new value of the numerical sequnence is stored in the val pointer.
*/
static bool add(int *val, int digit_decval, const int int_base)
{
    int value=*val;
    value=value*int_base+digit_decval;
    *val=value;
    return *val<0;
}

/*
The function scans the numerical input string passed as an argument and strores its value in the val pointer.
This function returns the respective error code in case of error or the success code when the integer is
successfully scanned.
Ther error codes are defined as:
-->OVERFLOW_ERROR
-->OUT_OF_BOUNDS_ERROR
-->EMPTY_NUM_EXPR_ERROR
The success code is INT_SCANNED.
*/
int read_int(const char *input,  int *val)
{
    int position;
    const int int_base=check_base(input,&position);
    bool enter=0;
    *val=0;
    for (int i=position;input[i]!='\0';i++)
    {
        enter=1;
        int dec_dig=char_to_dec(input[i],int_base);
        if (dec_dig==-1)
            return OUT_OF_BOUNDS_ERROR;
        if (add(val,dec_dig,int_base))
            return OVERFLOW_ERROR;
    }
    if (!enter && int_base!=OCT)        //input string may be the zero literal "0".
        return EMPTY_NUM_EXPR_ERROR;
    return INT_SCANNED;
}
