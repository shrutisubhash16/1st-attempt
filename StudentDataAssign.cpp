#include<iostream>
#include<string.h>
using namespace std;
struct studData
{
    int rollno;
    string name;
    float sgpa;
};
class student
{
public:

    struct studData s[100];
    void getdata(int n);
    void bubbleSort(int n);
    void insertionSort (int n);
    int quickSortPartition(int left,int right);
    void quickSort(int left,int right);
    void linearSearch(int n);
    void bubblesort(int n);
    void binarySearch(int left,int right,string key);
    void putdata(int n);
};
void student :: getdata(int n)
{
    for(int i=0;i<n;i++){
        cout<<i+1<<endl<<"Enter roll no. : ";
        cin>>s[i].rollno;
        cout<<"Enter name : ";
        cin>>s[i].name;
        cout<<"Enter SGPA : ";
        cin>>s[i].sgpa;
    }
}
void student ::bubbleSort(int n)
{
    studData temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(s[j].rollno > s[j+1].rollno){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    putdata(n);
}
void student ::insertionSort(int n)
{
    studData temp;
    int j;
    for(int i=0;i<n;i++){
        string temp1=s[i].name;
        temp=s[i];
        j=i;
        while(j>0 && s[j-1].name>temp1){
            s[j]=s[j-1];
            j--;
        }
        s[j]=temp;
    }
    putdata(n);
}
int student :: quickSortPartition(int left,int right)
{
    int i,j,pivot;
    studData temp;
    i=left;
    j=right;
    pivot=right;
    while(true){
        while(s[i].sgpa>=s[pivot].sgpa){
            i++;
        }
        while(j>0 && s[j].sgpa<s[pivot].sgpa){
            j--;
        }
        if(i>=j){
            break;
        }else{
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }

    }
    return j;
}
void student ::quickSort(int left,int right){
    if(left<right){
       int part=quickSortPartition(left,right);
       quickSort(left,part-1);
       quickSort(part+1,right);
    }
}
void student::linearSearch(int n)
{
    float str1;
    int flag=0;
    cout<<"Enter SGPA to be search  : ";
    cin>>str1;
    cout<<"\nRoll no\t\t\tName\t\t\tSGPA\n";
    for(int i=0;i<n;i++){
        if(str1==s[i].sgpa){
            flag=1;
            cout<<s[i].rollno<<"\t\t\t"<<s[i].name<<"\t\t\t"<<s[i].sgpa<<endl;
        }
    }
    if(flag==0){
        cout<<"***Not found***\n "<<endl;
    }
}
void student ::bubblesort(int n){
   studData temp;
   for(int i=0;i<n;i++){
    for(int j=0;j<n-1-i;j++){
        if(s[j].name>s[j+1].name){
            temp=s[j];
            s[j]=s[j+1];
            s[j+1]=temp;
        }
    }
   }
}
void student::binarySearch(int left,int right,string key)
{
    int mid,flag=0;
    while(left<=right){
        mid=(left+right)/2;
        if(key==s[mid].name){
            flag=1;
            cout<<s[mid].name<<" present at roll no "<<s[mid].rollno<<endl;
        }
        if(key<s[mid].name){
            right=mid-1;
        }
        else{
            left=mid+1;
        }


    }
    if(flag==0){
        cout<<endl<<key<<" is not found."<<endl;
    }
}
void student ::putdata(int n)
{
    cout<<"\nSr No.\tRoll no\t\tName\t\tSGPA\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<s[i].rollno<<"\t\t"<<s[i].name<<"\t\t"<<s[i].sgpa<<endl;
    }
}
int main()
{
    int n,flag=0,option;
    string str;
    cout<<"Enter no. of students : ";
    cin>>n;
    student f;
    f.getdata(n);
    while(flag==0){
        cout<<"\nEnter"<<endl<<"1 for sort students according to roll no."<<endl<<"2 for sort students by alphabetical order."<<endl;
        cout<<"3 for sort students according to their SGPA."<<endl<<"4 for search students according to their SGPA."<<endl;
        cout<<"5 for search students according to their name."<<endl<<"6 for Exit.\n";
        cin>>option;
        switch(option)
        {
            case 1:cout<<"\nDisplaying sorted student records according to roll no."<<endl;
                   f.bubbleSort(n);
                   break;
            case 2:cout<<"\nDisplaying sorted student records according to name."<<endl;
                   f.insertionSort(n);
                   break;
            case 3:f.quickSort(0,n-1);
                   f.putdata(n);
                   break;
            case 4:f.linearSearch(n);
                   break;
            case 5: cout<<"Enter name to be search : ";
                    cin>>str;
                    f.bubblesort(n);
                    f.binarySearch(0,n-1,str);
                    break;
            case 6:flag=1;
                   break;
            default :cout<<"Enter correct choice"<<endl;
        }
    }
    return 0;
}
