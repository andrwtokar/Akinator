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

	FILE* Play = fopen (name.c_str(), "rb");
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
    while (h > 1)
    {
        h--;
        if (arr[i] == 1)
        {
            printf ("Это %s, ", This_Node->text.c_str());
            This_Node = This_Node->YES;
        }
        else
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

    FILE* Play = fopen (name.c_str(), "rb");
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
    printf ("# Введите название сохраняемой игры (кириллицей, без заглавных): ");
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
