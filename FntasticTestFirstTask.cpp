#include <algorithm>
#include <iostream>
#include <string>
#include <utility>  
#include <vector>

struct CharPr
{
    char ch;
    bool NeedChange = false;
};

void change(std::string& s) {
    std::vector<CharPr*> Chars;
    std::transform(s.begin(), s.end(), s.begin(), tolower);
    for (auto i = s.begin(); i < s.end(); i++) {
        bool Changed = false;
        if (Chars.size() == 0) {
            CharPr* tmp = new CharPr;
            tmp->ch = *i;
            Chars.push_back(tmp);
        }
        else {
            for (auto v : Chars)
            {
                if (*i == v->ch) { 
                    v->NeedChange = true; 
                    Changed = true;
                }
            }
            if(!Changed)
            {
                CharPr* tmp = new CharPr;
                tmp->ch = *i;
                Chars.push_back(tmp);
            }
        }
    }
    for (auto i = s.begin(); i < s.end(); i++) {
        bool Changed = false;
        for (auto v : Chars) {
            if (*i == v->ch) {
                if (!v->NeedChange ) { 
                    *i = '(';
                    Changed = true;
                }
            }
        }
        if(!Changed)*i = ')';
    } 
    for (auto v : Chars) {
        delete v;
    }
}


int main() {

    std::string s = "a(( ts)";
    change(s);
    std::cout << s << std::endl;

}

