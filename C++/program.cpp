#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

string passwordGenerator(int number) //function to generate password
{
    const char passwordLetters[]={"0123456789!@#$%^&*/.!=""><-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int passwordLenght=sizeof(passwordLetters);
    string passwordStore="";

    for(int i=0;i<number;i++)
    {
        passwordStore+=passwordLetters[rand()%passwordLenght];
    }
    return passwordStore;
}

int main ()
{
    int number;   //password lenght 
    bool isTrue=true;   
    char anwser;
    srand(time(NULL));   //make a new random every time 

    ofstream myFile;   //make a ofstream named myfile
    myFile.open("myfile.txt");   //files name is myfile

    cout<<"Welcome To My Password Generator! "<<endl;

    while(isTrue=true)
    {
        cout<<"Enter Your Password Lenght ";
        cin>>number;

        int i=0;
        string storePassword[100];  //why not
        storePassword[i]=passwordGenerator(number);  //storing password so it can be the same as on the output of the IDE, and the notepad

        cout<<"Your Password Is: "<<storePassword[i]<<endl;

        cout<<"Do You Want To Generate Again?(Y/N) ";  //asking user if he wants to make another one 
        cin>>anwser;

        myFile<<storePassword[i]<<endl;   //print to notpead
        i++;        //increment i, in case if user want to make new password so we can store a new one 

        if(anwser=='Y' || anwser=='y'){
            isTrue=true;
        } else if (anwser=='N' || anwser=='n'){
            return 0;
        } else {
            cout<<"Enter a Valid Option ";
            return 0;
        }
    }
    return 0;
}

