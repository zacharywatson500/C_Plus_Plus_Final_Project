#include <iostream>
using namespace std; 





class Node
{
  private:
    int val;
    Node* left;
    Node* right;

  public:
    Node();
    Node(int); 
    ~Node();
    bool set_val(int);
    bool set_left(Node*);
    bool set_right(Node*);
    int get_val() const;
    Node* get_left();
    Node* get_right(); 
    const Node* get_left() const;
    const Node* get_right() const;
    void display();
};

Node::Node()
{
  val=0;
  left=NULL;
  right=NULL;
}

Node::Node(int v)
{
  val=v;
  left=NULL;
  right=NULL;
}

Node::~Node()
{ 
}

bool Node::set_val(int v)
{
  val=v;
  return true;
}

int Node::get_val() const
{
  return val;
}

bool Node::set_left(Node* n)
{
  left=n;
}

Node* Node::get_left()
{
  return left;
}

const Node* Node::get_left() const
{
  return left;
}
bool Node::set_right(Node* p)
{
  right=p;
}

Node* Node::get_right()
{
  return right;
} 

const Node* Node::get_right() const
{
  return right;
}

void Node::display()
{
  cout << val << " ";
} 





class MyList
{
private:
	Node* start; 
	Node* end;  
	int min; 
	int max; 
	int length;
	void copy(Node*, Node*);
	bool is_equal(const MyList*,const MyList*) const;

public:
	MyList(); 
	MyList(int); 
	MyList(int,int,int);
	~MyList(); 
	MyList( const MyList &obj); 

	
	Node* get_start() const; 
	Node* get_end() const;  
	int get_min() const; 
	int get_max() const;  
	int get_length()const;
	void set_start(Node*); 
	void set_end(Node*); 
	void set_min(int); 
	void set_max(int); 
	bool add(int); 
	bool remove(int); 
	bool is_present(int) const;  
	bool is_empty() const; 
	int  is_duplicate(int) const;
	void display() const; 
	void erase_all(); 
	bool remove_all(int);  

	MyList& operator=(const MyList&); 
    bool operator==(const MyList&) const; 
};


MyList::MyList()
{
	start=NULL; 
	end = NULL; 
	max = 9; 
	min = 0; 
	length = 0;
}
 
MyList::MyList(int v)
{
	start->set_val(v); 
	end->set_val(v);  
	max = 9; 
	min = 0; 
	length = 1;
} 

MyList::MyList(int v, int mn, int mx)
{
	start->set_val(v); 
	end->set_val(v);  
	min = mn; 
	max = mx; 
	length = 1;
}

MyList::~MyList()
{
	Node* curr=start;
	while(curr!=NULL)
	{
		Node* temp=curr->get_right();
		//cout << "Deleting node with value: " << curr->get_val() << endl;
		delete curr;
		curr=temp;
	}
} 

MyList::MyList( const MyList &obj){  
  min = obj.min; 
  max = obj.max; 
  length = obj.length;
  start = new Node(obj.start->get_val()); 
  copy(obj.start,start); 
}  



Node* MyList::get_start() const{ 
	return start; 
} 

Node* MyList::get_end() const{ 
	return end;
}

int MyList::get_min() const
{
  return min;
}  

int MyList::get_max() const
{
  return max;
} 

int MyList::get_length()const{ 
  return length;
}
 
void MyList::set_start(Node* n){ 
	start = n;
} 

void MyList::set_end(Node* n){ 
	end = n;
} 

void MyList::set_min(int v)
{
  min=v;
}
void MyList::set_max(int v)
{
  max=v;
} 



void MyList::copy(Node* old, Node* cpy) 
{    
	if (old==NULL)
    	return;    
	if (old->get_right()== NULL){ 
		end = start; 
		return;
	}
	if(cpy == start){
		Node* next = new Node(old->get_right()->get_val());  
		length++;
		cpy->set_right(next);   
		old = old->get_right();
	}
	while(old->get_right()!= NULL){ 
	  Node* next = new Node(old->get_right()->get_val());  
	  length++;  
	  Node* prev = cpy; 
	  cpy = cpy->get_right();
	  cpy->set_right(next);   
	  cpy->set_left(prev); 
	  old = old->get_right(); 
	}  
	//Set End Node   
	Node* prev = cpy;
	cpy = cpy->get_right(); 
	cpy->set_left(prev); 
	set_end(cpy); 
}  

bool MyList::add(int v)
{ 
	if(v>max||v<min) return false;
	Node* temp=new Node(v); 
	length++;
	if (start==NULL)
	{
		start=temp; 
		end = temp;
		return true;
	} 
	if (start->get_right()==NULL)
	{
		temp->set_right(start); 
		start->set_left(temp); 
		end = start; 
		start = temp;
		return true;
	}
	temp->set_right(start); 
	start->set_left(temp);
	start=temp;
	return true;
}   


bool MyList::remove(int v)
{
	Node* curr1=start;
	if (!is_present(v))
		return false;
	if (start->get_val()==v)
	{
		Node* temp=start;
		start=start->get_right(); 
		delete temp; 
		length--;
		return true;
	}

	while(curr1!=NULL)
	{
		Node* curr2=curr1->get_right();
		if (curr2->get_val()==v)
		{   
			Node* curr3 = curr2->get_right();
			curr1->set_right(curr3); 
			if(curr3!=NULL)curr3->set_left(curr1); 
			else end = curr1;
			delete curr2; 
			length--;
			return true;
		}
		curr1=curr1->get_right();
	}
}

bool MyList::is_present(int v) const
{ 
	if(v>max||v<min) return false;
	Node* curr=start;
	while(curr!=NULL)
	{
		if (curr->get_val()==v)
			return true;
		curr=curr->get_right();
	}
	return false;
} 

bool MyList::is_empty() const { 
	if(start == NULL && end == NULL)return true; 
	else return false;
}   

int MyList::is_duplicate(int v) const { 

	Node* temp = start;  
	int counter = 0;
	while(temp!=NULL){ 
		if (temp ->get_val() == v) counter++;
		temp = temp->get_right(); 	
	}
	return counter;

}

void MyList::display() const
{
	Node* curr=start;
	while(curr!=NULL)
	{
		cout << curr->get_val() << " ";
		curr=curr->get_right();
	}
	cout << endl;
}

void MyList::erase_all(){ 

	while(start!=NULL){ 
		Node* curr1 =start; 
		start= start->get_right();
		delete curr1;  
		length--;
		}    
	end = NULL;
}

bool MyList::remove_all(int v){ 
	Node* curr1=start;
	if (!is_present(v))
		return false;
	if (start->get_val()==v)
	{
		Node* temp=start;
		start=start->get_right();
		delete temp; 
		length--;
	}

	while(curr1!=NULL)
	{
		Node* curr2=curr1->get_right(); 
		if (curr2 == NULL) return true;
		if (curr2->get_val()==v)
		{
			curr1->set_right(curr2->get_right());
			delete curr2; 
			length--;
		}
		curr1=curr1->get_right();
	} 
	return true;
}   

MyList& MyList::operator=(const MyList &t){ 
  if (&t==this)
    return *this;  
  min = t.min; 
  max = t.max;  
  length = t.length;
  erase_all(); 
  start = new Node(t.start->get_val()); 
  copy(t.start,start);  
  return *this;
} 

bool MyList::operator==(const MyList& t) const{ 
  return is_equal(this,&t);
} 

bool MyList::is_equal(const MyList* one, const MyList* two)const{ 
  if (one->get_length()!=two->get_length()) return false;   
  if (one->get_start()==NULL&&two->get_start()==NULL) return true;  

  bool tracker[one->get_length()]; 
  for(int i= 0;i<one->get_length();i++){ 
  	tracker[i] = false;
  } 
  int j = 0;
  Node* temp1 = one->get_start(); 
  Node* temp2 = two->get_start(); 
  
  for(int i;i<one->get_length();i++){ 
  	while(temp2!=NULL){
  	  if(temp1->get_val()==temp2->get_val()){ 
  	  	if(tracker[j]==true){  
  	  		temp2 = temp2->get_right(); 
  	        j++;
  	  		continue; 
  	  	} 
  	  	tracker[j] = true; 
  	  	break;   	
  	  } 
  	  temp2 = temp2->get_right(); 
  	  j++;
  	} 
  	if (temp2 = NULL) return false;
  	temp1 = temp1->get_right(); 
  	j = 0;
  }
  //if ((one!=NULL&&two==NULL)||(one==NULL&&two!=NULL)) return false;
 // if (one->get_val() != two->get_val()) return false;
 // if(is_equal(one->get_right(),two->get_right())== false) return false;
  return true; 
}










class DynArray{ 
private: 
	MyList* pa;  
	int length; 

public: 
	DynArray(); 
	DynArray(int);
	~DynArray(); 
	DynArray( const DynArray &obj);  
	DynArray& operator=(const DynArray &t);
	bool operator==(const DynArray& t) const;  
	bool add_range(int,int); 
	void display(); 
	bool remove_range(int); 
	bool remove_element(int); 
	int get_length()const; 
	void set_length(int);
};  

DynArray::DynArray(){ 
	pa = new MyList[3];
 	for (int i = 0; i < 3; i++){ 
 		pa[i].set_min((i*10)); 
 		pa[i].set_max((i*10)+9); 
 		pa[i].add((i*10)+5);
 	}
 	length = 3;
} 

DynArray::DynArray(int v){ 
	pa = new MyList[v];
 	for (int i = 0; i < v; i++){ 
 		pa[i].set_min((i*10)); 
 		pa[i].set_max((i*10)+9);
 	}
 	length = v;
}

DynArray::~DynArray(){ 
 	delete [] pa;
} 

DynArray::DynArray( const DynArray &obj){ 
	length = obj.length;
	pa = new MyList[length]; 
	for (int i = 0; i < length; i++){ 
 		pa[i] = obj.pa[i];
 	}
} 

DynArray& DynArray::operator=(const DynArray &t){ 
  if (&t==this)
    return *this;  
  length = t.length;  
  delete [] pa; 
  pa = new MyList[length]; 
  for (int i = 0; i < length; i++){ 
 	pa[i] = t.pa[i];
  }
  return *this;
} 
 
bool DynArray::add_range(int MIN, int MAX){  
	for(int i = 0; i < length; i++){ 
		if(((MIN>pa[i].get_min())&&(MIN<pa[i].get_max()))||((MAX>pa[i].get_min())&&(MAX<pa[i].get_max()))) return false;
	} 
	MyList* newarr; 
	newarr = new MyList[length + 1]; 

	for(int i = 0; i < length; i++){ 
		newarr[i] = pa[i]; 
	}  
	newarr[length].set_min(MIN);
	newarr[length].set_max(MAX); 
	length++;  
	delete [] pa; 
	pa = newarr;
	return true;
} 
 
 void DynArray::display(){ 
 	for(int i = 0; i < length; i++){ 
 		cout << "Range: " << i << " Min: " << pa[i].get_min() << " Max: " << pa[i].get_max()  << endl;  
 		pa[i].display();
 	}
 }
 
 bool DynArray::remove_range(int v) { 
 	if(v>=length||v<0) return false; 
 	MyList* newar; 
	newar = new MyList[length]; 
	int j = 0; 
	for(int i = 0; i < length; i++){ 
		//if(i == v) continue;  
		newar[j] = pa[i];   
		newar[j].display();
		j++;
	}    
	length--;
	delete [] pa; 
	pa = newar; 
	return true;
 } 

 bool DynArray::remove_element(int v) { 
 	for(int i = 0; i < length; i++){ 
 		if(pa[i].remove(v)) return true;
 	} 
 	return false;
 }

bool DynArray::operator==(const DynArray &t)const{ 
  if (length!=t.length) return false;  
  for (int i = 0; i < length; i++)
  { 
  	if(pa[i]==t.pa[i]) continue;
  	else return false;
  } 
  return true;
}
int DynArray::get_length() const
{
  return length;
} 

void DynArray::set_length(int v) 
{
  length = v;
}




int main(){ 
	MyList c,d;  
	DynArray x, y;   
	x = y;  
	x.add_range(45,50); 
	x.display(); 
	x.remove_element(5); 
	x.display();
	if(x==y) cout <<"equal\n"; 
	else cout <<"not equal\n";
	return 0;
}










