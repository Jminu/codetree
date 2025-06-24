#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    int n; //식빵 개수
    int m; //암호문 개수

    string s; //식빵 상태
    
    cin >> n >> m;
    cin >> s;

    list<char> l;
    list<char>::iterator it = l.end();
    
    for(int i = 0; i < s.length(); i++) 
    {
        l.push_back(s[i]);
    }
    
    for(int i = 0; i < m; i++)
    {
        char command;
        char c;
        cin >> command;
        if(command == 'P')
        {
            cin >> c;
        }

        switch(command)
        {
            case 'L':
                if(it != l.begin())
                {
                    it--;
                }
                break;
            case 'R':
                if(it != l.end())
                {
                    it++;
                }
                break;
            case 'D': //바로 뒤에있는 빵 제거
                if(it != l.end())
                {
                    it = l.erase(it);
                }
                break;
            case 'P':
                l.insert(it, c);
                break;
        }
    }

    for(list<char>::iterator iter = l.begin(); iter != l.end(); iter++)
    {
        cout << *iter;
    }
}