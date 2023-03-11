#include<iostream>
using namespace std;

template<class T>
struct nodeSL
{
    T data;
    struct nodeSL * next;
};

template<class T>
class SinglyLL
{
    public:
        struct nodeSL <T>* First;

        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int count();

        T Sum();
        T Maximum();
        T Minimum();
        int DigitSum(int iNo);
        void DisplayDigitSum();
        bool Check_Perfect(int iNo);
        void DisplayPerfect();
        int SearchFirstAccurance(int iNo);
        int SearchLastAccurance(int iNo);
        void Display_Frequency(T iNo);
        T MiddleElement();
        void ReverseLinkedList();
};
template<class T>
SinglyLL <T>:: SinglyLL()
{
    First = NULL;
}
template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeSL <T>* newn = new struct nodeSL<T>;
    newn->data = no;
    newn->next = NULL;

    if(First== NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}
template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct nodeSL <T>* newn = new struct nodeSL<T>;
    newn->data = no;
    newn->next = NULL;

    if(First==NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeSL <T>* temp = First;

        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}
template<class T>
void SinglyLL<T> :: InsertAtPos(T no,int ipos)
{
    int iNodecount = 0;

    iNodecount = count();
    if((ipos<1)||(ipos>iNodecount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==iNodecount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeSL<T> * newn = new struct nodeSL<T>;
        newn->data = no;
        newn->next = NULL;
        struct nodeSL <T>* temp = First;
        int iCnt = 0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        
    }
}
template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeSL <T>* temp = First;
        First = First->next;
        delete temp;
    }
}
template<class T>
void SinglyLL<T> :: DeleteLast()
{
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeSL <T>* temp =First;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}
template<class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
    int iNodecount = count();

    if((ipos<1)||(ipos>iNodecount+1))
    {
        cout<<"invalide position";
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==iNodecount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeSL <T>* temp1 = First;
        struct nodeSL <T>* temp2 = NULL;
        int iCnt =0 ;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;

    }
}
template<class T>
void SinglyLL <T>:: Display()
{
    struct nodeSL<T> * temp = First;
    cout<<"Elements of linked list are:";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}
template<class T>
int SinglyLL<T> :: count()
{
    int iCnt =0 ;
    struct nodeSL <T>* temp = First;
    while(temp!=NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}
template<class T>
T SinglyLL<T> :: Sum()
{
    struct nodeSL<T> * temp = First;
    T iSum = 0;
    while(temp!=NULL)
    {
        iSum = iSum+(temp->data);
        temp = temp->next;
    }
    return iSum;
}
template<class T>
T SinglyLL<T> :: Maximum()
{
    struct nodeSL<T> * temp = First;
    

    if(First==NULL)
    {
        cout<<"Linkedlist is empty"<<"\n";
        return 0;
    }

    T Max = First->data;
    while(temp!=NULL)
    {
        if(temp->data>Max)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }
    return Max;
}
template<class T>
T SinglyLL<T> :: Minimum()
{
    struct nodeSL<T> * temp = First;

    if(First==NULL)
    {
        cout<<"Linkedlist is empty"<<"\n";
        return 0;
    }

    T Min = First->data;
    while(temp!=NULL)
    {
        if(temp->data<Min)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }
    return Min;
}
template<class T>
int SinglyLL<T> :: DigitSum(int iNo)
{
    int iDigit = 0;
    int iSum = 0;
    while(iNo!=0)
    {
        iDigit = iNo%10;
        iSum = iSum+iDigit;
        iNo = iNo/10;
    }
    return iSum;
}
template<class T>
void SinglyLL<T> :: DisplayDigitSum()
{
    int iRet = 0;
    struct nodeSL<T> * temp = First;
    while(temp!=NULL)
    {
        iRet = DigitSum(temp->data);
        printf("Sum of Digits %d is %d :\n",temp->data,iRet);
        temp = temp->next;
    }
}
template<class T>
bool SinglyLL <T>:: Check_Perfect(int iNo)
{
    int iSum = 0;
    int iCnt = 0;

    for(iCnt=1;iCnt<=iNo/2;iCnt++)
    {
        if(iNo%iCnt==0)
        {
            iSum = iSum+iCnt;
        }
    }
    return(iSum == iNo);
}
template<class T>
void  SinglyLL <T>:: DisplayPerfect()
{
    struct nodeSL<T> * temp = First;
    while(temp!=NULL)
    {
        if(Check_Perfect(temp->data)==true)
        {
            cout<<temp->data<<" is PERFECT Number."<<"\n";
        }
        temp = temp->next;
    }
}
template<class T>
int SinglyLL <T>:: SearchFirstAccurance(int iNo)
{
    int indexCnt = 1;
    int ipos = -1;

    struct nodeSL<T> * temp = First;

    while(temp!=NULL)
    {
        if(temp->data == iNo)
        {
            ipos = indexCnt;
            break;
        }
        indexCnt++;
        temp = temp->next;
    }
    return ipos;
}
template<class T>
int SinglyLL <T> :: SearchLastAccurance(int iNo)
{
    int indexCnt = 1;
    int ipos = -1;

    struct nodeSL <T>* temp = First;

    while(temp!=NULL)
    {
        if(temp->data == iNo)
        {
            ipos = indexCnt;
        }
        indexCnt++;
        temp = temp->next;
    }
    return ipos;
} 

template<class T>
void SinglyLL<T> :: Display_Frequency(T No)
{
    T iCounter = 0;

    struct nodeSL<T> * temp = First;

    while(temp!=NULL)
    {
        if(temp->data==No)
        {
            iCounter++;
        }
        temp = temp->next;
    }
    cout<<"Frequency of "<<No<<" in linked list is: "<<iCounter<<"\n";
}
template<class T>
T SinglyLL <T>:: MiddleElement()
{
    struct nodeSL<T> * Teacher = First;
    struct nodeSL<T> * Student = First;

    while((Teacher!=NULL)&&(Teacher->next!=NULL))
    {
        Teacher = Teacher->next->next;
        Student = Student->next;
    }
    return Student->data;

}
template<class T>
void SinglyLL<T>::ReverseLinkedList()
{
    struct nodeSL<T>* Next = NULL;
    struct nodeSL<T>* Previous = NULL;
    struct nodeSL<T>* Current = First;

    while(Current!=NULL)
    {
        Next = Current->next;
        Current->next = Previous;
        Previous = Current;
        Current = Next;
    }
    First = Previous;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
class SinglyCL
{
    public:
       struct nodeSL <T>* First;
        struct nodeSL <T>* Last;

        SinglyCL();
        
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();

        T Sum();
        T Maximum();
        T Minimum();
        int DigitSum(int iNo);
        void DisplayDigitSum();
        bool Check_Perfect(int iNo);
        void DisplayPerfect();
        int SearchFirstAccurance(int iNo);
        int SearchLastAccurance(int iNo);
        void Display_Frequency(T iNo);
        T MiddleElement();

};
template<class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
}
template<class T>        
void SinglyCL<T>:: InsertFirst(T no)
{
    struct nodeSL<T> * newn = new struct nodeSL<T>;
    newn->data = no;
    newn->next = NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First = Last = newn;
        Last->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
}
template<class T>
void SinglyCL<T>:: InsertLast(T no)
{
    struct nodeSL <T>* newn = new struct nodeSL<T>;
    newn->data = no;
    newn->next = NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First = Last = newn;
        Last->next = First;
    }
    else
    {
        Last->next = newn;
        Last = newn;
        Last->next = First;
    }
}
template<class T>
void SinglyCL<T>:: InsertAtPos(T no,int ipos)
{
    int iNodecount = Count();
    if((ipos<1)||(ipos>iNodecount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==iNodecount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeSL<T> * newn = new struct nodeSL<T>;
        newn->data = no;
        newn->next = NULL;
        struct nodeSL <T>* temp = First;

        int iCnt = 0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}
template<class T>
void SinglyCL<T>:: DeleteFirst()
{
    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
}
template<class T>
void SinglyCL<T>:: DeleteLast()
{
    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeSL<T> * temp = First;
        while(temp->next!=Last)
        {
            temp = temp->next;
        }
        delete temp->next;
        Last = temp;
        Last->next = First;
    }
}
template<class T>
void SinglyCL<T>:: DeleteAtPos(int ipos)
{
    int iNodecount = Count();
    if((ipos<1)||(ipos>iNodecount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==iNodecount+1)
    {
        DeleteLast();
    }
    else
    {
        struct nodeSL<T> * temp1 = First;
        struct nodeSL <T>* temp2 = NULL;
        int iCnt = 0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}
template<class T>
void SinglyCL<T>:: Display()
{
    struct nodeSL<T> * temp = First;
    cout<<"Elements of linekd list are:"<<"\n";
    do
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }while(temp!=Last->next);
    cout<<"\n";
}
template<class T>
int SinglyCL<T>:: Count()
{
    int iCnt = 0;
    struct nodeSL <T>* temp = First;
    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp!=Last->next);
    return iCnt;
}
template<class T>
T SinglyCL<T> :: Sum()
{
    struct nodeSL<T> * temp = First;
    T iSum = 0;
    do
    {
        iSum = iSum+(temp->data);
        temp = temp->next;
    }while(temp!=Last->next);
    return iSum;
}
template<class T>
T SinglyCL<T> :: Maximum()
{
    struct nodeSL<T> * temp = First;
    

    if(First==NULL)
    {
        cout<<"Linkedlist is empty"<<"\n";
        return 0;
    }

    T Max = First->data;
    do
    {
        if(temp->data>Max)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }while(temp!=Last->next);
    return Max;
}
template<class T>
T SinglyCL<T> :: Minimum()
{
    struct nodeSL<T> * temp = First;

    if(First==NULL)
    {
        cout<<"Linkedlist is empty"<<"\n";
        return 0;
    }

    T Min = First->data;
    do
    {
        if(temp->data<Min)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }while(temp!=Last->next);
    return Min;
}
template<class T>
int SinglyCL<T> :: DigitSum(int iNo)
{
    int iDigit = 0;
    int iSum = 0;
    while(iNo!=0)
    {
        iDigit = iNo%10;
        iSum = iSum+iDigit;
        iNo = iNo/10;
    }
    return iSum;
}
template<class T>
void SinglyCL<T> :: DisplayDigitSum()
{
    int iRet = 0;
    struct nodeSL<T> * temp = First;
    do
    {
        iRet = DigitSum(temp->data);
        printf("Sum of Digits %d is %d :\n",temp->data,iRet);
        temp = temp->next;
    }while(temp!=Last->next);
}
template<class T>
bool SinglyCL <T>:: Check_Perfect(int iNo)
{
    int iSum = 0;
    int iCnt = 0;

    for(iCnt=1;iCnt<=iNo/2;iCnt++)
    {
        if(iNo%iCnt==0)
        {
            iSum = iSum+iCnt;
        }
    }
    return(iSum == iNo);
}
template<class T>
void  SinglyCL <T>:: DisplayPerfect()
{
    struct nodeSL<T> * temp = First;
    do
    {
        if(Check_Perfect(temp->data)==true)
        {
            cout<<temp->data<<" is PERFECT Number."<<"\n";
        }
        temp = temp->next;
    }while(temp!=Last->next);
}
template<class T>
int SinglyCL <T>:: SearchFirstAccurance(int iNo)
{
    int indexCnt = 1;
    int ipos = -1;

    struct nodeSL<T> * temp = First;

    do
    {
        if(temp->data == iNo)
        {
            ipos = indexCnt;
            break;
        }
        indexCnt++;
        temp = temp->next;
    }while(temp!=Last->next);
    return ipos;
}
template<class T>
int SinglyCL <T> :: SearchLastAccurance(int iNo)
{
    int indexCnt = 1;
    int ipos = -1;

    struct nodeSL <T>* temp = First;

    do
    {
        if(temp->data == iNo)
        {
            ipos = indexCnt;
        }
        indexCnt++;
        temp = temp->next;
    }while(temp!=Last->next);
    return ipos;
} 

template<class T>
void SinglyCL<T> :: Display_Frequency(T No)
{
    T iCounter = 0;

    struct nodeSL<T> * temp = First;

    do
    {
        if(temp->data==No)
        {
            iCounter++;
        }
        temp = temp->next;
    }while(temp!=Last->next);
    cout<<"Frequency of "<<No<<" in linked list is: "<<iCounter<<"\n";

}

template<class T>
T SinglyCL <T>:: MiddleElement()
{
    struct nodeSL<T> * Teacher = First;
    struct nodeSL<T> * Student = First;
    struct nodeSL<T> * temp = Last;

    do
    {
        Teacher = Teacher->next->next;
        Student = Student->next;
    } while((Last->next!=Teacher)&&(Last!=Teacher));
    return Student->data;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeDL
{
    T data;
    struct nodeDL * next;
    struct nodeDL * prev;
};

template<class T>
class DoublyLL
{
    public:
        struct nodeDL <T> * First;

        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();

        T Sum();
        T Maximum();
        T Minimum();
        int DigitSum(int iNo);
        void DisplayDigitSum();
        bool Check_Perfect(int iNo);
        void DisplayPerfect();
        int SearchFirstAccurance(int iNo);
        int SearchLastAccurance(int iNo);
        void Display_Frequency(T iNo);
        T MiddleElement();
        void ReverseLinkedList();
};
template<class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
}
template<class T>
void DoublyLL<T>:: InsertFirst(T no)
{
    struct nodeDL <T>* newn = new struct nodeDL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
}
template<class T>
void DoublyLL<T>:: InsertLast(T no)
{
    struct nodeDL <T>* newn = new struct nodeDL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeDL <T>* temp = First;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }    
}
template<class T>
void DoublyLL<T>:: InsertAtPos(T no,int ipos)
{
    int iNodecount = Count();

    if((ipos<1)||(ipos>iNodecount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos ==iNodecount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeDL <T> * newn = new struct nodeDL<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        struct nodeDL <T> * temp = First;

        int iCnt = 0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        
    }    
}
template<class T>
void DoublyLL<T>:: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
}
template<class T>
void DoublyLL<T>:: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeDL <T> * temp = First;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }    
}
template<class T>
void DoublyLL<T>:: DeleteAtPos(int ipos)
{
    int iNodecount = Count();

    if((ipos<1)||(ipos>iNodecount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos ==iNodecount+1)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDL <T> * temp = First;

        int iCnt = 0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}
template<class T>
void DoublyLL<T>:: Display()
{
    struct nodeDL <T>* temp = First;
    cout<<"Elements of linekd list are:"<<"\n";
    cout<<"NULL<=>";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
template<class T>
int DoublyLL<T>:: Count()
{
    int iCnt= 0;
    struct nodeDL <T>* temp = First;
    while(temp!=NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;

}

template<class T>
T DoublyLL<T> :: Sum()
{
    struct nodeDL<T> * temp = First;
    T iSum = 0;
    while(temp!=NULL)
    {
        iSum = iSum+(temp->data);
        temp = temp->next;
    }
    return iSum;
}
template<class T>
T DoublyLL<T> :: Maximum()
{
    struct nodeDL<T> * temp = First;
    

    if(First==NULL)
    {
        cout<<"Linkedlist is empty"<<"\n";
        return 0;
    }

    T Max = First->data;
    while(temp!=NULL)
    {
        if(temp->data>Max)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }
    return Max;
}
template<class T>
T DoublyLL<T> :: Minimum()
{
    struct nodeDL<T> * temp = First;

    if(First==NULL)
    {
        cout<<"Linkedlist is empty"<<"\n";
        return 0;
    }

    T Min = First->data;
    while(temp!=NULL)
    {
        if(temp->data<Min)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }
    return Min;
}
template<class T>
int DoublyLL<T> :: DigitSum(int iNo)
{
    int iDigit = 0;
    int iSum = 0;
    while(iNo!=0)
    {
        iDigit = iNo%10;
        iSum = iSum+iDigit;
        iNo = iNo/10;
    }
    return iSum;
}
template<class T>
void DoublyLL<T> :: DisplayDigitSum()
{
    int iRet = 0;
    struct nodeDL<T> * temp = First;
    while(temp!=NULL)
    {
        iRet = DigitSum(temp->data);
        printf("Sum of Digits %d is %d :\n",temp->data,iRet);
        temp = temp->next;
    }
}
template<class T>
bool DoublyLL <T>:: Check_Perfect(int iNo)
{
    int iSum = 0;
    int iCnt = 0;

    for(iCnt=1;iCnt<=iNo/2;iCnt++)
    {
        if(iNo%iCnt==0)
        {
            iSum = iSum+iCnt;
        }
    }
    return(iSum == iNo);
}
template<class T>
void  DoublyLL<T>:: DisplayPerfect()
{
    struct nodeDL<T> * temp = First;
    while(temp!=NULL)
    {
        if(Check_Perfect(temp->data)==true)
        {
            cout<<temp->data<<" is PERFECT Number."<<"\n";
        }
        temp = temp->next;
    }
}
template<class T>
int DoublyLL<T>:: SearchFirstAccurance(int iNo)
{
    int indexCnt = 1;
    int ipos = -1;

    struct nodeDL<T> * temp = First;

    while(temp!=NULL)
    {
        if(temp->data == iNo)
        {
            ipos = indexCnt;
            break;
        }
        indexCnt++;
        temp = temp->next;
    }
    return ipos;
}
template<class T>
int DoublyLL<T> :: SearchLastAccurance(int iNo)
{
    int indexCnt = 1;
    int ipos = -1;

    struct nodeDL <T>* temp = First;

    while(temp!=NULL)
    {
        if(temp->data == iNo)
        {
            ipos = indexCnt;
        }
        indexCnt++;
        temp = temp->next;
    }
    return ipos;
} 

template<class T>
void DoublyLL<T> :: Display_Frequency(T No)
{
    T iCounter = 0;

    struct nodeDL<T> * temp = First;

    while(temp!=NULL)
    {
        if(temp->data==No)
        {
            iCounter++;
        }
        temp = temp->next;
    }
    cout<<"Frequency of "<<No<<" in linked list is: "<<iCounter<<"\n";
}
template<class T>
T DoublyLL<T>:: MiddleElement()
{
    struct nodeDL<T> * Teacher = First;
    struct nodeDL<T> * Student = First;

    while((Teacher!=NULL)&&(Teacher->next!=NULL))
    {
        Teacher = Teacher->next->next;
        Student = Student->next;
    }
    return Student->data;

}
template<class T>
void DoublyLL<T>::ReverseLinkedList()
{
    struct nodeDL<T>* Next = NULL;
    struct nodeDL<T>* Previous = NULL;
    struct nodeDL<T>* Current = First;

    while(Current!=NULL)
    {
        Next = Current->next;
        Current->next = Previous;
        Previous = Current;
        Current = Next;
    }
    First = Previous;

}
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyCL
{
    public:
        struct nodeDL <T>* First;
        struct nodeDL <T>* Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();

        T Sum();
        T Maximum();
        T Minimum();
        int DigitSum(int iNo);
        void DisplayDigitSum();
        bool Check_Perfect(int iNo);
        void DisplayPerfect();
        int SearchFirstAccurance(int iNo);
        int SearchLastAccurance(int iNo);
        void Display_Frequency(T iNo);
        T MiddleElement();
        
};
template<class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
}
template<class T>
void DoublyCL <T>:: InsertFirst(T no)
{
    struct nodeDL<T> * newn = new struct nodeDL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First = Last = newn;
        First->prev = Last;
        Last->next = First;
    }
    else
    {
        newn->next = First;
        First->next->prev = newn;
        First = newn;
        Last->next = First;
    }
}
template<class T>
void DoublyCL <T>:: InsertLast(T no)
{
    struct nodeDL <T>* newn = new struct nodeDL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First = Last = newn;
        First->prev = Last;
        Last->next = First;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
        First->prev = Last;
        Last->next = First;
    }
}
template<class T>
void DoublyCL <T>:: InsertAtPos(T no,int ipos)
{
    int NodeCount = Count();
    if((ipos<1)||(ipos>NodeCount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
        return;
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==NodeCount+1)
    {
        InsertLast(no);
    }
    else
    {
        int iCnt =0;
        struct nodeDL<T> * temp = First;
        struct nodeDL <T>* newn = new struct nodeDL<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }

}
template<class T>
void DoublyCL <T>:: DeleteFirst()
{
    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
         First->prev = Last;
        Last->next = First;
       
    }
}
template<class T>
void DoublyCL <T>:: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}
template<class T>
void DoublyCL <T>:: DeleteAtPos(int ipos)
{
    int NodeCount = Count();
    if((ipos<1)||(ipos>NodeCount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==NodeCount)
    {
        DeleteLast();
    }
    else
    {
        int iCnt = 0;
        struct nodeDL <T>* temp = First;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}
template<class T>
void DoublyCL <T>:: Display()
{
    struct nodeDL<T> * temp = First;
    cout<<"Elements of linked list are:"<<"\n";
    do 
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;

    }while(temp!=Last->next);
    cout<<"\n";
}
template<class T>
int DoublyCL <T>:: Count()
{
    int iCnt = 0;
    struct nodeDL <T>* temp = First;
    do
    {
        iCnt++;
        temp = temp->next;

    }while(temp!=Last->next);
    return iCnt;
}
template<class T>
T DoublyCL<T> :: Sum()
{
    struct nodeDL<T> * temp = First;
    T iSum = 0;
    do
    {
        iSum = iSum+(temp->data);
        temp = temp->next;
    }while(temp!=Last->next);
    return iSum;
}
template<class T>
T DoublyCL<T> :: Maximum()
{
    struct nodeDL<T> * temp = First;
    

    if(First==NULL)
    {
        cout<<"Linkedlist is empty"<<"\n";
        return 0;
    }

    T Max = First->data;
    do
    {
        if(temp->data>Max)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }while(temp!=Last->next);
    return Max;
}
template<class T>
T DoublyCL<T> :: Minimum()
{
    struct nodeDL<T> * temp = First;

    if(First==NULL)
    {
        cout<<"Linkedlist is empty"<<"\n";
        return 0;
    }

    T Min = First->data;
    do
    {
        if(temp->data<Min)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }while(temp!=Last->next);
    return Min;
}
template<class T>
int DoublyCL<T> :: DigitSum(int iNo)
{
    int iDigit = 0;
    int iSum = 0;
    while(iNo!=0)
    {
        iDigit = iNo%10;
        iSum = iSum+iDigit;
        iNo = iNo/10;
    }
    return iSum;
}
template<class T>
void DoublyCL<T> :: DisplayDigitSum()
{
    int iRet = 0;
    struct nodeDL<T> * temp = First;
    do
    {
        iRet = DigitSum(temp->data);
        printf("Sum of Digits %d is %d :\n",temp->data,iRet);
        temp = temp->next;
    }while(temp!=Last->next);
}
template<class T>
bool DoublyCL <T>:: Check_Perfect(int iNo)
{
    int iSum = 0;
    int iCnt = 0;

    for(iCnt=1;iCnt<=iNo/2;iCnt++)
    {
        if(iNo%iCnt==0)
        {
            iSum = iSum+iCnt;
        }
    }
    return(iSum == iNo);
}
template<class T>
void  DoublyCL<T>:: DisplayPerfect()
{
    struct nodeDL<T> * temp = First;
    do
    {
        if(Check_Perfect(temp->data)==true)
        {
            cout<<temp->data<<" is PERFECT Number."<<"\n";
        }
        temp = temp->next;
    }while(temp!=Last->next);
}
template<class T>
int DoublyCL<T>:: SearchFirstAccurance(int iNo)
{
    int indexCnt = 1;
    int ipos = -1;

    struct nodeDL<T> * temp = First;

    do
    {
        if(temp->data == iNo)
        {
            ipos = indexCnt;
            break;
        }
        indexCnt++;
        temp = temp->next;
    }while(temp!=Last->next);
    return ipos;
}
template<class T>
int DoublyCL<T> :: SearchLastAccurance(int iNo)
{
    int indexCnt = 1;
    int ipos = -1;

    struct nodeDL <T>* temp = First;

    do
    {
        if(temp->data == iNo)
        {
            ipos = indexCnt;
        }
        indexCnt++;
        temp = temp->next;
    }while(temp!=Last->next);
    return ipos;
} 

template<class T>
void DoublyCL<T> :: Display_Frequency(T No)
{
    T iCounter = 0;

    struct nodeDL<T> * temp = First;

    do
    {
        if(temp->data==No)
        {
            iCounter++;
        }
        temp = temp->next;
    }while(temp!=Last->next);
    cout<<"Frequency of "<<No<<" in linked list is: "<<iCounter<<"\n";
}
template<class T>
T DoublyCL<T>:: MiddleElement()
{
    struct nodeDL<T> * Teacher = First;
    struct nodeDL<T> * Student = First;
    struct nodeDL<T>* temp = Last;

    do
    {
        Teacher = Teacher->next->next;
        Student = Student->next;
    }while((Last->next!=Teacher)&&(Last!=Teacher));
    return Student->data;

}


////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
class Queue
{
    public:
        struct nodeSL<T> * First;
        int iCount;
        Queue();
        bool IsQueueEmpty();
        void EnQueue(T no);
        T DeQueue();
        void Display();
};
template<class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}
template<class T>
bool Queue<T>::IsQueueEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class T>
void Queue<T>::EnQueue(T no)
{
    struct nodeSL <T>* newn = new struct nodeSL<T>;
    newn->data = no;
    newn->next = NULL;

    if(First==NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeSL<T> * temp = First;
        while(temp->next!=NULL)
        {
            temp =temp->next;
        }
        temp->next = newn;
    }
    cout<<no<<" gets enqueue successfully in queue.."<<"\n";
}
template<class T>
T Queue<T>::DeQueue()
{
    if(First==NULL)
    {
        cout<<"Queue is empty.."<<"\n";
    }
    else
    {
        T value  = First->data;
        struct nodeSL <T>* temp = First;
        First = First->next;
        delete temp;
        iCount--;
        return value;
    }
}
template<class T>
void Queue<T>::Display()  
{
    cout<<"Elements of queue are:"<<"\n";
    struct nodeSL <T>* temp = First;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}      

////////////////////////////////////////////////////////////////////////////////
template<class T>
class Stack
{
    public :
        struct nodeSL <T>* First;
        int iCount;

        Stack();
        bool IsStackEmpty();
        void Push(T no);
        T Pop();
        void Display();
};
template<class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}
template<class T>
bool Stack<T>::IsStackEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class T>
void Stack<T>:: Push(T no)
{
    struct nodeSL <T>* newn = new struct nodeSL<T>;
    newn->data = no;
    newn->next = NULL;

    if(First==NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
    cout<<no<<" gets push into stack successfully..."<<"\n";
}
template<class T>
T Stack<T>:: Pop()
{
    if(First==NULL)
    {
        cout<<"Stack is empty..";
    }
    else
    {
        int value = First->data;
        struct nodeSL <T>* temp = First;
        First = First->next;
        iCount--;
        delete temp;
        return value;
    }
    
}
template<class T>
void Stack<T>:: Display()
{
    cout<<"Elements of stack are:.";
    struct nodeSL<T> * temp = First;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

/////////////////////////////////////////////////////////////////////////////////
int main()
{

    return 0;
}

