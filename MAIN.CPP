#include "..\\..\\C\\UTILITY.H"
#include "..\\..\\C\\UTILITY.CPP"

typedef double Stack_entry;
#include "..\\STACK\\STACK.H"

#include "..\\STACK\\STACK.CPP"
#include "COMMANDS.h"

//
//	Post-condition:
//		The program executes simple arithmetic commands
//		entered by the user.
//
//	Other files: commands.cpp, stack.cpp, utility.cpp
//
//	Program origionally created by some CS teacher
//	Modified by Alex Schrepfer (CS151212) in CS151 - UHH
//	Modification date - January 31, 2001
//
int main()
{
   Stack stored_numbers;
   introduction();
   instructions();
   while (do_command(get_command(), stored_numbers));

   logo();
   return 0;
}
