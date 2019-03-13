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
                printf ("# Извините, но данная функция находится на стадии доработки!\n     ;(");

                GG->Save_Tree (name);
                //TREE* delete_elem = GG->Play_Now;
                //delete (delete_elem);
                //GG->Play_Now = NULL;
                //GG->Read_Tree (name);


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
