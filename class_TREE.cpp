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
