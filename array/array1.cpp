#include <iostream>
using namespace std;
permutationinstring
bool ispermutationofanotherstring(string s,string v){
    int a[26]={0},b[26]={0};
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int index=ch-'a';
        a[index]++;
    }
    for(int i=0;i<v.length();i++){
        char ch=v[i];
        int index=ch-'a';
        b[index]++;
    }
    for(int i=0;i<26;i++){
        if(a[i]>b[i]){
            return false;
        }
    }
    return true;
}
string reversebypushpop(string s){
    char arr[100];
    int  j=0;
    for(int i=0;s[0]!='\0';i++){
        arr[j++]=s.back();
        s.pop_back();
    }
    arr[j]='\0';
    for(int i=0;i<j;i++){
        s.push_back(arr[i]);
    }
    return s;
}
string removeoccurences(string s , string part){
    while(s.length()!=0&&s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}
char maxoccuringchar(string str){
    int arr[26]={0};
    for(int i=0;i<str.length();i++){
        char s=str[i];
        int index=s-'a';
        arr[index]++;
    }
    int maxi=0;
    for(int i=0;i<26;i++){
        maxi=max(maxi,arr[i]);
        
    }
    int ans=0;
    for(int i=0;i<26;i++){
        if(arr[i]==maxi){
            ans=i;
            break;
        }
    }
    return 'a'+ans;
}
bool checkpalindrome(char arr[],int size){
    int s=0,e=size-1;
    while(s<=e){
        if(arr[s++]!=arr[e--]){
            return false;
        }
    }
    return true;
}

void swapname(char arr[],int size){
    int start=0,end=size-1;
    while(start<=end){
        swap(arr[start++],arr[end--]);
    }
}
int main(){
    char name[]="BABBAR IS GABBAR";
    cout<<name<<endl;;
    swapname(name,6);
    cout<<"swapped name is "<<name;
    checkpalindrome("babbab",6)?cout<<"\nname is palindrome"<<endl:cout<<"\nname is not palindrome"<<endl;
    char arr[]={'a','b','1','0','c','d','\0'};
    string ch={'a','b','1','0','c','d','\0'};
    cout<<"string  "<<ch;
    cout<<endl<<arr;
    cout<<"\n max occuring char is "<<maxoccuringchar("tilted");
    string NAME="I LOVE INDIA";
    for(int i=0;i<NAME.length();i++){
        if(NAME[i]==' '){
            NAME.replace(i,1,"@40");
        }
    }
    cout<<"name is "<<NAME;
    cout<<endl<<" new string is"<< removeoccurences("daabcbaabcbc","abc")<<endl;
    cout<<reversebypushpop("helloworld")<<endl;
    return 0;
}