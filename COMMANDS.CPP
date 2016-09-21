#include <iostream>
typedef double Stack_entry;
#include "..\\STACK\\STACK.H"
using namespace std;

void introduction() {
   cout << "Reverse Polish Calculator Program." << endl
        << "----------------------------------" << endl << endl;
}

void instructions() {
    cout << "User commands are entered to read in and operate on integers." << endl
		 << "The valid commands are as follows:" << endl
         << " [?] push to stack." << endl
		 << " [=] print top number." << endl
         << " [+] [-] [*] [/] are arithmetic operations." << endl
         << " [i] interchange last two numbers." << endl
		 << " [s] sum all numbers." << endl
		 << " [a] average all numbers." << endl
		 << " [o] checks if numbers are in order." << endl
         << " [Q] Quit." << endl
         << "These operations apply to the top pair of stacked integers." << endl;
}

char get_command() {
   char command;
   bool waiting = true;
   cout << "Select command and press <Enter>:";

   while (waiting) {
      cin >> command;
      command = tolower(command);
      if (command == '?' || command == '=' || command == '+' ||
          command == '-' || command == '*' || command == '/' ||
		  command == 'i' || command == 's' || command == 'a' ||
		  command == 'o' || command == 'q') waiting = false;


      else {
         cout << "Please enter a valid command:"   << endl
              << " [?] push to stack." << endl
			  << " [=] print top number." << endl
              << " [+] [-] [*] [/] are arithmetic operations." << endl
              << " [i] interchange last two numbers." << endl
			  << " [s] sum all numbers." << endl
			  << " [a] average all numbers." << endl
			  << " [o] checks if numbers are in order." << endl
              << " [Q] Quit." << endl;
      }
   }
   return command;
}

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
void interchange(Stack & numbers) {
	double p, q;
	if (numbers.top(p) == underflow) {
		cout << "Stack empty" << endl;
	}
	else {
		numbers.pop();
		if (numbers.top(q) == underflow) {
			cout << "Stack has just one entry" << endl;
			numbers.push(p);
		}
		else {
			numbers.pop();
			if (numbers.push(p) == overflow)
				cout << "Warning: Stack full, lost result" << endl;
			if (numbers.push(q) == overflow)
				cout << "Warning: Stack full, lost result" << endl;
		}
	}
}

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
void add(Stack & numbers) {

	double p, q;

	if (numbers.top(p) == underflow) {
		cout << "Stack empty" << endl;
	}
	else {

		bool cont = true;

		while (cont) {
			numbers.top(p);
			numbers.pop();
			if (numbers.empty()) {
				numbers.push(p);
				cont = false;
			}
			else {
				numbers.top(q);
				numbers.pop();
				numbers.push(p + q);
			}
		}
	}
}

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
void average(Stack & numbers) {
	int count = 1;

	double p, q;

	if (numbers.top(p) == underflow) {
		cout << "Stack empty" << endl;
	}
	else {

		bool cont = true;

		while (cont) {
			numbers.top(p);
			numbers.pop();
			if (numbers.empty()) {
				numbers.push(p);
				cont = false;
			}
			else {
				count++;
				numbers.top(q);
				numbers.pop();
				numbers.push(p + q);
			}
		}

		numbers.top(p);
		numbers.pop();
		numbers.push(p / count);
	}
}

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
void inorder(Stack numbers) {
	double p, q;
	bool cont = true;

	if (numbers.top(p) == underflow) {
		cout << "Stack empty" << endl;
	}
	else {
		numbers.top(p);
		numbers.pop();
		while ((numbers.top(q) != underflow) && (cont)) {
			numbers.pop();
			if (p < q)
				cont = false;
			p = q;
		}

		if (cont)
			cout << "Stack is in order" << endl;
		else
			cout << "Stack is out of order" << endl;
	}
}

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
bool do_command(char command, Stack & numbers) {
   double p, q;
   switch (command) {
   case '?':
      cout << "Enter a real number: " << flush;
      cin >> p;
      if (numbers.push(p) == overflow)
         cout << "Warning: Stack full, lost number" << endl;
      break;

   case '=':
      if (numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else
         cout << p << endl;
      break;

   case '+':
      if (numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q + p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }
      break;


   //   Add options for further user commands.

   case '-':
      if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         }
         else {
            numbers.pop();
            if (numbers.push(q - p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }
      break;

   case '*':
      if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         }
         else {
            numbers.pop();
            if (numbers.push(q * p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }
      break;

   case '/':
      if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
      else if (p == 0.0) {
          cerr << "Division by 0 fails; no action done." << endl;
          numbers.push(p);     //  Restore stack to its prior state.
      }
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         }
         else {
            numbers.pop();
            if (numbers.push(q / p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }
      break;

   case 'i':
		interchange(numbers);
		break;

   case 's':
		add(numbers);
		break;

   case 'a':
		average(numbers);
		break;

   case 'o':
		inorder(numbers);
		break;

   case 'q':
      cout << "Calculation finished.\n";
      return false;
   }
   return true;
}

//
//	Pre-condition
//		absoluetly nothing
//
//	Post-condition
//		clears screen, and displays alex schrepfer
//
void logo() {

	cout << endl
		 << "      _,." << endl
		 << "    ,` -.)" << endl
		 << "   ( _/-\\\\-._" << endl
		 << "  /,|`--._,-^|            ," << endl
		 << "  \\_| |`-._/||          ,'|          _" << endl
		 << "    |  `-, / |         /  /     __ _| | ___  _  _" << endl
		 << "    |     || |        /  /     / _` | |/ _ \\\\ \\/ /" << endl
		 << "     `r-._||/   __   /  /     | (_| | |  __/ >  <" << endl
		 << " __,-<_     )`-/  `./  /       \\__'_|_|\\___|/_/\\_\\" << endl
		 << "'  \\   `---'   \\   /  /                   _                   __" << endl
		 << "    |           |./  /           ___  ___| |__  _ __ ___ _ __/ _|___ _ __" << endl
		 << "    /           //  /           / __|/ __| '_ \\| '__/ _ \\ '_ \\|_/ _ \\ '__|" << endl
		 << "\\_/' \\         |/  /            \\__ \\ (__| | | | | |  __/  __/ _| __/ |" << endl
		 << " |    |   _,^-'/  /             |___/\\___|_| |_|_|  \\___| | | | \\___|_|" << endl
		 << " |    , ``  (\\/  /                                      |_| |_|" << endl
		 << "  \\,.->._    \\X-=/^" << endl
		 << "  (  /   `-._//^`" << endl
		 << "   `Y-.____(__}" << endl
		 << "    |     {__)" << endl
		 << "          ()" << endl
		 << endl << endl;

	return;
}
