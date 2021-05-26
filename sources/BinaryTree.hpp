#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
namespace ariel
{

    template <typename T>
    class BinaryTree
    {
        struct Node
        {
            T m_value;
            Node *left;
            Node *right;
            Node *parent;
            Node(const T &v, Node *left, Node *right, Node *parent)
                : m_value(v), left(left), right(right), parent(parent)
            {
            }
        };
        Node *root;

    public:
        BinaryTree(){
            this->root=nullptr;
        }
        ~BinaryTree(){};
        BinaryTree &add_root(const T &root)
        {
        
            return *this;
        }
        BinaryTree &add_left(const T &parent, const T &left)
        {
            return *this;
        }
        BinaryTree &add_right(const T &parent, const T &right)
        {
            return *this;
        }
        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &binaryTree){return os;}
        class preorder
        {

        private:
            Node *pointer_to_current_node;

        public:
            preorder(Node *ptr = nullptr)
                : pointer_to_current_node(ptr)
            {
            }

            T &operator*() const
            {return pointer_to_current_node->m_value; }

            T *operator->() const
            {
                T ans;
                return ans;
            }

            preorder &operator++()
            {

                   // pointer_to_current_node = pointer_to_current_node->m_next;
                return *this;
            }

            const preorder operator++(int)
            {
                preorder tmp = *this;
               // pointer_to_current_node = pointer_to_current_node->m_next;
                return tmp;
            }

            bool operator==(const preorder &rhs) const
            {
                return pointer_to_current_node == rhs.pointer_to_current_node;
            }

            bool operator!=(const preorder &rhs) const
            {
                return pointer_to_current_node != rhs.pointer_to_current_node;
            }
        }; // END OF CLASS ITERATOR
        preorder begin_preorder()
        {
            return preorder{root};
        }

        preorder end_preorder()
        {
            return preorder{};
        }
        class inorder
        {

        private:
            Node *pointer_to_current_node;

        public:
            inorder(Node *ptr = nullptr)
                : pointer_to_current_node(ptr)
            {
            }

            T &operator*() const
            {

                return pointer_to_current_node->m_value;
            }

            T *operator->() const
            {
                return &(pointer_to_current_node->m_value);
            }

            inorder &operator++()
            {

                //  pointer_to_current_node = pointer_to_current_node->m_next;
                return *this;
            }

            const inorder operator++(int)
            {
                iterator tmp = *this;
                pointer_to_current_node = pointer_to_current_node->m_next;
                return tmp;
            }

            bool operator==(const inorder &rhs) const
            {
                return pointer_to_current_node == rhs.pointer_to_current_node;
            }

            bool operator!=(const inorder &rhs) const
            {
                return pointer_to_current_node != rhs.pointer_to_current_node;
            }
        };
        inorder begin_inorder()
        {
            return inorder{root};
        }
        inorder end_inorder()
        {
            // return nullptr;
            return inorder{};
        }
        class postorder
        {

        private:
            Node *pointer_to_current_node;

        public:
            postorder(Node *ptr = nullptr)
                : pointer_to_current_node(ptr)
            {
            }

            T &operator*() const
            {

                return pointer_to_current_node->m_value;
            }

            T *operator->() const
            {
                return &(pointer_to_current_node->m_value);
            }

            postorder &operator++()
            {

                //pointer_to_current_node = pointer_to_current_node->m_next;
                return *this;
            }

            const postorder operator++(int)
            {
                iterator tmp = *this;
                pointer_to_current_node = pointer_to_current_node->m_next;
                return tmp;
            }

            bool operator==(const postorder &rhs) const
            {
                return pointer_to_current_node == rhs.pointer_to_current_node;
            }

            bool operator!=(const postorder &rhs) const
            {
                return pointer_to_current_node != rhs.pointer_to_current_node;
            }
        };
        postorder begin_postorder()
        {
            return postorder{root};
        }
        postorder end_postorder()
        {
            // return nullptr;
            return postorder{};
        }
        inorder begin()
        {
            return begin_inorder();
        };
        inorder end()
        {
            return end_inorder();
        };

    }; // end of binarytee

};
