#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

//Основная задача - реализовать данный метод
//Можно изменить передачу параметров на ссылки (&)
//Можно добавлять любое количество любых вспомогательных методов, структур и классов
void getSubstrings(string& source, string& substring, vector<int>& res)
{
    string temp = substring + "*" + source;
    vector<int> br(temp.length());
    br[0] = 0;
    int t;
    for (int i = 1; i < temp.length(); ++i)
    {
        t = br[i - 1];
        while (t > 0 && temp[i] != temp[t])
            t = br[t - 1];
        if (temp[i] == temp[t])
            br[i] = t + 1;
        else
            br[i] = 0;
    }
    for (int i = 0; i < temp.length(); ++i)
        if (substring.length() == br[i])
            res.push_back(i - substring.length() * 2);
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main()
{
    string t;
    string p;
    vector<int> res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, t);
        getline(fin, p);
        fin.close();
    }

    getSubstrings(t, p, res);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res.size() << "\n";
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        fout << *i << "\n";
    fout.close();

    return 0;
}
