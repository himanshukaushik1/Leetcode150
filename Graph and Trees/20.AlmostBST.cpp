// Only two nodes in the BST are swapped. Find and swap them back
// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isBST(Node* n, int lower, int upper)
{
    if(!n) return true;
    if( n->data <= lower || n->data >= upper ) return false;
    return (  isBST( n->left, lower, n->data )  &&  isBST( n->right, n->data, upper )  );
}

bool compare( Node* a, Node* b, vector<pair<int,int>> &mismatch )
{
    if( !a && !b ) return true;
    if( !a || !b ) return false;
    
    if( a->data != b->data )
        mismatch.push_back( pair<int,int> (a->data,b->data) );
    
    return ( compare( a->left, b->left, mismatch ) && compare( a->right, b->right, mismatch ) );
}

struct Node *correctBST( struct Node* root );

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        
        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);
        
        root = correctBST(root);
        
        // check 1: is tree now a BST
        if( ! isBST(root, INT_MIN, INT_MAX) )
        {
            cout<< "0\n";
            continue;
        }
        
        // check 2: comparing with duplicate tree
        
        vector<pair<int,int>> mismatch;
        // a vector to store data of mismatching nodes
        
        if( ! compare( root, duplicate, mismatch) )
        {
            // false output from this function indicates change in structure of tree
            cout<< "0\n";
            continue;
        }
        
        // finally, analysing the mismatching nodes
        if( mismatch.size() !=2 || mismatch[0].first!=mismatch[1].second || mismatch[0].second!=mismatch[1].first )
            cout<<"0\n";
        else cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends

// Auxiliary Space O(1)
void inorder(Node* root, Node* &prev, Node* &n1, Node* &n2){
    if(root == NULL)
        return;
    inorder(root->left, prev, n1, n2);
    
    if(prev != NULL and prev->data > root->data){
        if(!n1){
            n1 = prev;
            n2 = root;
        }
        else
            n2 = root;
    }
    prev = root;
    inorder(root->right, prev, n1, n2);
}

struct Node *correctBST( struct Node* root )
{
    Node *prev = NULL, *n1 = NULL, *n2 = NULL;
    inorder(root, prev, n1, n2);
    swap(n1->data, n2->data);
    return root;
}

// Auxiliary Space : O(n)
// void inorder(Node* root, vector<Node*> &v){
//     if(root == NULL)
//         return;
//     inorder(root->left, v);
//     v.push_back(root);
//     inorder(root->right, v);
// }

// struct Node *correctBST( struct Node* root )
// {
//     vector<Node*> v;
//     inorder(root, v);
//     if(v.size() <= 1)
//         return root;
//     Node* smaller = NULL, larger = NULL;
//     for(int i=v.size()-1; i>0; i--){
//         if(v[i]->data < v[i-1]->data){
//             int j=i-1;
//             while(j>=0 and v[j]->data > v[i]->data)
//                 j--;
//             swap(v[j+1]->data, v[i]->data);
//             break;
//         }
//     }
    
//     return root;
// }
