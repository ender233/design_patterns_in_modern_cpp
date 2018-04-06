#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

struct HtmlElement {
    string name_;
    string text_;
    vector<HtmlElement> elements_;

    HtmlElement() {}
    HtmlElement(const string &name_, const string &text_) :
            name_(name_), text_(text_) {
    }

    string str(int indent = 0) {
        std::string res("");
        for(int i=0; i<indent; ++i) res+=" ";

        res += "<" + name_ + ">";
        if(!text_.empty()) res += text_;
        else res += '\n';
        for(auto &ele : elements_) {
            res += ele.str(4);
        }
        res += "</" + name_ + ">\n";

        return res;
    }
};

struct HtmlBuilder
{
    HtmlElement root;
    HtmlBuilder(string root_name) {root.name_ = root_name;}

    HtmlBuilder& add_child(string childName, string childText) {
        HtmlElement e{childName, childText};
        root.elements_.emplace_back(e);
        return *this;
    }

    string str() {return root.str();}
};

int main() {
    // raw
    vector<string> words = {"hello", "world"};
    HtmlElement list{"ul", ""};
    for(auto w : words) {
        list.elements_.emplace_back(HtmlElement{"li", w});
    }
    std::cout << list.str() << std::endl;

    // builder
    HtmlBuilder builder{"ul"};
    builder.add_child("li", "hello")
            .add_child("li", "world");
    std::cout << builder.str() << std::endl;
    return 0;
}
