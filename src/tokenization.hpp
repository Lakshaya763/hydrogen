#pragma once
#include<vector>
#include<string>
#include<optional>
using namespace std;
enum class TokenType {
    exit,
    int_lit,
    semi,
    open_paren,
    close_paren,
    ident,
    let,
    eq,
    plus
  };
struct Token {
    TokenType type;
    optional<string> value{};
};
class Tokenizer{
  public:
    inline explicit Tokenizer(string src)
        :m_src(move(src))
    {
    }
    inline vector<Token>tokenize() {
      vector<Token> tokens;
        string buf;
        while (peek().has_value()){
            if (isalpha(peek().value())) {
                buf.push_back(consume());
                while (peek().has_value()&&isalnum(peek().value())) {
                    buf.push_back(consume());
                }
                if (buf=="exit") {
                    tokens.push_back({.type=TokenType::exit});
                    buf.clear();
                    continue;
                }
                else if (buf=="let") {
                    tokens.push_back({.type=TokenType::let});
                    buf.clear();
                    continue;
                }
                else {
                    tokens.push_back({.type=TokenType::ident, .value=buf});
                    buf.clear();
                    continue;
                }
            }
            else if (isdigit(peek().value())) {
                buf.push_back(consume());
                while (peek().has_value()&&isdigit(peek().value())){
                    buf.push_back(consume());
                }
                tokens.push_back({.type=TokenType::int_lit,.value=buf});
                buf.clear();
                continue;
            }
            else if(peek().value()=='('){
                consume();
                tokens.push_back({.type=TokenType::open_paren});
                continue;
            }
            else if(peek().value()==')'){
                consume();
                tokens.push_back({.type=TokenType::close_paren});
                continue;
            }
            else if (peek().value()==';') {
                consume();
                tokens.push_back({.type=TokenType::semi});
                continue;
            }
            else if (peek().value()=='=') {
                consume();
                tokens.push_back({.type=TokenType::eq});
                continue;
            }
            else if (isspace(peek().value())){
                consume();
                continue;
            }
            else if (peek().value()=='+'){
                consume();
                tokens.push_back({.type=TokenType::plus});
                continue;
            }else {
                cerr<<"You messed up!"<<endl;
                exit(EXIT_FAILURE);
            }
        }
        m_index=0;
        return tokens;
    }
  private:
    [[nodiscard]] inline optional<char>peek(int offset =0)const{
        if (m_index+offset >= m_src.length()){
            return {};
        }
        else{
            return m_src.at(m_index+offset);
        }
    }
    inline char consume(){
      return m_src.at(m_index++);
    }
    const string m_src;
    size_t m_index=0;
};
