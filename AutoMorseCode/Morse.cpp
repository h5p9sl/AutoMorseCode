#include "Morse.h"

namespace morse
{
	// Writing this shit out manually was not fun.
	char a[] = { dit, dah, 0 };
	char b[] = { dah, dit, dit, dit, 0 };
	char c[] = { dah, dit, dah, dit, 0 };
	char d[] = { dah, dit, dit, 0 };
	char e[] = { dit, 0 };
	char f[] = { dit, dit, dah, dit, 0 };
	char g[] = { dah, dah, dit, 0 };
	char h[] = { dit, dit, dit, dit, 0};
	char i[] = { dit, dit, 0 };
	char j[] = { dit, dah, dah, dah, 0 };
	char k[] = { dah, dit, dah, 0 };
	char l[] = { dit, dah, dit, dit, 0 };
	char m[] = { dah, dah, 0 };
	char n[] = { dah, dit, 0 };
	char o[] = { dah, dah, dah, 0 };
	char p[] = { dit, dah, dah, dit, 0 };
	char q[] = { dah, dah, dit, dah, 0 };
	char r[] = { dit, dah, dit, 0 };
	char s[] = { dit, dit, dit, 0 };
	char t[] = { dah, 0 };
	char u[] = { dit, dit, dah, 0 };
	char v[] = { dit, dit, dit, dah, 0 };
	char w[] = { dit, dah, dah, 0 };
	char x[] = { dah, dit, dit, dah, 0 };
	char y[] = { dah, dit, dah, dah, 0 };
	char z[] = { dah, dah, dit, dit, 0 };
	char zero[] = { '0', dah, dah, dah, dah, dah, 0 };
	char one[] = { '1', dit, dah, dah, dah, dah, 0 };
	char two[] = { '2', dit, dit, dah, dah, dah, 0 };
	char three[] = { '3', dit, dit, dit, dah, dah, 0 };
	char four[] = { '4', dit, dit, dit, dit, dah, 0 };
	char five[] = { '5', dit, dit, dit, dit, dit, 0 };
	char six[] = { '6', dah, dit, dit, dit, dit, 0 };
	char seven[] = { '7', dah, dah, dit, dit, dit, 0 };
	char eight[] = { '8', dah, dah, dah, dit, dit, 0 };
	char nine[] = { '9', dah, dah, dah, dah, dit, 0 };
	char period[] = { '.', dit, dah, dit, dah, dit, dah, 0 };
	char comma[] = { ',', dah, dah, dit, dit, dah, dah, 0 };
	char colon[] = { ':', dah, dah, dah, dit, dit, dit, 0 };
	char question[] = { '?', dit, dit, dah, dah, dit, dit, 0 };
	char singlequote[] = { '\'', dit, dah, dah, dah, dah, dit, 0 };
	char dash[] = { '-', dah, dit, dit, dit, dit, dah, 0 };
	char slash[] = { '/', dah, dit, dit, dah, dit, 0 };
	char quote[] = { '\"', dit, dah, dit, dit, dah, dit, 0 };
	char at[] = { '@', dit, dah, dah, dit, dah, dit, 0 };
	char equal[] = { '=', dah, dit, dit, dit, dah, 0 };
	char exclamation[] = { '!', dah, dah, dah, dit, 0 };
	char* _alphabet[] = { a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z };
	char* _symbols[] = { zero, one, two, three, four, five, six, seven, eight, nine, period, comma, colon, question, singlequote, dash, slash, quote, at, equal, exclamation };
}