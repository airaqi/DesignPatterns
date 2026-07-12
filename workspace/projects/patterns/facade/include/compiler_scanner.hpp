#ifndef __COMPILER_SCANNER_H__
#define __COMPILER_SCANNER_H__ 

#include "compiler_token.hpp"
#include "compiler_token_word.hpp"
#include <iostream>
#include <istream>
#include <map>
#include <string>
#include <vector>

class Scanner
{
    public:
        Scanner(std::istream& = std::cin);
        virtual ~Scanner();

        void reserve(std::shared_ptr<Word>);
        std::shared_ptr<Word> find(std::string);

        // next char
        char read();
        auto& read(char& c);
        int dread(double& val);
        bool readch(char);
        // advance indexes
        char increment(char c);
        char decrement(char c);
        // get next token

        std::string write(char c);

        static int line();
        static int column();
        static int index();

        static void reset();
          

        virtual Token::Ptr get();
        virtual Token::Ptr scan(std::string = "");
        // putback char
        void putback(char);
        // put token back to the stream
        void putback(Token::Ptr);
        
        virtual bool eof();

    protected:
        char                                            _peek;
        bool                                            _empty;
        Token::Ptr                                      _buffer;
        std::vector<Token::Ptr>                         _buf;
        std::map<std::string, Word::Ptr>                _words;
        std::istream&                                   _in;

        static int                                      _line;
        static int                                      _column;
        static int                                      _prev_col;
        static int                                      _index;
};

#endif /* ifndef __COMPILER_SCANNER_H__ */
