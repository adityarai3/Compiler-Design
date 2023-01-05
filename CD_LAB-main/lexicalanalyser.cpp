#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cout << "ENTER EXPRESSION : ";
    cin >> s;
    int i, l;
    l = s.length();
    for (i = 0; i < l; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            if (s[i + 1] >= 48 && s[i + 1] <= 57)
            {
                cout<<"'"<<s[i]<<s[i+1]<<"'"<< " is a valid constant\n";
                i+=1;
                continue;
            }
            else
                 cout<<"'"<<s[i]<<"'"<< " is a valid constant\n";
                
        }
        if(s[i]=='+' ||s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='%'|| s[i]=='='  )
        cout<<"'"<<s[i]<<"'"<<" is a valid operator.\n";
        else if(s[i]>57)
        cout<<"'"<<s[i]<<"'"<<" is a valid identifier\n";
    }

    return 0;
}