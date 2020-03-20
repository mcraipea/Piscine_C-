#include <iostream>
#include <string>

using namespace std;

string  ft_maj(string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
    return (str);
}

int main(int argc, char **argv)
{
    int     i(1);

    if (argc != 1)
    {
        while (argv[i])
            cout << ft_maj(argv[i++]);
    }
    else
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    cout << endl;
    return 0;
}