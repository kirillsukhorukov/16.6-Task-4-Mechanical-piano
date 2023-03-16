#include <iostream>

using namespace std;

//Объявление перечисления нот
enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

//Функция, которая задает ноты в аккорде 
//(из строки берутся только цифры, которые соответствуют нотам)
char accord_construct(const string& accordStr)
{
    char accord = 0;
    for (int i = 0; i < accordStr.size(); i++)
    {
        if (accordStr[i] == '1') accord |= DO;
        if (accordStr[i] == '2') accord |= RE;
        if (accordStr[i] == '3') accord |= MI;
        if (accordStr[i] == '4') accord |= FA;
        if (accordStr[i] == '5') accord |= SOL;
        if (accordStr[i] == '6') accord |= LA;
        if (accordStr[i] == '7') accord |= SI;
    }
    return accord;
}

//Функция вывода мелодии нотами
void melody_output(const char (&accords)[12])
{
    cout << "This is how the tune sounds:" << endl;
    for (int i = 0; i < 12; i++)
    {
        if (accords[i] & DO) cout << "-DO-";
        if (accords[i] & RE) cout << "-RE-";
        if (accords[i] & MI) cout << "-MI-";
        if (accords[i] & FA) cout << "-FA-";
        if (accords[i] & SOL) cout << "-SOL-";
        if (accords[i] & LA) cout << "-LA-";
        if (accords[i] & SI) cout << "-SI-";
        cout << ' ';
    }
    cout << endl << endl;
}

int main()
{
    //Вывод информации для пользователя
    cout << "-----Mechanical piano-----" << endl;

    cout << "Information to enter!" << endl
        << "Use numbers to enter melody chord notes:" << endl
        << "'1' for note 'DO'" << endl
        << "'2' for note 'RE'" << endl
        << "'3' for note 'MI'" << endl
        << "'4' for note 'FA'" << endl
        << "'5' for note 'SOL'" << endl
        << "'6' for note 'LA'" << endl
        << "'7' for note 'SI'" << endl << endl;
    
    //Строка для считывания пользовательского ввода
    string accordStr;
    
    //Массив 12 аккордов мелодии
    char accords[12];
    
    //Ввод нот пользователем
    for (int i = 0; i < 12; i++)
    {
        cout << "Enter the notes of the " << i + 1 << " chord using numbers without spaces: ";
        cin >> accordStr;
        accords[i] = accord_construct(accordStr);
    }
    
    //Вывод мелодии
    melody_output(accords);

    return 0;
}