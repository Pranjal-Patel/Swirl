#include <tokenizer/Tokenizer.h>
#include <array>
#include <map>

#ifndef SWIRL_PARSER_H
#define SWIRL_PARSER_H

struct Node {

    bool initialized = false;
    bool format      = false;

    std::string type;
    std::string value;
    std::string ident;
    std::string ctx_type;

    std::vector<Node> body;
    std::vector<Node> arg_nodes;
    std::vector<Node> template_args;
};

struct AbstractSyntaxTree {
    std::vector<Node> chl;
};

class Parser {
    std::array<const char*, 2> cur_rd_tok{};
public:
    TokenStream m_Stream;
    AbstractSyntaxTree* m_AST;
    bool m_AppendToScope = false;
    std::vector<std::string> registered_symbols{};

    explicit Parser(TokenStream&);

    void parseCondition(const char*);
    void parseCall(const char*) const;
    void dispatch();
    void parseFunction();
    void parseDecl(const char*, const char*);
    void parseLoop(const char*);
    inline void next();

    ~Parser();
};

#endif
