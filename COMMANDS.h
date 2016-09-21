#ifndef __COMMANDS_H__
#define __COMMANDS_H__

void introduction();

void instructions();

char get_command();
//
//	Pre-condition
//		Takes a stack as call by reference.
//
//	Post-condition
//		It then makes copies of top two values, then it puts the values
//		back on the stack in reverse order. It changes the stack.
//
//	Uses the class Stack
//
void interchange(Stack & numbers);
//
//	Pre-condition
//		Takes a stack as call by reference.
//
//	Post-condition
//		The function takes the stack, and adds up all the values
//		in the stack, it then returns the stack with just the one
//		value.
//
//	Uses the class Stack
//
void add(Stack & numbers);
//
//	Pre-condition
//		Takes a stack as call by reference.
//
//	Post-condition
//		The function adds up all the values in the stack
//		and counts how many times it did this addition, it
//		it then devides sum / times and sets avarage.
//
//	Uses the class Stack
//
void average(Stack & numbers);

//
//	Pre-condition
//		Takes a stack as call by reference.
//
//	Post-condition
//		The function adds up all the values in the stack
//		and counts how many times it did this addition, it
//		it then devides sum / times and sets avarage.
//
//	Uses the class Stack
//
void inorder(Stack numbers);
//
//	Pre-condition
//		The first parameter specifies a valid calculator command.
//
//	Post-condition
//		The command specified by the first parameter has been applied
//		to the Stack of numbers given by the second parameter. A result
//		of true is returned unless command == 'q'.
//
//	Uses the class Stack
//
bool do_command(char command, Stack & numbers);

//
//	Pre-condition
//		absoluetly nothing
//
//	Post-condition
//		clears screen, and displays alex schrepfer
//
void logo();
#endif
