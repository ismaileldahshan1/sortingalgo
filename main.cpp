#include <iostream>
#include<stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;
class helperFunctions{
public:
    void Save(string Txt,int n)
    {
        helperFunctions H;
        ofstream MyFile;
        MyFile.open(Txt);
        int *Arr=new int[n];
        H.RPA(Arr,n);
        for(int i=0;i<n;i++)
        {
            MyFile<<Arr[i]<<endl;
        }
        MyFile.close();
        delete [] Arr;
    }
    void Load(int *Arr,string Txt,int n)
    {
        ifstream MyFile;
        MyFile.open(Txt);
        for(int i=0;i<n;i++)
        {
            MyFile>>Arr[i];
        }
        MyFile.close();
    }
    void Swap(int &x,int &y)
    {
        int Temp=x;
        x=y;
        y=Temp;
    }
    void Print(int *a,int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<endl;
        }
    }
    void RPA(int *a,int n)
    {
        for(int i=0;i<n;i++)
        {
            a[i]=i;
        }
        srand(time(0));
        for(int i=2;i<n;i++)
        {
            int m=  rand() % i + 1;
            Swap(a[i],a[m]);
        }
    }
};
int SelectionSort(int arr[],int n)
{
    int count=0;
    helperFunctions H;
    for(int i=1;i<n-1;i++)
    {
        int x=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[x])
            {
                x=j;
            }
            count++;
        }
        H.Swap(arr[i],arr[x]);
    }
    return count;
}
void insertion(int *a, int size, int& count){
    int i, j, v;
    for (i = 1; i < size; i++)
    {
        v = a[i];
        j = i ;
        while (j > 0 && (count++,a[j-1] > v))
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}
class QuickSort{
private:
    helperFunctions H;
    int partition(int arr[], int low, int high,int &Counter)
    {
        int pivot = arr[low];
        int k = high;
        for (int i = high; i > low; i--) {
            if (arr[i] > pivot)
            {
                H.Swap(arr[i], arr[k--]);
            }
            Counter++;
        }
        H.Swap(arr[low], arr[k]);
        return k;
    }
public:
    void quickSort(int arr[], int low, int high,int &Counter)
    {
        if (low < high) {
            int i = partition(arr, low, high,Counter);
            quickSort(arr, low, i - 1,Counter);
            quickSort(arr, i + 1, high,Counter);
        }
    }
    void rQuickSort(int *arr,int low,int high,int &Counter)
    {
        if(low<high)
        {
            if((high-low)>5)
            {
                int k=rand()%(high-low+1)+low;
                H.Swap(arr[low],arr[k]);
            }
            int i = partition(arr, low, high,Counter);
            rQuickSort(arr, low, i-1,Counter);
            rQuickSort(arr, i+1, high,Counter);
        }
    }
};
class MergeSort{
public:
    void Merge(int *Arr,int left, int mid, int right,int &Counter)
    {
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[n1], R[n2];
        for (i = 0; i < n1; i++)
            L[i] = Arr[left + i];
        for (j = 0; j < n2; j++)
            R[j] = Arr[mid + 1 + j];
        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2) {
            Counter++;
            if (L[i] <= R[j]) {
                Arr[k] = L[i];
                i++;
            }
            else {
                Arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            Arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            Arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergeSort(int *Arr,int left,int right,int &Counter)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(Arr,left, mid,Counter);
            mergeSort(Arr,mid + 1, right,Counter);
            Merge(Arr,left, mid, right,Counter);
        }
    }
};
void DisplayExpQuick()
{
    cout<<"---------**QUICK SORT**---------"<<endl;
    QuickSort Q;helperFunctions H;
    int N_arr[] = {1001, 2001, 3001, 5001, 7001, 10001};
    cout << "Array size\tT-exp(N)" << endl;
    for (int i = 0; i < 6; i++)
    {
        int count_exp=0;
        int N = N_arr[i];
        int *Arr=new int[N];
        if(N==1001)
        {
            H.Load(Arr,"1000Arr.txt",1001);
        }
        else if(N==2001)
        {
            H.Load(Arr,"2000Arr.txt",2001);
        }
        else if(N==3001)
        {
            H.Load(Arr,"3000Arr.txt",3001);
        }
        else if(N==5001)
        {
            H.Load(Arr,"5000Arr.txt",5001);
        }
        else if(N==7001)
        {
            H.Load(Arr,"7000Arr.txt",7001);
        }
        else if(N==10001)
        {
            H.Load(Arr,"10000Arr.txt",10001);
        }
        Q.quickSort(Arr,1,N-1,count_exp);
        cout << N << "\t\t" << count_exp << endl;
        delete [] Arr;
    }
}
void DisplayExpRQuick()
{
    cout<<"---------**RQUICK SORT**---------"<<endl;
    QuickSort Q;helperFunctions H;
    int N_arr[] = {1001, 2001, 3001, 5001, 7001, 10001};
    cout << "Array size\tT-exp(N)" << endl;
    for (int i = 0; i < 6; i++)
    {
        int count_exp=0;
        int N = N_arr[i];
        int *Arr=new int[N];
        if(N==1001)
        {
            H.Load(Arr,"1000Arr.txt",1001);
        }
        else if(N==2001)
        {
            H.Load(Arr,"2000Arr.txt",2001);
        }
        else if(N==3001)
        {
            H.Load(Arr,"3000Arr.txt",3001);
        }
        else if(N==5001)
        {
            H.Load(Arr,"5000Arr.txt",5001);
        }
        else if(N==7001)
        {
            H.Load(Arr,"7000Arr.txt",7001);
        }
        else if(N==10001)
        {
            H.Load(Arr,"10000Arr.txt",10001);
        }
        Q.rQuickSort(Arr,1,N-1,count_exp);
        cout << N << "\t\t" << count_exp << endl;
        delete [] Arr;
    }
}
void DisplayExpInsertion()
{
    cout<<"---------**INSERTION SORT**---------"<<endl;
    helperFunctions H;
    int N_arr[] = {1001, 2001, 3001, 5001, 7001, 10001};
    cout << "Array size\tT-exp(N)" << endl;
    for (int i = 0; i < 6; i++)
    {
        int count_exp=0;
        int N = N_arr[i];
        int *Arr=new int[N];
        if(N==1001)
        {
            H.Load(Arr,"1000Arr.txt",1001);
        }
        else if(N==2001)
        {
            H.Load(Arr,"2000Arr.txt",2001);
        }
        else if(N==3001)
        {
            H.Load(Arr,"3000Arr.txt",3001);
        }
        else if(N==5001)
        {
            H.Load(Arr,"5000Arr.txt",5001);
        }
        else if(N==7001)
        {
            H.Load(Arr,"7000Arr.txt",7001);
        }
        else if(N==10001)
        {
            H.Load(Arr,"10000Arr.txt",10001);
        }
        insertion(Arr,N,count_exp);
        cout << N << "\t\t" << count_exp << endl;
        delete [] Arr;
    }
}
void DisplayExpSelection()
{
    cout<<"---------**SELECTION SORT**---------"<<endl;
    helperFunctions H;
    int N_arr[] = {1001, 2001, 3001, 5001, 7001, 10001};
    cout << "Array size\tT-exp(N)" << endl;
    for (int i = 0; i < 6; i++)
    {
        int count_exp=0;
        int N = N_arr[i];
        int *Arr=new int[N];
        if(N==1001)
        {
            H.Load(Arr,"1000Arr.txt",1001);
        }
        else if(N==2001)
        {
            H.Load(Arr,"2000Arr.txt",2001);
        }
        else if(N==3001)
        {
            H.Load(Arr,"3000Arr.txt",3001);
        }
        else if(N==5001)
        {
            H.Load(Arr,"5000Arr.txt",5001);
        }
        else if(N==7001)
        {
            H.Load(Arr,"7000Arr.txt",7001);
        }
        else if(N==10001)
        {
            H.Load(Arr,"10000Arr.txt",10001);
        }
        count_exp=SelectionSort(Arr,N);
        cout << N << "\t\t" << count_exp << endl;
        delete [] Arr;
    }
}
void DisplayExpMerge()
{
    cout<<"---------**MERGE SORT**---------"<<endl;
    helperFunctions H;MergeSort M;
    int N_arr[] = {1001, 2001, 3001, 5001, 7001, 10001};
    cout << "Array size\tT-exp(N)" << endl;
    for (int i = 0; i < 6; i++)
    {
        int count_exp=0;
        int N = N_arr[i];
        int *Arr=new int[N];
        if(N==1001)
        {
            H.Load(Arr,"1000Arr.txt",1001);
        }
        else if(N==2001)
        {
            H.Load(Arr,"2000Arr.txt",2001);
        }
        else if(N==3001)
        {
            H.Load(Arr,"3000Arr.txt",3001);
        }
        else if(N==5001)
        {
            H.Load(Arr,"5000Arr.txt",5001);
        }
        else if(N==7001)
        {
            H.Load(Arr,"7000Arr.txt",7001);
        }
        else if(N==10001)
        {
            H.Load(Arr,"10000Arr.txt",10001);
        }
        M.mergeSort(Arr,1,N-1,count_exp);
        cout << N << "\t\t" << count_exp << endl;
        delete [] Arr;
    }
}
int main() {
    DisplayExpSelection();
    DisplayExpInsertion();
    DisplayExpMerge();
    DisplayExpQuick();
    DisplayExpRQuick();
}
