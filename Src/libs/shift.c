#include "kb.h"
#include "types.h"

char shift(){
	uint8 i = 0;
	char buffstr2;
	uint8 reading2 = 1;
	while(reading2)
	{
		if(inportb(0x64) & 0x1)
		{
			switch(inportb(0x60))
			{
				case 2:
						printch('!');
						buffstr2 = '!';
						i++;
						reading2 = 0;
						break;
				case 3:
						printch('@');
						buffstr2 = '@';
						i++;
						reading2 = 0;
						break;
				case 4:
						printch('#');
						buffstr2 = '#';
						i++;
						reading2 = 0;
						break;
				case 5:
						printch('$');
						buffstr2 = '$';
						i++;
						reading2 = 0;
						break;
				case 6:
						printch('%');
						buffstr2 = '%';
						i++;
						reading2 = 0;
						break;
				case 7:
						printch('^');
						buffstr2 = '^';
						i++;
						reading2 = 0;
						break;
				case 8:
						printch('&');
						buffstr2 = '&';
						i++;
						reading2 = 0;
						break;
				case 9:
						printch('*');
						buffstr2 = '*';
						i++;
						reading2 = 0;
						break;
				case 10:
						printch('(');
						buffstr2 = '(';
						i++;
						reading2 = 0;
						break;
				case 11:
						printch(')');
						buffstr2 = ')';
						i++;
						reading2 = 0;
						break;
				case 12:
						printch('_');
						buffstr2 = '_';
						i++;
						reading2 = 0;
						break;
				case 13:
						printch('+');
						buffstr2 = '+';
						i++;
						reading2 = 0;
						break;
				case 14:
						printch('\b');
						i--;
						buffstr2 = 0;
						reading2 = 0;
						break;
				case 15:
						printch('	'); //Tab button
						buffstr2 = '	';
						i++;
						reading2 = 0;
						break;
				case 16:
						printch('Q');
						buffstr2 = 'Q';
						i++;
						reading2 = 0;
						break;
				case 17:
						printch('W');
						buffstr2 = 'W';
						i++;
						reading2 = 0;
						break;
				case 18:
						printch('E');
						buffstr2 = 'E';
						i++;
						reading2 = 0;
						break;
				case 19:
						printch('R');
						buffstr2 = 'R';
						i++;
						reading2 = 0;
						break;
				case 20:
						printch('T');
						buffstr2 = 'T';
						i++;
						break;
				case 21:
						printch('Y');
						buffstr2 = 'Y';
						i++;
						reading2 = 0;
						break;
				case 22:
						printch('U');
						buffstr2 = 'U';
						i++;
						reading2 = 0;
						break;
				case 23:
						printch('I');
						buffstr2 = 'I';
						i++;
						reading2 = 0;
						break;
				case 24:
						printch('O');
						buffstr2 = 'O';
						i++;
						break;
				case 25:
						printch('P');
						buffstr2 = 'P';
						i++;
						reading2 = 0;
						break;
				case 26:
						printch('{');
						buffstr2 = '{';
						i++;
						break;
				case 27:
						printch('}');
						buffstr2 = '}';
						i++;
						reading2 = 0;
						break;
				/* case 28:
					   // printch('\n');
					   // buffstr[i] = '\n';
						  i++;
						  reading = 0;
						  break; */
				case 30:
						printch('A');
						buffstr2 = 'A';
						i++;
						reading2 = 0;
						break;
				case 31:
						printch('S');
						buffstr2 = 'S';
						i++;
						reading2 = 0;
						break;
				case 32:
						printch('D');
						buffstr2 = 'D';
						i++;
						break;
				case 33:
						printch('F');
						buffstr2 = 'F';
						i++;
						reading2 = 0;
						break;
				case 34:
						printch('G');
						buffstr2 = 'G';
						i++;
						reading2 = 0;
						break;
				case 35:
						printch('H');
						buffstr2 = 'H';
						i++;
						reading2 = 0;
						break;
				case 36:
						printch('J');
						buffstr2 = 'J';
						i++;
						reading2 = 0;
						break;
				case 37:
						printch('K');
						buffstr2 = 'K';
						i++;
						reading2 = 0;
						break;
				case 38:
						printch('L');
						buffstr2 = 'L';
						i++;
						reading2 = 0;
						break;
				case 39:
						printch(':');
						buffstr2 = ':';
						i++;
						reading2 = 0;
						break;
				case 40:
						printch('"');               //   Single quote (')
						buffstr2 = '"';
						i++;
						reading2 = 0;
						break;
				case 41:
						printch((char)96);               // Back tick (`)
						buffstr2 = (char)96;
						i++;
						reading2 = 0;
						break;
				case 43:
						printch('|');
						buffstr2 = '|';
						i++;
						reading2 = 0;
						break;
				case 44:
						printch('Z');
						buffstr2 = 'Z';
						i++;
						reading2 = 0;
						break;
				case 45:
						printch('X');
						buffstr2 = 'X';
						i++;
						reading2 = 0;
						break;
				case 46:
						printch('C');
						buffstr2 = 'C';
						i++;
						reading2 = 0;
						break;
				case 47:
						printch('V');
						buffstr2 = 'V';
						i++;
						reading2 = 0;
						break;
				case 48:
						printch('B');
						buffstr2 = 'B';
						i++;
						reading2 = 0;
						break;
				case 49:
						printch('N');
						buffstr2 = 'N';
						i++;
						reading2 = 0;
						break;
				case 50:
						printch('M');
						buffstr2 = 'M';
						i++;
						reading2 = 0;
						break;
				case 51:
						printch('<');
						buffstr2 = '<';
						i++;
						reading2 = 0;
						break;
				case 52:
						printch('>');
						buffstr2 = '>';
						i++;
						reading2 = 0;
						break;
				case 53:
						printch('?');
						buffstr2 = '?';
						i++;
						reading2 = 0;
						break;
				case 55:
						printch('/');
						buffstr2 = '/';
						i++;
						reading2 = 0;
						break;
				default:
						reading2 = 0;
						break;
			}
		}
	}
						return buffstr2;
}
