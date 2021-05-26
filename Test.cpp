#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "BinaryTree.hpp"
#include <array>
using namespace ariel;
using namespace std;

TEST_CASE("start"){
// for(int h= 0 ; h<30 ; h++){
  BinaryTree<int> simpe;
CHECK_NOTHROW(simpe.add_root(5));//make a root 
CHECK_NOTHROW(simpe.add_left(5,2));//add a left leaf
CHECK_NOTHROW(simpe.add_right(5,7));//add right leef
// }

/*
   5
 /  \
2    7
*/
//make array that need to show inorder itrator should print 2->5->7
array<int,3 > num = {2,5,7};
// //for(int j = 0 ; j<30 ; j++){
  unsigned long i =0;
 for (auto it=simpe.begin_inorder(); it!=simpe.end_inorder(); ++it) {
    CHECK(*(it)==num.at(i++));
  } 
}
  

TEST_CASE("char"){
  BinaryTree<char> t ;
  //need to throw cuse he not have root yet
CHECK_THROWS(t.add_left('a' , 'b'));
//making a tree of string
CHECK_NOTHROW(t.add_root('a'));
CHECK_NOTHROW(t.add_left('a', 'b'));
//check that i can use same string in both sides
CHECK_NOTHROW(t.add_right('a', 'b'));
//check that i can to insert the root 
CHECK_NOTHROW(t.add_root('a').add_root('b').add_root('t'));
CHECK_NOTHROW(t.add_left('b', 'b'));
CHECK_THROWS (t.add_left('r', 's'));
/* 
        t
       / \
      b   b
    /
   b 

*/

array<char , 4> in_order = {'b', 'b' , 't', 'b'};
unsigned long i = 0 ;
 for (auto it=t.begin_inorder(); it!=t.end_inorder(); ++it){
 //change it to EQ somehow
  CHECK_EQ(*(it) , in_order.at(i++));
}
array<char ,4> post_order = {'b','b','b','t'};
unsigned long j = 0 ;
 for (auto it=t.begin_postorder(); it!=t.end_postorder(); ++it){
 //change it to EQ somehow
  CHECK_EQ(*(it) , post_order.at(j++));
}
CHECK_NOTHROW(t.add_left('t','c'));
CHECK_NOTHROW(t.add_right('c','r'));
/* 
        t
       / \
      c   b
    /  \
   b    r

*/
array<char , 5> pre_order = {'t','c','b','r','b'};
unsigned long p = 0 ;
 for (auto it=t.begin_postorder(); it!=t.end_postorder(); ++it){
   CHECK_EQ(*(it) , pre_order.at(p++));

}
}
TEST_CASE("string"){
BinaryTree<string> s ;
CHECK_THROWS(s.add_right("blabla","radio"));
CHECK_NOTHROW(s.add_root("all"));
CHECK_NOTHROW(s.add_left("all","you"));
CHECK_NOTHROW(s.add_left("you","need"));
CHECK_NOTHROW(s.add_right("you","is"));
CHECK_NOTHROW(s.add_right("all","love"));
array<string, 5>john_pre = {"all","you","need","is","love"};
unsigned long next = 0 ;

 for (auto it=s.begin_postorder(); it!=s.end_postorder(); ++it){
   CHECK_EQ(*(it) , john_pre.at(next++));

}
/* 
        all
       / \
      you   love
    /  \
   need  is

*/
CHECK_NOTHROW(s.add_root("need"));
CHECK_NOTHROW(s.add_left("need","all"));
CHECK_NOTHROW(s.add_left("all","love"));
CHECK_NOTHROW(s.add_left("need","you"));
/* 
        need
       / \
      all   you
    /  \
   love  is

*/
unsigned long b = 0 ;
array<string, 5> john_post = {"love","is","all","you","need"};
 for (auto it=s.begin_postorder(); it!=s.end_postorder(); ++it){
   CHECK_EQ(*(it) , john_post.at(b++));

}

}



