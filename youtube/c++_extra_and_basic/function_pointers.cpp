//function pointers is a way to assign a function to a variable

#include<iostream>

using namespace std;

void helloworld(){
    cout << "helloworld" << endl;
}
int hellovalue(int a){
    cout << "hello" << a ;
    return 44;
}
int main()
{
    helloworld();  //it will call the function
    auto function = helloworld;  //this is equivalent to &helloworld that is storing its address
    function();  //output is helloworld

    //lets break that auto -
    //returntype (*function_new_variable) (parameters taken up by helloworld i.e. same will be taken up by new function )
    void(*function1)() = helloworld; 
    function1();  //helloworld

    typedef void(*function_alias)() ;
    function_alias function2 = helloworld;
    function2();

    int(*value)(int) = hellovalue;
    cout << value(4) << endl;
    return 0;

}