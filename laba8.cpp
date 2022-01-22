using namespace std;
#include <iostream>
#include <stdio.h>
#include <io.h>

struct info
{
    char surname[20];
    int group, ph, m, i;
    double average;
};

int menu()
{
    int n;
    cout << "Press a digit according to the result you want to achieve.\n1 - creating a new file\n2 - reading a file\n3 - adding info in a file\n4 - solving an individual problem\n5 - editing an info\n6 - deleting\n7 - sorting\n8 - end\n";
    while (!(cin >> n) || n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6 && n != 7 && n != 8)
    {
        cout << "This can't be solved. Enter a number from 1 to 7\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return n;
}

void creating_adding_a_file(FILE* info_students)
{
    int num;
    fopen_s(&info_students, "info_students.txt", "ab");
    if (info_students == NULL)
    {
        fopen_s(&info_students, "info_students.txt", "wb");
        if (info_students == NULL)
        {
            cout << "There is no file!\n";
            return;
        }
    }
    cout << "How many students would you like to add?\n";
    while (!(cin >> num))
    {
        cout << "This can't be solved. Enter a number!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    for (int j = 0; j < num; j++)
    {
        cout << "Write a surname of a student, number of a group, marks for physics, math and informatics.\n";
        info students;
        cin >> students.surname >> students.group >> students.ph >> students.m >> students.i;
        students.average = (students.ph + students.m + students.i) / 3.;
        //fprintf(info_students, "Surname of a student: %s\nNumber of a group: %d\nMark for physics: %d\nMark for math: %d\nMark for informatics: %d\nAverage score: %lf\n", surname, group, ph, m, i, average);
        fwrite(&students, sizeof(info), 1, info_students);
    }
    fclose(info_students);
}

void reading_a_file(FILE* info_students)
{
    fopen_s(&info_students, "info_students.txt", "rb");
    if (info_students == NULL)
    {
        cout << "There is no file!\n";
        return;
    }
    info students;

    while (fread(&students, sizeof(info), 1, info_students))
    {
        printf("Surname of a student: %s\nNumber of a group: %d\nMark for physics: %d\nMark for math: %d\nMark for informatics: %d\nAverage score: %lf\n\n", students.surname, students.group, students.ph, students.m, students.i, students.average);
    }
    fclose(info_students);
}

void solving_an_individual_problem(FILE* info_students)
{
    int input_group;
    fopen_s(&info_students, "info_students.txt", "rb");
    if (info_students == NULL)
    {
        cout << "There is no file!\n";
        return;
    }
    info student_individual;
    cout << "Enter a group\n";
    cin >> input_group;
    while (fread(&student_individual, sizeof(info), 1, info_students))
    {
        if (student_individual.group == input_group && (student_individual.i == 9 || student_individual.i == 10  ))
        {
            printf("Surname of a student: %s\nNumber of a group: %d\nMark for physics: %d\nMark for math: %d\nMark for informatics: %d\nAverage score: %lf\n\n", student_individual.surname, student_individual.group, student_individual.ph, &student_individual.m, student_individual.i, student_individual.average);
        }
    }
    fclose(info_students);
}


void editing_info(FILE* info_students)
{
    int num, f;
    fopen_s(&info_students, "info_students.txt", "r+b");
    if (info_students == NULL)
    {
        cout << "There is no file!\n";
        return;
    }
    cout << "Enter a number of a student\n";
    while (!(cin >> num))
    {
        cout << "This can't be solved. Enter a number!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    fseek(info_students, sizeof(info) * (num - 1), SEEK_SET);
    cout << "Choose what whould you like to edit\nSurname - press 1\nGroup number - press 2\nMarks - press 3\n";
    while (!(cin >> f) || f != 1 && f != 2 && f != 3)
    {
        cout << "This can't be solved. Enter a number from 1 to 3!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    info student_edit;
    fread(&student_edit, sizeof(info), 1, info_students);
    printf("Surname of a student: %s\nNumber of a group: %d\nMark for physics: %d\nMark for math: %d\nMark for informatics: %d\nAverage score: %lf\n\n", student_edit.surname, student_edit.group, student_edit.ph, student_edit.m, student_edit.i, student_edit.average);
    switch (f)
    {
    case 1:
    {
        cout << "Enter a new surname\n";
        cin >> student_edit.surname;
        break;
    }
    case 2:
    {
        cout << "Enter a new group number\n";
        cin >> student_edit.group;
        break;
    }
    case 3:
    {
        cout << "Enter new marks\n";
        cin >> student_edit.ph >> student_edit.m >> student_edit.i;
        student_edit.average = (student_edit.ph + student_edit.m + student_edit.i) / 3.;
        break;
    }
    }
    fseek(info_students, sizeof(info) * (num - 1), SEEK_SET);
    fwrite(&student_edit, sizeof(info), 1, info_students);
    fclose(info_students);
}

void deleting(FILE* info_students)
{
    int num;
    //int number_of_students = _filelength(_fileno(info_students)))
    fopen_s(&info_students, "info_students.txt", "r+b");
    if (info_students == NULL)
    {
        cout << "There is no file!\n";
        return;
    }
    
        cout << "Enter a number of a student\n";
        while (!(cin >> num))
        {
            cout << "This can't be solved. Enter a number!\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        fseek(info_students, sizeof(info) * num, SEEK_SET); //начало файла
        info student_delete;
        int size = sizeof(info);
        while (fread(&student_delete, sizeof(info), 1, info_students))
        {
            fseek(info_students, -size * 2, SEEK_CUR); //текущее положение файла
            fwrite(&student_delete, sizeof(info), 1, info_students);
            fseek(info_students, size, SEEK_CUR);
        }
        _chsize(_fileno(info_students), _filelength(_fileno(info_students)) - size); //изменение размера файла  с номером файла после байта с номером
        fclose(info_students);
    }
    
    


void sorting(FILE* info_students)
{
    int f;
    cout << "Enter the type of sorting:\nBy name - press 1\nBy group - press 2\n";
    while (!(cin >> f) || f != 1 && f != 2)
    {
        cout << "This can't be solved. Enter a number from 1 to 7\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    switch (f)
    {
    case 1:
    {
        fopen_s(&info_students, "info_students.txt", "rb");

        if (info_students == NULL)
        {
            cout << "There is no file!\n";
            return;
        }

        long num = _filelength(_fileno(info_students)) / sizeof(info);
        info* student_sorting = new info[num];

        fread(student_sorting, sizeof(info), num, info_students);


        for (int i = 0; i < num - 1; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                for (int k = 0; k < 20; k++)
                {
                    if (student_sorting[i].surname[k] > student_sorting[j].surname[k])
                    {
                        info student_t = student_sorting[i];
                        student_sorting[i] = student_sorting[j];
                        student_sorting[j] = student_t;
                        break;
                    }
                    if (student_sorting[i].surname[k] < student_sorting[j].surname[k])
                    {
                        break;
                    }
                }
            }
        }
        fclose(info_students);
        fopen_s(&info_students, "info_students.txt", "wb");
        if (info_students == NULL)
        {
            cout << "There is no file!\n";
            return;
        }
        fwrite(student_sorting, sizeof(info), num, info_students);
        delete[] student_sorting;
        fclose(info_students);
        break;
    }
    case 2:
    {
        fopen_s(&info_students, "info_students.txt", "rb");

        if (info_students == NULL)
        {
            cout << "There is no file!\n";
            return;
        }

        long num = _filelength(_fileno(info_students)) / sizeof(info);
        info* student_sorting = new info[num];

        fread(student_sorting, sizeof(info), num, info_students);
        fclose(info_students);
        for (int i = 0; i < num - 1; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                if (student_sorting[i].group > student_sorting[j].group)
                {
                    info student_t = student_sorting[i];
                    student_sorting[i] = student_sorting[j];
                    student_sorting[j] = student_t;
                    break;
                }
            }
        }

        fopen_s(&info_students, "info_students.txt", "wb");
        if (info_students == NULL)
        {
            cout << "There is no file!\n";
            return;
        }
        fwrite(student_sorting, sizeof(info), num, info_students);
        delete[] student_sorting;
        fclose(info_students);
        break;
    }
    }
}

int main()
{
    FILE* info_students;
    fopen_s(&info_students, "info_students.txt", "ab");
    if (info_students == NULL)
    {
        cout << "There is no file!\n";
        return 0;
    }
    fclose(info_students);
    int n;
    cout << "Press a digit according to the result you want to achieve.\n1 - creating a new file\n2 - reading a file\n3 - adding info in a file\n4 - solving an individual problem\n5 - editing info\n6 - deleting\n7 - sorting\n";
    while (!(cin >> n) || n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6 && n != 7)
    {
        cout << "This can't be solved. Enter a number from 1 to 7\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    while (true)
    {
        switch (n)
        {
        case 1: creating_adding_a_file(info_students); break;
        case 2: reading_a_file(info_students); break;
        case 3: creating_adding_a_file(info_students); break;
        case 4: solving_an_individual_problem(info_students); break;
        case 5: editing_info(info_students); break;
        case 6:
            int choice;
            cout << "Do you really want to delete information about a student? Yes-enter 1, No-2.\n";
            cin >> choice;
            if (choice == 1)
            {
                deleting(info_students);
            } break;
        case 7: sorting(info_students); break;
        case 8: return 0;
        }

        n = menu();
    }
}

