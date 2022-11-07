#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BET
{
private:
  struct BinaryNode
  {
    string element;
    BinaryNode *left;
    BinaryNode *right;
  
    BinaryNode(const string & s = " ", BinaryNode *l = nullptr, BinaryNode *r = nullptr)
     : element{s}, left{l}, right{r} {}
    BinaryNode(string && s, BinaryNode *l = nullptr, BinaryNode *r = nullptr)
     : element{std::move(s)}, left{l}, right{r} {}
  };

public:
  BET();	//default constructor
  BET(const string& postfix);	//one param takes in postfix expression
  BET(const BET&);	//copy constructor
  ~BET();	//destrcutor
  
  bool buildFromPostfix(const string& postfix);	
  const BET& operator = (const BET &);	//deep copy
  void printInfixExpression();
  void printPostfixExpression();
  size_t size();	//return # of nodes in tree us recursion function
  size_t leaf_nodes();	//returns # of leaf nodes (use recursion function to help)
  bool empty();

  void makeEmpty();  

private:
  void printInfixExpression(BinaryNode *n);	//print to the standard
  void makeEmpty(BinaryNode* &t);	//delete all nodes in the subtree pointed to by t
  BinaryNode* clone(BinaryNode *t);	//clone all nodes can be called by functions such as operator=
  void printPostfixExpression(BinaryNode *n);
  size_t size(BinaryNode *t);
  size_t leaf_nodes(BinaryNode *t);
  
  BinaryNode *begin;	//node to start from begining
  stack<BinaryNode*> post;
  
  
};
