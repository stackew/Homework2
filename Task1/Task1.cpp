#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>

void replace(char* text, const int text_size)
{
    char* old_word = new char[25];
    std::cout << "Введите слово, которое хотите заменить: ";
    std::cin>>old_word;
    
    char* new_word = new char[25];
    std::cout << "Введите слово на которое хотите заменить: ";
    std::cin >> new_word;
    
    char* temp_text = new char[text_size];
    int old_word_start, old_word_size = strlen(old_word);
    
    do
    {
        old_word_start = strstr(text, old_word) - text;
        temp_text[0] = '\0';
        strncat(temp_text, text, old_word_start);
        strcat(temp_text, new_word);
        strcat(temp_text, text + old_word_start + old_word_size);
        text[0] = '\0';
        strcpy(text, temp_text);
    } while (strstr(text, old_word) != nullptr);
    delete[] old_word;
    delete[] new_word;
    delete[] temp_text;
    std::cout << "New text: " << text << std::endl;
}


void sentence_upper_case(char* text)
{
    text[0] = toupper(text[0]);
    for (size_t i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && text[i + 1] == ' ')
        {
            text[i + 2] = toupper(text[i + 2]);
        }
        else if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && text[i + 1] != ' ')
        {
            text[i + 1] = toupper(text[i + 1]);
        }
    }
}

void letter_count(char text[])
{
    char letter;
    std::cout << "Введите символ, который хотите найти: ";
    std::cin >> letter;
    int count = 0;
    for (size_t i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == letter)
        {
            count++;
        }
    }
    count > 0 ? std::cout << "Символ встречается " << count << " раз" << std::endl
        : std::cout << "Символа нет в тексте" << std::endl;
   
}

void number_count(char text[])
{
    char number;
    std::cout << "Введите цифру, которую хотите найти: ";
    std::cin >> number;
    int count = 0;
    for (size_t i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == number)
        {
            count++;
        }
    }
    count > 0 ? std::cout << "Цифра встречается " << number << " раз" << std::endl
        : std::cout << "Цифры нет в тексте" << std::endl;

}
int main()
{
    setlocale(LC_ALL, "RU");
    const int TextSize = 250;
    char text[TextSize];
    std::cout << "Введите текст: ";
    gets_s(text);

    //Задача 1
    replace(text, TextSize);
    
    //Задача 2
    sentence_upper_case(text);
    std::cout << "Ваш текст: ";
    puts(text);

    //Задача 3
    letter_count(text);

    //Задача 4
    number_count(text);
    return 0;
}

