#include <stdio.h>
#include <stdlib.h>
#include <locale.h>            //16-ричный редактор hexworkshop
#include <string>
#include <iostream>
#include <windows.h>



//-----------STRUCTS-------------------------//
struct Node
{
	std::string     text;
	Node* 	        YES;
	Node* 	        NO;
	Node*           Parent;
	Node 	                        	(std::string data);               //+
	~Node 	                        	();                               //+
	void		PG						();								  //+
	void    	Add_Node                ();                               //+
	Node*   	Find_Node               (std::string find_elem);          //+
	void    	Save                    (FILE* Play);                     //+
	void    	Read                    (FILE* Play);                     //+
};
//-------------------------------------------//
struct TREE
{
	Node*           root;
    	TREE                            (Node* data);                     //+
    	~TREE                           ();                               //+
   	 int     Way_To_Node             (std::string element, int* arr);  //+
};
//-------------------------------------------//
struct Akinator
{
    	TREE*           Play_Now;
    	Akinator                        ();                               //+
    	~Akinator                       ();                               //+
    	void    Registrated_User        (std::string name);         	  //+
    	void    Object_Comporison       ();                               //+
    	void    Object_Definition       ();                               //+
    	void    Read_Tree               (std::string name);               //+
    	void    Save_Tree               (std::string name);               //+
    	void    Play                    ();                               //+
};
//-----------Functions-----------------------//
void    Interface                   ();                               //+
//-------------------------------------------//

#include "class_Node.cpp"
#include "class_TREE.cpp"
#include "class_Akinator.cpp"
#include "Functions.cpp"

