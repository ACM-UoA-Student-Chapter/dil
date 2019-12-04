#pragma once

// takes the token. Returns the base, or 0 if error
int base_of(const char *);

// takes ONE character and the base. returns -1 on error
int read_int(char, const int);

// takes the token and a variable to fill
// with the integer. On error returns 0.
int read_int(const char *, int *);


/*

name:			Theodoros Dimakopoulos
GitHub:		TheodoreAlenas
e-mail:		dimakopt732@gmail.com			
place:		Greece, UOA (known there as sdi1900048)
last edit:	4-12-19

*/