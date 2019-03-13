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
	Node 	                        (std::string data);               //+
	~Node 	                        ();                               //+
	void	PG						();								  //+
	void    Add_Node                ();                               //+
	Node*   Find_Node               (std::string find_elem);          //+
	void    Save                    (FILE* Play);                     //+
	void    Read                    (FILE* Play);                     //
};
//-------------------------------------------//
struct TREE
{
    Node*           root;
    TREE                            (Node* data);                     //+
    ~TREE                           ();                               //+
    int     Way_To_Node             (std::string element, int* arr);  //+        массив 1 и 0
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
    void    Read_Tree               (std::string name);               //
    void    Save_Tree               (std::string name);               //+
    void    Play                    ();                               //+
};
//-----------Functions-----------------------//
void    Interface                   ();                               //+-
//-------------------------------------------//

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
//-------------------------------------------//
//-------------------Node--------------------//
//-------------------------------------------//
Node::Node (std::string data):
    text (data),
    YES  (NULL),
    NO   (NULL),
    Parent (NULL)
    {}
//-------------------------------------------//
Node::~Node ()
    {
    text.clear();
    delete YES;
    delete NO;
//    delete Parent;
    }
//-------------------------------------------//
void Node::PG ()
{
	printf ("# Это %s?\n# Ответ: ", text.c_str());
	std::string ans;
	while ((ans != "д") && (ans != "н"))
	{
        fflush(stdin);
		std::getline (std::cin, ans);

		if (ans == "д")
		{
			if (YES != NULL) {	YES->PG();}
			else {	printf ("# Ура, угадал!\n\n"); return;};
		}
		else if (ans == "н")
		{
			if (NO != NULL) {	NO->PG();}
			else
			{
    	        Add_Node();
    	        printf ("\n");
    	        return;
    	    };
		}
		else {	printf ("# Введите корректный ответ: ");}
	};
//	else if (ans == "D")
//	{
//
//	}
;
}
//-------------------------------------------//
void Node::Add_Node ()
{
    printf ("# А что это?\n");
    std::string answerN;
    std::getline (std::cin, answerN);
    Node* new_YES = new Node (answerN);

    std::string answerY = text;
    Node* new_NO = new Node (answerY);

    YES = new_YES;
    new_YES->Parent = this;
    NO = new_NO;
    new_NO->Parent = this;

    printf ("# Чем %s отличается от %s?\n", answerN.c_str(), answerY.c_str());
    std::string question;
    std::getline (std::cin, question);
    text = question;
}
//-------------------------------------------//
Node* Node::Find_Node (std::string find_elem)
{
    if (text == find_elem) { return (this);}
    else if ((YES != NULL) && (NO != NULL))
    {
    	Node* Found = NULL;
    	Found = YES->Find_Node (find_elem);
        if (Found == NULL)
        {
            Found = NO->Find_Node (find_elem);
        }
        if (Found == NULL) { return NULL;};
        return Found;
    };
}
//-------------------------------------------//
void Node::Read (FILE* Play)
{
    size_t str_size = 0;
    std::string element_of_reading = " ";
    fread (&element_of_reading[0], sizeof(char), 1, Play);
    fread (&str_size, 1, sizeof(size_t), Play);
    std::string data (str_size, '0');
    fread (&data[0], 1, str_size, Play);
    text = data;


    fread (&element_of_reading[0], sizeof(char), 1, Play);
    if (element_of_reading == " ")
    {
        Node* new_YES = new Node ("");
        YES = new_YES;
        new_YES->Parent = this;
        //getchar();
        YES->Read (Play);
    }

    fread (&element_of_reading[0],sizeof(char), 1, Play);
    if (element_of_reading == " ")
    {
        Node* new_NO = new Node ("");
        NO = new_NO;
        new_NO->Parent = this;
        //getchar();
        NO->Read (Play);
    }

    element_of_reading.clear ();
    fread (&element_of_reading[0],sizeof(char), 1, Play);
}
//-------------------------------------------//
void Node::Save (FILE* Play)
{
    //SAVE ME...please//
    std::string element_of_printing ("[");
    fwrite (element_of_printing.data (), 1, sizeof (char), Play);
    size_t text_size = text.size();
    fwrite (&text_size, 1, sizeof (size_t), Play);
    fwrite (text.data (), sizeof (char), text_size, Play);
    element_of_printing.clear ();

    if (YES != NULL)
    {

        element_of_printing = " ";
        fwrite (element_of_printing.data (), 1, sizeof (char), Play);
        YES->Save (Play);
    }
    else
    {
        element_of_printing = "N";
        fwrite (element_of_printing.data (), 1, sizeof (char), Play);
    }


    if (NO != NULL)
    {

        element_of_printing = " ";
        fwrite (element_of_printing.data (), 1, sizeof (char), Play);
        NO->Save (Play);
    }
    else
    {
        element_of_printing = "N";
        fwrite (element_of_printing.data (), 1, sizeof (char), Play);
    }

    element_of_printing.clear ();
    element_of_printing = "]";
    fwrite (element_of_printing.data (), 1, sizeof (char), Play);
}
//-------------------------------------------//
//-------------------TREE--------------------//
//-------------------------------------------//
TREE::TREE (Node* data):
    root (data)
    {}
//-------------------------------------------//
TREE::~TREE ()
    {
       delete root;       //проверка на существование, добавка (NULL nullptr)
    }
//-------------------------------------------//
int TREE::Way_To_Node (std::string find_elem, int* arr)
{
    Node* Req_Node = root->Find_Node (find_elem);
    if (Req_Node == NULL) { return 0;};

	int h = 1;
    Node* Spare = Req_Node;
    while (Spare->Parent != NULL) {h++; Spare = Spare->Parent;};
    int high = h;

    h--;
    while (Req_Node->Parent != NULL)
    {
    	h--;
        if (Req_Node->Parent->YES == Req_Node) { arr[h] = 1;}
        else if (Req_Node->Parent->NO == Req_Node) { arr[h] = 0;};
        Req_Node = Req_Node->Parent;
    };
    return high;
};
//-------------------------------------------//
//----------------Akinator-------------------//
//-------------------------------------------//
Akinator::Akinator ():
Play_Now()
{}
//-------------------------------------------//
Akinator::~Akinator ()
{
	delete Play_Now;
}
//-------------------------------------------//
void Akinator::Registrated_User (std::string name)
{
    printf ("# Введите название игры (кириллицей, без заглавных): ");
    std::string name_2;
	std::getline (std::cin, name_2);
	name += "_";
	name += name_2;
	name += ".txt";

	FILE* Play = fopen (name.c_str(), "r");                       //можно загнать в create_Tree
    if (Play == NULL)
    {
        Play = fopen (name.c_str(), "w");
        fclose (Play);
        std::string data_text ("живое");
        Node* data = new Node (data_text);
        Play_Now = new TREE(data);

        std::string text_NL ("камень");
        Node* Not_Living = new Node (text_NL);
        Play_Now->root->NO = Not_Living;
        Not_Living->Parent = Play_Now->root;

        std::string text_L ("человек");
        Node* Living = new Node (text_L);
        Play_Now->root->YES = Living;
        Living->Parent = Play_Now->root;

        std::string text_P ("Владимир Путин");
        Node* People = new Node (text_P);
        Living->YES = People;
        People->Parent = Living;

        std::string text_NP ("полторашка");
        Node* Not_People = new Node (text_NP);
        Living->NO = Not_People;
        Not_People->Parent = Living;
    }
    else
    {
    	Read_Tree (name);
	};

	return;
};
//-------------------------------------------//
void Akinator::Object_Comporison ()                 //mnojestvennoe chislo i don't know how do it
{

    printf ("# Введите первый объект: ");
	std::string a;
    fflush(stdin);
    std::getline (std::cin, a);
    int arrA[50];

    int hA = Play_Now->Way_To_Node (a, arrA);
    if (hA == 0) { printf ("# Ошибка! Такого объекта не существует!\n"); return;};


    printf ("# Введите второй объект: ");
	std::string b;
    fflush(stdin);
    std::getline (std::cin, b);
    int arrB[50];

    int hB = Play_Now->Way_To_Node (b, arrB);
    if (hB == 0) { printf ("# Ошибка! Такого объекта не существует!\n"); return;};

    int i = 0;
    Node* A = Play_Now->root;
    Node* B = Play_Now->root;

    printf ("\n# И то, и другое: ");
    while ((hA > 1) && (hB > 1))     // 1 or 0
    {
        hA--; hB--;
        if ((arrA[i] == arrB[i]) && (arrA[i] == 1))
        {

            printf ("%s, ", A->text.c_str());
            A = A->YES;
            B = B->YES;
        }
        else if ((arrA[i] == arrB[i]) && (arrA[i] == 0))
        {

            printf ("не %s, ", A->text.c_str());
            A = A->NO;
            B = B->NO;
        }
        else {  break;};
        i++;
    };
    hA++; hB++;
    if (i == 0) {printf ("нет сходств;\n");}
    else { printf ("\n");};


    printf ("# НО\n");
    printf ("  @ %s: ", a.c_str());
    int j = i;

    while (hA > 1)
    {
        hA--;
        if (arrA[i] == 1)
        {
            printf ("%s, ", A->text.c_str());
            A = A->YES;
        }
        else if (arrA[i] == 0)
        {
            printf ("не %s, ", A->text.c_str());
            A = A->NO;
        };
        i++;
    };

    printf ("\n  @ %s: ", b.c_str());

    while (hB > 1)
    {
        hB--;
        if (arrB[j] == 1)
        {
            printf ("%s, ", B->text.c_str());
            B = B->YES;
        }
        else if (arrB[j] == 0)
        {
            printf ("не %s, ", B->text.c_str());
            B = B->NO;
        };
        j++;
    };
    printf ("\n\n");

};
//-------------------------------------------//
void Akinator::Object_Definition ()
{
    printf ("# Введите интересующий вас объект: ");

	std::string a;
    fflush(stdin);
    std::getline (std::cin, a);
    int arr[50];

    int h = Play_Now->Way_To_Node (a, arr);
    if (h == 0) { printf ("# Ошибка! Такого объекта не существует!\n"); return;};

    int i = 0;
    Node* This_Node = Play_Now->root;
    printf ("# ");
    while (h > 1)     // 1 or 0
    {
        h--;
        if (arr[i] == 1)
        {
            printf ("Это %s, ", This_Node->text.c_str());
            This_Node = This_Node->YES;
        }
        else //if (arr[i] == 0)
        {
            printf ("Это не %s,", This_Node->text.c_str());
            This_Node = This_Node->NO;
        };
        i++;
    };
    printf ("\n");

};
//-------------------------------------------//
void Akinator::Read_Tree (std::string name)
{
    FILE* Play = fopen (name.c_str(), "r");
    size_t str_size = 0;


    std::string data_text = " ";
	Node* data = new Node (data_text);
	Play_Now = new TREE(data);

    Play_Now->root->Read (Play);

    fclose (Play);
};
//-------------------------------------------//
void Akinator::Save_Tree (std::string name)
{
    printf ("# Введите название игры (кириллицей, без заглавных): ");
    std::string name_2;
    fflush (stdin);
	std::getline (std::cin, name_2);
	name += "_";
	name += name_2;
	name += ".txt";

	FILE* Play = fopen (name.c_str(), "wb");

	Play_Now->root->Save (Play);
	fclose (Play);
};
//-------------------------------------------//
void Akinator::Play ()
{
    Play_Now->root->PG ();
};
//-------------------------------------------//
//----------------Functions------------------//
//-------------------------------------------//
void Interface ()
{
    printf ("# Здравствуйте! Мы готовы начать игру :-)\n"
    "# Напишите своё имя (пример: Петров Иван): ");
    std::string name;
    std::getline (std::cin, name);

    Akinator* GG = new Akinator;
	GG->Registrated_User (name);

    printf ("# Хорошо, начнём!\n");
    int action = 0;

    do {
        printf ("# Выбирите действие:\n"
        "	@ 1 - отгадывать;\n"
        "	@ 2 - дать определение;\n"
        "	@ 3 - сравнить объекты;\n"
        "	@ 4 - подгрузить новое дерево;\n"                   //change function;
        "	@ 5 - закончить игру без сохранения;\n"
        "	@ 6 - закончить игру с сохранением.\n");
        scanf ("%i", &action);} while ((action < 1) || (action > 6));


    while ((action != 7) && (action != 5))
    {
        switch (action)
        {
            case 1:
            {
                printf ("# Ввeдите \'д\', если ответ \"да\" или \'н\' или если \"нет\".\n");// или \'нз\', если ответ \"не знаю\".\n");
                GG->Play ();
                action = 0;
                break;
            };
            case 2:
            {
                GG->Object_Definition ();
                action = 0;
                break;
            };
            case 3:
            {
                GG->Object_Comporison ();
                action = 0;
                break;
            };
            case 4:               //дописать
            {
                GG->Save_Tree (name);
                TREE* delete_elem = GG->Play_Now;
                delete (delete_elem);
                GG->Play_Now = NULL;
                GG->Read_Tree (name);
                action = 0;
                break;
            };
            case 5: { delete GG; action = 0; break;};
            case 6:
            {
                GG->Save_Tree (name);
                delete GG;
                action = 0;
                return;
                break;
            };
        };




        do {
        	printf ("# Выбирите действие:\n"
       		"	@ 1 - отгадывать;\n"
       		"	@ 2 - дать определение;\n"
        	"	@ 3 - сравнить объекты;\n"
        	"	@ 4 - подгрузить новое дерево;\n"                   //change function;
        	"	@ 5 - закончить игру без сохранения;\n"
        	"	@ 6 - закончить игру с сохранением.\n");
        	scanf ("%i", &action);} while ((action < 1) || (action > 6));
    };

    name.clear();

};
//===========================================//
                  //+++//
//===========================================//
                  //+++//
//===========================================//
















