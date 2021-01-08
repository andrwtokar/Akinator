void Interface ()
{
    printf ("# Здравствуйте! Мы готовы начать игру :-)\n"
    "# Напишите своё имя (Пример: Петров Иван): ");
    std::string name;
    std::getline (std::cin, name);

    Akinator* GG = new Akinator;
	GG->Registrated_User (name);

    printf ("# Хорошо, начнём!\n");
    int action = 0;

    do {
        printf ("# Выберите действие:\n"
       	"	@ 1 - отгадывать;\n"
       	"	@ 2 - дать определение;\n"
        "	@ 3 - сравнить объекты;\n"
        "	@ 4 - подгрузить новое дерево;\n"                   //change function;
        "	@ 5 - закончить игру без сохранения;\n"
        "	@ 6 - закончить игру с сохранением.\n");
        scanf ("%i", &action);
    } while ((action < 1) || (action > 6));


    while ((action != 7) && (action != 5))
    {
        switch (action)
        {
            case 1:
            {
		printf ("# Выберите \'д\', если ответ \"да\" или \'н\' если ответ \"нет\".\n");// или \'нз\', если ответ \"не знаю".\n");                
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

                printf ("# Введите название новой игры (кириллицей, без заглавных букв): ");
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
            printf ("# Выберите действие:\n"
            "	@ 1 - отгадывать;\n"
            "	@ 2 - дать определение;\n"
            "	@ 3 - сравнить объекты;\n"
            "	@ 4 - подгрузить новое дерево;\n"                   //change function;
            "	@ 5 - закончить игру без сохранения;\n"
            "	@ 6 - закончить игру с сохранением.\n");
            scanf ("%i", &action);
        } while ((action < 1) || (action > 6));
    };

    name.clear();

};
