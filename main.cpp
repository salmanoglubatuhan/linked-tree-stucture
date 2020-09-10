#include<iostream>
    using namespace std;
    
    struct Node
    {
        string word;
        Node* left;
        Node* right;
        Node* father;
        int nodelevel;
        int leftnumber;
    };

    class tree
    {
        Node* root;
        int level;
        int noodnumber;
        Node* index;
        Node* fatherindex;
        int searchkey;

        public:
        tree(string x)
        {
            root=new Node;
            noodnumber=1;
            level=0;
            root->word=x;
            root->father=NULL;
            root->left=NULL;
            root->right=NULL;
            root->nodelevel=level;
            index=root;        
            fatherindex=root;
            root->leftnumber=1;
            searchkey=1;
        }
        void addnode(string y)      
        {
            
            int levelcontrol=1,i=0;
            for(i=0;i<level;i++)
                levelcontrol*=2;
            if (noodnumber==levelcontrol) 
            {
                level++;
                noodnumber=0;
                searchkey=1;
            }
            noodnumber++;
            if(noodnumber%2==0)
            {
                fatherindex=index->father;
                index=index->father->right;
                index=new Node;
                index->father=fatherindex;
                index->nodelevel=level;
                index->word=y;
                fatherindex->right=index;
                searchkey++;
                index->leftnumber=noodnumber;
                index->left=NULL;
                index->right=NULL;
            }
            if(noodnumber%2==1 && noodnumber!=1)
            {
                index=index->father;
                
                while(1)
                {
                    if(searchkey==index->leftnumber && level-1==index->nodelevel)
                    {
                        fatherindex=index;
                        index=index->left;
                        index=new Node;
                        index->father=fatherindex;
                        index->nodelevel=level;
                        index->word=y;
                        fatherindex->left=index;
                        index->leftnumber=noodnumber;
                        index->left=NULL;
                        index->right=NULL;
                        break;
                    }
                    while(index->father->right==index)
                    {
                        index=index->father;
                    }
                    index=index->father->right;
                    while(level-1!=index->nodelevel)
                    {
                        index=index->left;
                    }

                }
            }
            if(noodnumber==1)
            {
                index=root;
                 while(level-1!=index->nodelevel)
                    {
                        index=index->left;
                    }
                if(searchkey==index->leftnumber && level-1==index->nodelevel)
                    {
                        fatherindex=index;
                        index=index->left;
                        index=new Node;
                        index->father=fatherindex;
                        index->nodelevel=level;
                        index->word=y;
                        index->leftnumber=noodnumber;
                        fatherindex->left=index;
                        index->left=NULL;
                        index->right=NULL;
                    }
            }
            
        }
        
        Node * getroot()
        {
            return root;
        }
        void printpre(Node* indroot)
        {
            if(indroot==NULL)
                return;
            cout<<indroot->word<<endl;
            printpre(indroot->left);
            printpre(indroot->right);
        }
        void printpost(Node* indroot)
        {   
            if(indroot==NULL)
                return;
            printpost(indroot->left);
            printpost(indroot->right);
            cout<<indroot->word<<endl;
        }
        void printin(Node* indroot)
        {
            if(indroot==NULL)
                return;
            printin(indroot->left);
            cout<<indroot->word<<endl;
            printin(indroot->right);
        }
        void printnoc(Node* indroot)
        {
            
            if(indroot==NULL)
                return;
            if(indroot->left==NULL && indroot->right==NULL)
            cout<<indroot->word<<endl;
            printnoc(indroot->left);
            printnoc(indroot->right);
        }
    };
    int main()
    {
        string temp;
        int key=-1;
        cin>>temp;
        tree y(temp);
        while(1)
        {
            cin>>temp;
            if(temp == "end")
            break;
            y.addnode(temp);
        }
        cin>>key;
        while(key!=-1)
        {
            if(key==1)
            {
                cout<<"*****"<<endl;
                y.printpre(y.getroot());
            }
            if(key==2)
            {
                cout<<"*****"<<endl;
                y.printpost(y.getroot());
            }
            if(key==3)
            {
                cout<<"*****"<<endl;
                y.printin(y.getroot());
            }
            if(key==4)
            {
                cout<<"*****"<<endl;
                y.printnoc(y.getroot());
            }
            cin>>key;
        }
        cout<<"Done!";
    }