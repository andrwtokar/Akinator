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
