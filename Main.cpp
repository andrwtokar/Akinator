#include "akinator_list.h"

int main ()
{
    SetConsoleCP(1251);               //узнать что это значит
    SetConsoleOutputCP(1251);
    setlocale (LC_ALL, "russian");
	printf ("# Akinator.\n"
	"# Tokar. 2018.\n\n");

    Interface ();

    printf ("# Спасибо за использование этой программы)\n");
    return 0;
};
