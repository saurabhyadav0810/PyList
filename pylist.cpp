#include <bits/stdc++.h>
using namespace std;

class Pylist;
enum Dtype
{
    INT,
    FLOAT,
    BOOL,
    DOUBLE,
    STRING,
    CHAR,
    LIST
};
class Pynode
{
public:
    int ival;
    float fval;
    double dval;
    bool bval;
    string sval;
    char cval;
    Pylist *list;

    // public:
    Dtype type;

    // constructors
    Pynode *next, *prev;
    Pynode(int data) : ival(data), type(INT)
    {
        next = prev = nullptr;
    }
    Pynode(float data) : fval(data), type(FLOAT)
    {
        next = prev = nullptr;
    }
    Pynode(double data) : dval(data), type(DOUBLE)
    {
        next = prev = nullptr;
    }
    Pynode(char data) : cval(data), type(CHAR)
    {
        next = prev = nullptr;
    }
    Pynode(bool data) : bval(data), type(BOOL)
    {
        next = prev = nullptr;
    }
    Pynode(string data) : sval(data), type(STRING)
    {
        next = prev = nullptr;
    }
   
    Pynode(const Pynode &other)
    {
        next = prev = nullptr;
        switch (other.type)
        {
        case INT:
            this->ival = other.ival;
            this->type = INT;
            break;
        case DOUBLE:
            this->dval = other.dval;
            this->type = DOUBLE;
            break;
        case FLOAT:
            this->fval = other.fval;
            this->type = FLOAT;
            break;
        case STRING:
            this->sval = other.sval;
            this->type = STRING;
            break;
        case BOOL:
            this->bval = other.bval;
            this->type = BOOL;
            break;
        case CHAR:
            this->cval = other.cval;
            this->type = CHAR;
            break;
        default:
            break;
        }
    }
    Pynode(const Pynode *other)
    {
        next = prev = nullptr;
        switch (other->type)
        {
        case INT:
            this->ival = other->ival;
            this->type = INT;
            break;
        case DOUBLE:
            this->dval = other->dval;
            this->type = DOUBLE;
            break;
        case FLOAT:
            this->fval = other->fval;
            this->type = FLOAT;
            break;
        case STRING:
            this->sval = other->sval;
            this->type = STRING;
            break;
        case BOOL:
            this->bval = other->bval;
            this->type = BOOL;
            break;
        case CHAR:
            this->cval = other->cval;
            this->type = CHAR;
            break;
        default:
            break;
        }
    }
  

    Pynode &operator=(double val)
    {
        this->dval = val;
        this->type = DOUBLE;
        return *this;
    }
    Pynode &operator=(int val)
    {
        this->ival = val;
        this->type = INT;
        return *this;
    }
    Pynode &operator=(float val)
    {
        this->fval = val;
        this->type = FLOAT;
        return *this;
    }
    Pynode &operator=(string val)
    {
        this->sval = val;
        this->type = STRING;
        return *this;
    }
    Pynode &operator=(char val)
    {
        this->cval = val;
        this->type = CHAR;
        return *this;
    }
    Pynode &operator=(bool val)
    {
        this->bval = val;
        this->type = BOOL;
        return *this;
    }
    Pynode &operator=(const char *val)
    {
        this->sval = string(val);
        this->type = STRING;
        return *this;
    }

    Pynode &operator=(const Pynode &other)
    {
        switch (other.type)
        {
        case INT:
            this->ival = other.ival;
            this->type = INT;
            break;
        case DOUBLE:
            this->dval = other.dval;
            this->type = DOUBLE;
            break;
        case FLOAT:
            this->fval = other.fval;
            this->type = FLOAT;
            break;
        case STRING:
            this->sval = other.sval;
            this->type = STRING;
            break;
        case BOOL:
            this->bval = other.bval;
            this->type = BOOL;
            break;
        case CHAR:
            this->cval = other.cval;
            this->type = CHAR;
            break;
        default:
            break;
        }
        return *this;
    }
    Pynode &operator=(const Pynode *other)
    {
        if (!other)
            return *this;
        switch (other->type)
        {
        case INT:
            this->ival = other->ival;
            this->type = INT;
            break;
        case DOUBLE:
            this->dval = other->dval;
            this->type = DOUBLE;
            break;
        case FLOAT:
            this->fval = other->fval;
            this->type = FLOAT;
            break;
        case STRING:
            this->sval = other->sval;
            this->type = STRING;
            break;
        case BOOL:
            this->bval = other->bval;
            this->type = BOOL;
            break;
        case CHAR:
            this->cval = other->cval;
            this->type = CHAR;
            break;
        default:
            break;
        }
        return *this;
    }
    
};
class Pylist
{
    Pynode *head, *tail;
    unordered_map<int, Pynode *> mp;
    int index;
    int length;

    bool push_front(Pynode *newnode);

public:
    Pylist()
    {
        head = tail = nullptr;
        length = 0;
        index = 0;
    }

    void append(int);
    void append(float);
    void append(double);
    void append(string);
    void append(char);
    void append(bool);
    void append(const char *data);   //"Without the code won't accept string literals like append("hello"). compiler won’t automatically convert const char* to std::string ."
    void append(Pynode *);   //for pointer
    // ---------------------------

    // --------------------------
    bool insert(int idx, int data)
    {
        if (idx > length)
            idx = length;
        return insertNode(idx, new Pynode(data));
    }
    bool insert(int idx, float data)
    {
        if (idx > length)
            idx = length;
        return insertNode(idx, new Pynode(data));
    }
    bool insert(int idx, double data)
    {
        if (idx > length)
            idx = length;
        return insertNode(idx, new Pynode(data));
    }
    bool insert(int idx, string data)
    {
        if (idx > length)
            idx = length;
        return insertNode(idx, new Pynode(data));
    }
    bool insert(int idx, char data)
    {
        if (idx > length)
            idx = length;
        return insertNode(idx, new Pynode(data));
    }
    bool insert(int idx, bool data)
    {
        if (idx > length)
            idx = length;
        return insertNode(idx, new Pynode(data));
    }
    bool insert(int idx, const char *data)
    {
        if (idx > length)
            idx = length;
        return insertNode(idx, new Pynode(string(data)));
    }
    bool insert(int idx, Pynode *newnode)
    {
        if (idx > length)
            idx = length;
        return insertNode(idx, newnode);
    }
    bool insertNode(int idx, Pynode *newnode);

    // -----------------------

    // Functions of removing an element from list
    bool pop();
    bool remove(int idx);

    // all about clearing the list
    void clear();

    // Adding a list to other list
    void extend(Pylist &list);
    void append(Pylist &list);
    Pylist &operator=(const Pylist &other)
    {
        Pynode *curr = other.head;
        while (curr)
        {
            this->append(curr);
            curr = curr->next;
        }
        return *this;
    }

    // other functions on list
    Pylist slice(int start, int end = INT_MAX, int step = 1);
    void display() const;
    int size();
    void reverse();

    // Operatror overloaded functions

    friend std::ostream &operator<<(std::ostream &out, const Pylist &list);
    friend std::ostream &operator<<(std::ostream &out, Pynode *curr);
    Pynode *operator[](int idx);
    Pylist& operator=(Pylist& other);
    
   
    // destructor 
    ~Pylist() {
        clear();
    // is_deleted = true;
    }
    
};

// All Memebr functions Implementations
void Pylist::append(Pynode *node)
{
    Pynode *newnode = new Pynode(node);
    if (!head)
        head = tail = newnode;
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    length++;
    mp[index++] = newnode;
}
void Pylist::append(int data)
{
    Pynode *newnode = new Pynode(data);
    if (!head)
        head = tail = newnode;
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    length++;
    mp[index++] = newnode;
}
//
void Pylist::append(float data)
{
    Pynode *newnode = new Pynode(data);
    if (!head)
        head = tail = newnode;
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    length++;
    mp[index++] = newnode;
}
void Pylist::append(double data)
{
    Pynode *newnode = new Pynode(data);
    if (!head)
        head = tail = newnode;
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    length++;
    mp[index++] = newnode;
}
void Pylist::append(const char *data)
{
    append(string(data));
}
void Pylist::append(string data)
{
    Pynode *newnode = new Pynode(data);
    if (!head)
        head = tail = newnode;
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    length++;
    mp[index++] = newnode;
}
void Pylist::append(char data)
{
    Pynode *newnode = new Pynode(data);
    if (!head)
        head = tail = newnode;
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    length++;
    mp[index++] = newnode;
}
void Pylist::append(bool data)
{
    Pynode *newnode = new Pynode(data);
    if (!head)
        head = tail = newnode;
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    length++;
    mp[index++] = newnode;
}

// -------------------------
bool Pylist::push_front(Pynode *node)
{
    Pynode *newnode = new Pynode(node);
    if (length == 0)
    {
        append(newnode);
        return true;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    for (int i = length; i > 0; i--)
        mp[i] = mp[i - 1];
    mp[0] = newnode;
    length++;
    return true;
}

bool Pylist::insertNode(int idx, Pynode *node)
{
    Pynode *newnode = new Pynode(node);
    if (idx < 0)
        return false;
    else if (idx >= this->length)
    {
        append(newnode);
        return true;
    }
    else if (idx == 0)
        return push_front(newnode);

    Pynode *flag = mp[idx];
    flag->prev->next = newnode;
    newnode->prev = flag->prev;
    flag->prev = newnode;
    newnode->next = flag;
    for (int i = length; i > idx; --i)
        mp[i] = mp[i - 1];
    mp[idx] = newnode;
    length++;
    return true;
}

// All removal funcrtions

bool Pylist::pop()
{
    if (!head)
        return false;

    if (length == 1)
    {
        delete head;
        head = tail = nullptr;
        mp.erase(0);
        length--;
        return true;
    }
    Pynode *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    mp.erase(length - 1);
    length--;

    return true;
}

bool Pylist::remove(int idx)
{
    if (this->mp.find(idx) == mp.end())
        return false;   // check is the index is valid or not

    if (idx == length - 1)
    {
        return pop();
    }
    Pynode *temp = mp[idx];
    if (temp == head)
        head = head->next;
    // else if(temp==tail)tail = tail->prev;

    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    for (int i = idx; i < length - 1; i++)
        mp[i] = mp[i + 1];
    mp.erase(length - 1);
    temp->next = temp->prev = nullptr;
    delete temp;
    length--;
    return true;
}

void Pylist::clear()
{
    Pynode *curr = this->head;
    while (curr)
    {
        Pynode *temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = tail = nullptr;
    mp.clear();
    length = index = 0;
}
// Functions of adding one list to another
void Pylist::extend(Pylist &newlist)
{
    if (newlist.size() == 0)
        return;
    Pynode *curr = newlist.head;
    while (curr)
    {
        this->append(new Pynode(curr));
        curr = curr->next;
    }
}

void Pylist::reverse()
{
    if (!head || head == tail)
        return;
    Pynode *p = nullptr;
    Pynode *curr = head;
    while (curr)
    {
        Pynode *next = curr->next;
        curr->next = p;
        if (p)
            p->prev = curr;
        p = curr;
        curr = next;
    }
    tail = head;
    head = p;
    
    int l = 0, r = length - 1;
    while (l < r)
    {
        Pynode *temp = mp[l];
        mp[l] = mp[r];
        mp[r] = temp;
        l++;
        r--;
    }
}
void Pylist::display() const
{
    if (!head)
        cout << "[]" << endl;
    else
    {
        Pynode *curr = head;

        cout << "\033[32m[\033[0m";
        while (curr)
        {
            switch (curr->type)
            {
            case INT:
                cout << "\033[31m" << curr->ival << "\033[0m";
                break;
            case FLOAT:
                cout << "\033[35m" << curr->fval << "\033[01m";
                break;
            case DOUBLE:
                cout << "\033[34m" << curr->dval << "\033[0m";
                break;
            case CHAR:
                cout << curr->cval;
                break;
            case STRING:
                cout << "\033[32m\"" << curr->sval << "\"\033[0m";
                break;
            case BOOL:
                cout << "\033[33m" << (curr->bval ? "True" : "False") << "\033[0m";
                break;
            }
            if (curr->next)
                if (curr->next)
                    cout << "\033[36m, \033[0m";
            curr = curr->next;
        }
        cout << "\033[32m]\033[0m" << endl;
    }
}

int Pylist::size()
{
    return length;
}

Pylist Pylist::slice(int start, int end, int step)
{

    Pylist newlist;
    if (start >= length)
    {
        cout << "Index out of Bounds";
        return newlist;
    }
    if (end > length)
        end = length;

    for (int i = start; i < end; i += step)
    {
        Pynode *newnode = new Pynode(*(this->mp[i]));
        newlist.append(newnode);
    }

    return newlist;
}
// ------------operator overloaded functions-----------------
ostream &operator<<(ostream &os, const Pylist &list)
{
    list.display();
    return os;
}

ostream &operator<<(ostream &os, Pynode *curr)
{
    if (!curr)
        cout << "None" << endl;
    else
    {
        switch (curr->type)
        {
        case INT:
            cout << "\033[31m" << curr->ival << "\033[0m";
            break;
        case FLOAT:
            cout << "\033[35m" << curr->fval << "\033[01m";
            break;
        case DOUBLE:
            cout << "\033[34m" << curr->dval << "\033[0m";
            break;
        case CHAR:
            cout << curr->cval;
            break;
        case STRING:
            cout << "\033[32m" << curr->sval << "\033[0m";
            break;
        case BOOL:
            cout << "\033[33m" << (curr->bval ? "True" : "False") << "\033[0m";
            break;
        }
    }

    return os;
}
Pynode *Pylist::operator[](int idx)
    {
        if (mp.find(idx) != mp.end())
        {
            Pynode *curr = mp.find(idx)->second;
            return curr;
        }
        else
        {
            cout << "Index out of range" << endl;
            return nullptr;
        }
    }
Pylist& Pylist::operator=(Pylist& other)
{
    if(this==&other)return *this;
    this->clear();
    this->extend(other);
    return *this;
}

int main()
{
    Pylist list;
    list.append(10);
    list.append("Saurabh");
    list.append("Ankur");
    list.append(10.5);
    list.insert(true,2);
    cout<<"Original list"<<endl;
    cout<<list;
    list.reverse();
    cout<<"reversed list"<<endl;
    list.display();    
}