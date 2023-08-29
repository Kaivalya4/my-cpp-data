#include<iostream>
#include<string>

using namespace std;

class Human{
    public:
        string name;

        void introduce()
        {
            cout<< "hi " << name << endl;
        }
};

int main()
{
    Human kt; //object kt will stored in stack not in heap
    Human *pt = new Human() ; //this will create object dynamically using new keyword. new returns the memory address thats why we need pointer
        //this pt will stored in heap as it is dynamic
    
    kt.name = "Kaivalya";
    kt.introduce();

    cout << endl;
    pt -> name = "Kaivalya";
    pt -> introduce();

    return 0;
}