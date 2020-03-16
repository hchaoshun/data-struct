// Class to implement node 
class Node { 
public: 
    int key; 
  
    // Array to hold pointers to node of different level  
    Node **forward; 
    Node(int, int); 
}; 
  
// Class for Skip list
class SkipList {
private:
    // Maximum level for this skip list
    int MAXLVL;

    // P is the fraction of the nodes with level
    // i pointers also having level i+1 pointers
    float P;

    // current level of skip list
    int level;

    // pointer to header node
    Node *header;
public:
    SkipList(int, float);
    int randomLevel();
    Node* createNode(int, int);
    void insertElement(int);
    void deleteElement(int);
    void searchElement(int);
    void displayList();
};
