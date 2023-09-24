#include <iostream>
using namespace std;

std::int_fast64_t pow1(int base, int exp)
{
    std::int_fast64_t result{ 1 };
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

int getHash(string str, int p, int n) {

    int hash = 0;

    for (int i = 0; i < str.size(); i++)
    {
        hash = hash + ((int)str[i] * pow1(p,i));
    }

    hash = hash % n;

    return hash;
}

void simple_string_hash() {
    string str = "";
    int p = 0 ;
    int n = 0 ;

    while (str != "exit") {
        cout << "Введите p ";
        cin >> p;
        cout << "Введите n ";
        cin >> n;
        cout << "Введите строку: ";
        cin >> str;

        cout << "Наивный хэш строки " << str << " = " << getHash(str, p , n) << endl;

    }

}
int main()
{
    setlocale(LC_ALL, ".UTF8");
    setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
    system("chcp 1251");

    simple_string_hash();
}

