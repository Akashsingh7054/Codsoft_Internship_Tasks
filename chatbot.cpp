#include<bits/stdc++.h>
using namespace std;
int main(){
    char input[300];
    while(1){
        gets(input);
        
        if(strcmp(input,"Hi")==0){
            cout<<"Hello...How can i help you."<<endl;
        }
        if(strcmp(input,"How are you")==0){
            cout<<"I am fine"<<endl;
        }
        if(strcmp(input,"what are you doing")==0){
            cout<<"I am doing good. what about you?"<<endl;
        }
        if(strcmp(input,"sum")==0){
            int a,b;
            cout<<"Give first number"<<endl;
            cin>>a;
            cout<<"Give second number"<<endl;
            cin>>b;
            cout<<"The sum is :"<<a+b<<endl;
        }
        if(strcmp(input,"product")==0){
            int a,b;
            cout<<"Give first number"<<endl;
            cin>>a;
            cout<<"Give second number"<<endl;
            cin>>b;
            cout<<"The product is :"<<a*b<<endl;
        }
        if(strcmp(input,"diffrence")==0){
            int a,b;
            cout<<"Give first number"<<endl;
            cin>>a;
            cout<<"Give second number"<<endl;
            cin>>b;
            cout<<"The diffrence is :"<<a-b<<endl;
        }
        if(strcmp(input,"divide")==0){
            float a,b;
            cout<<"Give first number"<<endl;
            cin>>a;
            cout<<"Give second number"<<endl;
            cin>>b;
            cout<<"The answer is :"<<a/b<<endl;
        }
        if(strcmp(input,"can you feel")==0){
            cout<<"No..I am an AI based Robot"<<endl;
        }
        if(strcmp(input,"tell me a joke")==0){
            cout<<"Why did the tomato turn red? Because it saw the salad dressing!"<<endl;
        }
    }
    return 0;
}