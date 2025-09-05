#include <iostream>
// Global variable
long double decimalLargeNumber=0x151215612751;
//aux function
void aux_fun(){
    std::cout<<"long double global var"<<decimalLargeNumber<<std::endl;
    //std::cout<<"printing x"<<x<<std::endl;
}
//main function
int main()
{
    /*Multi 
    line 
    comment
    Swap x and y values
    */
    int x, y;
    int aux;
    std::cout<<"ingrese dos numeros"<<std::endl;
    std::cin >> x >> y;
    aux = x;
    x = y;
    y = aux;
    std::cout << x<<" "<< y<<std::endl;
    /*
    Declaring multiple variable types
     */
    double pi=3.1415;
    float height=1.6;
    char character='a';
    bool flag=false;
    short count=0;
    unsigned long largeInteger=1515487518454184;
    //prinitng values
    std::cout<<"Double var: "<<pi<<std::endl;//printf("Double var: %f\n",pi)
    std::cout<<"Float var: "<<height<<std::endl;
    std::cout<<"Char var: "<<character<<std::endl;
    std::cout<<"bool var: "<<flag<<std::endl;
    std::cout<<"short var: "<<count<<std::endl;
    std::cout<<"unsinged long var: "<<largeInteger<<std::endl;
    {
        int a=2;
        std::cout<<"a: "<<a<<std::endl;
        std::cout<<"x: "<<x<<std::endl;
    }
    aux_fun();
    //std::cout<<"a: "<<a<<std::endl;   

    return 0;
}