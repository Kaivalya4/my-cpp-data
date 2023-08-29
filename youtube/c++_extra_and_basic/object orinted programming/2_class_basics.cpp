#include<iostream>
#include<string.h>
using namespace std;

class human{
public :
    string name;
    void introduce()
    {
        cout<< "hi i am " << name << endl;
    }
};

int main()
{
    human info;
    info.name = " Anil";
    info.introduce();
    info.name = "Anjali";
    info.introduce();
    return 0;
}
