// 1
// Reverse Integer
// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};


// 2
// String to Integer (atoi)
// Input: s = "   -42"
// Output: -42


int myAtoi(string str) {
    long result = 0;
    int indicator = 1;
    for(int i = 0; i<str.size();)
    {
        i = str.find_first_not_of(' ');
        if(str[i] == '-' || str[i] == '+')
            indicator = (str[i++] == '-')? -1 : 1;
        while('0'<= str[i] && str[i] <= '9') 
        {
            result = result*10 + (str[i++]-'0');
            if(result*indicator >= INT_MAX) return INT_MAX;
            if(result*indicator <= INT_MIN) return INT_MIN;                
        }
        return result*indicator;
    }
}


// 3
// Longest Palindromic Substring
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

#include<bits/stdc++.h>
using namespace std;

string lPS(string s){
    int n = s.size();
    vector<vector<int>>dp(n, vector<int>(n,0));
    int maxLength = 0;
    string ans;
    for(int diff = 0;diff<n;diff++){
        for(int i=0, j=i+diff; j<n;i++,j++){
            if(i==j){
                dp[i][j]=1;
            }else if(diff == 1){
                dp[i][j] = s[i] == s[j] ? 2 : 0;
            }else{
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
            }
            if(dp[i][j]){
                if(j-i+1>maxLength){
                    maxLength = j-i+1;
                    ans = s.substr(i, maxLength);
                }
            }
        }
    }
    return ans;
}

int main() {
    // Write C++ code here
    std::cout << lPS("babad") ;

    return 0;
}

// 4
// Longest Common Prefix
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        int n =strs.size();
        string ans; 
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[n-1];
        for(int i =0; i< a.size(); i++){
            if(a[i] == b[i]){
                ans += a[i];
            }else break;
        }
        return ans;
    }
};



// 5
// Merge two sorted lists


#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }
};

void InsertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next=head;
    head=n;
}

void InsertAtTail(node* &head, int val){
    node* n = new node(val);

    node* temp = head;
    while(temp->next!=NULL){
        temp= temp->next;
    }

    temp->next=n;
}

void DeleteHead(node* &head){
    node* todelete = head;

    head=head->next;
    delete todelete;
}

void Deletion(node* &head, int val){
    // if(head==NULL){
    //     return;
    // }
    // if(head->next==NULL){
    //     DeleteHead(head);
    //     return;
    // }

    // node* n = new node(val);

    node*temp = head;
    while(temp->next->data==val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

node* reverse(node* &head){
        node* prevptr = NULL;
        node* currptr = head;
        node* nextptr;

        while(currptr!=NULL){
            nextptr=currptr->next;
            currptr->next=prevptr;

            prevptr=currptr;
            currptr=nextptr;
        }
        return prevptr; //Because prevptr is new head at the end
}

node* RecursiveReverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead = RecursiveReverse(head->next);
    head->next->next=head;
    head->next= NULL;

    return newhead;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}

bool Search(node* head,int key){
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==key){
          return true;
        }
        temp=temp->next;  
  }
  return false;
}

int sizeofll(node *&head)
{
    int count = 1;
    node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

node *reversek(node *&head, int k, int size)
{
    if (k > size)
    {
        return head;
    }
        node *prevptr = NULL;
        node *currptr = head;
        node *nextptr;
        int count = 0;

        while (currptr != NULL && count < k)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;

            prevptr = currptr;
            currptr = nextptr;
            count++;
        }
        if (nextptr != NULL)
        {
            head->next = reversek(nextptr, k, size);
        }
        return prevptr;
}

void traversal(node* ptr)
{
	
  while(ptr!=NULL )
  {
  	cout<<ptr->data<<"->";
  	ptr=ptr->next;
  	
  }
  cout<<"NULL"<<endl;
}
void makeCycle(node* ptr,int pos)
{
	node* temp=ptr;
	node* p;
	int count=1;
	while(temp->next!=NULL)
	{
		if(count==pos)
		{
			p=temp;
		}
		temp=temp->next;
		count++;
	}
	temp->next=p;
}
bool isCyclic(node* head)
{
	node* fast=head;
	node* slow=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)
		{
			return true;
		}
	}
	return false;
}
void removeCycle(node* head)
{
	node* slow=head;
	node* fast=head;
	do{
		slow=slow->next;
		fast=fast->next->next;	
	}while(slow!=fast);
	fast=head;
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}

node* mergetwosorted(node* head1,node* head2)
{
   if (head1->data<head2->data)
   swap(head1,head2);
   node* head=head2;
   node* lst=head2;
   head2=head2->next;
   while (true)
   {  
      if (head1==NULL)
      {
         lst->next=head2;
         break;
      }
      else if (head2==NULL)
      {
         lst->next=head1;
         break;
      }
      else if ((head1->data)<(head2->data))
      {
         lst->next=head1;
         lst=lst->next;
         head1=head1->next;
      }
      else
      {
         lst->next=head2;
         lst=lst->next;
         head2=head2->next;
      }
   }
   return head;
}

int main(){
    node* head = NULL;
    InsertAtHead(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 10);
    
    display(head);
    
    node* head2 = NULL;
    InsertAtHead(head2, 5);
    InsertAtTail(head2, 6);
    InsertAtTail(head2, 7);
    InsertAtTail(head2, 8);
    InsertAtTail(head2, 9);
    
    display(head2);
    
	
	cout<<"merge";
	node *head3 = mergetwosorted(head, head2);
    display(head3);
    
    return 0;
}









// 6
// Linked List Operations



#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }
};

void InsertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next=head;
    head=n;
}

void InsertAtTail(node* &head, int val){
    node* n = new node(val);

    node* temp = head;
    while(temp->next!=NULL){
        temp= temp->next;
    }

    temp->next=n;
}

void DeleteHead(node* &head){
    node* todelete = head;

    head=head->next;
    delete todelete;
}

void Deletion(node* &head, int val){
    // if(head==NULL){
    //     return;
    // }
    // if(head->next==NULL){
    //     DeleteHead(head);
    //     return;
    // }

    // node* n = new node(val);

    node*temp = head;
    while(temp->next->data==val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

node* reverse(node* &head){
        node* prevptr = NULL;
        node* currptr = head;
        node* nextptr;

        while(currptr!=NULL){
            nextptr=currptr->next;
            currptr->next=prevptr;

            prevptr=currptr;
            currptr=nextptr;
        }
        return prevptr; //Because prevptr is new head at the end
}

node* RecursiveReverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead = RecursiveReverse(head->next);
    head->next->next=head;
    head->next= NULL;

    return newhead;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}

bool Search(node* head,int key){
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==key){
          return true;
        }
        temp=temp->next;  
  }
  return false;
}

int sizeofll(node *&head)
{
    int count = 1;
    node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

node *reversek(node *&head, int k, int size)
{
    if (k > size)
    {
        return head;
    }
        node *prevptr = NULL;
        node *currptr = head;
        node *nextptr;
        int count = 0;

        while (currptr != NULL && count < k)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;

            prevptr = currptr;
            currptr = nextptr;
            count++;
        }
        if (nextptr != NULL)
        {
            head->next = reversek(nextptr, k, size);
        }
        return prevptr;
}

void traversal(node* ptr)
{
	
  while(ptr!=NULL )
  {
  	cout<<ptr->data<<"->";
  	ptr=ptr->next;
  	
  }
  cout<<"NULL"<<endl;
}
void makeCycle(node* ptr,int pos)
{
	node* temp=ptr;
	node* p;
	int count=1;
	while(temp->next!=NULL)
	{
		if(count==pos)
		{
			p=temp;
		}
		temp=temp->next;
		count++;
	}
	temp->next=p;
}
bool isCyclic(node* head)
{
	node* fast=head;
	node* slow=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)
		{
			return true;
		}
	}
	return false;
}
void removeCycle(node* head)
{
	node* slow=head;
	node* fast=head;
	do{
		slow=slow->next;
		fast=fast->next->next;	
	}while(slow!=fast);
	fast=head;
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}

node* mergetwosorted(node* head1,node* head2)
{
   if (head1->data<head2->data)
   swap(head1,head2);
   node* head=head2;
   node* lst=head2;
   head2=head2->next;
   while (true)
   {  
      if (head1==NULL)
      {
         lst->next=head2;
         break;
      }
      else if (head2==NULL)
      {
         lst->next=head1;
         break;
      }
      else if ((head1->data)<(head2->data))
      {
         lst->next=head1;
         lst=lst->next;
         head1=head1->next;
      }
      else
      {
         lst->next=head2;
         lst=lst->next;
         head2=head2->next;
      }
   }
   return head;
}

int main(){
    node* head = NULL;
    InsertAtHead(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    InsertAtTail(head, 7);
    InsertAtTail(head, 8);
    InsertAtTail(head, 9);
    display(head);
    
    cout<<"Deletion";
    DeleteHead(head);
    display(head);
    // Deletion(head,7);
    // display(head);
    
    cout<<"reverse";
    cout<<">>>>>>>After reversing<<<<<<<"<<endl;
    node* newhead = reverse(head);
    display(newhead);

    cout<<">>>>>>>>>>After recursive reverse<<<<<<<<<<"<<endl;
    node* headnew = RecursiveReverse(newhead);
    display(headnew);
    cout<<Search(head,1)<<"   ";
    
    cout<<"reverse k node";
    
    int s = sizeofll(head);
    int k = 6;
    node *head1 = reversek(head, k, s);
    display(head1);
    
    cout<<"cycle";
    node *head2 = NULL;
    InsertAtHead(head, 1);
    int a[]={1,2,3,4,5,6,7,8,9};
	for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++)
	{
		InsertAtTail(head2,a[i]);
	}
	traversal(head);
	bool res=isCyclic(head);
	cout<<boolalpha<<res<<endl;
	makeCycle(head,4);
// 	traversal(head);
	res=isCyclic(head);
	cout<<boolalpha<<res<<endl;
	removeCycle(head);
	res=isCyclic(head);
	cout<<boolalpha<<res<<endl;
	traversal(head);
	
	cout<<"merge";
	node *head3 = mergetwosorted(head, head2);
	display(head2);
    display(head3);
    
    return 0;
}
