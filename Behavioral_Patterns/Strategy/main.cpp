#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>
#include <memory>
using namespace std;

typedef enum outputFormat{
    markdown,
    html
} OutputFormat;

struct ListStrategy
{
    virtual void start(ostringstream &oss) {};
    virtual void add_list_item(ostringstream &oss, const string &item) {};
    virtual void end(ostringstream &oss) {};
};

struct HtmlStrategy : ListStrategy
{
    void start(ostringstream &oss) {oss << "<ul>\n";}
    void end(ostringstream &oss) {oss << "</ul>\n";}
    void add_list_item(ostringstream &oss, const string &item) {
        oss <<"<li>"<<item<<"</li>\n";
    }
};

struct MarkdownStrategy : ListStrategy
{
    void add_list_item(ostringstream &oss, const string &item) override {
        oss<<"*"<<item<<endl;
    }
};

class TextProcessor
{
public:
    void append_list(const vector<string> items) {
        list_strategy->start(oss);
        for(auto item : items) {
            list_strategy->add_list_item(oss, item);
        }
        list_strategy->end(oss);
    }

    TextProcessor(OutputFormat format) {
        // 三目表达式需要:两侧的静态类型类型相同,否则编译报错; 因此不支持动态类型
        //list_strategy =  ((int)format == (int)markdown) ?
        //                make_unique<MarkdownStrategy>() :  make_unique<HtmlStrategy>();
        if(format == markdown) {
            list_strategy = make_unique<MarkdownStrategy>();
        }
        else
            list_strategy = make_unique<HtmlStrategy>();
    }

    ostringstream                 oss;
    std::unique_ptr<ListStrategy> list_strategy;
};

int main() {
    std::vector<std::string> vec{"hello", "my", "world"};
    TextProcessor pro1(markdown);
    TextProcessor pro2(html);

    pro1.append_list(vec);
    std::cout<<pro1.oss.str()<<std::endl;
    pro2.append_list(vec);
    std::cout<<pro2.oss.str()<<std::endl;
}