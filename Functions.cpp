void Interface ()
{
    printf ("# ������������! �� ������ ������ ���� :-)\n"
    "# �������� ��� ��� (������: ������ ����): ");
    std::string name;
    std::getline (std::cin, name);

    Akinator* GG = new Akinator;
	GG->Registrated_User (name);

    printf ("# ������, ������!\n");
    int action = 0;

    do {
        printf ("# �������� ��������:\n"
       	"	@ 1 - ����������;\n"
       	"	@ 2 - ���� �����������;\n"
        "	@ 3 - �������� �������;\n"
        "	@ 4 - ���������� ����� ������;\n"                   //change function;
        "	@ 5 - ��������� ���� ��� ����������;\n"
        "	@ 6 - ��������� ���� � �����������.\n");
        scanf ("%i", &action);
    } while ((action < 1) || (action > 6));


    while ((action != 7) && (action != 5))
    {
        switch (action)
        {
            case 1:
            {
		printf ("# �������� \'�\', ���� ����� \"��\" ��� \'�\' ���� ����� \"���\".\n");// ��� \'��\', ���� ����� \"�� ����".\n");                
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
            case 4:              
            {
                GG->Save_Tree (name);
                Akinator* delete_elem = GG;
                GG = NULL;
                GG = new Akinator;
                delete delete_elem;

                printf ("# ������� �������� ����� ���� (����������, ��� ��������� ����): ");
                std::string name_2;
                std::getline (std::cin, name_2);
                std::string name_3 = name;
                name_3 += "_";
                name_3 += name_2;
                name_3 += ".txt";

                GG->Read_Tree (name_3);
                action = 0;
                name_3 = name;
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
            printf ("# �������� ��������:\n"
            "	@ 1 - ����������;\n"
            "	@ 2 - ���� �����������;\n"
            "	@ 3 - �������� �������;\n"
            "	@ 4 - ���������� ����� ������;\n"                   //change function;
            "	@ 5 - ��������� ���� ��� ����������;\n"
            "	@ 6 - ��������� ���� � �����������.\n");
            scanf ("%i", &action);
        } while ((action < 1) || (action > 6));
    };

    name.clear();

};
