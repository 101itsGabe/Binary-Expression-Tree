#include <iostream>
#include "bet.h"
#include <stack>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

//Constructor
BET::BET()
{ begin = new BinaryNode; }

//postfix into BET
BET::BET(const string& postfix)
{
 begin = new BinaryNode;
 buildFromPostfix(postfix);
}


//Copy Constructor
BET::BET(const BET& b): begin(nullptr)
{
  begin = clone(b.begin);
}

//assignment operator=
const BET& BET::operator=(const BET& b)
{
 makeEmpty();
 begin = clone(b.begin);
}

//Deconstrcutor
BET::~BET()
{
  makeEmpty();
} 

//empty
bool BET::empty()
{
 if(size() == 0)
  return true;
 else
  return false;
}

//buildFromPostfix
bool BET::buildFromPostfix(const string& postfix)
{
  if(postfix.empty())
  {
   cout << "Nothing here!" << endl;
   return false;
  }


 if(!empty())
   makeEmpty();

 string use;
 bool isOp = false;
 stringstream s(postfix);

 while(s >> use)
 {
  if(use == "+" || use == "-" || use == "/" || use == "*")
     isOp = true;
  else
    isOp = false;

   BinaryNode *b = new BinaryNode;
   if(isOp)     //if an operator, assign element and left and right pointer
   {                                            //and pop both off the stack
    if(post.size() < 2)
    {
     cout << "ERROR" << endl;
     while(!post.empty())
      post.pop();
     return false;
    }
    b->element = use;
    b->right = post.top();
    post.pop();
    b->left = post.top();
    post.pop();
    post.push(b);
    use.clear();
   }
  else if(!isOp)
  {
     b->element = use;
     b->right = nullptr;
     b->left = nullptr;
     post.push(b);
     use.clear();
  }
 }//while loop
 
 if(post.size() != 1)
 {
  cout << "ERROR" << endl;
  while(!post.empty())
   post.pop();
  return false;
 }

 begin = clone(post.top());
 
 while(!post.empty())
  post.pop();
 
 return true;

}


//size
size_t BET::size()
{
 return size(begin);
}


//size recursive
size_t BET::size(BinaryNode *t)		//function returns a number
{
 size_t s = 0;
  
  if(t == nullptr)
   return 0;

  else
  {
   s += size(t->left);	//adding each s + 1 to cur s
   s += size(t->right);
   s++;	
   return s;
  }
}

//makeEmpty
void BET::makeEmpty()
{
   makeEmpty(begin);
}

//makeEmpty recursive
void BET::makeEmpty(BinaryNode* &t)
{
 if(t != nullptr)
 {
   makeEmpty(t->left);
   makeEmpty(t->right);
   delete t;
 }
 t = nullptr;
}


//clone: Clones Node given
BET::BinaryNode* BET::clone(BinaryNode *t)
{
  if(t == nullptr)
   return nullptr;
  else
   return new BinaryNode{t->element,clone(t->left),clone(t->right)};
}


void BET::printPostfixExpression()
{
  printPostfixExpression(begin);
}
 

//printPostfixExpression recursion
void BET::printPostfixExpression(BinaryNode *n)
{
  if(n->left == nullptr && n->right == nullptr)
    cout << n->element << ' ';
  else
  {
      printPostfixExpression(n->left);
      printPostfixExpression(n->right);
      cout << n->element << ' ' ;
  }  
}

void BET::printInfixExpression()
{
  printInfixExpression(begin);
}


//printInfix
void BET::printInfixExpression(BinaryNode *n)
{
 if(n->right == nullptr && n->left == nullptr)
 {
  cout << n->element << ' ';
 }
 else
 {
  if(n != begin)
   cout << "( ";

  printInfixExpression(n->left);
  cout << n->element << ' ';
  printInfixExpression(n->right);

  if(n != begin)
   cout << ") ";
 }
}

size_t BET::leaf_nodes()
{ leaf_nodes(begin); }

//leaf_nodes recrusive
size_t BET::leaf_nodes(BinaryNode *t)
{
  size_t s = 0;
  
  if(t == nullptr)
   return 0;

  else
  {
    if(t->right == nullptr && t->left == nullptr)
    {
     s++;
     return s;
    }
    else
    {
     s += leaf_nodes(t->left);
     s += leaf_nodes(t->right);
    }
 
    return s;
  }
  
}


