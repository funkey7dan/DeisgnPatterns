//
// Created by funke on 2/13/2022.
//

#ifndef AP4TEST_ITERATOR_H
#define AP4TEST_ITERATOR_H

#endif //AP4TEST_ITERATOR_H
class Node{
    int data;
    Node* left;
    Node* right;
public:
    Node(){
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(int d,Node* l,Node* r){
        this->data = d;
        this->left = l;
        this->right = r;
    }
    int getValue(){
        return data;
    }
    Node* getRight(){
        return this->right;
    }
    Node* getLeft(){
        return this->left;
    }

    Node* find(int value){
        if(this==nullptr){
            return this;
        }
        if(value==this->data){
            return this;
        } else if (value<this->data){
            return this->getLeft()->find(value);
        }
        else{
            return this->getRight()->find(value);
        }
    }
};

class BST{
    Node* root;
public:
    BST(){
        root = new Node();
    }
    Node* find(int value){
       return root->find(value);
    }
    void addNode(Node* n){
        Node* temp = root->find(n->getValue());


    }
};