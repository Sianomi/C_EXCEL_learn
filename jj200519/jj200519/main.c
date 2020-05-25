#include "jin.h"

int main(void)
{
	StudentData list[30];

	read_file(list);

	search(list);
	
	return 0;

}