#include<bits/stdc++.h>
using namespace std;

//Create a data block class
class data_block{

    public:

    string data;
    data_block* next;

    data_block(string data){
        this->data = data;
        next=NULL;
    }
    
};

//Insert a string data into datablocks
data_block* insertDataIntoDataBlock(string data){
    data_block* head=NULL;
    data_block* tail=NULL;

    for(int i=0;i<data.size();i+=4){
        string sub_string=data.substr(i,4);
        cout<<sub_string<<endl;

        if (head==NULL) {
            data_block* temp=new data_block(sub_string);
            head=temp;
            tail=temp;
        }

        else{
            data_block* temp=new data_block(sub_string);
            tail->next= temp;
            tail=temp;
        }
    }
    return head;
}

//Create I-Node class
class Inode {
public:
    int id;
    string name;
    int size;
    string permissions;
    data_block* AddressOfDataBlock;

    Inode(int id, string name, int size,string permissions,string data) {
        this->id = id;
        this->name = name;
        this->size = size;
        this->permissions = permissions; 
        this->AddressOfDataBlock=insertDataIntoDataBlock(data);
    }
};

// Develop Filesystem
class FileSystem {

private:
    vector<Inode*> inodes;

public:
    void create_inode(int id,string name, int size, string permissions,string data) {
        Inode* inode=new Inode(id, name, size, permissions,data);
        inodes.push_back(inode);
        return;
    }

    Inode* get_inode(int id) {
        for (Inode* i : inodes) {
            if (i->id == id) {
                return i;
            }
        }
        return NULL;
    }

    void update_inode(int id, int newSize, string newPermissions,string newName,int newId) {
        
        // Find the inode with given ID and update its attributes

        Inode* i=get_inode(id);

        if(i){
            i->id=newId;
            i->name=newName;
            i->size = newSize;
            i->permissions = newPermissions;
        }
    }

    bool delete_inode(int id) {
        for (auto it = inodes.begin(); it != inodes.end(); ++it) {
            if ((*it)->id == id) {
                inodes.erase(it);
                return true;
            }
        }
        return false;
    }
};

int main() {
    FileSystem* file_system=new FileSystem();

    string data="khush patel jayeshkumar";
    string file_name="file1";
    string perm="user_access:khush";
    int id=1;

    file_system->create_inode(id,file_name,data.size(),perm,data);
    Inode* IsAvailable=file_system->get_inode(1);

    if(IsAvailable){
        cout<<"File is available in your system."<<endl;
    }

    else{
        cout<<"File doesn't exist!!"<<endl;
    }

    bool Delete=file_system->delete_inode(1);

    Inode* vailable=file_system->get_inode(1);

    if(vailable){
        cout<<"File is available in your system."<<endl;
    }

    else{
        cout<<"File doesn't exist!!"<<endl;
    }
    
}