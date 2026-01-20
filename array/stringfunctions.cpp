#include <iostream>
using namespace std;
int main(){
    string s="hello";
    s.append(" World");
    cout <<s<<endl;
    s.replace(5,1,"lulu");
    cout<<s<<endl;
    s.assign("HELLO WORLD");
    cout<<s<<endl;
    s.erase(5,1);
    s.insert(5,"lulu");
    cout<<s<<endl;
    s.assign("HELLOWORLD");
    cout<<s.at(1)<<endl;
    cout<<s.back()<<endl;
    cout << s.capacity()<<endl;
    cout<<s.compare("hehe");
    char arr[20];
    s.copy(arr,4,1);// copies string into a char arr
    arr[4]='\0';
    cout<<arr<<endl;
    s.erase(2,6);
    cout<<s<<endl;
    s.assign("HELLOWORLD");
    cout<<s.find("WORL")<<endl;
    cout<<s.find_first_not_of("HL")<<endl;//returns FIRST index where  H OR L is not present
    cout<<s.find_first_of("RD")<<endl;// returns FIRST index where R OR D IS PRESENT
    cout<<s.front()<<endl;
    cout<<s[string("hola").find_first_of("aeiou")]<<endl;
    return 0;
}