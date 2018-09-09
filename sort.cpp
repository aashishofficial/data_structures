#include<conio.h>
#include<iostream>
using namespace std;
class sort_functions{
    public:
          void get_array(int,int arr[]);
          void display_arr(int ,int arr[]);
          void merge_sort(int arr[],int,int);
          void merg(int arr[],int, int,int);
          void quick_sort(int arr[],int,int);
          int find_pivot(int arr[],int,int);
          void insertion_sort(int arr[],int n);
          void selection_sort(int arr[],int n);
          void bubble_sort(int arr[],int n);
};
int main(){
    sort_functions sf;
    cout<<"Please enter the size of array u want to deal with->\n";
    int n;
    cin>>n;
    cout<<"You entered->"<<n<<endl;
    int arr[n];
    sf.get_array(n,arr);
    cout<<"Which sort would u like to perform:"<<endl;
    cout<<"1. Merge Sort"<<endl<<"2. Quick Sort"<<endl<<"3. Insertion Sort"<<endl<<"4. Selection Sort"<<endl<<"5. Bubble Sort"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        case 1:cout<<"Performing Merge Sort........"<<endl<<"Press Enter to Continue."<<endl;
               getch();
               sf.merge_sort(arr,0,n-1);
               sf.display_arr(n,arr);
               break;
        case 2:cout<<"Performing Quick Sort........"<<endl<<"Press Enter to Continue."<<endl;
               getch();
               sf.quick_sort(arr,0,n-1);
               sf.display_arr(n,arr);
               break;
        case 3:cout<<"Performing Insertion Sort......"<<endl<<"Press Enter to Continue."<<endl;
               getch();
               sf.insertion_sort(arr,n);
               sf.display_arr(n,arr);
               break;
        case 4:cout<<"Performing Selection Sort......"<<endl<<"Press Enter to Continue."<<endl;
               getch();
               sf.selection_sort(arr,n);
               sf.display_arr(n,arr);
               break;
        case 5:cout<<"Performing Bubble Sort........."<<endl<<"Press Enter to Continue."<<endl;
               getch();
               sf.bubble_sort(arr,n);
               sf.display_arr(n,arr);
               break;
    }
    return 0;
}
void sort_functions::get_array(int n,int arr[]){
        cout<<"Enter "<<n<<" elements -> "<<endl;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            cout<<"Element "<<i+1<<" -> "<<arr[i]<<endl;
        }
        display_arr(n,arr);
}
void sort_functions::display_arr(int n,int arr[]){
        cout<<"Sir, your current array is : ";
        for(int i=0; i<n;i++)
             cout<<" "<<arr[i]<<" ";
        cout<<endl;
}
void sort_functions::merge_sort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merg(arr,l,m,r);
    }

}
void sort_functions::merg(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}
void sort_functions::quick_sort(int arr[],int l,int r){
    if(l<r){
        int pindex=find_pivot(arr,l,r);
        quick_sort(arr,l,pindex-1);
        quick_sort(arr,pindex+1,r);
    }
}
int sort_functions::find_pivot(int arr[],int l,int r){
    int pivot=arr[r];
    int pindex=l;
    for(int i=l;i<r;i++){
        if(arr[i]<=pivot){
        swap(arr[i],arr[pindex]);
        pindex++;
        }
    }
    swap(arr[pindex],arr[r]);
    return pindex;
}
void sort_functions::insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void sort_functions::selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int imin=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[imin]){
                imin=j;
            }
        }
        swap(arr[imin],arr[i]);
    }
}
void sort_functions::bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool a=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                a=true;
            }
        }
        if(a==false) break;
    }
}
