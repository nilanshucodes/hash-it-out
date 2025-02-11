#include <bits/stdc++.h>
using namespace std;
int getdigits(const int number){
    return number%10 + (number/10 % 10);
}
int sumodddigits(const string cardnumber){
    int sum=0;
    for(int i = cardnumber.size()-1; i>=0; i-=2){
        sum += cardnumber[i]-'0';
    }
    return sum;
}
int sumevendigits(const string cardnumber){
    int sum=0;
    for(int i = cardnumber.size()-2; i>=0; i-=2){
        sum += getdigits((cardnumber[i]-'0') * 2);//we r working with decimal representation of char  
    //When you subtract '0' (which has an ASCII value of 48), you are effectively converting the character to its corresponding integer value.
    }
    return sum;
} 
int main(){
     string cardnumber;
     int result = 0;
     cout<<"enter a credit card number # ";
     cin>>cardnumber;
     cout<<cardnumber<<endl;

     result = sumevendigits(cardnumber)+ sumodddigits(cardnumber);
      
     if(result%10 ==0){
        cout<< cardnumber <<" is valid"; 
     }else 
        cout<< cardnumber <<" is  not valid"; 
        return 0;  
}
 /* some valid card numbers:-
374245455400126
378282246310005
5011054488597827
6250941006528599
 */